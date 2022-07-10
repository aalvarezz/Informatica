#pragma once
#include "Pieza.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Peon : public Pieza {
private:
	Sprite PeonB{ "imagenes/PeonB.png" };
	Sprite PeonN{ "imagenes/PeonN.png" };
public:
	Peon(bool _color) : Pieza(_color, 1) {};
	bool comprueba(Tablero*, Pos, Pos);
	void draw(float, float);
};
