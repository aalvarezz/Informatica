#pragma once
#include "Pieza.h"

class Peon : public Pieza {
public:
	Peon(bool _color) : Pieza(_color, 1) {
		if (color) { sprite.setState(0); }
		else { sprite.setState(6); }
	};
	bool comprueba(Tablero*, Pos, Pos);
};
