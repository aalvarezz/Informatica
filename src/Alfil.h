#pragma once
#include "Pieza.h"

class Alfil : public Pieza {
public:
	Alfil(bool _color) : Pieza(_color, 4) {
		if (color) { sprite.setState(3); }
		else { sprite.setState(9); }
	};
	bool comprueba(Tablero*, Pos, Pos);
	void draw(float, float);
};
