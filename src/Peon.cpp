#pragma once
#include "Peon.h"

bool Peon::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	Pos posaux1(1, 0), posaux2(1, -1),  posaux3(1, 1), posaux4(-1, 0), posaux5(-1, -1), posaux6(-1, 1);

	switch (color) {
	case 0:		//BLANCO
		//1.Avanza una posición en la columna (Movimiento normal)
		posaux1 = posaux1 + inicio;
		if ((posaux1 == fin) && (tablero->getPieza(fin) == nullptr)) {
			return true;
		}

		//2.Diagonal izq (Al comer otra ficha)
		posaux2 = posaux2 + inicio;
		if ((posaux2 == fin) && (tablero->getPieza(fin) != nullptr)) {
			if (tablero->getPieza(fin)->getColor() != color) {
				return true;
			}
		}

		//3.Diagonal dcha (Al comer otra ficha)
		posaux3 = posaux3 + inicio;
		if ((posaux3 == fin) && (tablero->getPieza(fin) != nullptr)) {
			if (tablero->getPieza(fin)->getColor() != color) {
				return true;
			}
		}
		break;

	case 1:		//NEGRO
		//1.Avanza una posición en la columna (Movimiento normal)
		posaux4 = posaux4 + inicio;
		if ((posaux4 == fin) && (tablero->getPieza(fin) == nullptr)) {
			return true;
		}

		//2.Diagonal izq (Al comer otra ficha)
		posaux5 = posaux5 + inicio;
		if ((posaux5 == fin) && (tablero->getPieza(fin) != nullptr)) {
			if (tablero->getPieza(fin)->getColor() != color) {
				return true;
			}
		}

		//3.Diagonal dcha (Al comer otra ficha)
		posaux6 = posaux6 + inicio;
		if ((posaux6 == fin) && (tablero->getPieza(fin) != nullptr)) {
			if (tablero->getPieza(fin)->getColor() != color) {
				return true;
			}
		}
		break;

	}
	return false;
}
