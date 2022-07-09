#pragma once
#include "Tablero.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Pieza {

protected:
	//Pos pos; //provisional
	bool color, origen = true;
	unsigned short int tipo;
	int LIM_CASILLA = 60, AJUSTE_X = 58, AJUSTE_Y = 540;
	SpriteSequence sprite{ "imagenes/Piezas.png", 6, 2 };

	float lado = 2.5f;
public:
	//Pieza() {};
	Pieza(bool _color, unsigned short int _tipo) : color(_color), tipo(_tipo) {};
	void dibujar(Pos); //dibuja la pieza en su casilla actual calculando el centro de esta y haciendo las conversiones de coordenadas pertinentes.
	void dibujarArrastrar(Pos); //dibuja la pieza en unas coordenadas del bitmap dadas para que se aprecie el movimiento de arrastre. Se deben realizar conversiones de bitmap a glut.
	void draw(float, float);

	//calcula si cierto movimiento es v�lido para la pieza. considera las reglas normales de la pieza consultando el
	//estado actual del tablero, sin tener en cuenta excepciones (mayor prioridad)
	virtual bool comprueba(Tablero*, Pos, Pos) { return false; }

	virtual void posibleCasilla(Tablero*, Pos) {}; //en función de las reglas de movimiento de cada pieza dibuja sus posibles movimientos al ser seleccionada

	unsigned short int getTipo() { return tipo; }
	bool getColor() { return color; }
	void setOrigen() { origen = false; } //probablemente mejorable
	bool checkOrigen() { return origen; }
};
