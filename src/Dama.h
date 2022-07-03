#pragma once
#include "Pieza.h"

class Dama : public Pieza{
public:
	Dama(bool _color) : Pieza(_color, 3) {};
	virtual bool comprueba(Tablero*, Pos, Pos) const;
};

