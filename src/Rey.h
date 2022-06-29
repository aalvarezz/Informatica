#pragma once
#include "Pos.h"
#include "Pieza.h"
#include <ETSIDI.h>

using ETSIDI::Sprite;

class Rey : public Pieza {
public: //lo pongo as� porque no s� si es private o no
	Sprite ReyB{ "imagenes/ReyB.png" };
	Sprite ReyN{ "imagenes/ReyN.png" };
	
public:
	Rey(bool _color) : Pieza(_color) {};
	virtual bool comprueba(Tablero*, Pos, Pos);

	void dibujar(Pos); //dibuja el rey del color correspondiente en la posici�n que se le ordene

};
