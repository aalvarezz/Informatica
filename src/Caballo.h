#pragma once
#include "Pieza.h"
#include "Pos.h"
#include <ETSIDI.h>

using ETSIDI::Sprite;

class Caballo : public Pieza {
public: //lo pongo así porque no sé si es private o no

	Sprite CaballoB{ "imagenes/CaballoB.png" };
	Sprite CaballoN{ "imagenes/CaballoN.png" };

public:
	Caballo(bool _color) : Pieza(_color) {};
	bool comprueba(Tablero*, Pos, Pos);

	void dibujar(Pos); //dibuja el caballo del color correspondiente en la posición que se le ordene

	void posibleCasilla(Tablero*, Pos); //en función de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada

};