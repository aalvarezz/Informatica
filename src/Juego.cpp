#include "Juego.h"

Juego::Juego() {

	AJUSTE_X = 86;
	AJUSTE_Y = 813;
	LIM_TABLERO = 728;
	LIM_CASILLA = 91;

	turno_blancas = true;
	turno_negras = false;

}

void Juego::arrastrar() {

}

void Juego::clicRaton(bool mouse_pressed, bool mouse_released, int x, int y) { //Provisionalmente pressed y released no son atributos de Juego, solo variables locales
	int fila_clic, columna_clic;
	bool micolor; //provisionalmente local
	//ENCONTRAR EN QUÉ CASILLA ESTÁ EL CURSOR AL CLICAR/ SOLTAR EL CLIC
	int x0 = x - AJUSTE_X;
	int y0 = y - AJUSTE_Y; //traslado de coordenadas del ratón
	int f = 0;
	int c = 0;

	if (((x0 >= 0) && (x0 <= LIM_TABLERO)) && ((y0 <= 0) && (y0 >= -LIM_TABLERO))) {
		for (int i = 0; i < 8; i++) {
			if ((y0 <= -f) && (y0 > -(f + LIM_CASILLA))) {
				fila_clic = i;
			}
			if ((x0 >= c) && (x0 < (c + LIM_CASILLA))) {
				columna_clic = i;
			}
			//dimensiones de la casilla: 91 x 91
			f += LIM_CASILLA;
			c += LIM_CASILLA;
		}
		within_board = true;
	}
	else {
		within_board = false;
	}
	if (mouse_released) { //pos_inicial.fila y pos_inicial.columna deben ser las de aquella casilla donde se ha clicado pero NO soltado el clic.
		pos_inicial.fila = fila_clic;
		pos_inicial.columna = columna_clic;
		micolor = tablero.getPieza(pos_inicial)->getColor();
	}
	if (mouse_pressed) {
		pos_final.fila = fila_clic;
		pos_final.columna = columna_clic;
	}

	//ACTUALIZACIÓN DE PIEZAS
	if (within_board) { //Acciones a ejecutar si se ha clicado/dejado de clicar dentro del tablero

		if (!micolor && turno_blancas) { //Turno de las blancas

			if (mouse_released && tablero.getPieza(pos_inicial) != nullptr && pieza_elegida == nullptr) { //(mouse_released && tablero[pos_inicial.fila][pos_inicial.columna].getEstado() && puntero_aux == NULL)

					//AÑADIR CÓDIGO COGER PIEZA

				pieza_elegida = tablero.getPieza(pos_inicial);

				//pieza_aux = tablero[pos_inicial.fila][pos_inicial.columna].getPieza(); //Para evitar C2102
				//puntero_aux = &pieza_aux;
				//borrarPosiblesCasillas();
				//dibujarPosiblesCasillas();
			}
			//suelto en una casilla válida de la pieza que mueves (tienes q estar moviendo una pieza)
			if (mouse_pressed && (pieza_elegida != nullptr) && movimientoValido()) { //(mouse_pressed && (pieza_elegida != nullptr) && comprueba(pieza_aux, pos_inicial, pos_final))

					//AÑADIR CÓDIGO SUSTITUIR PIEZA

				//cambiarPieza();
				tablero.moverPieza(pos_inicial, pos_final);
				//puntero_aux = NULL;
				pieza_elegida = nullptr;


				//borrarPosiblesCasillas();
				/*if (pieza_aux.GetTipo() == 2) {
					posReyB.fila = pos_final.fila;
					posReyB.columna = pos_final.columna;
				}*/
				turno_blancas = false;
				turno_negras = true;
				/*if (blancas_en_jaque) {
					blancas_en_jaque = false;
				}
				if (checkJaque(posReyN, pieza_aux, pos_final)) {
					negras_en_jaque = true;
				}*/
			}
			//si estás moviendo una pieza y el movimiento no es correcto, se devuelve a su casilla original
			if (mouse_pressed && (pieza_elegida != nullptr) && !movimientoValido()) { //(mouse_pressed && (puntero_aux != NULL) && !comprueba(pieza_aux, pos_inicial, pos_final))
				//tablero[pos_inicial.fila][pos_inicial.columna].setPieza(pieza_aux);
				tablero.setPieza(pieza_elegida, pos_inicial);
				//puntero_aux = NULL;
				pieza_elegida = nullptr;
			}
		}

		if (micolor && turno_negras) { //Turno de las negras

			if (mouse_released && tablero.getPieza(pos_inicial) != nullptr && pieza_elegida == nullptr) { //(mouse_released && tablero[pos_inicial.fila][pos_inicial.columna].getEstado() && puntero_aux == NULL)

					//AÑADIR CÓDIGO COGER PIEZA

				pieza_elegida = tablero.getPieza(pos_inicial);

				//pieza_aux = tablero[pos_inicial.fila][pos_inicial.columna].getPieza(); //Para evitar C2102
				//puntero_aux = &pieza_aux;
				//borrarPosiblesCasillas();
				//dibujarPosiblesCasillas();
			}
			//suelto en una casilla válida de la pieza que mueves (tienes q estar moviendo una pieza)
			if (mouse_pressed && (pieza_elegida != nullptr) && movimientoValido()) { //(mouse_pressed && (pieza_elegida != nullptr) && comprueba(pieza_aux, pos_inicial, pos_final))

					//AÑADIR CÓDIGO SUSTITUIR PIEZA

				//cambiarPieza();
				tablero.moverPieza(pos_inicial, pos_final);
				//puntero_aux = NULL;
				pieza_elegida = nullptr;


				//borrarPosiblesCasillas();
				/*if (pieza_aux.GetTipo() == 8) {
					posReyN.fila = pos_final.fila;
					posReyN.columna = pos_final.columna;
				}*/
				turno_negras = false;
				turno_blancas = true;
				/*if (negras_en_jaque) {
					negras_en_jaque = false;
				}
				if (checkJaque(posReyB, pieza_aux, pos_final)) {
					blancas_en_jaque = true;
				}*/
			}
			//si estás moviendo una pieza y el movimiento no es correcto, se devuelve a su casilla original
			if (mouse_pressed && (pieza_elegida != nullptr) && !movimientoValido()) { //(mouse_pressed && (puntero_aux != NULL) && !comprueba(pieza_aux, pos_inicial, pos_final))
				//tablero[pos_inicial.fila][pos_inicial.columna].setPieza(pieza_aux);
				tablero.setPieza(pieza_elegida, pos_inicial);
				//puntero_aux = NULL;
				pieza_elegida = nullptr;
			}
		}
	}

	//Si se suelta el clic fuera del tablero llevando una pieza no se confirma el movimiento y devuelve la pieza a la casilla inicial previa al movimiento.
	if (!within_board && mouse_pressed && (pieza_elegida != nullptr)) {
		tablero.setPieza(pieza_elegida, pos_inicial);
		pieza_elegida = nullptr;
	}
}

bool Juego::movimientoValido() {
	//CÓDIGO EXCEPCIONES
	if (pieza_elegida->comprueba(&tablero)) return true; //Provisional, esto solo debe ser así en el caso de que no se esté dando ninguna excepción o algo de mayor prioridad.
}
