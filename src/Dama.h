#pragma once
#include "Pieza.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Dama : public Pieza{
private:

public:
	Dama(bool _color) : Pieza(_color, 3) {
		if (color) { sprite.setState(2); }
		else { sprite.setState(8); }
	};
	bool comprueba(Tablero*, Pos, Pos);
	void draw(float, float);
	//void posibleCasilla(Tablero*, Pos); //en funci�n de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada
};
