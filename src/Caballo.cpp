#pragma once
#include "Caballo.h"
#include <math.h>

bool Caballo::comprueba(Tablero* tablero, Pos inicio, Pos fin) { //comprueba los movimientos validos de la pieza, sin tener en cuenta posibles excepciones
	for (int j = -2; j <= 2; j++) {//se itera para obtener direcciones auxiliares de los movimientos posibles del caballo
		for (int k = -2; k <= 2; k++) {
			if ((abs(j) != abs(k)) && (j != 0) && (k != 0)) {//comprueba que con la iteracion se obtiene una posible direccion del movimiento del caballo
				Pos posaux(j, k);//crea la direccion en base a la iteracion
				posaux = posaux + inicio;//actualiza la posicion para que tenga en cuenta la posicion inicial y la posible direccion de movimiento

				if (posaux == fin) {//se compueba si la posicion auxiliar coincide con la posicion final del caballo
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