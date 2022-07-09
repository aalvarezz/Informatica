#pragma once
#include "Pieza.h"

class Rey : public Pieza{
private:

public:
	Rey(bool _color) : Pieza(_color, 2) {};
	bool comprueba(Tablero*, Pos, Pos);
};
