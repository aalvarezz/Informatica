#pragma once
#include "Pos.h"
#include "Tablero.h"

class Pieza {
protected:
	bool color;

public:
	Pieza(bool _color) : color(_color) {};

	//dibuja la pieza en su posicion actual (si la pieza sabe su posicion, la funcion no necesita argumentos)
	void dibujar(Pos);

	//calcula si cierto movimiento es v�lido para la pieza. considera las reglas normales de la pieza consultando
	//el estado actual del tablero, sin tener en cuenta excepciones (mayor prioridad)
	virtual bool comprueba(Tablero*, Pos, Pos) {};

	bool getColor() { return color; }
};
