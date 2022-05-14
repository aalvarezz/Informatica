#pragma once

#include "Tablero.h"
#include "freeglut.h"

class Coordinador
{
protected:
	Tablero damero;

public:
	Coordinador();
	enum Estado {INICIO, JUEGO }; //Meter diferentes ventanas
	Estado estado;
	void Inicializa();
	void Dibuja();
	void Tecla(int button, int state, int x, int y);
	void Movimiento(int x, int y);
};

