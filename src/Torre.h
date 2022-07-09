#pragma once
#include "Pieza.h"

class Torre : public Pieza {
public:
	Torre(bool _color) : Pieza(_color, 6) {
		if (color) { sprite.setState(5); }
		else { sprite.setState(11); }
	};
	bool comprueba(Tablero*, Pos, Pos);
};