#pragma once
#include "Caballo.h"
#include <math.h>

bool Caballo::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	for (int j = -2; j <= 2; j++) {
		for (int k = -2; k <= 2; k++) {
			if ((abs(j) != abs(k)) && (j != 0) && (k != 0)) {
				Pos posaux(j, k);
				if (((inicio + posaux) == fin) &&
					((this->getColor() != tablero->getPieza(fin)->getColor()) || (tablero->getPieza(fin) == 0)))	//que sea de otro color o que no haya, mejorable?
					return true;
			}
		}
	}
	return false;
}