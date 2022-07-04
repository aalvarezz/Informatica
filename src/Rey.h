#pragma once
#include "Pieza.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Rey : public Pieza{
private:
	Sprite ReyB{ "imagenes/ReyB.png" };
	Sprite ReyN{ "imagenes/ReyN.png" };
public:
	Rey(bool _color) : Pieza(_color, 2) {};
	bool comprueba(Tablero*, Pos, Pos);
	void draw(float, float);
 	void posibleCasilla(Tablero*, Pos); //en función de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada
};
