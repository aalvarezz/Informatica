#pragma once
#include "Rey.h"

bool Rey::comprueba(Tablero* tablero, Pos inicio, Pos fin) { //comprueba los movimientos validos de la pieza, sin tener en cuenta posibles excepciones
	for (int j = -1; j <= 1; j++) {//se itera para obtener direcciones auxiliares de los movimientos posibles del rey
		for (int k = -1; k <= 1; k++) {
			Pos posaux(j, k);//crea la direccion en base a la iteracion
			posaux = posaux + inicio;//actualiza la posicion para que tenga en cuenta la posicion inicial y la posible direccion de movimiento
			//se compueba si el rey no se queda en la posicion de partida y si la posicion auxiliar coincide con la posicion final del rey
			if (((j != 0) || (k != 0)) && (posaux == fin)) {
				if (tablero->getPieza(fin) == nullptr) {//comprueba si la posicion final esta vacia
					return true;
				}
				else if (color != tablero->getPieza(fin)->getColor()) {//comprueba si la posicion final la ocupa una pieza de otro color
					return true;
				}
			}
		}
	}
	return false;
}
