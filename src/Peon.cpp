#pragma once
#include "Peon.h"

bool Peon::comprueba(Tablero* tablero, Pos inicio, Pos fin) {

	bool color = this->getColor();
	Pos posaux1(0, 1), posaux2(-1, 1),  posaux3(1, 1), posaux4(0, -1), posaux5(-1, -1), posaux6(1, -1);

	switch (color) {
	case 0:		//BLANCO
		//1.Avanza una posición en la columna (Movimiento normal)
	
		if (((inicio + posaux1) == fin) && (tablero->getPieza(fin) == 0))
			return true;

		//2.Diagonal izq (Al comer otra ficha)
	
		if (((inicio + posaux2) == fin) && (tablero->getPieza(fin)->getColor() != color))
			return true;

		//3.Diagonal dcha (Al comer otra ficha)
	
		if (((inicio + posaux3) == fin) && (tablero->getPieza(fin)->getColor() != color))
			return true;
		break;


	case 1:		//NEGRO
		//1.Avanza una posición en la columna (Movimiento normal)

		if (((inicio + posaux4) == fin) && (tablero->getPieza(fin) == 0))
			return true;

		//2.Diagonal izq (Al comer otra ficha)

		if (((inicio + posaux5) == fin) && (tablero->getPieza(fin)->getColor() != color))
			return true;

		//3.Diagonal dcha (Al comer otra ficha)

		if (((inicio + posaux6) == fin) && (tablero->getPieza(fin)->getColor() != color))
			return true;
		break;
	}
	return false;
}
