
#pragma once
//#include "Pieza.h"
#include "Pos.h"

class Pieza;

class Tablero {
private:
	float lado;
	unsigned char rojo, verde, azul;
	Pieza* piezas[8][8]; //nombre/tamaño provisionales
	Pieza* pieza_elegida; //pieza que se está movimiendo, necesario la funcionalidad de arrastrar
	bool posible; //hace posible visualizar las posibles casillas de movimiento
public:
	Tablero();


	/*
		PROBLEMA IMPORTANTE: inicializar() y setPieza() hacen lo mismo
	*/

	//void inicializar(Pieza*, int, int);
	void dibujoDamero();
	//void imprimir(); //imprime el tablero, en principio lo imprime contando con que él sabe todos los cambios que se han hecho, recorriendo sus piezas
	//void moverPieza(Pos, Pos); //mínimo debes decirle a donde se va a mover, probablemente tambien cual vas a mover

	void quitarPieza(Pos);
	void setPieza(Pieza*, Pos); //PROBABLEMENTE HAYA QUE HACER AJUSTES, YA QUE moverPieza() = quitarPieza() + setPieza()

	Pieza* getPieza(Pos);

	void setPosibleCasilla(Pos); //muy provisional, pero se va a implementar en esta clase. Hay que pensar forma de borrar posibles casillas

	void setLado(float);
	float getLado();
};