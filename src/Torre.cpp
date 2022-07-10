
#pragma once
#include "Torre.h"

bool Torre::comprueba(Tablero* tablero, Pos inicio, Pos fin) { //comprueba los movimientos validos de la pieza, sin tener en cuenta posibles excepciones
	int sentido = 0;
	for (int j = 1; j <= 7; j++) {
		Pos aux1(j, 0), aux2(-j, 0), aux3(0, j), aux4(0, -j);
		aux1 = aux1 + inicio;
		aux2 = aux2 + inicio;
		aux3 = aux3 + inicio;
		aux4 = aux4 + inicio;

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
	case 0:
		return false;
		break;

	case 1:	// 1. Hacia arriba
		for (int j = 1; j <= 7; j++) {//se itera para obtener el avance de la torre cuando se desplaza hacia arriba
			Pos posaux1(j, 0);//crea el avance en base a la iteracion
			posaux1 = posaux1 + inicio;//actualiza la posicion para que tenga en cuenta la posicion inicial y el desplazamiento del movimiento

			if (posaux1 == fin) {//se compueba si la posicion auxiliar coincide con la posicion final de la torre
				if(tablero->getPieza(fin) == nullptr) {//comprueba si la posicion final esta vacia
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {//comprueba si la posicion final la ocupa una pieza de otro color
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux1) != nullptr)
				return false;
		}
		break;

	case 2:	// 2. Hacia abajo
		for (int j = 1; j <= 7; j++) {//se itera para obtener el avance de la torre cuando se desplaza hacia abajo
			Pos posaux2(-j, 0);//crea el avance en base a la iteracion
			posaux2 = posaux2 + inicio;//actualiza la posicion para que tenga en cuenta la posicion inicial y el desplazamiento del movimiento

			if (posaux2 == fin) {//se compueba si la posicion auxiliar coincide con la posicion final de la torre
				if(tablero->getPieza(fin) == nullptr) {//comprueba si la posicion final esta vacia
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {//comprueba si la posicion final la ocupa una pieza de otro color
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux2) != nullptr)
				return false;
		}
		break;

	case 3:	// 3. Derecha
		for (int j = 1; j <= 7; j++) {//se itera para obtener el avance de la torre cuando se desplaza hacia la derecha
			Pos posaux3(0, j);//crea el avance en base a la iteracion
			posaux3 = posaux3 + inicio;//actualiza la posicion para que tenga en cuenta la posicion inicial y el desplazamiento del movimiento

			if (posaux3 == fin) {//se compueba si la posicion auxiliar coincide con la posicion final de la torre
				if(tablero->getPieza(fin) == nullptr) {//comprueba si la posicion final esta vacia
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {//comprueba si la posicion final la ocupa una pieza de otro color
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux3) != nullptr)
				return false;
		}
		break;

	case 4:	//4. Izquierda
		for (int j = 1; j <= 7; j++) {//se itera para obtener el avance de la torre cuando se desplaza hacia la izquierda
			Pos posaux4(0, -j);//crea el avance en base a la iteracion
			posaux4 = posaux4 + inicio;//actualiza la posicion para que tenga en cuenta la posicion inicial y el desplazamiento del movimiento

			if (posaux4 == fin) {//se compueba si la posicion auxiliar coincide con la posicion final de la torre
				if(tablero->getPieza(fin) == nullptr) {//comprueba si la posicion final esta vacia
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {//comprueba si la posicion final la ocupa una pieza de otro color
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux4) != nullptr)
				return false;
		}
		break;

	}
	return false;
}