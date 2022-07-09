#pragma once
#include "Pieza.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Torre : public Pieza {
public:
	Torre(bool _color) : Pieza(_color, 6) {
		if (color) { sprite.setState(5); }
		else { sprite.setState(11); }
	};
	bool comprueba(Tablero*, Pos, Pos);
  	void posibleCasilla(Tablero*, Pos); //en funci�n de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada
};
