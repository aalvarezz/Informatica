#pragma once
#include "Rey.h"

bool Rey::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	for (int j = -1; j <= 1; j++) {
		for (int k = -1; k <= 1; k++) {
			Pos posaux(j, k);
			if ((j != 0) && (k != 0) && ((inicio + posaux)==fin) &&
				((this->getColor() != tablero->getPieza(fin)->getColor()) || (tablero->getPieza(fin) == 0)))	//que sea de otro color o que no haya, mejorable?
				return true;
		}
	}
	return false;
}