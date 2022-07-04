
#include "Juego.h"
#include "Peon.h"
#include "Rey.h"
#include "Dama.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Torre.h"


//#include "freeglut.h"
#include <iostream>
using namespace std; //cuidado

Juego::Juego() {

	AJUSTE_X = 86;
	AJUSTE_Y = 813;
	LIM_TABLERO = 728;
	LIM_CASILLA = 91;

	turno_blancas = true;
	turno_negras = false;
	mouse_pressed = false;
	mouse_released = true;
	color_elegido = false;

	coronegra = 0;
	coroblanca = 0;

	enroqueblancoder = 0;
	enroqueblancoizq = 0;
	enroquenegroder = 0;
	enroquenegroizq = 0;

}

void Juego::inicializar() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i > 1 && i < 6) // Vacías las casillas centrales
				tablero.inicializar(nullptr, i, j);
			if (i == 1) { //Peones, hay que diferenciar entre color
				piezas[i][j] = new Peon(0);
				tablero.inicializar(&piezas[i][j], i, j);
			}
			if (i == 6) { //Peones, hay que diferenciar entre color
				piezas[i - 4][j] = new Peon(1);
				tablero.inicializar(&piezas[i - 4][j], i, j);
			}
			if (i == 0) { //blancas
				switch (j) {
				case 0: case 7:
					piezas[i][j] = new Torre(0); //torres
					tablero.inicializar(&piezas[i][j], i, j);
					break;
				case 1: case 6:
					piezas[i][j] = new Caballo(0); //caballos
					tablero.inicializar(&piezas[i][j], i, j);
					break;
				case 2: case 5:
					piezas[i][j] = new Alfil(0); //alfiles
					tablero.inicializar(&piezas[i][j], i, j);
					break;
				case 3:
					piezas[i][j] = new Dama(0); //dama
					tablero.inicializar(&piezas[i][j], i, j);
					break;
				case 4:
					piezas[i][j] = new Rey(0); //rey
					tablero.inicializar(&piezas[i][j], i, j);
					break;
				default: break;
				}
			}
			if (i == 7) { //negras
				switch (j) {
				case 0: case 7:
					piezas[i - 4][j] = new Torre(1); //torres
					tablero.inicializar(&piezas[i - 4][j], i, j);
					break;
				case 1: case 6:
					piezas[i - 4][j] = new Caballo(1); //caballos
					tablero.inicializar(&piezas[i - 4][j], i, j);
					break;
				case 2: case 5:
					piezas[i - 4][j] = new Alfil(1); //alfiles
					tablero.inicializar(&piezas[i - 4][j], i, j);
					break;
				case 3:
					piezas[i - 4][j] = new Dama(1); //dama
					tablero.inicializar(&piezas[i - 4][j], i, j);
					break;
				case 4:
					piezas[i - 4][j] = new Rey(1); //rey
					tablero.inicializar(&piezas[i - 4][j], i, j);
					break;
				default: break;
				}
			}
		}
	}
}

void Juego::inicializar() {
	Pieza* pieza_ini;
	Pos pos_aux;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			pos_aux.fila = i;
			pos_aux.columna = j;
			if (i > 1 && i < 6) // Vacías las casillas centrales
				tablero.setPieza(nullptr, pos_aux);
			if (i == 1) { //Peones, hay que diferenciar entre color
				pieza_ini = new Peon(0);
				tablero.setPieza(pieza_ini, pos_aux);
			}
			if (i == 6) { //Peones, hay que diferenciar entre color
				pieza_ini = new Peon(1);
				tablero.setPieza(pieza_ini, pos_aux);
			}
			if (i == 0) { //blancas
				switch (j) {
				case 0: case 7:
					pieza_ini = new Torre(0); //torres
					tablero.setPieza(pieza_ini, pos_aux);
					break;
				case 1: case 6:
					pieza_ini = new Caballo(0); //caballos
					tablero.setPieza(pieza_ini, pos_aux);
					break;
				case 2: case 5:
					pieza_ini = new Alfil(0); //alfiles
					tablero.setPieza(pieza_ini, pos_aux);
					break;
				case 3:
					pieza_ini = new Dama(0); //dama
					tablero.setPieza(pieza_ini, pos_aux);
					break;
				case 4:
					pieza_ini = new Rey(0); //rey
					tablero.setPieza(pieza_ini, pos_aux);
					break;
				default: break;
				}
			}
			if (i == 7) { //negras
				switch (j) {
				case 0: case 7:
					pieza_ini = new Torre(1); //torres
					tablero.setPieza(pieza_ini, pos_aux);
					break;
				case 1: case 6:
					pieza_ini = new Caballo(1); //caballos
					tablero.setPieza(pieza_ini, pos_aux);
					break;
				case 2: case 5:
					pieza_ini = new Alfil(1); //alfiles
					tablero.setPieza(pieza_ini, pos_aux);
					break;
				case 3:
					pieza_ini = new Dama(1); //dama
					tablero.setPieza(pieza_ini, pos_aux);
					break;
				case 4:
					pieza_ini = new Rey(1); //rey
					tablero.setPieza(pieza_ini, pos_aux);
					break;
				default: break;
				}
			}
		}
	}
}

