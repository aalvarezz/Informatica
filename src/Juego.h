#pragma once
#include "Tablero.h"
#include "Pos.h"

class Juego {
private:
	Tablero tablero;
	Pos pos_inicial, pos_final;
	int AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA;
	bool within_board;
public:
	Juego();
	void inicializar(); //provisional, crearia instancia de tablero como mínimo. Posible conflicto con Coordinador
	void arrastrar(); //movimiento + arrastrar
	void actualizacion(int, int); //raton (nombre y funcionalidad provisionales) + (probablemente) setMouse. Debe consultar de alguna forma si el movimiento es válido
	void jaqueMate(); //condición de máxima prioridad para terminar el juego. Importante su relación con Coordinador
};
