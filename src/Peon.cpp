#pragma once
#include "Peon.h"

bool Peon::comprueba(Tablero* tablero, Pos inicio, Pos fin) const {

	bool color = this->getColor();
	Pos posaux1(0, 1), posaux2(-1, 1), posaux3(1, 1), posaux4(0, -1), posaux5(-1, -1), posaux6(1, -1);

	switch (color) {
	case 0:		//BLANCO
		//1.Avanza una posición en la columna (Movimiento normal)
		posaux1.columna = posaux1.columna + inicio.columna;
		posaux1.fila = posaux1.fila + inicio.fila;

		posaux2.columna = posaux2.columna + inicio.columna;
		posaux2.fila = posaux2.fila + inicio.fila;

		posaux3.columna = posaux3.columna + inicio.columna;
		posaux3.fila = posaux3.fila + inicio.fila;

		if (((posaux1) == fin) && (tablero->getPieza(fin) == nullptr))
			return true;

		//2.Diagonal izq (Al comer otra ficha)

		if (((posaux2) == fin) && (tablero->getPieza(fin)->getColor() != color))
			return true;

		//3.Diagonal dcha (Al comer otra ficha)

		if (((posaux3) == fin) && (tablero->getPieza(fin)->getColor() != color))
			return true;
		break;


	case 1:		//NEGRO
		//1.Avanza una posición en la columna (Movimiento normal)
		posaux4.columna = posaux4.columna + inicio.columna;
		posaux4.fila = posaux4.fila + inicio.fila;

		posaux5.columna = posaux5.columna + inicio.columna;
		posaux5.fila = posaux5.fila + inicio.fila;

		posaux6.columna = posaux6.columna + inicio.columna;
		posaux6.fila = posaux6.fila + inicio.fila;

		if (((posaux4) == fin) && (tablero->getPieza(fin) == nullptr))
			return true;

		//2.Diagonal izq (Al comer otra ficha)

		if (((posaux5) == fin) && (tablero->getPieza(fin)->getColor() != color))
			return true;

		//3.Diagonal dcha (Al comer otra ficha)

		if (((posaux6) == fin) && (tablero->getPieza(fin)->getColor() != color))
			return true;
		break;
	}
	return false;
}

void Peon::dibujar(Pos posicion)
{
	bool color = this->getColor();
	//en funcion del color de la pieza la dibuja en su posicion correspondiente
	switch (color) {
	case 0:
		PeonB.setCenter(lado / 2, lado / 2);
		PeonB.setSize(lado, lado);
		glTranslatef(posicion.fila, posicion.columna, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		PeonB.draw();
		glTranslatef(-posicion.fila, -posicion.columna, -0.1f);
		break;
	case 1:
		PeonN.setCenter(lado / 2, lado / 2);
		PeonN.setSize(lado, lado);
		glTranslatef(posicion.fila, posicion.columna, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		PeonN.draw();
		glTranslatef(-posicion.fila, -posicion.columna, -0.1f);
		break;
	}
}
