#pragma once
#include "Dama.h"

bool Dama::comprueba(Tablero* tablero, Pos inicio, Pos fin) const{
	int sentido;
	// Decide cual es el sentido en el que queremos mover la pieza
	for (int j = 1; j <= 7; j++) {
		Pos aux1(0, j), aux2(0, -j), aux3(j, 0), aux4(-j, 0), aux5(j, j), aux6(j, -j), aux7(-j, -j), aux8(-j, j);
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

	// Una vez decidido, va comprobando que no haya piezas entre el origen y la posición final
	switch (sentido) {
	case 1:	// 1. Hacia arriba
		for (int j = 1; j <= 7; j++) {
			Pos posaux1(0, j);
			if (((inicio + posaux1) == fin) && ((tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color)))
				return true;
			else if (tablero->getPieza(inicio + posaux1) != nullptr)
				return false;
		}
		break;

	case 2:	// 2. Hacia abajo
		for (int j = 1; j <= 7; j++) {
			Pos posaux2(0, -j);
			if (((inicio + posaux2) == fin) && ((tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color)))
				return true;
			else if (tablero->getPieza(inicio + posaux2) != nullptr)
				return false;
		}
		break;

	case 3:	// 3. Derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux3(j, 0);
			if (((inicio + posaux3) == fin) && ((tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color)))
				return true;
			else if (tablero->getPieza(inicio + posaux3) != nullptr)
				return false;
		}
		break;

	case 4:	//4. Izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux4(-j, 0);
			if (((inicio + posaux4) == fin) && ((tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color)))
				return true;
			else if (tablero->getPieza(inicio + posaux4) != nullptr)
				return false;
		}
		break;

	case 5:	//5. Arriba derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux5(j, j);
			if (((inicio + posaux5) == fin) && ((tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color)))
				return true;
			else if (tablero->getPieza(inicio + posaux5) != nullptr)
				return false;
		}
		break;

	case 6:	//6. Abajo derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux6(-j, j);
			if (((inicio + posaux6) == fin) && ((tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color)))
				return true;
			else if (tablero->getPieza(inicio + posaux6) != nullptr)
				return false;
		}
		break;

	case 7:	//7. Abajo izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux7(-j, -j);
			if (((inicio + posaux7) == fin) && ((tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color)))
				return true;
			else if (tablero->getPieza(inicio + posaux7) != nullptr)
				return false;
		}
		break;

	case 8://5. Arriba izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux8(-j, j);
			if (((inicio + posaux8) == fin) && ((tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color)))
				return true;
			else if (tablero->getPieza(inicio + posaux8) != nullptr)
				return false;
		}
		break;
	}
	return false;
}