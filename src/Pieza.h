#pragma once
#include "Pos.h"
#include "Tablero.h"

class Pieza {
	//private:
protected:
	//Pos pos; //provisional
	bool color;
	float lado;

public:
	Pieza() {};
	Pieza(bool _color) : color(_color) {};
	void dibujar(Pos);
	//dibuja la pieza en su posici�n actual (si la pieza sabe su posici�n, la funci�n no necesita argumentos)

	//virtual bool comprueba(Tablero*, Pos, Pos) = 0; AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA DESCOMENTAR

	bool comprueba(Tablero*, Pos, Pos);

	//calcula si cierto movimiento es v�lido para la pieza. considera las reglas normales de la pieza consultando el
	//estado actual del tablero, sin tener en cuenta excepciones (mayor prioridad)

	bool getColor() { return color; }

	/*provisional*/
	//void setPos(Pos); //solo necesario en el caso de hacer definitivo que las piezas almacenen su posici�n
	//Pos getPos();

	void posibleCasilla(Tablero*, Pos); //en función de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada
};