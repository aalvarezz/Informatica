#pragma once
#include "Pieza.h"

class Rey : public Pieza{
public:
	Rey(bool _color) : Pieza(_color) {}
	bool comprueba(Tablero*, Pos, Pos) const;
};

