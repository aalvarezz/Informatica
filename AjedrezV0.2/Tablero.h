#pragma once
#include "Casilla.h"
#include "Pieza.h"

class Tablero
{
public:
	Tablero();
	~Tablero();

	Casilla tablero[8][8];
	V2D d;
	Pieza piezatest;

	void Inicializar();
	void DibujarTablero();
	void DibujarPiezas();

private:

};
