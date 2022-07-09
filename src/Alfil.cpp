#pragma once
#include "Alfil.h"

bool Alfil::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	int sentido = 0;
	for (int j = 1; j <= 7; j++) {
		Pos aux1(j, j), aux2(-j, j), aux3(-j, -j), aux4(j, -j);
		aux1 = aux1 + inicio;
		aux2 = aux2 + inicio;
		aux3 = aux3 + inicio;
		aux4 = aux4 + inicio;

		if (aux1.fila == fin.fila && aux1.columna==fin.columna)
			sentido = 1;
		if (aux2.fila == fin.fila && aux2.columna==fin.columna)
			sentido = 2;
		if (aux3.fila == fin.fila && aux3.columna==fin.columna)
			sentido = 3;
		if (aux4.fila == fin.fila && aux4.columna == fin.columna)
			sentido = 4;
	}

	switch (sentido) {
	case 0:
		return false;
		break;

	case 1:	//1. Arriba derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux1(j, j);
			posaux1 = posaux1 + inicio;

			if (posaux1.fila == fin.fila && posaux1.columna==fin.columna) {
				if(tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if(tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux1) != nullptr)
				return false;
		}
		break;

	case 2:	//2. Abajo derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux2(-j, j);
			posaux2 = posaux2 + inicio;

			if (posaux2.fila == fin.fila && posaux2.columna==fin.columna) {
				if(tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if(tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux2) != nullptr)
				return false;
		}
		break;

	case 3:	//3. Abajo izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux3(-j, -j);
			posaux3 = posaux3 + inicio;

			if (posaux3.fila == fin.fila && posaux3.columna == fin.columna) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux3) != nullptr)
				return false;
		}
		break;

	case 4: //4. Arriba izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux4(j, -j);
			posaux4 = posaux4 + inicio;

			if (posaux4.fila == fin.fila && posaux4.columna == fin.columna) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
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

/*void Alfil::posibleCasilla(Tablero* tablero, Pos inicio) {
	//los bucles "for" se emplean para barrer todos los posibles movimientos de las piezas
	//las condiciones dentro de los bucles verifican si los posibles movimientos de la pieza están limitados de algun modo.
	//si no lo estuvieran, se haría llamada al método con el que se dibujan los posibles movimientos de la pieza

	//Arriba derecha
	for (int j = 1; j <= 7; j++) {
		Pos posaux1(j, j);

		posaux1 = posaux1 + inicio;

		if (posaux1.columna > 7 || posaux1.fila > 7)
			break;

		if (tablero->getPieza(posaux1) == NULL)
			tablero->setPosibleCasilla(posaux1);
		else
		{
			if (tablero->getPieza(posaux1)->getColor() == color)
				break;
			else
			{
				tablero->setPosibleCasilla(posaux1);
				break;
			}
		}
	}

	//Abajo derecha
	for (int j = 1; j <= 7; j++) {
		Pos posaux2(-j, j);

		posaux2 = posaux2 + inicio;

		if (posaux2.columna > 7 || posaux2.fila < 0)
			break;

		if (tablero->getPieza(posaux2) == NULL)
			tablero->setPosibleCasilla(posaux2);
		else
		{
			if (tablero->getPieza(posaux2)->getColor() == color)
				break;
			else
			{
				tablero->setPosibleCasilla(posaux2);
				break;
			}
		}

	}
	
	//Abajo izquierda
	for (int j = 1; j <= 7; j++) {
		Pos posaux3(-j, -j);

		posaux3 = posaux3 + inicio;

		if (posaux3.columna < 0 || posaux3.fila < 0)
			break;

		if (tablero->getPieza(posaux3) == NULL)
			tablero->setPosibleCasilla(posaux3);
		else
		{
			if (tablero->getPieza(posaux3)->getColor() == color)
				break;
			else
			{
				tablero->setPosibleCasilla(posaux3);
				break;
			}
		}

	}
	
	//Arriba izquierda
	for (int j = 1; j <= 7; j++) {
		Pos posaux4(j, -j);

		posaux4 = posaux4 + inicio;

		if (posaux4.fila > 7 || posaux4.columna < 0)
			break;

		if (tablero->getPieza(posaux4) == NULL)
			tablero->setPosibleCasilla(posaux4);
		else
		{
			if (tablero->getPieza(posaux4)->getColor() == color)
				break;
			else
			{
				tablero->setPosibleCasilla(posaux4);
				break;
			}
		}
	}
}*/
