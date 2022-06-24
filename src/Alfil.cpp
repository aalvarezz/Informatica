#pragma once
#include "Alfil.h"

bool Alfil::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	bool color = this->getColor();
	int sentido;
	for (int j = 1; j <= 7; j++) {
		Pos aux1(j, j), aux2(j, -j), aux3(-j, -j), aux4(-j, j);
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
	case 1:	//1. Arriba derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux1(j, j);
			if (((inicio + posaux1) == fin) && (tablero->getPieza(fin) == 0) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(inicio + posaux1) != 0)
				return false;
		}
		break;

	case 2:	//2. Abajo derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux2(-j, j);
				if (((inicio + posaux2) == fin) && (tablero->getPieza(fin) == 0) || (tablero->getPieza(fin)->getColor() != color))
					return true;
				else if (tablero->getPieza(inicio + posaux2) != 0)
					return false;
		}
		break;

	case 3:	//3. Abajo izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux3(-j, -j);
			if (((inicio + posaux3) == fin) && (tablero->getPieza(fin) == 0) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(inicio + posaux3) != 0)
				return false;
		}
		break;

	case 4: //4. Arriba izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux4(-j, j);
			if (((inicio + posaux4) == fin) && (tablero->getPieza(fin) == 0) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(inicio + posaux4) != 0)
				return false;
		}
	}
	return false;
}
