#pragma once
#include "Pieza.h"

class Torre : public Pieza {
public:
	Torre(bool _color) : Pieza(_color) {};
	virtual bool comprueba(Tablero*, Pos, Pos);
};
