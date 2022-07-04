#pragma once
#include "Pieza.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Alfil : public Pieza {
private:
	float lado;
	Sprite AlfilB{ "imagenes/AlfilB.png" };
	Sprite AlfilN{ "imagenes/AlfilN.png" };
public:
	Alfil(bool _color) : Pieza(_color, 4), lado(2.5f) {};
	bool comprueba(Tablero*, Pos, Pos);
	void dibujar(Pos); //dibuja el alfil del color correspondiente en la posición que se le ordene
	void dibujarArrastrar(Pos);
	void draw(float, float);
};