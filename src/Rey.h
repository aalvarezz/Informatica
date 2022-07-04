#pragma once
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
	void dibujar(Pos); //dibuja el alfil del color correspondiente en la posici�n que se le ordene
	void dibujarArrastrar(Pos);
	void draw(float, float);
};
