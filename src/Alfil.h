#pragma once

#include "Pieza.h"
#include "Pos.h"
#include <ETSIDI.h>
#include "Tablero.h"

using ETSIDI::Sprite;

class Alfil : public Pieza {
public: //lo pongo así porque no sé si es private o no

	Sprite AlfilB{ "imagenes/AlfilB.png" };
	Sprite AlfilN{ "imagenes/AlfilN.png" };
	
public:
	Alfil(bool _color) : Pieza(_color) {};
	bool comprueba(Tablero*, Pos, Pos);

	void dibujar(Pos); //dibuja el alfil del color correspondiente en la posición que se le ordene

	void posibleCasilla(Tablero*, Pos); //en función de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada

};
