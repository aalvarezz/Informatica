#pragma once
#include "Dama.h"

bool Dama::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	int sentido = 0;
	for (int j = 1; j <= 7; j++) {
		Pos aux1(j, 0), aux2(-j, 0), aux3(0, j), aux4(0, -j), aux5(j, j), aux6(-j, j), aux7(-j, -j), aux8(j, -j);
		aux1 = aux1 + inicio;
		aux2 = aux2 + inicio;
		aux3 = aux3 + inicio;
		aux4 = aux4 + inicio;
		aux5 = aux5 + inicio;
		aux6 = aux6 + inicio;
		aux7 = aux7 + inicio;
		aux8 = aux8 + inicio;

		if (aux1.fila == fin.fila && aux1.columna == fin.columna)
			sentido = 1;
		if (aux2.fila == fin.fila && aux2.columna == fin.columna)
			sentido = 2;
		if (aux3.fila == fin.fila && aux3.columna == fin.columna)
			sentido = 3;
		if (aux4.fila == fin.fila && aux4.columna == fin.columna)
			sentido = 4;
		if (aux5.fila == fin.fila && aux5.columna == fin.columna)
			sentido = 5;
		if (aux6.fila == fin.fila && aux6.columna == fin.columna)
			sentido = 6;
		if (aux7.fila == fin.fila && aux7.columna == fin.columna)
			sentido = 7;
		if (aux8.fila == fin.fila && aux8.columna == fin.columna)
			sentido = 8;
	}

	switch (sentido) {
	case 0:
		return false;
		break;

	case 1:	// 1. Hacia arriba
		for (int j = 1; j <= 7; j++) {
			Pos posaux1(j, 0);
			posaux1 = posaux1 + inicio;

			if (posaux1.fila == fin.fila && posaux1.columna == fin.columna) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux1) != nullptr)
				return false;
		}
		break;

	case 2:	// 2. Hacia abajo
		for (int j = 1; j <= 7; j++) {
			Pos posaux2(-j, 0);
			posaux2 = posaux2 + inicio;

			if (posaux2.fila == fin.fila && posaux2.columna == fin.columna) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux2) != nullptr)
				return false;
		}
		break;

	case 3:	// 3. Derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux3(0, j);
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

	case 4:	//4. Izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux4(0, -j);
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

	case 5:	//5. Arriba derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux5(j, j);
			posaux5 = posaux5 + inicio;

			if (posaux5.fila == fin.fila && posaux5.columna == fin.columna) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux5) != nullptr)
				return false;
		}
		break;

	case 6:	//6. Abajo derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux6(-j, j);
			posaux6 = posaux6 + inicio;

			if (posaux6.fila == fin.fila && posaux6.columna == fin.columna) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux6) != nullptr)
				return false;
		}
		break;

	case 7:	//7. Abajo izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux7(-j, -j);
			posaux7 = posaux7 + inicio;

			if (posaux7.fila == fin.fila && posaux7.columna == fin.columna) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux7) != nullptr)
				return false;
		}
		break;

	case 8: //8. Arriba izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux8(j, -j);
			posaux8 = posaux8 + inicio;

			if (posaux8.fila == fin.fila && posaux8.columna == fin.columna) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux8) != nullptr)
				return false;
		}
		break;

	}
	return false;
}

void Dama::posibleCasilla(Tablero* tablero, Pos inicio) {
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

	//Derecha
	for (int j = 1; j <= 7; j++) {
		Pos posaux5(0, j);
		
		posaux5 = posaux5 + inicio;

		if (posaux5.columna > 7)
			break;
		if (tablero->getPieza(posaux5) == NULL)
			tablero->setPosibleCasilla(posaux5);
		else
		{
			if (tablero->getPieza(posaux5)->getColor() == color)
				break;
			else
			{
				tablero->setPosibleCasilla(posaux5);
				break;
			}
		}
	}

	//Izquierda
	for (int j = 1; j <= 7; j++) {
		Pos posaux6(0, -j);
		
		posaux6 = posaux6 + inicio;

		if (posaux6.columna < 0)
			break;
		if (tablero->getPieza(posaux6) == NULL)
			tablero->setPosibleCasilla(posaux6);
		else
		{
			if (tablero->getPieza(posaux6)->getColor() == color)
				break;
			else
			{
				tablero->setPosibleCasilla(posaux6);
				break;
			}
		}
	}

	//Arriba
	for (int j = 1; j <= 7; j++) {
		Pos posaux7(j, 0);
		
		posaux7 = posaux7 + inicio;

		if (posaux7.fila > 7)
			break;
		if (tablero->getPieza(posaux7) == NULL)
			tablero->setPosibleCasilla(posaux7);
		else
		{
			if (tablero->getPieza(posaux7)->getColor() == color)
				break;
			else
			{
				tablero->setPosibleCasilla(posaux7);
				break;
			}
		}
	}

	//Abajo
	for (int j = 1; j <= 7; j++) {
		Pos posaux8(-j, 0);
		
		posaux8 = posaux8 + inicio;

		if (posaux8.fila < 0)
			break;
		if (tablero->getPieza(posaux8) == NULL)
			tablero->setPosibleCasilla(posaux8);
		else
		{
			if (tablero->getPieza(posaux8)->getColor() == color)
				break;
			else
			{
				tablero->setPosibleCasilla(posaux8);
				break;
			}
		}
	}
}