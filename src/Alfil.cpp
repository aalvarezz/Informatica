#pragma once
#include "Alfil.h"

bool Alfil::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	bool color = this->getColor();
	int sentido;
	for (int j = 1; j <= 7; j++) {
		Pos aux1(j, j), aux2(j, -j), aux3(-j, -j), aux4(-j, j);
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
	case 1:	//1. Arriba derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux1(j, j);
			posaux1.columna = posaux1.columna + inicio.columna;
			posaux1.fila = posaux1.fila + inicio.fila;
			if (((posaux1) == fin) && (tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(posaux1) != nullptr)
				return false;
		}
		break;

	case 2:	//2. Abajo derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux2(-j, j);
			posaux2.columna = posaux2.columna + inicio.columna;
			posaux2.fila = posaux2.fila + inicio.fila;
			if (((posaux2) == fin) && (tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(posaux2) != nullptr)
				return false;
		}
		break;

	case 3:	//3. Abajo izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux3(-j, -j);
			posaux3.columna = posaux3.columna + inicio.columna;
			posaux3.fila = posaux3.fila + inicio.fila;
			if (((posaux3) == fin) && (tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(posaux3) != nullptr)
				return false;
		}
		break;

	case 4: //4. Arriba izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux4(-j, j);
			posaux4.columna = posaux4.columna + inicio.columna;
			posaux4.fila = posaux4.fila + inicio.fila;
			if (((posaux4) == fin) && (tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(posaux4) != nullptr)
				return false;
		}
	}
	return false;
}

void Alfil::dibujar(Pos posicion)
{
	bool color = this->getColor();
	//en funcion del color de la pieza la dibuja en su posicion correspondiente

	switch (color) {
	case 0:
		AlfilB.setCenter(lado / 2, lado / 2);
		AlfilB.setSize(lado, lado);
		glTranslatef(posicion.fila, posicion.columna, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		AlfilB.draw();
		glTranslatef(-posicion.fila, -posicion.columna, -0.1f);
		break;
	case 1:
		AlfilN.setCenter(lado / 2, lado / 2);
		AlfilN.setSize(lado, lado);
		glTranslatef(posicion.fila, posicion.columna, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		AlfilN.draw();
		glTranslatef(-posicion.fila, -posicion.columna, -0.1f);
		break;
	}
}

void Alfil::posibleCasilla(Tablero* tablero, Pos inicio)
{
	bool color = this->getColor();

	//los bucles "for" se emplean para barrer todos los posibles movimientos de las piezas
	//las condiciones dentro de los bucles verifican si los posibles movimientos de la pieza están limitados de algun modo.
	//si no lo estuvieran, se haría llamada al método con el que se dibujan los posibles movimientos de la pieza

	//Arriba derecha
	for (int j = 1; j <= 7; j++) {
		Pos posaux1(j, j);
		posaux1.columna = posaux1.columna + inicio.columna;
		posaux1.fila = posaux1.fila + inicio.fila;
		if (tablero->getPieza(posaux1)->getColor() == color)
			break;
		else if (tablero->getPieza(posaux1)->getColor() != color)
		{
			tablero->setPosibleCasilla(posaux1);
			break;
		}
		else
			tablero->setPosibleCasilla(posaux1);
	}

	//Abajo derecha
	for (int j = 1; j <= 7; j++) {
		Pos posaux2(-j, j);
		posaux2.columna = posaux2.columna + inicio.columna;
		posaux2.fila = posaux2.fila + inicio.fila;
		if (tablero->getPieza(posaux2)->getColor() == color)
			break;
		else if (tablero->getPieza(posaux2)->getColor() != color)
		{
			tablero->setPosibleCasilla(posaux2);
			break;
		}
		else
			tablero->setPosibleCasilla(posaux2);
	}

	//Abajo izquierda
	for (int j = 1; j <= 7; j++) {
		Pos posaux3(-j, -j);
		posaux3.columna = posaux3.columna + inicio.columna;
		posaux3.fila = posaux3.fila + inicio.fila;
		if (tablero->getPieza(posaux3)->getColor() == color)
			break;
		else if (tablero->getPieza(posaux3)->getColor() != color)
		{
			tablero->setPosibleCasilla(posaux3);
			break;
		}
		else
			tablero->setPosibleCasilla(posaux3);
	}

	//Arriba izquierda
	for (int j = 1; j <= 7; j++) {
		Pos posaux4(-j, j);
		posaux4.columna = posaux4.columna + inicio.columna;
		posaux4.fila = posaux4.fila + inicio.fila;
		if (tablero->getPieza(posaux4)->getColor() == color)
			break;
		else if (tablero->getPieza(posaux4)->getColor() != color)
		{
			tablero->setPosibleCasilla(posaux4);
			break;
		}
		else
			tablero->setPosibleCasilla(posaux4);
	}
}
