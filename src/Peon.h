#pragma once
#include "Pieza.h"
#include "Pos.h"
#include <ETSIDI.h>

using ETSIDI::Sprite;

class Peon : public Pieza {
public: //lo pongo as� porque no s� si es private o no

	Sprite PeonB{ "imagenes/PeonB.png" };
	Sprite PeonN{ "imagenes/PeonN.png" };
public:
	Peon(bool _color) : Pieza(_color) {};
	virtual bool comprueba(Tablero*, Pos, Pos) const;
	//dibujar a si mismo, tal vez asignar la posicion

	void dibujar(Pos); //dibuja el peon del color correspondiente en la posici�n que se le ordene
};