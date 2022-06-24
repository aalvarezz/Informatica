#pragma once
#include "Pieza.h"

class Peon : public Pieza {
public:
	Peon(bool _color) : Pieza(_color) {};
	virtual bool comprueba(Tablero*, Pos, Pos) const;
};
