#pragma once
#include "Pieza.h"

class Juego {
protected:
	Tablero tablero, tablero_fantasma;
	Pos pos_inicial, pos_final, mouse_pos, salida_doble;
	Pieza* pieza_elegida;
	bool within_board, mouse_pressed, mouse_released, turno_blancas, turno_negras, color_elegido, alpaso_blancas, alpaso_negras;
public:
	Juego();
	void inicializar(int, int, int, int);

	void dibujar();
	void dibujarPiezas(); //recorre todas las piezas de tablero y llama a su función de dibujo.
	void dibujarArrastrar(); //movimiento + arrastrar. Necesario pensar condicion nueva si no se incluye setmouse.
	void dibujarPosiblesCasillas();

	void clicRaton(bool, bool, int, int); //raton (nombre y funcionalidad provisionales) + (probablemente) setMouse. Debe consultar de alguna forma si el movimiento es válido
	void movimientoRaton(int, int);
	bool movimientoValido(Pieza*, Pos, Pos, Tablero*); //comprueba que el movimiento en proceso es correcto, tiene en cuenta el veredicto de Pieza::comprueba() además de considerar todas las excepciones y estado de jaque. Quizás necesite argumentos en un futuro.
	bool enroque(Tablero*, bool, bool);
	void coronacion(Tablero*, Pos);

	bool checkJaque(Tablero, bool);
	bool finDeJuego(bool); //condición de máxima prioridad para terminar el juego (pensar en rey ahogado). Importante su relación con Coordinador
};
