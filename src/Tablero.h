#pragma once
#include "Pieza.h"

class Tablero {
private:
	Pieza* piezas[8][8]; //nombre/tama�o provisionales
	Pieza* pieza_elegida; //pieza que se est� movimiendo, necesario la funcionalidad de arrastrar
public:
	Tablero();
	void imprimir(); //imprime el tablero, en principio lo imprime contando con que �l sabe todos los cambios que se han hecho, recorriendo sus piezas
	void moverPieza(Pos, Pos); //m�nimo debes decirle a donde se va a mover, probablemente tambien cual vas a mover
	void quitarPieza(Pos);

	void setPieza(Pieza*, Pos); //PROBABLEMENTE HAYA QUE HACER AJUSTES, YA QUE moverPieza() = quitarPieza() + setPieza()

	void setPosibleCasilla(); //muy provisional, pero se va a implementar en esta clase. Hay que pensar forma de borrar posibles casillas
	Pieza* getPieza(Pos);
	Pieza* getPiezaElegida();
};