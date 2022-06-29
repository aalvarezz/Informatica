#pragma once
#include "Dama.h"

bool Dama::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	bool color = this->getColor();
	int sentido;
	for (int j = 1; j <= 7; j++) {
		Pos aux1(0, j), aux2(0, -j), aux3(j, 0), aux4(-j, 0), aux5(j, j), aux6(j, -j), aux7(-j, -j), aux8(-j, j);
		if (aux1 == fin)
			sentido = 1;
		if (aux2 == fin)
			sentido = 2;
		if (aux3 == fin)
			sentido = 3;
		if (aux4 == fin)
			sentido = 4;
		if (aux5 == fin)
			sentido = 5;
		if (aux6 == fin)
			sentido = 6;
		if (aux7 == fin)
			sentido = 7;
		if (aux8 == fin)
			sentido = 8;
	}

	switch (sentido) {
	case 1:	// 1. Hacia arriba
		for (int j = 1; j <= 7; j++) {
			Pos posaux1(0, j);
			posaux1.columna = posaux1.columna + inicio.columna;
			posaux1.fila = posaux1.fila + inicio.fila;
			if (((posaux1) == fin) && (tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(posaux1) != nullptr)
				return false;
		}
		break;

	case 2:	// 2. Hacia abajo
		for (int j = 1; j <= 7; j++) {
			Pos posaux2(0, -j);
			posaux2.columna = posaux2.columna + inicio.columna;
			posaux2.fila = posaux2.fila + inicio.fila;
			if (((posaux2) == fin) && (tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(posaux2) != nullptr)
				return false;
		}
		break;

	case 3:	// 3. Derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux3(j, 0);
			posaux3.columna = posaux3.columna + inicio.columna;
			posaux3.fila = posaux3.fila + inicio.fila;
			if (((posaux3) == fin) && (tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(posaux3) != nullptr)
				return false;
		}
		break;

	case 4:	//4. Izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux4(-j, 0);
			posaux4.columna = posaux4.columna + inicio.columna;
			posaux4.fila = posaux4.fila + inicio.fila;
			if (((posaux4) == fin) && (tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(posaux4) != nullptr)
				return false;
		}
		break;

	case 5:	//5. Arriba derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux5(j, j);
			posaux5.columna = posaux5.columna + inicio.columna;
			posaux5.fila = posaux5.fila + inicio.fila;
			if (((posaux5) == fin) && (tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(posaux5) != nullptr)
				return false;
		}
		break;

	case 6:	//6. Abajo derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux6(-j, j);
			posaux6.columna = posaux6.columna + inicio.columna;
			posaux6.fila = posaux6.fila + inicio.fila;
			if (((posaux6) == fin) && (tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(posaux6) != nullptr)
				return false;
		}
		break;

	case 7:	//7. Abajo izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux7(-j, -j);
			posaux7.columna = posaux7.columna + inicio.columna;
			posaux7.fila = posaux7.fila + inicio.fila;
			if (((posaux7) == fin) && (tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(posaux7) != nullptr)
				return false;
		}
		break;

	case 8://5. Arriba izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux8(-j, j);
			posaux8.columna = posaux8.columna + inicio.columna;
			posaux8.fila = posaux8.fila + inicio.fila;
			if (((posaux8) == fin) && (tablero->getPieza(fin) == nullptr) || (tablero->getPieza(fin)->getColor() != color))
				return true;
			else if (tablero->getPieza(posaux8) != nullptr)
				return false;
		}
		break;
	}
	return false;
}

void Dama::dibujar(Pos posicion)
{
	bool color = this->getColor();
	//en funcion del color de la pieza la dibuja en su posicion correspondiente

	switch (color) {
	case 0:
		DamaB.setCenter(lado / 2, lado / 2);
		DamaB.setSize(lado, lado);
		glTranslatef(posicion.fila, posicion.columna, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		DamaB.draw();
		glTranslatef(-posicion.fila, -posicion.columna, -0.1f);
		break;
	case 1:
		DamaN.setCenter(lado / 2, lado / 2);
		DamaN.setSize(lado, lado);
		glTranslatef(posicion.fila, posicion.columna, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		DamaN.draw();
		glTranslatef(-posicion.fila, -posicion.columna, -0.1f);
		break;
	}
}
