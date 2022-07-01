#pragma once
#include "Pos.h"
#include "Tablero.h"

class Pieza {
//private:
protected:

	//Pos pos; //provisional
	bool color;

public:
	Pieza() {};
	Pieza(bool _color) : color(_color) {};
	void dibujar(Pos);
	//dibuja la pieza en su posici�n actual (si la pieza sabe su posici�n, la funci�n no necesita argumentos)

	virtual bool comprueba(Tablero*, Pos, Pos) const = 0;
	//calcula si cierto movimiento es v�lido para la pieza. considera las reglas normales de la pieza consultando el
	//estado actual del tablero, sin tener en cuenta excepciones (mayor prioridad)

	bool getColor() { return color; }
	
	/*provisional*/
	//void setPos(Pos); //solo necesario en el caso de hacer definitivo que las piezas almacenen su posici�n
	//Pos getPos();
};
