#pragma once
#include "Caballo.h"
#include <math.h>

bool Caballo::comprueba(Tablero* tablero, Pos inicio, Pos fin) const {
	for (int j = -2; j <= 2; j++) {
		for (int k = -2; k <= 2; k++) {
			if ((abs(j) != abs(k)) && (j != 0) && (k != 0)) {
				Pos posaux(j, k);
				if (((inicio + posaux) == fin) &&
					((color != tablero->getPieza(fin)->getColor()) || (tablero->getPieza(fin) == nullptr)))
					return true;
			}
		}
	}
	return false;
}