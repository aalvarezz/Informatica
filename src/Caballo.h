#pragma once
#include "Pieza.h"

class Caballo : public Pieza {
private:

public:
	Caballo(bool _color) : Pieza(_color, 5) {};
	bool comprueba(Tablero*, Pos, Pos);
};
