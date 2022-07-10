
#pragma once
#include "Pos.h"
//#include "Pieza.h"

class Pieza;

class Tablero {
private:
	//REVISAR
	float lado;
	unsigned char rojo, verde, azul;
	int LIM_CASILLA, AJUSTE_X, AJUSTE_Y;
	Pieza* piezas[8][8]; //nombre/tamaño provisionales

	//REVISAR
	bool posible; //hace posible visualizar las posibles casillas de movimiento
public:
	Tablero();

	void dibujoDamero();

	void quitarPieza(Pos);
	void setPieza(Pieza*, Pos);
	Pieza* getPieza(Pos);

	void dibujarPosibleCasilla(Pos); //muy provisional, pero se va a implementar en esta clase. Hay que pensar forma de borrar posibles casillas
	void setValores(bool);
	void setLado(float);
	float getLado();
	int getLim() { return LIM_CASILLA; }
	int getAjusteX() { return AJUSTE_X; }
	int getAjusteY() { return AJUSTE_Y; }
};