#pragma once
#include "Pieza.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;
class Torre : public Pieza {
private:
	float lado;
	Sprite TorreB{ "imagenes/TorreB.png" };
	Sprite TorreN{ "imagenes/TorreN.png" };	
public:
	Torre(bool _color) : Pieza(_color, 6), lado(2.5f) {};
	bool comprueba(Tablero*, Pos, Pos);
	void dibujar(Pos);
	void dibujarArrastrar(Pos);
	void draw(float, float);
};
