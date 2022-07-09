#pragma once
#include "Pieza.h"

class Dama : public Pieza{
private:

public:
	Dama(bool _color) : Pieza(_color, 3) {};
	bool comprueba(Tablero*, Pos, Pos);
};
