#include "Juego.h"

#include "Peon.h"
#include "Rey.h"
#include "Dama.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Torre.h"

#include <iostream>
using namespace std;

Juego::Juego() {

	AJUSTE_X = 86;
	AJUSTE_Y = 813;
	LIM_TABLERO = 728;
	LIM_CASILLA = 91;

	turno_blancas = true;
	turno_negras = false;

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
				tablero.setPieza(pieza_elegida, pos_final);
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
				tablero.setPieza(pieza_elegida, pos_final);
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
	//Cï¿½DIGO EXCEPCIONES

	//MOVER DE 2 EL PEON. IMPORTANTE: SE HA AÃADIDO UN FLAG EN PIEZA QUE INDICA QUE LA PIEZA NUNCA SE HA MOVIDO ANTES. 
	if (pieza_elegida == "PEON" && pieza_elegida->posoriginal == 0)  //si la pieza es un peon y nunca se ha movido
	{
		if (pos_final.fila == pos_inicial.fila - 2 && pos_final.fila == NULL) //si se mueve 2 y la casilla final esta vacia
			return true;
		if (pos_final.fila == pos_inicial.fila + 2 && pos_final.fila == NULL) //si se mueve 2 y la casilla final esta vacia
			return true;
	}

	//ENROQUE BLANCO
	if (pieza_elegida == "REY BLANCO" && pieza_elegida->posoriginal == 0) //MOVER EL REY BLANCO SIEMPRE Y CUANDO NO HAYA SIDO MOVIDO ANTES
	{
		if (pos_final.columna == pos_inicial.columna + 2 && "TORRE BLANCA DERECHA".posoriginal == 0)
			//QUE LA TORRE DEL LADO AL QUE HAYAMOS MOVIDO EL REY NO SE HAYA MOVIDO NUNCA. PERDÃN SI ESA NO ES LA POSICIÃN CORRECTA DEL REY EN EL ENROQUE
		{
			if (pos_final.columna + 1 == NULL && pos_final.columna + 2 == NULL)
			{
				enroqueblancoder == 1;
				return true;
			}
		}
		if (pos_final.columna == pos_inicial.columna - 2 && "TORRE BLANCA DERECHA".posoriginal == 0)
			//QUE LA TORRE DEL LADO AL QUE HAYAMOS MOVIDO EL REY NO SE HAYA MOVIDO NUNCA. PERDÃN SI ESA NO ES LA POSICIÃN CORRECTA DEL REY EN EL ENROQUE
		{
			if (pos_final.columna - 1 == NULL && pos_final.columna - 2 == NULL && pos_final.columna - 3 == NULL)
			{
				enroqueblancoizq == 1;
				return true;
			}
		}
	}

	//ENROQUE NEGRO
	if (pieza_elegida == "REY NEGRO" && pieza_elegida->posoriginal == 0) //MOVER EL REY NEGRO SIEMPRE Y CUANDO NO HAYA SIDO MOVIDO ANTES
	{
		if (pos_final.columna == pos_inicial.columna + 2 && "TORRE NEGRA DERECHA".posoriginal == 0)
			//QUE LA TORRE DEL LADO AL QUE HAYAMOS MOVIDO EL REY NO SE HAYA MOVIDO NUNCA. PERDÃN SI ESA NO ES LA POSICIÃN CORRECTA DEL REY EN EL ENROQUE
		{
			if (pos_final.columna + 1 == NULL && pos_final.columna + 2 == NULL)
			{
				enroquenegroder == 1;
				return true;
			}
		}
		if (pos_final.columna == pos_inicial.columna - 2 && "TORRE NEGRA DERECHA".posoriginal == 0)
			//QUE LA TORRE DEL LADO AL QUE HAYAMOS MOVIDO EL REY NO SE HAYA MOVIDO NUNCA. PERDÃN SI ESA NO ES LA POSICIÃN CORRECTA DEL REY EN EL ENROQUE
		{
			if (pos_final.columna - 1 == NULL && pos_final.columna - 2 == NULL && pos_final.columna - 3 == NULL)
			{
				enroquenegroizq == 1;
				return true;
			}
		}
	}

	//CÃDIGO DE MOVIMIENTOS NORMALES
	if (pieza_elegida->comprueba(&tablero, pos_inicial, pos_final))  //Provisional, esto solo debe ser así en el caso de que no se esté dando ninguna excepción o algo de mayor prioridad.
	{
		//CONDICION DE CORONACION
		if (pieza_elegida == "PEON NEGRO" && pos_inicial.fila == 1 && pos_final.fila == 0)
			coronegra = 1;
		if (pieza_elegida == "PEON BLANCO" && pos_inicial.fila == 1 && pos_final.fila == 0)
			coroblanca = 1;
		return true;
	}

}

//LAS CORONACIONES BLANCAS Y NEGRAS SE TRATAN INDEPENDIENTEMENTES, A LA ESPERA DE VER CÃMO SON TRATADAS LAS PIEZAS

void Juego::coronacionBlanca() {
	//Mensajes
	int elegido = 0;
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
			pieza_elegida.setTipo(3);
			break;
		case 4:
			pieza_elegida.setTipo(4);
			break;
		case 5:
			pieza_elegida.setTipo(5);
			break;
		case 6:
			pieza_elegida.setTipo(6);
			break;
		default:
			cout << endl << "Pieza no valida. ";
		}
	} while (elegido > 6 || elegido < 3);
}

void Juego::coronacionNegra() {
	int elegido = 0;
	cout << endl << "Dama: 9" << endl;
	cout << "Alfil: 10" << endl;
	cout << "Caballo: 11" << endl;
	cout << "Torre: 12" << endl;
	do {
		elegido = 0;
		cout << "Elige que pieza quieres: ";
		std::cin >> elegido;
		switch (elegido) {
		case 3:
			pieza_elegida.setTipo(9);
			break;
		case 4:
			pieza_elegida.setTipo(10);
			break;
		case 5:
			pieza_elegida.setTipo(11);
			break;
		case 6:
			pieza_elegida.setTipo(12);
			break;
		default:
			cout << endl << "Pieza no valida. ";
		}
	} while (elegido > 12 || elegido < 9);
}