void Juego::dibujar(){
	tablero.dibujoDamero();
	dibujarPiezas();
}

void Juego::dibujarArrastrar() {
	if (mouse_pressed && pieza_elegida != nullptr) {
		pieza_elegida->dibujarArrastrar(mouse_pos);
		//glutPostRedisplay();
	}
}

void Juego::dibujarPiezas() {
	Pieza* pieza_aux;
	Pos pos_aux;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			pos_aux.fila = i;
			pos_aux.columna = j;
			pieza_aux = tablero.getPieza(pos_aux);
			if (pieza_aux != nullptr)
				pieza_aux->dibujar(pos_aux);
		}
	}
}

void Juego::clicRaton(bool mouseP, bool mouseR, int x, int y) {
	//Actualización de los atributos de Juego referidos al estado de los clics
	mouse_pressed = mouseP;
	mouse_released = mouseR;

	int fila_clic, columna_clic;
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
	if (mouse_pressed && within_board) { //pos_inicial.fila y pos_inicial.columna deben ser las de aquella casilla donde se ha clicado pero NO soltado el clic.
		pos_inicial.fila = fila_clic;
		pos_inicial.columna = columna_clic;
		if (tablero.getPieza(pos_inicial) != nullptr) {
			color_elegido = tablero.getPieza(pos_inicial)->getColor();
		}
	}
	if (mouse_released && within_board) {
		pos_final.fila = fila_clic;
		pos_final.columna = columna_clic;
	}

	cout << "COLOR ACTUAL: " << color_elegido << endl;

	//ACTUALIZACIÓN DE PIEZAS
	if (within_board) { //Acciones a ejecutar si se ha clicado/dejado de clicar dentro del tablero

		cout << "mouse_pressed: " << mouse_pressed << endl;
		cout << "mouse_released: " << mouse_released << endl;

		if (!color_elegido && turno_blancas) { //Turno de las blancas

			if (mouse_pressed && tablero.getPieza(pos_inicial) != nullptr && pieza_elegida == nullptr) { //(mouse_released && tablero[pos_inicial.fila][pos_inicial.columna].getEstado() && puntero_aux == NULL)
				//Se coge una pieza
				pieza_elegida = tablero.getPieza(pos_inicial);
			}
			//suelto en una casilla válida de la pieza que mueves (tienes q estar moviendo una pieza)

			if (mouse_released && (pieza_elegida != nullptr) && movimientoValido()) { //(mouse_pressed && (pieza_elegida != nullptr) && comprueba(pieza_aux, pos_inicial, pos_final))
				//Se actualiza el tablero
				tablero.setPieza(pieza_elegida, pos_final);
				//Se finalizó el movimiento, por lo que se devuelve el puntero a null
				pieza_elegida = nullptr;
				//Gestión de turnos
				turno_blancas = false;
				turno_negras = true;
			}
			//si estás moviendo una pieza y el movimiento no es correcto, se devuelve a su casilla original
			if (mouse_released && (pieza_elegida != nullptr) && !movimientoValido()) { //(mouse_pressed && (puntero_aux != NULL) && !comprueba(pieza_aux, pos_inicial, pos_final))
				//Se devuelve a la casilla original
				tablero.setPieza(pieza_elegida, pos_inicial);
				//Se suelta la pieza
				pieza_elegida = nullptr;
			}
		}

		if (color_elegido && turno_negras) { //Turno de las negras

			if (mouse_pressed && tablero.getPieza(pos_inicial) != nullptr && pieza_elegida == nullptr) { //(mouse_released && tablero[pos_inicial.fila][pos_inicial.columna].getEstado() && puntero_aux == NULL)
				//Se coge una pieza
				pieza_elegida = tablero.getPieza(pos_inicial);
			}

			//Suelto en una casilla válida de la pieza que mueves (tienes q estar moviendo una pieza)
			if (mouse_released && (pieza_elegida != nullptr) && movimientoValido()) { //(mouse_pressed && (pieza_elegida != nullptr) && comprueba(pieza_aux, pos_inicial, pos_final))
				//Se actualiza el tablero
				tablero.setPieza(pieza_elegida, pos_final);
				//Se finalizó el movimiento, por lo que se devuelve el puntero a null
				pieza_elegida = nullptr;
				//Gestión de turnos
				turno_blancas = true;
				turno_negras = false;
			}
			//si estás moviendo una pieza y el movimiento no es correcto, se devuelve a su casilla original
			if (mouse_released && (pieza_elegida != nullptr) && !movimientoValido()) { //(mouse_pressed && (puntero_aux != NULL) && !comprueba(pieza_aux, pos_inicial, pos_final))
				//Se devuelve a la casilla original
				tablero.setPieza(pieza_elegida, pos_inicial);
				//Se suelta la pieza
				pieza_elegida = nullptr;
			}
		}
	}

	//Si se suelta el clic fuera del tablero llevando una pieza no se confirma el movimiento y devuelve la pieza a la casilla inicial previa al movimiento.
	if (!within_board && mouse_released && (pieza_elegida != nullptr)) {
		tablero.setPieza(pieza_elegida, pos_inicial);
		pieza_elegida = nullptr;
	}
}

