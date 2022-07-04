#pragma once
#include "Pieza.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Dama : public Pieza{
private:
	Sprite DamaB{ "imagenes/DamaB.png" };
	Sprite DamaN{ "imagenes/DamaN.png" };
public:
	Dama(bool _color) : Pieza(_color, 3) {};
	bool comprueba(Tablero*, Pos, Pos);
	void draw(float, float);
	void posibleCasilla(Tablero*, Pos); //en funci�n de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada
};
