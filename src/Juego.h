#pragma once
#include "Tablero.h"
#include "Pos.h"

class Juego {
private:
	Tablero tablero;
	Pos pos_inicial, pos_final;
	Pieza* pieza_elegida;
	int AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA;
	bool within_board, turno_blancas, turno_negras;

	bool coronegra, coroblanca;
	bool enroqueblancoder, enroqueblancoizq, enroquenegroder, enroquenegroizq;
public:
	Juego();
	void inicializar(); //provisional, crearia instancia de tablero como m�nimo. Posible conflicto con Coordinador
	void arrastrar(); //movimiento + arrastrar. Necesario pensar condicion nueva si no se incluye setmouse.
	void clicRaton(bool, bool, int, int); //raton (nombre y funcionalidad provisionales) + (probablemente) setMouse. Debe consultar de alguna forma si el movimiento es v�lido
	bool movimientoValido(); //comprueba que el movimiento en proceso es correcto, tiene en cuenta el veredicto de 
	//Pieza::comprueba() adem�s de considerar todas las excepciones y estado de jaque. Quiz�s necesite argumentos en un futuro.
	void jaqueMate(); //condici�n de m�xima prioridad para terminar el juego (pensar en rey ahogado). Importante su relaci�n con Coordinador

	void coronacionBlanca();
	void coronacionNegra();
};