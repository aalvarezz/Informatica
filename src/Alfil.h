#pragma once
#include "Pieza.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Alfil : public Pieza {
private:
	Sprite AlfilB{ "imagenes/AlfilB.png" };
	Sprite AlfilN{ "imagenes/AlfilN.png" };
public:
	Alfil(bool _color) : Pieza(_color, 4) {};
	bool comprueba(Tablero*, Pos, Pos);
	void draw(float, float);
  	void posibleCasilla(Tablero*, Pos); //en función de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada
};
