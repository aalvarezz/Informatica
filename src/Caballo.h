#pragma once
#include "Pieza.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Caballo : public Pieza {
private:
	Sprite CaballoB{ "imagenes/CaballoB.png" };
	Sprite CaballoN{ "imagenes/CaballoN.png" };
public:
	Caballo(bool _color) : Pieza(_color, 5) {};
	bool comprueba(Tablero*, Pos, Pos);
	void draw(float, float);
};
