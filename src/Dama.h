#pragma once
#include "Pieza.h"
#include "Pos.h"
#include <ETSIDI.h>

using ETSIDI::Sprite;

class Dama : public Pieza {
public: //lo pongo as� porque no s� si es private o no

	Sprite DamaB{ "imagenes/DamaB.png" };
	Sprite DamaN{ "imagenes/DamaN.png" };

public:
	Dama(bool _color) : Pieza(_color) {};
	virtual bool comprueba(Tablero*, Pos, Pos);

	void dibujar(Pos); //dibuja la dama del color correspondiente en la posici�n que se le ordene

};
