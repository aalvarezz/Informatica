#pragma once
#include "Pieza.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Peon : public Pieza {
private:

public:
	Peon(bool _color) : Pieza(_color, 1) {
		if (color) { sprite.setState(0); }
		else { sprite.setState(6); }
	};
	bool comprueba(Tablero*, Pos, Pos);
  	//void posibleCasilla(Tablero*, Pos); //en función de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada
};