void Juego::movimientoRaton(int x, int y) {
	//ACCIÓN DE ARRASTRAR
	if (within_board && pieza_elegida != nullptr) {
		if ((!pieza_elegida->getColor() && turno_blancas) || (pieza_elegida->getColor() && turno_negras)) {
			//La pieza que se está moviendo (aún no se ha soltado el clic) se borra de la casilla de la que se había cogido. Esto se hace para evitar que se repita la pieza.
			tablero.quitarPieza(pos_inicial);
			mouse_pos.fila = x;
			mouse_pos.columna = y;
		}
	}
}

bool Juego::movimientoValido() {
	//Cï¿½DIGO EXCEPCIONES

	//MOVER DE 2 EL PEON. IMPORTANTE: SE HA AÃADIDO UN FLAG EN PIEZA QUE INDICA QUE LA PIEZA NUNCA SE HA MOVIDO ANTES. 
	if (pieza_elegida->getTipo() == 1 && !pieza_elegida->checkOrigen())  //si la pieza es un peon y nunca se ha movido
	{
		if (pos_final.fila == pos_inicial.fila - 2 && pos_final.fila == NULL) //si se mueve 2 y la casilla final esta vacia
			return true;
		if (pos_final.fila == pos_inicial.fila + 2 && pos_final.fila == NULL) //si se mueve 2 y la casilla final esta vacia
			return true;
	}

	//ENROQUE BLANCO
	if (pieza_elegida->getTipo() == 2 && !pieza_elegida->getColor() && !pieza_elegida->checkOrigen()) //MOVER EL REY BLANCO SIEMPRE Y CUANDO NO HAYA SIDO MOVIDO ANTES
	{
		Pos torre_blanca_dcha;
		torre_blanca_dcha.fila = 0;
		torre_blanca_dcha.columna = 7;
		if (pos_final.columna == pos_inicial.columna + 2 && !tablero.getPieza(torre_blanca_dcha)->checkOrigen())
			//QUE LA TORRE DEL LADO AL QUE HAYAMOS MOVIDO EL REY NO SE HAYA MOVIDO NUNCA. PERDÃN SI ESA NO ES LA POSICIÃN CORRECTA DEL REY EN EL ENROQUE
		{
			if (pos_final.columna + 1 == NULL && pos_final.columna + 2 == NULL)
			{
				enroqueblancoder = 1;
				return true;
			}
		}
		if (pos_final.columna == pos_inicial.columna - 2 && !tablero.getPieza(torre_blanca_dcha)->checkOrigen())
			//QUE LA TORRE DEL LADO AL QUE HAYAMOS MOVIDO EL REY NO SE HAYA MOVIDO NUNCA. PERDÃN SI ESA NO ES LA POSICIÃN CORRECTA DEL REY EN EL ENROQUE
		{
			if (pos_final.columna - 1 == NULL && pos_final.columna - 2 == NULL && pos_final.columna - 3 == NULL)
			{
				enroqueblancoizq = 1;
				return true;
			}
		}
	}

	//ENROQUE NEGRO
	if (pieza_elegida->getTipo() == 2 && pieza_elegida->getColor() && !pieza_elegida->checkOrigen()) //MOVER EL REY NEGRO SIEMPRE Y CUANDO NO HAYA SIDO MOVIDO ANTES
	{
		Pos torre_negra_dcha;
		torre_negra_dcha.fila = 7;
		torre_negra_dcha.columna = 7;
		if (pos_final.columna == pos_inicial.columna + 2 && !tablero.getPieza(torre_negra_dcha)->checkOrigen())
			//QUE LA TORRE DEL LADO AL QUE HAYAMOS MOVIDO EL REY NO SE HAYA MOVIDO NUNCA. PERDÃN SI ESA NO ES LA POSICIÃN CORRECTA DEL REY EN EL ENROQUE
		{
			if (pos_final.columna + 1 == NULL && pos_final.columna + 2 == NULL)
			{
				enroquenegroder = 1;
				return true;
			}
		}
		if (pos_final.columna == pos_inicial.columna - 2 && !tablero.getPieza(torre_negra_dcha)->checkOrigen())
			//QUE LA TORRE DEL LADO AL QUE HAYAMOS MOVIDO EL REY NO SE HAYA MOVIDO NUNCA. PERDÃN SI ESA NO ES LA POSICIÃN CORRECTA DEL REY EN EL ENROQUE
		{
			if (pos_final.columna - 1 == NULL && pos_final.columna - 2 == NULL && pos_final.columna - 3 == NULL)
			{
				enroquenegroizq = 1;
				return true;
			}
		}
	}

	//CÃDIGO DE MOVIMIENTOS NORMALES

	if (pieza_elegida->comprueba(&tablero, pos_inicial, pos_final)) { //Provisional, esto solo debe ser así en el caso de que no se esté dando ninguna excepción o algo de mayor prioridad.
		//CONDICION DE CORONACION
		if (pieza_elegida->getTipo() == 1 && pieza_elegida->getColor() && pos_inicial.fila == 1 && pos_final.fila == 0)
			coronegra = 1;
		if (pieza_elegida->getTipo() == 1 && !pieza_elegida->getColor() && pos_inicial.fila == 1 && pos_final.fila == 0)
			coroblanca = 1;
		return true;
	}

}

