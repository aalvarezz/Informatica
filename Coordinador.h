#pragma once

#include "Tablero.h"
#include "freeglut.h"
#include "menu.h"

class Coordinador
{
protected:
	Tablero damero;
	Menu menu;
	bool tamano;

public:
	Coordinador();
	enum Estado {INICIO,TURNO_BLANCAS,TURNO_NEGRAS}; //Meter diferentes ventanas
	Estado estado;
	void Inicializa();
	void Dibuja();
	void Tecla(int button, int state, int x, int y);
	void Movimiento(int x, int y);
	void setTamano(bool);
};

