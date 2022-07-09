#pragma once
#include "Tablero.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Pieza {
protected:
	//Pos pos; //provisional
	bool color, origen = true;
	unsigned short int tipo;
	float lado = 2.5f;
	SpriteSequence sprite{ "imagenes/Piezas.png", 6, 2 };
public:
	Pieza(bool _color, unsigned short int _tipo) : color(_color), tipo(_tipo) {};
	void dibujar(Pos); //dibuja la pieza en su casilla actual calculando el centro de esta y haciendo las conversiones de coordenadas pertinentes.
	void dibujarArrastrar(Pos,Tablero*); //dibuja la pieza en unas coordenadas del bitmap dadas para que se aprecie el movimiento de arrastre. Se deben realizar conversiones de bitmap a glut.
	void draw(float, float);

	//calcula si cierto movimiento es válido para la pieza. considera las reglas normales de la pieza consultando el
	//estado actual del tablero, sin tener en cuenta excepciones (mayor prioridad)
	virtual bool comprueba(Tablero*, Pos, Pos) { return false; }

	unsigned short int getTipo() { return tipo; }
	bool getColor() { return color; }

	void setOrigenFalse() { origen = false; } //probablemente mejorable
	bool checkOrigen() { return origen; }
};
