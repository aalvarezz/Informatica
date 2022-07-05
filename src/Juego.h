#pragma once
#include "Tablero.h"

//#include "Pos.h"
#include "Pieza.h"

class Juego {
private:
	Tablero tablero;

	//Pieza piezas[4][8];
	Pos pos_inicial, pos_final, mouse_pos;
	Pieza* pieza_elegida;
	int AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA;
	bool within_board, mouse_pressed, mouse_released, turno_blancas, turno_negras, color_elegido;

	bool coronegra, coroblanca;
public:
	Juego();
	void inicializar(); //provisional, crearia instancia de tablero como mínimo. Posible conflicto con Coordinador

	void dibujar(); //MUY PROVISIONAL
	void dibujarArrastrar(); //movimiento + arrastrar. Necesario pensar condicion nueva si no se incluye setmouse.

	void dibujarPiezas(); //recorre todas las piezas de tablero y llama a su función de dibujo.
	void clicRaton(bool, bool, int, int); //raton (nombre y funcionalidad provisionales) + (probablemente) setMouse. Debe consultar de alguna forma si el movimiento es válido
	void movimientoRaton(int, int);
	bool movimientoValido(); //comprueba que el movimiento en proceso es correcto, tiene en cuenta el veredicto de Pieza::comprueba() además de considerar todas las excepciones y estado de jaque. Quizás necesite argumentos en un futuro.
	//void jaqueMate(); //condición de máxima prioridad para terminar el juego (pensar en rey ahogado). Importante su relación con Coordinador
  
  void coronacion();
};
