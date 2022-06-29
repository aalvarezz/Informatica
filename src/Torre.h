#pragma once
#include "Pieza.h"
#include "Pos.h"
#include <ETSIDI.h>

using ETSIDI::Sprite;

class Torre : public Pieza {
public: //lo pongo así porque no sé si es private o no

	Sprite TorreB{ "imagenes/TorreB.png" };
	Sprite TorreN{ "imagenes/TorreN.png" };

public:
	Torre(bool _color) : Pieza(_color) {};
	virtual bool comprueba(Tablero*, Pos, Pos);

	void dibujar(Pos); //dibuja la torre del color correspondiente en la posición que se le ordene

};