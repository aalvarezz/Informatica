#pragma once
#include "Torre.h"

bool Torre::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	int sentido = 0;
	for (int j = 1; j <= 7; j++) {
		Pos aux1(j, 0), aux2(-j, 0), aux3(0, j), aux4(0, -j);
		aux1 = aux1 + inicio;
		aux2 = aux2 + inicio;
		aux3 = aux3 + inicio;
		aux4 = aux4 + inicio;

		if (aux1 == fin)
			sentido = 1;
		if (aux2 == fin)
			sentido = 2;
		if (aux3 == fin)
			sentido = 3;
		if (aux4 == fin)
			sentido = 4;
	}

	switch (sentido) {
	case 0:
		return false;
		break;

	case 1:	// 1. Hacia arriba
		for (int j = 1; j <= 7; j++) {
			Pos posaux1(j, 0);
			posaux1 = posaux1 + inicio;

			if (posaux1 == fin) {
				if(tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux1) != nullptr)
				return false;
		}
		break;

	case 2:	// 2. Hacia abajo
		for (int j = 1; j <= 7; j++) {
			Pos posaux2(-j, 0);
			posaux2 = posaux2 + inicio;

			if (posaux2 == fin) {
				if(tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux2) != nullptr)
				return false;
		}
		break;

	case 3:	// 3. Derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux3(0, j);
			posaux3 = posaux3 + inicio;

			if (posaux3 == fin) {
				if(tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux3) != nullptr)
				return false;
		}
		break;

	case 4:	//4. Izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux4(0, -j);
			posaux4 = posaux4 + inicio;

			if (posaux4 == fin) {
				if(tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux4) != nullptr)
				return false;
		}
		break;

	}
	return false;
}

void Torre::draw(float x, float y) {
	//en funcion del color de la pieza la dibuja en su posicion correspondiente

	switch (color) {
	case 0:
		TorreB.setCenter(2.5f / 2, 2.5f / 2);
		TorreB.setSize(2.5f, 2.5f);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		TorreB.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	case 1:
		TorreN.setCenter(2.5f / 2, 2.5f / 2);
		TorreN.setSize(2.5f, 2.5f);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		TorreN.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	}
}
