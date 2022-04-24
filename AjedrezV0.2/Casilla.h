#pragma once
#include "V2D.h"

class Casilla
{
public:
	Casilla();
	~Casilla();

	float lado;
	unsigned char rojo, verde, azul;
	V2D pos;
	unsigned short int estado;
	bool color;

	void Dibujar(V2D);
	void SetColor(V2D);
	void SetPosicion(float, float);

private:

};
