#pragma once
#include "Pieza.h"

class Rey : public Pieza {
public:
	Rey(bool _color) : Pieza(_color, 2) {
		if (color) { sprite.setState(1); }
		else { sprite.setState(7); }
	};
	bool comprueba(Tablero*, Pos, Pos);
};
