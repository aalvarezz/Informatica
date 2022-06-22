#pragma once
#include "Pos.h"
#include "Tablero.h"

class Pieza {
private:
	//Pos pos; //provisional
	bool color;

public:
	Pieza(bool _color) : color(_color) {};
	void dibujar(Pos);
	//dibuja la pieza en su posición actual (si la pieza sabe su posición, la función no necesita argumentos)

	virtual bool comprueba(Tablero*, Pos, Pos) = 0;
	//calcula si cierto movimiento es válido para la pieza. considera las reglas normales de la pieza consultando el
	//estado actual del tablero, sin tener en cuenta excepciones (mayor prioridad)

	bool getColor() { return color; }
	

	/*provisional*/
	//void setPos(Pos); //solo necesario en el caso de hacer definitivo que las piezas almacenen su posición
	//Pos getPos();

};