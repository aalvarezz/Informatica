#pragma once
#include "Peon.h"

bool Peon::comprueba(Tablero* tablero, Pos inicio, Pos fin) {


	Pos posaux1(1, 0), posaux2(1, -1),  posaux3(1, 1), posaux4(-1, 0), posaux5(-1, -1), posaux6(-1, 1);

	switch (color) {
	case 0:		//BLANCO
		//1.Avanza una posición en la columna (Movimiento normal)

		posaux1 = posaux1 + inicio;
		if ((posaux1.fila == fin.fila && posaux1.columna==fin.columna) && (tablero->getPieza(fin) == nullptr))
			return true;

		//2.Diagonal izq (Al comer otra ficha)
		posaux2 = posaux2 + inicio;
		if ((posaux2.fila == fin.fila && posaux2.columna==fin.columna) && (tablero->getPieza(fin)->getColor() != color))
			return true;

		//3.Diagonal dcha (Al comer otra ficha)
		posaux3 = posaux3 + inicio;
		if ((posaux3.fila == fin.fila && posaux3.columna==fin.columna) && (tablero->getPieza(fin)->getColor() != color))
			return true;

		return false;
		break;


	case 1:		//NEGRO
		//1.Avanza una posición en la columna (Movimiento normal)
		posaux4 = posaux4 + inicio;
		if ((posaux4.fila == fin.fila && posaux4.columna==fin.columna) && (tablero->getPieza(fin) == nullptr))
			return true;

		//2.Diagonal izq (Al comer otra ficha)
		posaux5 = posaux5 + inicio;
		if ((posaux5.fila == fin.fila && posaux5.columna==fin.columna) && (tablero->getPieza(fin)->getColor() != color))
			return true;

		//3.Diagonal dcha (Al comer otra ficha)
		posaux6 = posaux6 + inicio;
		if ((posaux6.fila == fin.fila && posaux6.columna==fin.columna) && (tablero->getPieza(fin)->getColor() != color))
			return true;
		break;
	}
	return false;
}


void Peon::dibujar(Pos posicion) {
	//traslado de la posición de la matriz a coordenadas de glut. x es la columna e y la fila porque las coordenadas de glut están invertidas.
	float x = posicion.columna * lado;
	float y = posicion.fila * lado;

	draw(x, y);
}

void Peon::dibujarArrastrar(Pos posicion) {
	float x = posicion.fila;
	float y = posicion.columna;

	//Trasladar 0
	x -= AJUSTE_X;
	y -= AJUSTE_Y;

	//traslado de la posición del bitmap a coordenadas de glut.
	x = lado / LIM_CASILLA * x - (lado / 2);
	y = -lado / LIM_CASILLA * y - (lado / 2);

	draw(x, y);
}

void Peon::draw(float x, float y) {
	//en funcion del color de la pieza la dibuja en su posicion correspondiente
	bool color = this->getColor();

	switch (color) {
	case 0:
		PeonB.setCenter(lado / 2, lado / 2);
		PeonB.setSize(lado, lado);

		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		PeonB.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	case 1:
		PeonN.setCenter(lado / 2, lado / 2);
		PeonN.setSize(lado, lado);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		PeonN.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	}
}

void Peon::posibleCasilla(Tablero* tablero, Pos inicio)
{
	bool color = this->getColor();

	Pos posaux1(1, 0), posaux2(1, -1), posaux3(1, 1), posaux4(-1, 0), posaux5(-1, -1), posaux6(-1, 1);

	//el switch siguiente verifica los posibles movimientos del peon en funcion del color de este.
	//todo movimiento posible que pueda realizar se mostrara en pantalla
	//no se tienen en cuenta las excepciones como el comer al paso o el avance doble al estar situado en la casilla inicial

	switch (color) {
	case 0:		//BLANCO
		//1.Avanza una posición en la columna (Movimiento normal)
		posaux1.columna = posaux1.columna + inicio.columna;
		posaux1.fila = posaux1.fila + inicio.fila;

		posaux2.columna = posaux2.columna + inicio.columna;
		posaux2.fila = posaux2.fila + inicio.fila;

		posaux3.columna = posaux3.columna + inicio.columna;
		posaux3.fila = posaux3.fila + inicio.fila;

		if (tablero->getPieza(posaux1) == nullptr)
			tablero->setPosibleCasilla(posaux1);

		//2.Diagonal izq (Al comer otra ficha)
		if (tablero->getPieza(posaux2) != nullptr)
		{
			if (tablero->getPieza(posaux2)->getColor() != color)
				tablero->setPosibleCasilla(posaux2);
		}

		//3.Diagonal dcha (Al comer otra ficha)
		if (tablero->getPieza(posaux3) != nullptr)
		{
			if (tablero->getPieza(posaux3)->getColor() != color || tablero->getPieza(posaux3) == NULL)
				tablero->setPosibleCasilla(posaux3);
		}
		break;

	case 1:		//NEGRO
		//1.Avanza una posición en la columna (Movimiento normal)
		posaux4.columna = posaux4.columna + inicio.columna;
		posaux4.fila = posaux4.fila + inicio.fila;

		posaux5.columna = posaux5.columna + inicio.columna;
		posaux5.fila = posaux5.fila + inicio.fila;

		posaux6.columna = posaux6.columna + inicio.columna;
		posaux6.fila = posaux6.fila + inicio.fila;

		if (tablero->getPieza(posaux4) == nullptr)
			tablero->setPosibleCasilla(posaux4);

		//2.Diagonal izq (Al comer otra ficha)

		if (tablero->getPieza(posaux5) != nullptr)
		{
			if (tablero->getPieza(posaux5)->getColor() != color)
				tablero->setPosibleCasilla(posaux5);
		}

		//3.Diagonal dcha (Al comer otra ficha)

		if (tablero->getPieza(posaux6) != nullptr)
		{
			if (tablero->getPieza(posaux6)->getColor() != color || tablero->getPieza(posaux6) == NULL)
				tablero->setPosibleCasilla(posaux6);
		}
		break;
	}
}