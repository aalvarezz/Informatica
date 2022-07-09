#pragma once
#include "Pieza.h"

class Torre : public Pieza {
private:

public:
	Torre(bool _color) : Pieza(_color, 6) {};
	bool comprueba(Tablero*, Pos, Pos);
};
