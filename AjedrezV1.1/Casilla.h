#pragma once
#include "V2D.h"
#include "Pieza.h"

class Casilla {
public:
	Casilla();
	~Casilla();

	float lado;
	unsigned char rojo, verde, azul;
	bool estado;
	V2D pos;
	Pieza pieza;

	void Dibujar(int, int);
	void SetColor(int, int);
	void SetPosicion(int, int);
	Pieza GetPieza();
	void SetPieza(Pieza const &);
	bool GetEstado();
	void SetEstado(bool);
	void QuitarPieza();
	void SetPosibilidad(int, int);


private:

};
