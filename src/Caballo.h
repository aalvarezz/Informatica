#pragma once
#include "Pieza.h"

class Caballo : public Pieza {
public:
	Caballo(bool _color) : Pieza(_color) {};
	virtual bool comprueba(Tablero*, Pos, Pos);
};
