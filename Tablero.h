#pragma once
#include "Casilla.h"
#include "Pieza.h" //pragma once
#include "Pos.h" //pragma once

class Tablero {
private:

	Casilla tablero[8][8];
	Pos mouse_pos, pos_inicial, pos_final, posReyB, posReyN;
	Pieza pieza_aux;
	Pieza* puntero_aux;
	int columna_movimiento, fila_movimiento, columna_raton, fila_raton;//fila01, columna01, columna1, fila1;
	bool mouse_pressed, mouse_released, within_board;//turno, mover; //flag provisional
	float lado;
	//BOOLES PROVISIONALES PARA PODER EFECTUAR MOVIMIENTOS ESPECIALES
	bool alpaso, coronacion;
	///////////////////////
	Pieza piezas[32];
	Pos doblemov_negra, doblemov_blanca;
	////////////////////////////////
	bool turno_b;
	int AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA;

public: //REVISAR METODOS (algunos pueden ser redundantes/simplificables

	Tablero();
	~Tablero();

	void Inicializar();
	void crearPiezas();
	void InicializarPiezas();
	Casilla getCasilla(int, int);
	void DibujarTablero();
	void DibujarPiezas();
	std::vector<Casilla> aplicaReglas(Pieza, Pos);
	bool comprueba(Pieza, Pos, Pos);
	bool checkFinal(Casilla);
	void Raton(int, int, int, int);
	void SetMouse(int, int, bool, bool);
	Pos GetMousePos();
	Pieza GetPieza();
	void CambiarPieza();
	void Movimiento(int, int);
	void Arrastrar();
	void DibujarPosiblesCasillas();
	//////////////////////////
	bool getTurnoB();
	void setTamano(bool);
	void CoronacionBlanca();
	void CoronacionNegra();
	bool MovimAlfil();
	bool MovimTorre();
};