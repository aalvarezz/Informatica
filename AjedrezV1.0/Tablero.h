#pragma once
#include "Casilla.h"
#include "Pieza.h" //pragma once
#include "Pos.h" //pragma once


extern int tablerillo[8][8];

class Tablero {
private:

	Casilla tablero[8][8];
	Pos mouse_pos, pos_inicial, pos_final, posReyB, posReyN;
	Pieza pieza_aux;
	Pieza* puntero_aux;
<<<<<<< Updated upstream
	int columna_movimiento, fila_movimiento, columna_raton, fila_raton;
	bool mouse_pressed, mouse_released, within_board, turno_negras, turno_blancas, micolor;
=======
	int columna_movimiento, fila_movimiento, columna_raton, fila_raton, AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA;
	bool mouse_pressed, mouse_released, within_board, turno_negras, turno_blancas, micolor, blancas_en_jaque, negras_en_jaque;
>>>>>>> Stashed changes
	float lado;
	Pieza piezas[32];

public: //REVISAR METODOS (algunos pueden ser redundantes/simplificables

	Tablero();
	~Tablero();

<<<<<<< Updated upstream
	void Inicializar();
	void crearPiezas();
	void InicializarPiezas();
	void DibujarTablero();
	void DibujarPiezas();
	std::vector<Casilla> aplicaReglas(Pieza, Pos);
	bool comprueba(Pieza, Pos, Pos);
	bool checkFinal(Casilla);
	bool checkJaque(Pos);
	void Raton(int, int, int, int);
	void SetMouse(int, int, bool, bool);
	Pos GetMousePos();
	Pieza GetPieza();
	void CambiarPieza();
	void Movimiento(int, int);
	void Arrastrar();
	void DibujarPosiblesCasillas();
	void borrarPosiblesCasillas();
=======
	void inicializar();
	void crearPiezas();
	void inicializarPiezas();
	void dibujarTablero();
	void dibujarPiezas();
	std::vector<Casilla> aplicaReglas(Pieza, Pos);
	bool comprueba(Pieza, Pos, Pos);
	bool checkFinal(Casilla);
	bool checkJaque(Pos, Pieza, Pos);
	void raton(int, int, int, int);
	void setMouse(int, int, bool, bool);
	Pos getMousePos();
	Pieza getPieza();
	void cambiarPieza();
	void movimiento(int, int);
	void arrastrar();
	void dibujarPosiblesCasillas();
	void borrarPosiblesCasillas();
	void setTamano(bool);
	bool getTurnoB();
	bool getTurnoN();
>>>>>>> Stashed changes

};
