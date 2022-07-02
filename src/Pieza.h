#pragma once
#include "Tablero.h"
//#include "Pos.h"

class Pieza {
protected:

	//Pos pos; //provisional
	bool color, origen;
	unsigned short int tipo;

public:
	Pieza() {};
	Pieza(bool _color, unsigned short int _tipo) : color(_color), tipo(_tipo), origen(true) {};
	void dibujar(Pos);

	virtual bool comprueba(Tablero*, Pos, Pos) { return false; }
	//calcula si cierto movimiento es v�lido para la pieza. considera las reglas normales de la pieza consultando el
	//estado actual del tablero, sin tener en cuenta excepciones (mayor prioridad)

	unsigned short int getTipo() { return tipo; }
	bool getColor() { return color; }
	void setOrigen() { origen = false; } //probablemente mejorable
	bool checkOrigen() { return origen; }

	/*provisional*/
	//void setPos(Pos); //solo necesario en el caso de hacer definitivo que las piezas almacenen su posici�n
	//Pos getPos();
};
