#pragma once
#include "Pieza.h"

class Alfil : public Pieza {
public:
	Alfil(bool _color) : Pieza(_color) {};
	virtual bool comprueba(Tablero*, Pos, Pos);
};