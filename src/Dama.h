#pragma once
#include "Pieza.h"

class Dama : public Pieza{
public:
	Dama(bool _color) : Pieza(_color) {}
	bool comprueba(Tablero*, Pos, Pos) const;
};

