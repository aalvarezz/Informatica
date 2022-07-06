#pragma once
#include "Pieza.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Alfil : public Pieza {
public:
	Alfil(bool _color) : Pieza(_color, 4) {
		if (color) { sprite.setState(3); }
		else { sprite.setState(9); }
	};
	bool comprueba(Tablero*, Pos, Pos);
	void draw(float, float);
  	void posibleCasilla(Tablero*, Pos); //en función de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada
};
