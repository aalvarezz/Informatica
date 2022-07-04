#pragma once
#include "Pieza.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Peon : public Pieza {
private:
	float lado;
	Sprite PeonB{ "imagenes/PeonB.png" };
	Sprite PeonN{ "imagenes/PeonN.png" };
public:
	Peon(bool _color) : Pieza(_color, 1), lado(2.5f) {};
	bool comprueba(Tablero*, Pos, Pos);
	void dibujar(Pos); //dibuja el alfil del color correspondiente en la posición que se le ordene
	void dibujarArrastrar(Pos);
	void draw(float, float);
};
