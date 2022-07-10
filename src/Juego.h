#pragma once
#include "Pieza.h"
#include "Menu.h"

class Juego {
protected:
	Tablero tablero, tablero_fantasma;
	Pos pos_inicial, pos_final, mouse_pos, salida_doble;
	Pieza* pieza_elegida;
	Menu menu_coronacion;
	bool within_board, mouse_pressed, mouse_released, turno_blancas, turno_negras, color_elegido, alpaso_blancas, alpaso_negras;
public:
	//Constructores y destructores de juego
	Juego();
	~Juego();

	//Procedimiento a realizar cuando se inicia el juego la primera vez y las sucesivas veces
	void inicializar(int, int, int, int);
	void volverAJugar();

	//Métodos de dibujo
	void dibujar();
	virtual void dibujarPiezas(); //Recorre todas las piezas de tablero y llama a su función de dibujo
	void dibujarArrastrar();
	void dibujarPosiblesCasillas();
  
	//Métodos de interacción con el ratón
	int clicRaton(bool, bool, int, int);
	void movimientoRaton(int, int);

	//Métodos encargados de juzgar si un movimiento es válido o no, incluyendo las excepciones
	bool movimientoValido(Pieza*, Pos, Pos, Tablero*);
	bool enroque(Tablero*, bool, bool);
	void coronacion(Tablero*, Pos);

	//Métodos encargados de detectar un final de juego e identificarlo
	bool checkJaque(Tablero, bool);
	bool finDeJuego(bool); //Condición de máxima prioridad para terminar el juego (pensar en rey ahogado). Importante su relación con Coordinador
};
