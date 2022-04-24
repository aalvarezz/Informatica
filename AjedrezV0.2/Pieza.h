#pragma once
#include "V2D.h"

class Pieza
{
public:
	Pieza();
	~Pieza();

	unsigned short int tipo;
	bool color;
	float tam, lado;
	unsigned char rojo, verde, azul;
	V2D pos;

	void Mover();
	void Dibujar(V2D, int, bool);

private:

};
