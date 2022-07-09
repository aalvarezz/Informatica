#pragma once
#include "tablero.h"
#include "juego.h"
#include "Menu.h"
#include "ETSIDI.h"
#include "freeglut.h"


enum Estado { MENU, PARTIDA, FIN_DE_PARTIDA };

// libreria para final de juego?

class Coordinador {
private:
	bool running;
	Menu menu;
	Estado estado;

public:
	Coordinador();
	void Inicializa(int argc, char* argv[]);
	//void Dibuja();

	//movimiento de las piezas en el teclado
	//void Movimiento(int x, int y);
	//void setTamano(bool);
	void cambioEstado();
	//void OnDraw(void); //esta funcion sera llamada para dibujar
	//void OnMouseClick(int, int, int, int);
	//void OnMotion(int, int);

	void asignarTamano(bool);
	Estado getEstado();
	//Juego getJuego();
	bool getRunning() { return running; }
};
