#pragma once
#include "Torre.h"

bool Torre::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	int sentido = 0;
	for (int j = 1; j <= 7; j++) {
		Pos aux1(j, 0), aux2(-j, 0), aux3(0, j), aux4(0, -j);
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

	case 1:	// 1. Hacia arriba
		for (int j = 1; j <= 7; j++) {
			Pos posaux1(j, 0);
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

	case 2:	// 2. Hacia abajo
		for (int j = 1; j <= 7; j++) {
			Pos posaux2(-j, 0);
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

	case 3:	// 3. Derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux3(0, j);
			posaux3 = posaux3 + inicio;

			if (posaux3.fila == fin.fila && posaux3.columna==fin.columna) {
				if(tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if(tablero->getPieza(fin)->getColor() != color) {
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

			if (posaux4.fila == fin.fila && posaux4.columna==fin.columna) {
				if(tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if(tablero->getPieza(fin)->getColor() != color) {
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

void Torre::draw(float x, float y) {
	//en funcion del color de la pieza la dibuja en su posicion correspondiente

	switch (color) {
	case 0:
		TorreB.setCenter(lado / 2, lado / 2);
		TorreB.setSize(lado, lado);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		TorreB.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	case 1:
		TorreN.setCenter(lado / 2, lado / 2);
		TorreN.setSize(lado, lado);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		TorreN.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	}
}

void Torre::posibleCasilla(Tablero* tablero, Pos inicio)
{
	bool color = this->getColor();
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