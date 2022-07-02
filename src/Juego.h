#pragma once
#include "Tablero.h"
//#include "Pos.h"
#include "Pieza.h"

class Juego {
private:
	Tablero tablero;
	//Pieza piezas[4][8];
	Pos pos_inicial, pos_final;
	Pieza* pieza_elegida;
	int AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA;
	bool within_board, turno_blancas, turno_negras;

	bool coronegra, coroblanca;
	bool enroqueblancoder, enroqueblancoizq, enroquenegroder, enroquenegroizq;
public:
	Juego();
	void inicializar(); //provisional, crearia instancia de tablero como mínimo. Posible conflicto con Coordinador
	void arrastrar(); //movimiento + arrastrar. Necesario pensar condicion nueva si no se incluye setmouse.
	void clicRaton(bool, bool, int, int); //raton (nombre y funcionalidad provisionales) + (probablemente) setMouse. Debe consultar de alguna forma si el movimiento es válido
	bool movimientoValido(); //comprueba que el movimiento en proceso es correcto, tiene en cuenta el veredicto de Pieza::comprueba() además de considerar todas las excepciones y estado de jaque. Quizás necesite argumentos en un futuro.
	//void jaqueMate(); //condición de máxima prioridad para terminar el juego (pensar en rey ahogado). Importante su relación con Coordinador
  
  void coronacion();
};
