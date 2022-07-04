#pragma once
#include "Tablero.h"
//#include "Pos.h"

class Pieza {
	//private:
protected:

	//Pos pos; //provisional
	bool color, origen;
	unsigned short int tipo;
	int LIM_CASILLA = 60, AJUSTE_X = 58, AJUSTE_Y = 540;

public:
	Pieza() {};
	Pieza(bool _color, unsigned short int _tipo) : color(_color), tipo(_tipo), origen(true) {};
	virtual void dibujar(Pos); //dibuja la pieza en su posici�n actual (si la pieza sabe su posici�n, la funci�n no necesita argumentos)
	virtual void dibujarArrastrar(Pos);

	virtual bool comprueba(Tablero*, Pos, Pos) { return false; }
	//calcula si cierto movimiento es v�lido para la pieza. considera las reglas normales de la pieza consultando el
	//estado actual del tablero, sin tener en cuenta excepciones (mayor prioridad)

	virtual void posibleCasilla(Tablero*, Pos) {}; //en función de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada

	unsigned short int getTipo() { return tipo; }
	bool getColor() { return color; }
	void setOrigen() { origen = false; } //probablemente mejorable
	bool checkOrigen() { return origen; }
};
