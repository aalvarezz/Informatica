#pragma once
#include "Pieza.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Rey : public Pieza{
private:

public:
	Rey(bool _color) : Pieza(_color, 2) {
		if (color) { sprite.setState(1); }
		else { sprite.setState(7); }
	};
	bool comprueba(Tablero*, Pos, Pos);
 	//void posibleCasilla(Tablero*, Pos); //en función de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada

};