//LAS CORONACIONES BLANCAS Y NEGRAS SE TRATAN INDEPENDIENTEMENTES, A LA ESPERA DE VER CÃMO SON TRATADAS LAS PIEZAS


void Juego::coronacion() {
	int elegido = 0;
	Pieza* pieza_aux;

	//Mensajes
	cout << endl << "Dama: 3" << endl;
	cout << "Alfil: 4" << endl;
	cout << "Caballo: 5" << endl;
	cout << "Torre: 6" << endl;

	do {
		elegido = 0;
		cout << "Elige que pieza quieres: ";
		cin >> elegido;
		switch (elegido) {
		case 3:
			pieza_aux = new Dama(pieza_elegida->getColor());
			tablero.quitarPieza(pos_inicial); //COMPROBAR QUE POS ES LA ADECUADA
			tablero.setPieza(pieza_aux, pos_inicial);
			break;
		case 4:
			pieza_aux = new Alfil(pieza_elegida->getColor());
			tablero.quitarPieza(pos_inicial); //COMPROBAR QUE POS ES LA ADECUADA
			tablero.setPieza(pieza_aux, pos_inicial);
			break;
		case 5:
			pieza_aux = new Caballo(pieza_elegida->getColor());
			tablero.quitarPieza(pos_inicial); //COMPROBAR QUE POS ES LA ADECUADA
			tablero.setPieza(pieza_aux, pos_inicial);
			break;
		case 6:
			pieza_aux = new Torre(pieza_elegida->getColor());
			tablero.quitarPieza(pos_inicial); //COMPROBAR QUE POS ES LA ADECUADA
			tablero.setPieza(pieza_aux, pos_inicial);
			break;
		default:
			cout << endl << "Pieza no valida. ";
		}

	} while (elegido > 6 || elegido < 3);
}
