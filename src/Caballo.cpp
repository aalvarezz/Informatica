#pragma once
#include "Caballo.h"
#include <math.h>

bool Caballo::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	for (int j = -2; j <= 2; j++) {
		for (int k = -2; k <= 2; k++) {
			if ((abs(j) != abs(k)) && (j != 0) && (k != 0)) {
				Pos posaux(j, k);
				posaux = posaux + inicio;

				//la casilla fin entra en las reglas
				if ((posaux.fila == fin.fila) && (posaux.columna == fin.columna)) {
					//Está vacía
					if (tablero->getPieza(fin) == nullptr) {
						return true;
					}
					//Hay una pieza del color contrario
					else if (tablero->getPieza(fin)->getColor() != color) {
						return true;
					}
				}				
			}
		}
	}
	return false;
}
