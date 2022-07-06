#pragma once
#include "Pieza.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Caballo : public Pieza {
private:
	Sprite CaballoB{ "imagenes/CaballoB.png" };
	Sprite CaballoN{ "imagenes/CaballoN.png" };
public:
	Caballo(bool _color) : Pieza(_color, 5) {
		if (color) { sprite.setState(4); }
		else { sprite.setState(10); }
	};
	bool comprueba(Tablero*, Pos, Pos);
	void draw(float, float);
  	void posibleCasilla(Tablero*, Pos); //en funci�n de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada
};
