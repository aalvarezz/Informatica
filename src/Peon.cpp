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

/*void Peon::posibleCasilla(Tablero* tablero, Pos inicio)
{
	bool color = this->getColor();

	Pos posiciones_blancas;
	Pos posiciones_negras;

	int j = -1;

	switch (color)
	{
	case 0:
		for (int k = -1; k <= 1; k++)
		{
			for (int f = 1; f <= 2; f++)
			{
				posiciones_blancas.fila = inicio.fila + f;
				posiciones_blancas.columna = inicio.columna + k;
					if (comprueba(tablero, inicio, posiciones_blancas)) //cambiar comprueba por movimientovalido. para ello tiene que barrer todas las casillas
						tablero->setPosibleCasilla(posiciones_blancas); //del tablero, o al menos a las que pueda mover el peon
			}
		}
		break;
	case 1:
		for (int k = -1; k <= 1; k++) {
			posiciones_negras.fila = inicio.fila + j;
			posiciones_negras.columna = inicio.columna + k;
			if (comprueba(tablero, inicio, posiciones_negras))
				tablero->setPosibleCasilla(posiciones_negras);
		}
		break;
	}

}*/
