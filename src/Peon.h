#pragma once
#include "Pieza.h"

class Peon : public Pieza {
public:
	Peon(bool _color) : Pieza(_color, 1) {};
	virtual bool comprueba(Tablero*, Pos, Pos) const;
};
