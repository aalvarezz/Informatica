#pragma once
#include "Rey.h"

bool Rey::comprueba(Tablero* tablero, Pos inicio, Pos fin) const{
	for (int j = -1; j <= 1; j++) {
		for (int k = -1; k <= 1; k++) {
			Pos posaux(j, k);
			if ((j != 0) && (k != 0) && ((inicio + posaux)==fin) &&
				((color != tablero->getPieza(fin)->getColor()) || (tablero->getPieza(fin) == nullptr)))
				return true;
		}
	}
	return false;
}