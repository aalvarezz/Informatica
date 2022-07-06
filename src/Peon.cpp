#pragma once
#include "Peon.h"

bool Peon::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	Pos posaux1(1, 0), posaux2(1, -1),  posaux3(1, 1), posaux4(-1, 0), posaux5(-1, -1), posaux6(-1, 1);

	switch (color) {
	case 0:		//BLANCO
		//1.Avanza una posición en la columna (Movimiento normal)
		if (tablero->getPieza(fin) == nullptr)
		{
			posaux1 = posaux1 + inicio;
			if (posaux1.fila == fin.fila && posaux1.columna == fin.columna)
				return true;
			else
				return false;
		}

		if (tablero->getPieza(fin) != nullptr)
		{
			//2.Diagonal izq (Al comer otra ficha)
			posaux2 = posaux2 + inicio;
			if ((posaux2.fila == fin.fila && posaux2.columna == fin.columna) && (tablero->getPieza(fin)->getColor() != color))
				return true;

			//3.Diagonal dcha (Al comer otra ficha)
			posaux3 = posaux3 + inicio;
			if ((posaux3.fila == fin.fila && posaux3.columna == fin.columna) && (tablero->getPieza(fin)->getColor() != color))
				return true;
		}
		return false;
		break;

	case 1:		//NEGRO
		//1.Avanza una posición en la columna (Movimiento normal)
		if (tablero->getPieza(fin) == nullptr)
		{
			posaux4 = posaux4 + inicio;
			if (posaux4.fila == fin.fila && posaux4.columna == fin.columna)
				return true;
			else
				return false;
		}

		if (tablero->getPieza(fin) != nullptr)
		{
			//2.Diagonal izq (Al comer otra ficha)
			posaux5 = posaux5 + inicio;
			if ((posaux5.fila == fin.fila && posaux5.columna == fin.columna) && (tablero->getPieza(fin)->getColor() != color))
				return true;

			//3.Diagonal dcha (Al comer otra ficha)
			posaux6 = posaux6 + inicio;
			if ((posaux6.fila == fin.fila && posaux6.columna == fin.columna) && (tablero->getPieza(fin)->getColor() != color))
				return true;
		}
		return false;
		break;
	}
	return false;
}

void Peon::draw(float x, float y) {
	//en funcion del color de la pieza la dibuja en su posicion correspondiente

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
	Pos dobleb(2, 0), doblen(-2, 0);

	//el switch siguiente verifica los posibles movimientos del peon en funcion del color de este.
	//todo movimiento posible que pueda realizar se mostrara en pantalla
	//no se tienen en cuenta las excepciones como el comer al paso o el avance doble al estar situado en la casilla inicial

	switch (color) {
	case 0:		//BLANCO
		//1.Avanza una posición en la columna (Movimiento normal)
		posaux1 = posaux1 + inicio;
		posaux2 = posaux2 + inicio;
		posaux3 = posaux3 + inicio;
		dobleb = dobleb + inicio;

		if (tablero->getPieza(posaux1) == nullptr)
			tablero->setPosibleCasilla(posaux1);

		if (tablero->getPieza(dobleb) == nullptr && origen == 1) //condicion para que el peon avance dos casillas al no haberse movido antes
			tablero->setPosibleCasilla(dobleb);

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
		posaux4 = posaux4 + inicio;
		posaux5 = posaux5 + inicio;
		posaux6 = posaux6 + inicio;
		doblen = doblen + inicio;

		if (tablero->getPieza(posaux4) == nullptr)
			tablero->setPosibleCasilla(posaux4);

		if (tablero->getPieza(doblen) == nullptr && origen == 1) //condicion para que el peon avance dos casillas al no haberse movido antes
			tablero->setPosibleCasilla(doblen);

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