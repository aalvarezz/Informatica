#pragma once
#include "Pos.h"
#include "Tablero.h"

class Pieza {
private:
	//Pos pos; //provisional
	bool color;
public:
	bool posoriginal;
	Pieza();
	void dibujar(); //dibuja la pieza en su posici�n actual (si la pieza sabe su posici�n, la funci�n no necesita argumentos)
	bool comprueba(Tablero*); //calcula si cierto movimiento es v�lido para la pieza. considera las reglas normales de la pieza 
	//consultando el estado actual del tablero, sin tener en cuenta excepciones (mayor prioridad)
	void setPos(Pos); //solo necesario en el caso de hacer definitivo que las piezas almacenen su posici�n
	Pos getPos();
	bool getColor();
};