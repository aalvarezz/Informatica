#pragma once
#include "Pieza.h"

class Tablero {
private:
	float lado;
	Pieza* piezas[8][8]; //nombre/tamaño provisionales
	Pieza* pieza_elegida; //pieza que se está movimiendo, necesario la funcionalidad de arrastrar
public:
	Tablero();

	void inicializar(Pieza*, int, int);
	void dibujoDamero();
	void imprimir(); //imprime el tablero, en principio lo imprime contando con que él sabe todos los cambios que se han hecho, recorriendo sus piezas
	//void moverPieza(Pos, Pos); //mínimo debes decirle a donde se va a mover, probablemente tambien cual vas a mover

	void quitarPieza(Pos); 
	void setPieza(Pieza*, Pos); //PROBABLEMENTE HAYA QUE HACER AJUSTES, YA QUE moverPieza() = quitarPieza() + setPieza()

	//void setPosibleCasilla(); //muy provisional, pero se va a implementar en esta clase. Hay que pensar forma de borrar posibles casillas
	Pieza* getPieza(Pos);
	//Pieza* getPiezaElegida();

	void setLado(float);
	float getLado();
};
