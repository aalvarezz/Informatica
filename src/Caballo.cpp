#pragma once
#include "Caballo.h"
#include <math.h>

bool Caballo::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	for (int j = -2; j <= 2; j++) {
		for (int k = -2; k <= 2; k++) {
			if ((abs(j) != abs(k)) && (j != 0) && (k != 0)) {
				Pos posaux(j, k);
				if (((inicio + posaux) == fin) &&
					((this->getColor() != tablero->getPieza(fin)->getColor()) || (tablero->getPieza(fin) == nullptr)))
					return true;
			}
		}
	}
	return false;
}

void Caballo::dibujar(Pos posicion)
{
	bool color = this->getColor();
	//en funcion del color de la pieza la dibuja en su posicion correspondiente

	switch (color) {
	case 0:
		CaballoB.setCenter(lado / 2, lado / 2);
		CaballoB.setSize(lado, lado);
		glTranslatef(posicion.fila, posicion.columna, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		CaballoB.draw();
		glTranslatef(-posicion.fila, -posicion.columna, -0.1f);
		break;
	case 1:
		CaballoN.setCenter(lado / 2, lado / 2);
		CaballoN.setSize(lado, lado);
		glTranslatef(posicion.fila, posicion.columna, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		CaballoN.draw();
		glTranslatef(-posicion.fila, -posicion.columna, -0.1f);
		break;
	}
}

void Caballo::posibleCasilla(Tablero* tablero, Pos posicion)
{

	//el bucle "for" se emplea para barrer todos los posibles movimientos de las piezas
	//las condiciones dentro del bucle verifican si los posibles movimientos de la pieza est�n limitados de algun modo.
	//si no lo estuvieran, se har�a llamada al m�todo con el que se dibujan los posibles movimientos de la pieza

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
