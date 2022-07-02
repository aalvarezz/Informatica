#pragma once
#include "Torre.h"

bool Torre::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	bool color = this->getColor();
	int sentido;
	for (int j = 1; j <= 7; j++) {
		Pos aux1(0, j), aux2(0, -j), aux3(j, 0), aux4(-j, 0);
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
	case 1:	// 1. Hacia arriba
		for (int j = 1; j <= 7; j++) {
			Pos posaux1(0, j);
			if (((inicio + posaux1) == fin) && (tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(inicio + posaux1) != nullptr)
				return false;
		}
		break;

	case 2:	// 2. Hacia abajo
		for (int j = 1; j <= 7; j++) {
			Pos posaux2(0, -j);
			if (((inicio + posaux2) == fin) && (tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(inicio + posaux2) != nullptr)
				return false;
		}
		break;

	case 3:	// 3. Derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux3(j, 0);
			if (((inicio + posaux3) == fin) && (tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(inicio + posaux3) != nullptr)
				return false;
		}
		break;

	case 4:	//4. Izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux4(-j, 0);
			if (((inicio + posaux4) == fin) && (tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(inicio + posaux4) != nullptr)
				return false;
		}
		break;
	}
	return false;
}

void Torre::dibujar(Pos posicion)
{
	bool color = this->getColor();
	//en funcion del color de la pieza la dibuja en su posicion correspondiente

	//los bucles "for" se emplean para barrer todos los posibles movimientos de las piezas
	//las condiciones dentro de los bucles verifican si los posibles movimientos de la pieza están limitados de algun modo.
	//si no lo estuvieran, se haría llamada al método con el que se dibujan los posibles movimientos de la pieza

	switch (color) {
	case 0:
		TorreB.setCenter(lado / 2, lado / 2);
		TorreB.setSize(lado, lado);
		glTranslatef(posicion.fila, posicion.columna, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		TorreB.draw();
		glTranslatef(-posicion.fila, -posicion.columna, -0.1f);
		break;
	case 1:
		TorreN.setCenter(lado / 2, lado / 2);
		TorreN.setSize(lado, lado);
		glTranslatef(posicion.fila, posicion.columna, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		TorreN.draw();
		glTranslatef(-posicion.fila, -posicion.columna, -0.1f);
		break;
	}
}

void Torre::posibleCasilla(Tablero* tablero, Pos inicio)
{
	bool color = this->getColor();
	//Hacia arriba
	for (int j = 1; j <= 7; j++) {
		Pos posaux5(0, j);
		posaux5.columna = posaux5.columna + inicio.columna;
		posaux5.fila = posaux5.fila + inicio.fila;
		if (tablero->getPieza(posaux5)->getColor() == color)
			break;
		else if (tablero->getPieza(posaux5)->getColor() != color)
		{
			tablero->setPosibleCasilla(posaux5);
			break;
		}
		else
			tablero->setPosibleCasilla(posaux5);
	}

	//Hacia abajo
	for (int j = 1; j <= 7; j++) {
		Pos posaux6(0, -j);
		posaux6.columna = posaux6.columna + inicio.columna;
		posaux6.fila = posaux6.fila + inicio.fila;
		if (tablero->getPieza(posaux6)->getColor() == color)
			break;
		else if (tablero->getPieza(posaux6)->getColor() != color)
		{
			tablero->setPosibleCasilla(posaux6);
			break;
		}
		else
			tablero->setPosibleCasilla(posaux6);
	}

	//Derecha
	for (int j = 1; j <= 7; j++) {
		Pos posaux7(j, 0);
		posaux7.columna = posaux7.columna + inicio.columna;
		posaux7.fila = posaux7.fila + inicio.fila;
		if (tablero->getPieza(posaux7)->getColor() == color)
			break;
		else if (tablero->getPieza(posaux7)->getColor() != color)
		{
			tablero->setPosibleCasilla(posaux7);
			break;
		}
		else
			tablero->setPosibleCasilla(posaux7);
	}

	//Izquierda
	for (int j = 1; j <= 7; j++) {
		Pos posaux8(-j, 0);
		posaux8.columna = posaux8.columna + inicio.columna;
		posaux8.fila = posaux8.fila + inicio.fila;
		if (tablero->getPieza(posaux8)->getColor() == color)
			break;
		else if (tablero->getPieza(posaux8)->getColor() != color)
		{
			tablero->setPosibleCasilla(posaux8);
			break;
		}
		else
			tablero->setPosibleCasilla(posaux8);
	}
}
