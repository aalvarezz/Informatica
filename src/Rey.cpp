#pragma once
#include "Rey.h"

bool Rey::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	for (int j = -1; j <= 1; j++) {
		for (int k = -1; k <= 1; k++) {
			Pos posaux(j, k);
			posaux = posaux + inicio;

			if (((j != 0) || (k != 0)) && (posaux.fila == fin.fila && posaux.columna == fin.columna)) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (color != tablero->getPieza(fin)->getColor()) {
					return true;
				}
			}
		}
	}
	return false;
}

void Rey::draw(float x, float y) {
	//en funcion del color de la pieza la dibuja en su posicion correspondiente

	switch (color) {
	case 0:
		ReyB.setCenter(lado / 2, lado / 2);
		ReyB.setSize(lado, lado);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		ReyB.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	case 1:
		ReyN.setCenter(lado / 2, lado / 2);
		ReyN.setSize(lado, lado);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		ReyN.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	}
}

void Rey::posibleCasilla(Tablero* tablero, Pos posicion) {
	//el bucle "for" se emplea para barrer todos los posibles movimientos de las piezas
	//las condiciones dentro del bucle verifican si los posibles movimientos de la pieza están limitados de algun modo.
	//si no lo estuvieran, se haría llamada al método con el que se dibujan los posibles movimientos de la pieza
	for (int j = -1; j <= 1; j++) {
		for (int k = -1; k <= 1; k++) {
			Pos posaux(j, k);
			if ((j != 0) && (k != 0) &&
				((this->getColor() != tablero->getPieza(posaux)->getColor()) || (tablero->getPieza(posaux) == nullptr)))
				tablero->setPosibleCasilla(posaux);
		}
	}
}
