#pragma once
#include "tablero.h"
#include "juego.h"
#include "Menu.h"
#include "ETSIDI.h"
#include "freeglut.h"
// libreria para final de juego?

class Coordinador {
private:
	bool turno_1;
	Juego juego;
	Menu menu;
	enum Estado {INICIO,TURNO_B,TURNO_N,FIN_DE_PARTIDA};
	Estado estado;

public:
	Coordinador();
	void Inicializa();
	void Dibuja();

	//movimiento de las piezas en el teclado
	void Movimiento(int x, int y);
	//void setTamano(bool);
	void cambioEstado(int button, int state, int x, int y);
};
