#include "Juego.h"
#include "Peon.h"
#include "Rey.h"
#include "Dama.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Torre.h"

#include <iostream>
using namespace std; //cuidado

Juego::Juego() {

	pieza_elegida = nullptr;
	within_board = false;

	turno_blancas = true;
	turno_negras = false;
	mouse_pressed = false;
	mouse_released = true;
	color_elegido = false;

	miraryactuar = true;
  
	coronegra = 0;
	coroblanca = 0;

	pasonegro = 0;
	pasoblanco = 0;
  
	miraryactuar = 1;

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
	tablero_fantasma = tablero;
}

void Juego::dibujar() { //PROVISIONAL
	tablero.dibujoDamero();
	dibujarPiezas();
}

void Juego::dibujarArrastrar() {
	if (mouse_pressed && pieza_elegida != nullptr) {
		pieza_elegida->dibujarArrastrar(mouse_pos);

		miraryactuar = 0;
		dibujarPosiblesCasillas();
		miraryactuar = 1;

	}
}

void Juego::dibujarPosiblesCasillas() {
	Pos pos_iteracion;
	for (int fil = 0; fil < 8; fil++) {
		for (int col = 0; col < 8; col++) {
			pos_iteracion.fila = fil;
			pos_iteracion.columna = col;
			if (movimientoValido(pieza_elegida, pos_inicial, pos_iteracion, &tablero))
				tablero.dibujarPosibleCasilla(pos_iteracion);
		}
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
			if (pieza_aux != nullptr) {
				pieza_aux->dibujar(pos_aux);
			}
		}
	}
}

