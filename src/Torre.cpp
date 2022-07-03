#pragma once
#include "Torre.h"

bool Torre::comprueba(Tablero* tablero, Pos inicio, Pos fin) const{
	int sentido;
	for (int j = 1; j <= 7; j++) {
		Pos aux1(0, j), aux2(0, -j), aux3(j, 0), aux4(-j, 0);
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
	}
	return false;
}