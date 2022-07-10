#pragma once
#include "Dama.h"

bool Dama::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	int sentido = 0;
	for (int j = 1; j <= 7; j++) {
		Pos aux1(j, 0), aux2(-j, 0), aux3(0, j), aux4(0, -j), aux5(j, j), aux6(-j, j), aux7(-j, -j), aux8(j, -j);
		aux1 = aux1 + inicio;
		aux2 = aux2 + inicio;
		aux3 = aux3 + inicio;
		aux4 = aux4 + inicio;
		aux5 = aux5 + inicio;
		aux6 = aux6 + inicio;
		aux7 = aux7 + inicio;
		aux8 = aux8 + inicio;

		if (aux1 == fin)
			sentido = 1;
		if (aux2 == fin)
			sentido = 2;
		if (aux3 == fin)
			sentido = 3;
		if (aux4 == fin)
			sentido = 4;
		if (aux5 == fin)
			sentido = 5;
		if (aux6 == fin)
			sentido = 6;
		if (aux7 == fin)
			sentido = 7;
		if (aux8 == fin)
			sentido = 8;
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
				if (tablero->getPieza(fin) == nullptr) {
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
				if (tablero->getPieza(fin) == nullptr) {
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
				if (tablero->getPieza(fin) == nullptr) {
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
				if (tablero->getPieza(fin) == nullptr) {
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

	case 5:	//5. Arriba derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux5(j, j);
			posaux5 = posaux5 + inicio;

			if (posaux5 == fin) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux5) != nullptr)
				return false;
		}
		break;

	case 6:	//6. Abajo derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux6(-j, j);
			posaux6 = posaux6 + inicio;

			if (posaux6 == fin) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux6) != nullptr)
				return false;
		}
		break;

	case 7:	//7. Abajo izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux7(-j, -j);
			posaux7 = posaux7 + inicio;

			if (posaux7 == fin) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux7) != nullptr)
				return false;
		}
		break;

	case 8: //8. Arriba izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux8(j, -j);
			posaux8 = posaux8 + inicio;

			if (posaux8 == fin) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux8) != nullptr)
				return false;
		}
		break;

	}
	return false;
}
