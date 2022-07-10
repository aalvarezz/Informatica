#pragma once
#include "Pos.h"

class Pieza; //forward declaration para evitar recursividad

class Tablero {
private:
	float lado;
	int LIM_TABLERO, LIM_CASILLA, AJUSTE_X, AJUSTE_Y;
	Pieza* piezas[8][8];
public:
	//Constructores de tablero
	Tablero();
	Tablero(int, int, int, int);

	//Funciones de dibujo del tablero
	void dibujarDamero();
	void dibujarPosibleCasilla(Pos);

	//Getters y setters referidos a la gestión de piezas en el tablero
	void setPieza(Pieza*, Pos);
	void quitarPieza(Pos);
	Pieza* getPieza(Pos);

	//Getters y setters de los parámetros referidos al tamaño de la ventana
	int getLT() { return LIM_TABLERO; }
	int getLC() { return LIM_CASILLA; }
	int getAjusteX() { return AJUSTE_X; }
	int getAjusteY() { return AJUSTE_Y; }
	float getLado() { return lado; }
};