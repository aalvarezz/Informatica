#pragma once

#include "Pieza.h"
#include "Pos.h"
#include <ETSIDI.h>
#include "Tablero.h"

using ETSIDI::Sprite;

class Alfil : public Pieza {
public: //lo pongo as� porque no s� si es private o no

	Sprite AlfilB{ "imagenes/AlfilB.png" };
	Sprite AlfilN{ "imagenes/AlfilN.png" };
	
public:
	Alfil(bool _color) : Pieza(_color) {};
	bool comprueba(Tablero*, Pos, Pos);

	void dibujar(Pos); //dibuja el alfil del color correspondiente en la posici�n que se le ordene

	void posibleCasilla(Tablero*, Pos); //en funci�n de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada

};
