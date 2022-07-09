#pragma once
#include "Pieza.h"

class Alfil : public Pieza {
private:

public:
	Alfil(bool _color) : Pieza(_color, 4) {};
	bool comprueba(Tablero*, Pos, Pos);
};
