#include "Juego.h"
#include "Peon.h"
#include "Rey.h"
#include "Dama.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Torre.h"
#include <iostream>
#include "ETSIDI.h"

using namespace std; //cuidado

Juego::Juego() {

	pieza_elegida = nullptr;
	within_board = false;

	turno_blancas = true;
	turno_negras = false;
	mouse_pressed = false;
	mouse_released = true;
	color_elegido = false;

	alpaso_blancas = false;
	alpaso_negras = false;
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
		pieza_elegida->dibujarArrastrar(mouse_pos, &tablero);
		dibujarPosiblesCasillas();
	}
}

void Juego::dibujarPosiblesCasillas() {
	Pos pos_iteracion;
	Tablero tab = tablero;

	//Se itera a lo largo de todo el tablero en busca de casillas a las que la pieza en movimiento puede moverse legalmente
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			pos_iteracion.fila = i;
			pos_iteracion.columna = j;

			//El movimiento a la casilla estudiada en la iteración es legal
			if (movimientoValido(pieza_elegida, pos_inicial, pos_iteracion, &tablero)) {

				//Se modifica un tablero fantasma para comprobar que, además, el movimiento planteado no pone al rey de su color en jaque
				tab.setPieza(pieza_elegida, pos_iteracion);
				tab.quitarPieza(pos_inicial);
				if (!checkJaque(tab, pieza_elegida->getColor())) {
					tablero.dibujarPosibleCasilla(pos_iteracion);
				}
				tab = tablero;
			}
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
	if (mouse_pressed && within_board) { //pos_inicial.fila y pos_inicial.columna deben ser las de aquella casilla donde se ha clicado pero NO soltado el clic
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
	if (within_board) { //Acciones a ejecutar si se ha clicado/dejado de clicar dentro del tablero

		if (!color_elegido && turno_blancas) { //Turno de las blancas

			//Se clica en una casilla que contiene pieza para cogerla e iniciar el movimiento
			if (mouse_pressed && tablero.getPieza(pos_inicial) != nullptr && pieza_elegida == nullptr) {
				pieza_elegida = tablero.getPieza(pos_inicial);
			}
			//Se suelta el clic en una casilla válida de la pieza que mueves (tienes que estar moviendo una pieza)
			//El movimiento no puede provocar que el color pase a estar en jaque
			if (mouse_released && (pieza_elegida != nullptr) && movimientoValido(pieza_elegida, pos_inicial, pos_final, &tablero) 
				&& !checkJaque(tablero_fantasma, pieza_elegida->getColor())) {

				//Se actualiza el tablero
				tablero.setPieza(pieza_elegida, pos_final);
				ETSIDI::play("Musica/SoltarPieza.mp3");

				if (finDeJuego(true)) {
					cout << "GG" << endl;
					if (checkJaque(tablero, true)) {
						cout << "Victoria de las blancas por jaque mate!" << endl;
					}
					else {
						cout << "Tablas por rey ahogado! (provocado por las blancas)" << endl;
					}
				}

				//Tanto el estado de origen de la pieza en movimiento como el indicador de que se 
				//puede comer al paso se reinician cuando se completa un movimiento válido
				pieza_elegida->setOrigenFalse();
				alpaso_blancas = false;

				//Se finalizó el movimiento, por lo que se devuelve el puntero a null y se deshacen los cambios del tablero fantasma
				pieza_elegida = nullptr;
				tablero_fantasma = tablero;

				//Gestión de turnos
				turno_blancas = false;
				turno_negras = true;
			}
			//Si estás moviendo una pieza y el movimiento no es correcto o este provoca que el color pase a estar en jaque, se devuelve a su casilla original
			if (mouse_released && (pieza_elegida != nullptr) && (!movimientoValido(pieza_elegida, pos_inicial, pos_final, &tablero)
				|| checkJaque(tablero_fantasma, pieza_elegida->getColor()))) {

				//Se devuelve a la casilla original
				tablero.setPieza(pieza_elegida, pos_inicial);

				//Se finalizó el movimiento, por lo que se devuelve el puntero a null y se deshacen los cambios del tablero fantasma
				pieza_elegida = nullptr;
				tablero_fantasma = tablero;
			}
		}

		if (color_elegido && turno_negras) { //Turno de las negras

			//Se clica en una casilla que contiene pieza para cogerla e iniciar el movimiento
			if (mouse_pressed && tablero.getPieza(pos_inicial) != nullptr && pieza_elegida == nullptr) {
				pieza_elegida = tablero.getPieza(pos_inicial);
			}
			//Se suelta el clic en una casilla válida de la pieza que mueves (tienes que estar moviendo una pieza)
			//El movimiento no puede provocar que el color pase a estar en jaque
			if (mouse_released && (pieza_elegida != nullptr) && movimientoValido(pieza_elegida, pos_inicial, pos_final, &tablero)
				&& !checkJaque(tablero_fantasma, pieza_elegida->getColor())) {

				//Se actualiza el tablero
				tablero.setPieza(pieza_elegida, pos_final);
				ETSIDI::play("Musica/SoltarPieza.mp3");

				if (finDeJuego(false)) {
					cout << "GG" << endl;
					if (checkJaque(tablero, false)) {
						cout << "Victoria de las negras por jaque mate!" << endl;
					}
					else {
						cout << "Tablas por rey ahogado! (provocado por las negras)" << endl;
					}
				}//Se reinician los indicadores de que la pieza se ha movido al movido al menos una vez y de que se puede comer al paso al completarse un movimiento válido

				//Tanto el estado de origen de la pieza en movimiento como el indicador de que se 
				//puede comer al paso se reinician cuando se completa un movimiento válido
				pieza_elegida->setOrigenFalse();
				alpaso_negras = false;

				//Se finalizó el movimiento, por lo que se devuelve el puntero a null y se deshacen los cambios del tablero fantasma
				pieza_elegida = nullptr;
				tablero_fantasma = tablero;

				//El indicador de que se puede comer al paso se reinicia cuando se completa un movimiento válido


				//Gestión de turnos
				turno_blancas = true;
				turno_negras = false;
			}
			//Si estás moviendo una pieza y el movimiento no es correcto o este provoca que el color pase a estar en jaque, se devuelve a su casilla original
			if (mouse_released && (pieza_elegida != nullptr) && (!movimientoValido(pieza_elegida, pos_inicial, pos_final, &tablero)
				|| checkJaque(tablero_fantasma, pieza_elegida->getColor()))) {

				//Se devuelve a la casilla original
				tablero.setPieza(pieza_elegida, pos_inicial);

				//Se finalizó el movimiento, por lo que se devuelve el puntero a null y se deshacen los cambios del tablero fantasma
				pieza_elegida = nullptr;
				tablero_fantasma = tablero;
			}
		}
	}

	//Si se suelta el clic fuera del tablero llevando una pieza no se confirma el movimiento y devuelve la pieza a la casilla inicial previa al movimiento
	if (!within_board && mouse_released && (pieza_elegida != nullptr)) {

		//Se devuelve a la casilla original
		tablero.setPieza(pieza_elegida, pos_inicial);

		//Se finalizó el movimiento, por lo que se devuelve el puntero a null y se deshacen los cambios del tablero fantasma
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

	//COMER AL PASO DE BLANCAS
	if (alpaso_blancas) { //el peon negro puede ser comido por el blanco
		//se comprueba si la pieza elegida es un peon blanco, esta en la misma fila que el peon que puede ser comido al paso, y en una columna colindante a la suya
		if (pieza->getTipo() == 1 && !pieza->getColor() && pos_inicio.fila == salida_doble.fila
			&& (pos_inicio.columna == (salida_doble.columna + 1) || pos_inicio.columna == (salida_doble.columna - 1))) {
			//se confirma si se realiza un movimiento valido de comer al paso comprobando la posicion final del peon blanco con la posicion del peon negro
			if (pos_fin.fila == salida_doble.fila + 1 && pos_fin.columna == salida_doble.columna) {
				if (mouse_released) {//comprueba si se ha soltado el raton
					tab->quitarPieza(salida_doble); //eliminamos del tablero el peon comido al paso
				}
				return true;
			}
		}
	}

	//COMER AL PASO DE NEGRAS
	if (alpaso_negras) { //el peon blanco puede ser comido por el negro
		//se comprueba si la pieza elegida es un peon negro, esta en la misma fila que el peon que puede ser comido al paso, y en una columna colindante a la suya
		if (pieza->getTipo() == 1 && pieza->getColor() && pos_inicio.fila == salida_doble.fila
			&& (pos_inicio.columna == (salida_doble.columna + 1) || pos_inicio.columna == (salida_doble.columna - 1))) {
			//se confirma si se realiza un movimiento valido de comer al paso comprobando la posicion final del peon negro con la posicion del peon blanco
			if (pos_fin.fila == salida_doble.fila - 1 && pos_fin.columna == salida_doble.columna) {
				if (mouse_released) {//comprueba si se ha soltado el raton
					tab->quitarPieza(salida_doble);//eliminamos del tablero el peon comido al paso
				}
				return true;
			}
		}
	}

	//SALIDA DE 2 DEL PEON
	if (pieza->getTipo() == 1 && pieza->getOrigen()) { //La pieza es un peón intentando hacer su primer movimiento
		//se crean posiciones auxiliares que representan la casilla entre la casilla inicial y final del peon cuando avanza dos posiciones
		Pos pos_aux_negras = Pos(pos_inicio.fila - 1, pos_inicio.columna); 
		Pos pos_aux_blancas = Pos(pos_inicio.fila + 1, pos_inicio.columna);

		//PEON BLANCO. Se mueve dos posiciones hacia delante, esa casilla está vacía y la anterior también
		if (pos_fin.fila == pos_inicio.fila + 2 && pos_inicio.columna == pos_fin.columna
			&& tab->getPieza(pos_fin) == nullptr && tab->getPieza(pos_aux_blancas) == nullptr) { 
			salida_doble = pos_fin; //se guarda su posicion final para que el equipo rival pueda comer al paso
			alpaso_negras = true;//declara que el equipo rival puede comer al paso en el siguiente turno
			return true;
		}

		//PEON NEGRO. Se mueve dos posiciones hacia delante, esa casilla está vacía y la anterior también
		if (pos_fin.fila == pos_inicio.fila - 2 && pos_inicio.columna == pos_fin.columna 
			&& tab->getPieza(pos_fin) == nullptr && tab->getPieza(pos_aux_negras) == nullptr) {
			salida_doble = pos_fin;//se guarda su posicion final para que el equipo rival pueda comer al paso
			alpaso_blancas = true;//declara que el equipo rival puede comer al paso en el siguiente turno
			return true;
		}
	}

	//ENROQUES BLANCOS
	if (pieza->getTipo() == 2 && !pieza->getColor() && pieza->getOrigen()) { //Se tiene que estar intentando mover el rey blanco y debe tratarse de su primer movimiento

		//ENROQUE CORTO. Se cumple que la posicion final del rey es la del enroque corto, sin tener en cuenta aun el resto de condiciones
		if (pos_fin.columna == pos_inicio.columna + 2 && pos_fin.fila == pos_inicio.fila) {
			return enroque(tab, false, true);//llama a la funcion enroque pasando el tablero, el color del rey y el tipo de enroque a realizar
		}

		//ENROQUE LARGO. Se cumple que la posicion final del rey es la del enroque largo, sin tener en cuenta aun el resto de condiciones
		if (pos_fin.columna == pos_inicio.columna - 2 && pos_fin.fila == pos_inicio.fila) {
			return enroque(tab, false, false);//llama a la funcion enroque pasando el tablero, el color del rey y el tipo de enroque a realizar
		}
	}

	//ENROQUES NEGROS
	if (pieza->getTipo() == 2 && pieza->getColor() && pieza->getOrigen()) { //Se tiene que estar intentando mover el rey blanco y debe tratarse de su primer movimiento

		//ENROQUE CORTO. Se cumple que la posicion final del rey es la del enroque corto, sin tener en cuenta aun el resto de condiciones
		if (pos_fin.columna == pos_inicio.columna + 2 && pos_fin.fila == pos_inicio.fila) {
			return enroque(tab, true, true);//llama a la funcion enroque pasando el tablero, el color del rey y el tipo de enroque a realizar
		}

		//ENROQUE LARGO. Se cumple que la posicion final del rey es la del enroque largo, sin tener en cuenta aun el resto de condiciones
		if (pos_fin.columna == pos_inicio.columna - 2 && pos_fin.fila == pos_inicio.fila) {
			return enroque(tab, true, false);//llama a la funcion enroque pasando el tablero, el color del rey y el tipo de enroque a realizar
		}
	}

	//REGLAS NORMALES DE MOVIMIENTO (GESTIONADAS POR LA PIEZA QUE SE INTENTA MOVER)
	if (pieza->comprueba(tab, pos_inicio, pos_fin)) {
		//CONDICION DE CORONACION
		if (mouse_released) {//si se ha soltado el click y el peon ha llegado a la fila en la que este realiza el enroque, se corona
			if (pieza->getTipo() == 1 && !pieza->getColor() && pos_fin.fila == 7)
				coronacion(tab, pos_fin);
			if (pieza->getTipo() == 1 && pieza->getColor() && pos_fin.fila == 0)
				coronacion(tab, pos_fin);
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
			if (tab->getPieza(torre_blanca_dcha)->getOrigen()) {

				//Se especifican las posiciones entre el rey y la torre que participa en el enroque
				Pos aux1 = Pos(0, 6);
				Pos aux2 = Pos(0, 5);

				//Declaración de variables auxiliares para la comprobación de las dos últimas condiciones
				Pos pos_rey_original = Pos(0, 4);
				Tablero tablero_aux = *tab;
				tablero_aux.setPieza(new Rey(color), pos_rey_original);

				//Si las casillas entre rey y torre se encuentran vacías se realiza el enroque
				if (tab->getPieza(aux1) == nullptr && tab->getPieza(aux2) == nullptr) {

					//El rey no puede hacer enroque si se encuentra en jaque
					if (!checkJaque(tablero_aux, color)) {

						//Si una de las casillas por las que el rey pasará o quedará al hacer el enroque, este no es legal
						tablero_aux.setPieza(tablero_aux.getPieza(pos_rey_original), aux1);
						tablero_aux.quitarPieza(pos_rey_original);
						if (checkJaque(tablero_aux, color)) {
							return false;
						}
						tablero_aux.setPieza(tablero_aux.getPieza(aux1), aux2);
						tablero_aux.quitarPieza(aux1);
						if (checkJaque(tablero_aux, color)) {
							return false;
						}

						//Se cumplen todas las condiciones del enroque
						if (mouse_released) { //movimientoValido() se ejecuta se haya o no depositado una pieza en una casilla, de esta forma nos aseguramos que así sea
							tab->setPieza(tab->getPieza(torre_blanca_dcha), aux2);//movemos la torre a la posicion final del enroque
							tab->quitarPieza(torre_blanca_dcha);//quitamos la torre que realiza el enroque de su posicion inicial
						}
						return true;
					}
				}
			}
		}

		//ENROQUE LARGO
		if (!enroque_corto && tab->getPieza(torre_blanca_izq) != nullptr) {

			//La torre que participe en el enroque que se esté intentando realizar no se puede haber movido nunca
			if (tab->getPieza(torre_blanca_izq)->getOrigen()) {

				//Se especifican las posiciones entre el rey y la torre que participa en el enroque
				Pos aux1 = Pos(0, 3);
				Pos aux2 = Pos(0, 2);
				Pos aux3 = Pos(0, 1);

				//Declaración de variables auxiliares para la comprobación de las dos últimas condiciones
				Pos pos_rey_original = Pos(0, 4);
				Tablero tablero_aux = *tab;
				tablero_aux.setPieza(new Rey(color), pos_rey_original);

				//Si las casillas entre rey y torre se encuentran vacías se realiza el enroque
				if (tab->getPieza(aux1) == nullptr && tab->getPieza(aux2) == nullptr && tab->getPieza(aux3) == nullptr) {

					//El rey no puede hacer enroque si se encuentra en jaque
					if (!checkJaque(tablero_aux, color)) {

						//Si una de las casillas por las que el rey pasará o quedará al hacer el enroque, este no es legal
						tablero_aux.setPieza(tablero_aux.getPieza(pos_rey_original), aux1);
						tablero_aux.quitarPieza(pos_rey_original);
						if (checkJaque(tablero_aux, color)) {
							return false;
						}
						tablero_aux.setPieza(tablero_aux.getPieza(aux1), aux2);
						tablero_aux.quitarPieza(aux1);
						if (checkJaque(tablero_aux, color)) {
							return false;
						}
						tablero_aux.setPieza(tablero_aux.getPieza(aux2), aux3);
						tablero_aux.quitarPieza(aux2);
						if (checkJaque(tablero_aux, color)) {
							return false;
						}

						//Se cumplen todas las condiciones del enroque
						if (mouse_released) { //movimientoValido() se ejecuta se haya o no depositado una pieza en una casilla, de esta forma nos aseguramos que así sea
							tab->setPieza(tab->getPieza(torre_blanca_izq), aux1);//movemos la torre a la posicion final del enroque
							tab->quitarPieza(torre_blanca_izq);//quitamos la torre que realiza el enroque de su posicion inicial
						}
						return true;
					}
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
			if (tab->getPieza(torre_negra_dcha)->getOrigen()) {

				//Se especifican las posiciones entre el rey y la torre que participa en el enroque
				Pos aux1 = Pos(7, 6);
				Pos aux2 = Pos(7, 5);

				//Declaración de variables auxiliares para la comprobación de las dos últimas condiciones
				Pos pos_rey_original = Pos(7, 4);
				Tablero tablero_aux = *tab;
				tablero_aux.setPieza(new Rey(color), pos_rey_original);

				//Si las casillas entre rey y torre se encuentran vacías se realiza el enroque
				if (tab->getPieza(aux1) == nullptr && tab->getPieza(aux2) == nullptr) {

					//El rey no puede hacer enroque si se encuentra en jaque
					if (!checkJaque(tablero_aux, color)) {

						//Si una de las casillas por las que el rey pasará o quedará al hacer el enroque, este no es legal
						tablero_aux.setPieza(tablero_aux.getPieza(pos_rey_original), aux1);
						tablero_aux.quitarPieza(pos_rey_original);
						if (checkJaque(tablero_aux, color)) {
							return false;
						}
						tablero_aux.setPieza(tablero_aux.getPieza(aux1), aux2);
						tablero_aux.quitarPieza(aux1);
						if (checkJaque(tablero_aux, color)) {
							return false;
						}

						//Se cumplen todas las condiciones del enroque
						if (mouse_released) { //movimientoValido() se ejecuta se haya o no depositado una pieza en una casilla, de esta forma nos aseguramos que así sea
							tab->setPieza(tab->getPieza(torre_negra_dcha), aux2);//movemos la torre a la posicion final del enroque
							tab->quitarPieza(torre_negra_dcha);//quitamos la torre que realiza el enroque de su posicion inicial
						}
						return true;
					}
				}
			}
		}

		//ENROQUE LARGO
		if (!enroque_corto && tab->getPieza(torre_negra_izq) != nullptr) {

			//La torre que participe en el enroque que se esté intentando realizar no se puede haber movido nunca
			if (tab->getPieza(torre_negra_izq)->getOrigen()) {

				//Se especifican las posiciones entre el rey y la torre que participa en el enroque
				Pos aux1 = Pos(7, 3);
				Pos aux2 = Pos(7, 2);
				Pos aux3 = Pos(7, 1);

				//Declaración de variables auxiliares para la comprobación de las dos últimas condiciones
				Pos pos_rey_original = Pos(7, 4);
				Tablero tablero_aux = *tab;
				tablero_aux.setPieza(new Rey(color), pos_rey_original);

				//Si las casillas entre rey y torre se encuentran vacías se realiza el enroque
				if (tab->getPieza(aux1) == nullptr && tab->getPieza(aux2) == nullptr && tab->getPieza(aux3) == nullptr) {

					//El rey no puede hacer enroque si se encuentra en jaque
					if (!checkJaque(tablero_aux, color)) {

						//Si una de las casillas por las que el rey pasará o quedará al hacer el enroque, este no es legal
						tablero_aux.setPieza(tablero_aux.getPieza(pos_rey_original), aux1);
						tablero_aux.quitarPieza(pos_rey_original);
						if (checkJaque(tablero_aux, color)) {
							return false;
						}
						tablero_aux.setPieza(tablero_aux.getPieza(aux1), aux2);
						tablero_aux.quitarPieza(aux1);
						if (checkJaque(tablero_aux, color)) {
							return false;
						}
						tablero_aux.setPieza(tablero_aux.getPieza(aux2), aux3);
						tablero_aux.quitarPieza(aux2);
						if (checkJaque(tablero_aux, color)) {
							return false;
						}

						//Se cumplen todas las condiciones del enroque
						if (mouse_released) { //movimientoValido() se ejecuta se haya o no depositado una pieza en una casilla, de esta forma nos aseguramos que así sea
							tab->setPieza(tab->getPieza(torre_negra_izq), aux1);//movemos la torre a la posicion final del enroque
							tab->quitarPieza(torre_negra_izq);//quitamos la torre que realiza el enroque de su posicion inicial
						}
						return true;
					}
				}
			}
		}
	}
	return false;
}

//la funcion pide al usuario elegir la pieza que desea por haber coronado un peon, siendo representada en el tablero, quedando este acualizado
void Juego::coronacion(Tablero* tab, Pos pos_coronacion) {
	int elegido = 0; //sirve para elegir la pieza que queremos, y para mantenernos en el bucle si no escogemos una pieza valida

	//Piezas que puede elegir el jugador en la coronacion
	cout << endl << "Dama: 3" << endl;
	cout << "Alfil: 4" << endl;
	cout << "Caballo: 5" << endl;
	cout << "Torre: 6" << endl;

	do { //mientras no se elija una pieza valida no se sale del bucle
		elegido = 0;
		cout << "Elige que pieza quieres: ";
		cin >> elegido;
		switch (elegido) {
		case 3:
			pieza_elegida = new Dama(pieza_elegida->getColor());//la pieza seleccionada pasa de ser un peon a ser una dama
			tab->setPieza(pieza_elegida, pos_coronacion);//se situa la nueva pieza en la casilla en la que se ha coronado el peon
			break;
		case 4:
			pieza_elegida = new Alfil(pieza_elegida->getColor());//la pieza seleccionada pasa de ser un peon a ser un alfil
			tab->setPieza(pieza_elegida, pos_coronacion);//se situa la nueva pieza en la casilla en la que se ha coronado el peon
			break;
		case 5:
			pieza_elegida = new Caballo(pieza_elegida->getColor());//la pieza seleccionada pasa de ser un peon a ser un caballo
			tab->setPieza(pieza_elegida, pos_coronacion);//se situa la nueva pieza en la casilla en la que se ha coronado el peon
			break;
		case 6:
			pieza_elegida = new Torre(pieza_elegida->getColor());//la pieza seleccionada pasa de ser un peon a ser una torre
			tab->setPieza(pieza_elegida, pos_coronacion);//se situa la nueva pieza en la casilla en la que se ha coronado el peon
			break;
		default:
			cout << endl << "Pieza no valida. ";
		}
	} while (elegido > 6 || elegido < 3);
}

void Juego::setValores(bool t) {
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