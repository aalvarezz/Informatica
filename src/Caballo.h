#pragma once
#include "Pieza.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Caballo : public Pieza {
private:
	float lado;
	Sprite CaballoB{ "imagenes/CaballoB.png" };
	Sprite CaballoN{ "imagenes/CaballoN.png" };
public:
	Caballo(bool _color) : Pieza(_color, 5), lado(2.5f) {};
	bool comprueba(Tablero*, Pos, Pos);
	void dibujar(Pos);
	void dibujarArrastrar(Pos);
	void draw(float, float);
  	void posibleCasilla(Tablero*, Pos); //en funci�n de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada
};
