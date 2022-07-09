#pragma once
#include "Pieza.h"

class Peon : public Pieza {
private:

public:
	Peon(bool _color) : Pieza(_color, 1) {};
	bool comprueba(Tablero*, Pos, Pos);
};
