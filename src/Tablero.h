#pragma once
#include "Pieza.h"

class Tablero {
private:
	Pieza* piezas[8][4]; //nombre/tama�o provisionales
public:
	Tablero();
	void imprimir(); //imprime el tablero, en principio lo imprime contando con que �l sabe todos los cambios que se han hecho, recorriendo sus piezas
	void moverPieza(Pos); //m�nimo debes decirle a donde se va a mover, probablemente tambien cual vas a mover
	void setPosibleCasilla(); //muy provisional, pero se va a implementar en esta clase. Hay que pensar forma de borrar posibles casillas
};
