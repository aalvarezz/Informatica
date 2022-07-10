#pragma once
#include "Pos.h"
//#include "Pieza.h"

class Pieza;

class Tablero {
protected:
	float lado;
	unsigned char rojo, verde, azul;

	int LIM_CASILLA, AJUSTE_X, AJUSTE_Y;

	Pieza* piezas[8][8]; //nombre/tamaño provisionales
public:
	Tablero(): lado(2.5f) {};
	
	void dibujoDamero();
	void borrarPiezas();
	void quitarPieza(Pos);
	void quitarPiezaTablero(Pos);
	void setPieza(Pieza*, Pos); 
	void setPiezaTablero(Pieza*, Pos);
	Pieza* getPieza(Pos);

	void dibujarPosibleCasilla(Pos); //muy provisional, pero se va a implementar en esta clase. Hay que pensar forma de borrar posibles casillas

	void setValores(bool);
	void setLado(float);
	float getLado();

	int getLim() { return LIM_CASILLA; }
	int getAjusteX() { return AJUSTE_X; }
	int getAjusteY() { return AJUSTE_Y; }
};