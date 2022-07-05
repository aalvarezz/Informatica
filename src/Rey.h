#pragma once
#include "Pos.h"
#include "Pieza.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Rey : public Pieza{
private:
	float lado;
	Sprite ReyB{ "imagenes/ReyB.png" };
	Sprite ReyN{ "imagenes/ReyN.png" };
public:
	Rey(bool _color) : Pieza(_color, 2), lado(2.5f) {};
	bool comprueba(Tablero*, Pos, Pos);
	void dibujar(Pos); //dibuja el alfil del color correspondiente en la posición que se le ordene
	void dibujarArrastrar(Pos);
	void draw(float, float);
 	void posibleCasilla(Tablero*, Pos); //en función de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada

};