void Juego::clicRaton(bool mouseP, bool mouseR, int x, int y) {
	//Actualización de los atributos de Juego referidos al estado de los clics
	mouse_pressed = mouseP;
	mouse_released = mouseR;

	//ENCONTRAR EN QUÉ CASILLA ESTÁ EL CURSOR AL CLICAR/ SOLTAR EL CLIC
	int fila_clic, columna_clic;
	int x0 = x - AJUSTE_X;
	int y0 = y - AJUSTE_Y; 
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
		if (pieza_elegida != nullptr) {
			tablero_fantasma.quitarPieza(pos_inicial);
			tablero_fantasma.setPieza(pieza_elegida, pos_final);
		}
	}

	//ACTUALIZACIÓN DE PIEZAS
	bool kk;
	if (within_board) { //Acciones a ejecutar si se ha clicado/dejado de clicar dentro del tablero
		if (!color_elegido && turno_blancas) { //Turno de las blancas

			//Se clica en una casilla que contiene pieza para cogerla e iniciar el movimiento
			if (mouse_pressed && tablero.getPieza(pos_inicial) != nullptr && pieza_elegida == nullptr) {
				pieza_elegida = tablero.getPieza(pos_inicial);
			}
			//Se suelta el clic en una casilla válida de la pieza que mueves (tienes que estar moviendo una pieza). 
			//El movimiento no puede provocar que el color pase a estar en jaque.
			if (mouse_released && (pieza_elegida != nullptr) && movimientoValido(pieza_elegida, pos_inicial, pos_final, &tablero) 
				&& !checkJaque(tablero_fantasma, pieza_elegida->getColor())) {

				//Se actualiza el tablero
				tablero.setPieza(pieza_elegida, pos_final);

				if (finDeJuego(true)) {
					cout << "GG" << endl;
					if (checkJaque(tablero, true)) {
						cout << "Victoria de las blancas por jaque mate!" << endl;
					}
					else {
						cout << "Victoria de las blancas por rey ahogado!" << endl;
					}
				}

				pieza_elegida->setOrigenFalse(); //indica que la pieza ha sido movida al menos una vez, para realizar movimientos excepcionales
				if (coroblanca == 1) //se cumple que un peon ha llegado al final, siendo este coronado
				{
					coroblanca = 0;
					coronacion();
				}

				//Se finalizó el movimiento, por lo que se devuelve el puntero a null y se deshacen los cambios del tablero fantasma.
				pieza_elegida = nullptr;
				tablero_fantasma = tablero;

				pasonegro = false;

				//Gestión de turnos
				turno_blancas = false;
				turno_negras = true;
			}
			//Si estás moviendo una pieza y el movimiento no es correcto o este provoca que el color pase a estar en jaque, se devuelve a su casilla original
			if (mouse_released && (pieza_elegida != nullptr) && (!movimientoValido(pieza_elegida, pos_inicial, pos_final, &tablero) 
				|| checkJaque(tablero_fantasma, pieza_elegida->getColor()))) {

				//Se devuelve a la casilla original
				tablero.setPieza(pieza_elegida, pos_inicial);

				//Se finalizó el movimiento, por lo que se devuelve el puntero a null y se deshacen los cambios del tablero fantasma.
				pieza_elegida = nullptr;
				tablero_fantasma = tablero;
			}
		}

		if (color_elegido && turno_negras) { //Turno de las negras

			//Se clica en una casilla que contiene pieza para cogerla e iniciar el movimiento
			if (mouse_pressed && tablero.getPieza(pos_inicial) != nullptr && pieza_elegida == nullptr) {
				pieza_elegida = tablero.getPieza(pos_inicial);
			}
			//Se suelta el clic en una casilla válida de la pieza que mueves (tienes que estar moviendo una pieza). 
			//El movimiento no puede provocar que el color pase a estar en jaque.
			if (mouse_released && (pieza_elegida != nullptr) && movimientoValido(pieza_elegida, pos_inicial, pos_final, &tablero)
				&& !checkJaque(tablero_fantasma, pieza_elegida->getColor())) {

				//Se actualiza el tablero
				tablero.setPieza(pieza_elegida, pos_final);

				if (finDeJuego(false)) {
					cout << "GG" << endl;
					if (checkJaque(tablero, false)) {
						cout << "Victoria de las negras por jaque mate!" << endl;
					}
					else {
						cout << "Victoria de las negras por rey ahogado!" << endl;
					}
				}

				pieza_elegida->setOrigenFalse(); //indica que la pieza ha sido movida al menos una vez, para realizar movimientos excepcionales
				if (coronegra == 1) //se cumple que un peon ha llegado al final, siendo este coronado
				{
					coronegra = 0;
					coronacion();
				}

				//Se finalizó el movimiento, por lo que se devuelve el puntero a null y se deshacen los cambios del tablero fantasma.
				pieza_elegida = nullptr;
				tablero_fantasma = tablero;

				pasoblanco = false;

				//Gestión de turnos
				turno_blancas = true;
				turno_negras = false;
			}
      
			//Si estás moviendo una pieza y el movimiento no es correcto o este provoca que el color pase a estar en jaque, se devuelve a su casilla original
			if (mouse_released && (pieza_elegida != nullptr) && (!movimientoValido(pieza_elegida, pos_inicial, pos_final, &tablero)
				|| checkJaque(tablero_fantasma, pieza_elegida->getColor()))) {

				//Se devuelve a la casilla original
				tablero.setPieza(pieza_elegida, pos_inicial);

				//Se finalizó el movimiento, por lo que se devuelve el puntero a null y se deshacen los cambios del tablero fantasma.
				pieza_elegida = nullptr;
				tablero_fantasma = tablero;
			}
		}
	}

	//Si se suelta el clic fuera del tablero llevando una pieza no se confirma el movimiento y devuelve la pieza a la casilla inicial previa al movimiento.
	if (!within_board && mouse_released && (pieza_elegida != nullptr)) {

		//Se devuelve a la casilla original
		tablero.setPieza(pieza_elegida, pos_inicial);

		//Se finalizó el movimiento, por lo que se devuelve el puntero a null y se deshacen los cambios del tablero fantasma.
		pieza_elegida = nullptr;
		tablero_fantasma = tablero;
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

bool Juego::movimientoValido(Pieza* pieza, Pos pos_inicio, Pos pos_fin, Tablero* tab) {

	//EXCEPCIONES

	//COMER AL PASO
	if (pasonegro == 1) //el peon negro puede ser comido por el blanco
	{
		if (pieza->getTipo() == 1 && pieza->getColor() == 0 && pos_inicial.fila == doblenegro.fila)
		{
			if (pos_fin.fila == doblenegro.fila + 1 && pos_fin.columna == doblenegro.columna)
			{
				if (miraryactuar)
					tablero.quitarPieza(doblenegro); //eliminamos el peon comido al paso
				return true;
			}
		}
	}

	if (pasoblanco == 1) //el peon blanco puede ser comido por el negro
	{
		if (pieza->getTipo() == 1 && pieza->getColor() != 0 && pos_inicial.fila == dobleblanco.fila)
		{
			if (pos_fin.fila == dobleblanco.fila - 1 && pos_fin.columna == dobleblanco.columna)
			{
				if (miraryactuar)
					tablero.quitarPieza(dobleblanco); //eliminamos el peon comido al paso
				return true;
			}
		}
	}

	//MOVER DE 2 EL PEON. IMPORTANTE: SE HA AÃADIDO UN FLAG EN PIEZA QUE INDICA QUE LA PIEZA NUNCA SE HA MOVIDO ANTES. 
	if (pieza->getTipo() == 1 && pieza->checkOrigen())  //si la pieza es un peon y nunca se ha movido
	{
		if (pos_fin.fila == pos_inicio.fila - 2 && pos_inicio.columna == pos_fin.columna && tablero.getPieza(pos_fin) == NULL) //si se mueve 2 y la casilla final esta vacia

		{
			doblenegro = pos_fin;
			pasonegro = 1;
			return true;
		}
		if (pos_fin.fila == pos_inicio.fila + 2 && pos_inicio.columna == pos_fin.columna && tablero.getPieza(pos_fin) == NULL) //si se mueve 2 y la casilla final esta vacia

		{
			dobleblanco = pos_fin;
			pasoblanco = 1;
			return true;
		}
	}

	//ENROQUES BLANCOS
	if (pieza->getTipo() == 2 && !pieza->getColor() && pieza->checkOrigen()) { //Se tiene que estar intentando mover el rey blanco y debe tratarse de su primer movimiento

		//ENROQUE CORTO
		if (pos_fin.columna == pos_inicio.columna + 2 && pos_fin.fila == pos_inicio.fila) {
			return enroque(tab, false, true);
		}

		//ENROQUE LARGO
		if (pos_fin.columna == pos_inicio.columna - 2 && pos_fin.fila == pos_inicio.fila) {
			return enroque(tab, false, false);
		}
	}

	//ENROQUES NEGROS
	if (pieza->getTipo() == 2 && pieza->getColor() && pieza->checkOrigen()) { //Se tiene que estar intentando mover el rey blanco y debe tratarse de su primer movimiento

		//ENROQUE CORTO
		if (pos_fin.columna == pos_inicio.columna + 2 && pos_fin.fila == pos_inicio.fila) {
			return enroque(tab, true, true);
		}

		//ENROQUE LARGO
		if (pos_fin.columna == pos_inicio.columna - 2 && pos_fin.fila == pos_inicio.fila) {
			return enroque(tab, true, false);
		}
	}

	//REGLAS NORMALES DE MOVIMIENTO (GESTIONADAS POR LA PIEZA QUE SE INTENTA MOVER)
	if (pieza->comprueba(tab, pos_inicio, pos_fin)) {
		//CONDICION DE CORONACION
		if (miraryactuar)
		{
			if (pieza->getTipo() == 1 && !pieza->getColor() && pos_fin.fila == 7)
				coroblanca = 1;
			if (pieza->getTipo() == 1 && pieza->getColor() && pos_fin.fila == 0)
				coronegra = 1;
		}

		return true;
	}
	else return false;
}

bool Juego::enroque(Tablero* tab, bool color, bool enroque_corto) {

	//ENROQUES BLANCOS
	if (!color) {

		//Se declaran las posiciones que deben de tener las torres que participan en el enroque
		Pos torre_blanca_dcha = Pos(0, 7);
		Pos torre_blanca_izq = Pos(0, 0);

		//ENROQUE CORTO
		if (enroque_corto && tab->getPieza(torre_blanca_dcha) != nullptr) {
			//La torre que participe en el enroque que se esté intentando realizar no se puede haber movido nunca
			if (tab->getPieza(torre_blanca_dcha)->checkOrigen()) {

				//Se especifican las posiciones entre el rey y la torre que participa en el enroque
				Pos aux1 = Pos(0, 6);
				Pos aux2 = Pos(0, 5);

				//Si las casillas entre rey y torre se encuentran vacías se realiza el enroque
				if (tab->getPieza(aux1) == nullptr && tab->getPieza(aux2) == nullptr) {
					if (miraryactuar) {
						Pieza* pieza_aux = tab->getPieza(torre_blanca_dcha);
						tab->quitarPieza(torre_blanca_dcha);
						tab->setPieza(pieza_aux, aux2);
					}
					return true;
				}
			}
		}

		//ENROQUE LARGO
		if (!enroque_corto && tab->getPieza(torre_blanca_izq) != nullptr) {
			//La torre que participe en el enroque que se esté intentando realizar no se puede haber movido nunca
			if (tab->getPieza(torre_blanca_izq)->checkOrigen()) {

				//Se especifican las posiciones entre el rey y la torre que participa en el enroque
				Pos aux1 = Pos(0, 3);
				Pos aux2 = Pos(0, 2);
				Pos aux3 = Pos(0, 1);

				//Si las casillas entre rey y torre se encuentran vacías se realiza el enroque
				if (tab->getPieza(aux1) == nullptr && tab->getPieza(aux2) == nullptr && tab->getPieza(aux3) == nullptr) {
					if (miraryactuar) {
						Pieza* pieza_aux = tab->getPieza(torre_blanca_izq);
						tab->quitarPieza(torre_blanca_izq);
						tab->setPieza(pieza_aux, aux1);
					}
					return true;
				}
			}
		}
	}

	//ENROQUES NEGROS
	if (color) {

		//Se declaran las posiciones que deben de tener las torres que participan en el enroque
		Pos torre_negra_dcha = Pos(7, 7);
		Pos torre_negra_izq = Pos(7, 0);

		//ENROQUE CORTO
		if (enroque_corto && tab->getPieza(torre_negra_dcha) != nullptr) {
			//La torre que participe en el enroque que se esté intentando realizar no se puede haber movido nunca
			if (tab->getPieza(torre_negra_dcha)->checkOrigen()) {

				//Se especifican las posiciones entre el rey y la torre que participa en el enroque
				Pos aux1 = Pos(7, 6);
				Pos aux2 = Pos(7, 5);

				//Si las casillas entre rey y torre se encuentran vacías se realiza el enroque
				if (tab->getPieza(aux1) == nullptr && tab->getPieza(aux2) == nullptr) {
					if (miraryactuar) {
						Pieza* pieza_aux = tab->getPieza(torre_negra_dcha);
						tab->quitarPieza(torre_negra_dcha);
						tab->setPieza(pieza_aux, aux2);
					}
					return true;
				}
			}
		}

		//ENROQUE LARGO
		if (!enroque_corto && tab->getPieza(torre_negra_izq) != nullptr) {
			//La torre que participe en el enroque que se esté intentando realizar no se puede haber movido nunca
			if (tab->getPieza(torre_negra_izq)->checkOrigen()) {

				//Se especifican las posiciones entre el rey y la torre que participa en el enroque
				Pos aux1 = Pos(7, 3);
				Pos aux2 = Pos(7, 2);
				Pos aux3 = Pos(7, 1);

				//Si las casillas entre rey y torre se encuentran vacías se realiza el enroque
				if (tab->getPieza(aux1) == nullptr && tab->getPieza(aux2) == nullptr && tab->getPieza(aux3) == nullptr) {
					if (miraryactuar) {
						Pieza* pieza_aux = tab->getPieza(torre_negra_izq);
						tab->quitarPieza(torre_negra_izq);
						tab->setPieza(pieza_aux, aux1);
					}
					return true;
				}
			}
		}
	}
	return false;
}

//LAS CORONACIONES BLANCAS Y NEGRAS SE TRATAN INDEPENDIENTEMENTES, A LA ESPERA DE VER COMO SON TRATADAS LAS PIEZAS

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
			tablero.quitarPieza(pos_final);
			pieza_aux = new Dama(pieza_elegida->getColor());
			tablero.setPieza(pieza_aux, pos_final);
			break;
		case 4:
			tablero.quitarPieza(pos_final);
			pieza_aux = new Alfil(pieza_elegida->getColor());
			tablero.setPieza(pieza_aux, pos_final);
			break;
		case 5:
			tablero.quitarPieza(pos_final);
			pieza_aux = new Caballo(pieza_elegida->getColor());
			tablero.setPieza(pieza_aux, pos_final);
			break;
		case 6:
			tablero.quitarPieza(pos_final);
			pieza_aux = new Torre(pieza_elegida->getColor());
			tablero.setPieza(pieza_aux, pos_final);
			break;
		default:
			cout << endl << "Pieza no valida. ";
		}
	} while (elegido > 6 || elegido < 3);
}

