#pragma once
#include "Caballo.h"
#include <math.h>

bool Caballo::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	for (int j = -2; j <= 2; j++) {
		for (int k = -2; k <= 2; k++) {
			if ((abs(j) != abs(k)) && (j != 0) && (k != 0)) {
				Pos posaux(j, k);
				posaux = posaux + inicio;

				//la casilla fin entra en las reglas
				if ((posaux.fila == fin.fila) && (posaux.columna == fin.columna)) {
					//Está vacía
					if (tablero->getPieza(fin) == nullptr) {
						return true;
					}
					//Hay una pieza del color contrario
					else if (tablero->getPieza(fin)->getColor() != color) {
						return true;
					}
				}				
			}
		}
	}
	return false;
}

void Caballo::draw(float x, float y) {
	//en funcion del color de la pieza la dibuja en su posicion correspondiente

	switch (color) {
	case 0:
		CaballoB.setCenter(lado / 2, lado / 2);
		CaballoB.setSize(lado, lado);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		CaballoB.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	case 1:
		CaballoN.setCenter(lado / 2, lado / 2);
		CaballoN.setSize(lado, lado);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		CaballoN.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	}
}
void Caballo::posibleCasilla(Tablero* tablero, Pos posicion) {
	//el bucle "for" se emplea para barrer todos los posibles movimientos de las piezas
	//las condiciones dentro del bucle verifican si los posibles movimientos de la pieza están limitados de algun modo.
	//si no lo estuvieran, se haría llamada al método con el que se dibujan los posibles movimientos de la pieza

	for (int j = -2; j <= 2; j++) {
		for (int k = -2; k <= 2; k++) {
			if ((abs(j) != abs(k)) && (j != 0) && (k != 0)) {
				Pos posaux(j, k);
				if ((this->getColor() != tablero->getPieza(posaux)->getColor()) || (tablero->getPieza(posaux) == nullptr))
					tablero->setPosibleCasilla(posaux);
			}
		}
	}
}