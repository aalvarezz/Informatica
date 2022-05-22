#pragma once
#include "Pos.h"
#include "Pieza.h"

class Casilla {
private:

	float lado;
	int fila, columna;
	unsigned char rojo, verde, azul;
	bool estado;
	bool posible;
	Pos pos; //Posicion bitmap
	Pieza pieza;

public:

	Casilla(int, int);
	Casilla();
	~Casilla();

	void Dibujar(int, int);
	void SetColor(int, int);
	void SetPosicion(int, int);
	Pieza GetPieza();
	void SetPieza(Pieza p);
	bool GetEstado();
	void SetEstado(bool);
	void QuitarPieza();
	//void SetPosibilidad(int, int);
	void SetPosibilidad(Casilla c);
	bool operator == (Casilla);
	Pos getPos();
};