void Juego::setValores(bool t) {
	grande = t;
	if (t) {
		AJUSTE_X = 86;
		AJUSTE_Y = 813;
		LIM_TABLERO = 728;
		LIM_CASILLA = 91;
		tablero.setValores(t);
		
	}
	else {
		AJUSTE_X = 58;
		AJUSTE_Y = 540;
		LIM_TABLERO = 480;
		LIM_CASILLA = 60;
		tablero.setValores(t);
	}
}

bool Juego::checkJaque(Tablero tab, bool color) {

	//Se busca la posicion del rey del color elegido
	bool exit_loop = false;
	Pos pos_rey, pos_iteracion;
	Pieza* pieza_iteracion;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			pos_iteracion.fila = i;
			pos_iteracion.columna = j;
			pieza_iteracion = tab.getPieza(pos_iteracion); //Para mejorar la claridad del código
			if (pieza_iteracion != nullptr) {
				if (pieza_iteracion->getTipo() == 2 && pieza_iteracion->getColor() == color) {
					pos_rey = pos_iteracion;
					exit_loop = true;
					break;
				}
			}
		}
		if (exit_loop) break; //Maniobra para salir de dos bucles anidados y así optimizar ligeramente el código.
	}

	//Se itera respecto de todas las posiciones del tablero dado para comprobar si, al menos, una de las posciones válidas
	//a las que se pueden mover todas las piezas del color contrario coincide con la del rey del color elegido. 
	//El peón se considera una excepción ya que su forma de comer piezas es distinta a la de moverse.
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			pos_iteracion.fila = i;
			pos_iteracion.columna = j;
			pieza_iteracion = tab.getPieza(pos_iteracion); //Para mejorar la claridad del código
			if (pieza_iteracion != nullptr) {
				if (pieza_iteracion->getColor() != color) {
					if (pieza_iteracion->getTipo() == 1) {
						if (pieza_iteracion->getColor()) { //El peón que se está evaluando es negro
							if ((pos_rey.fila == (pos_iteracion.fila - 1) && pos_rey.columna == (pos_iteracion.columna - 1)) ||
								(pos_rey.fila == (pos_iteracion.fila - 1) && pos_rey.columna == (pos_iteracion.columna + 1))) {
								return true;
							}
						}
						//Si no es negro tiene que ser blanco
						else if ((pos_rey.fila == (pos_iteracion.fila + 1) && pos_rey.columna == (pos_iteracion.columna - 1)) ||
							(pos_rey.fila == (pos_iteracion.fila + 1) && pos_rey.columna == (pos_iteracion.columna + 1))) {
							return true;
						}
					}
					//Código para cualquier pieza menos el peón (todas tienen las mismas reglas para comer que para moverse)
					else if (movimientoValido(pieza_iteracion, pos_iteracion, pos_rey, &tab)) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

//Cuando es true se acaba el juego. Se debería juzgar justo después de completar un movimiento válido, 
//si un movimiento provoca que el color contrario no pueda realizar ningún movimiento legal, directamente salta el menú antes de que se pase al siguiente movimiento.
bool Juego::finDeJuego(bool color) {

	Pos pos_iteracion, pos_posible;
	Pieza* pieza_iteracion;
	Tablero tab_aux = tablero;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			pos_iteracion.fila = i;
			pos_iteracion.columna = j;
			pieza_iteracion = tablero.getPieza(pos_iteracion); //Para mejorar la claridad del código
			if (pieza_iteracion != nullptr) {
				if (pieza_iteracion->getColor() == color) {
					for (int k = 0; k < 8; k++) {
						for (int l = 0; l < 8; l++) {
							pos_posible.fila = k;
							pos_posible.columna = l;
							if (movimientoValido(pieza_iteracion, pos_iteracion, pos_posible, &tablero)) {
								tab_aux.quitarPieza(pos_iteracion);
								tab_aux.setPieza(pieza_iteracion, pos_posible);
								if (!checkJaque(tab_aux, color)) {
									return false;
								}
								tab_aux = tablero;
							}
						}
					}
				}
			}
		}
	}
	return true;
}
