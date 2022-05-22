//Librerías
#include "Tablero.h"
#include "Casilla.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <iostream>
#include <algorithm>

<<<<<<< Updated upstream
//Constantes predefinidas
#define AJUSTE_X 86
#define AJUSTE_Y 813
#define LIM_TABLERO 728
#define LIM_CASILLA 91

=======
>>>>>>> Stashed changes
/**
 * @brief Construct a new Tablero:: Tablero object
 * 
 */
Tablero::Tablero() {
	//Atributos que tienen que ver con lo gráfico
	lado = 2.5f;
	fila_raton = 0;
	columna_raton = 0;
	fila_movimiento = 0;
	columna_movimiento = 0;
	mouse_pressed = 0;
	mouse_released = 1;
	puntero_aux = NULL;
	within_board = FALSE;
	turno_negras = false;
	turno_blancas = true; //Blancas juegan primero

<<<<<<< Updated upstream
=======
	AJUSTE_X = 86;
	AJUSTE_Y = 813;
	LIM_TABLERO = 728;
	LIM_CASILLA = 91;

>>>>>>> Stashed changes
	//Elementos del juego
	Casilla tablero[8][8]; //Matriz de casillas
	Pieza piezas[32]; //Array de piezas
}

/**
 * @brief Destroy the Tablero:: Tablero object
 * 
 */
Tablero::~Tablero() {

}

/**
 * @brief Esta función sincroniza las casillas con su posición en pantalla
 * 
 */
<<<<<<< Updated upstream
void Tablero::Inicializar() {
=======
void Tablero::inicializar() {
>>>>>>> Stashed changes
	//Igualamos a constantes predefinidas
	int x = AJUSTE_X;
	int y = AJUSTE_Y;
	//Bucle anidado para cuadrar posiciones
	for (int i = 0; i < 8; i++) {
		x += (LIM_CASILLA * i);
		for (int j = 0; j < 8; j++) {
			y -= (LIM_CASILLA * j);
			tablero[i][j] = Casilla(i, j);
<<<<<<< Updated upstream
			tablero[i][j].SetPosicion(x, y); //obtenemos la casilla que nos interesa del tablero y la sincronizamos con su posicion
=======
			tablero[i][j].setPosicion(x, y); //obtenemos la casilla que nos interesa del tablero y la sincronizamos con su posicion
>>>>>>> Stashed changes
		}
	}
}

/**
 * @brief Esta funcion crea las piezas y las añade al array de piezas del tablero de forma ORDENADA
 * 
 */
void Tablero::crearPiezas() {
	int i = 0;
	for (i = i; i < 8; i++) {
<<<<<<< Updated upstream
		piezas[i] = Pieza(1); //Peones blancos (1) - tamaño array: 8 
	}
	piezas[i] = Pieza(2); //Rey blanco (2) - tamaño array: 9
	i++;
	piezas[i] = Pieza(3); //Dama blanca (3) - tamaño array: 10  
	i++;
	for (i = i; i < 12; i++) {
		piezas[i] = Pieza(4); //Alfiles blancos (4) - tamaño array: 12
	}
	for (i = i; i < 14; i++) {
		piezas[i] = Pieza(5); //Caballos blancos (5) - tamaño array: 14
	}
	for (i = i; i < 16; i++) {
		piezas[i] = Pieza(6); //Torres blancas (6) - tamaño array: 16
	}
	for (i = i; i < 24; i++) {
		piezas[i] = Pieza(7); //Peones negros (7) - tamaño array: 24
	}
	piezas[i] = Pieza(8); //Rey negro (8) - tamaño array: 25
	i++;
	piezas[i] = Pieza(9); //Dama negra (9) - tamaño array: 26
	i++;
	for (i = i; i < 28; i++) {
		piezas[i] = Pieza(10); //Alfiles negros (10) - tamaño array: 28
	}
	for (i = i; i < 30; i++) {
		piezas[i] = Pieza(11); //Caballos negros(11) - tamaño array: 30
	}
	for (i = i; i < 32; i++) {
		piezas[i] = Pieza(12); //Torres negras(12) - tamaño array: 32
=======
		piezas[i] = Pieza(1); //Peones blancos (1) - tamaño array: 8
		piezas[i].setTamano(AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA);
	}
	piezas[i] = Pieza(2); //Rey blanco (2) - tamaño array: 9
	piezas[i].setTamano(AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA);
	i++;
	piezas[i] = Pieza(3); //Dama blanca (3) - tamaño array: 10
	piezas[i].setTamano(AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA);
	i++;
	for (i = i; i < 12; i++) {
		piezas[i] = Pieza(4); //Alfiles blancos (4) - tamaño array: 12
		piezas[i].setTamano(AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA);
	}
	for (i = i; i < 14; i++) {
		piezas[i] = Pieza(5); //Caballos blancos (5) - tamaño array: 14
		piezas[i].setTamano(AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA);
	}
	for (i = i; i < 16; i++) {
		piezas[i] = Pieza(6); //Torres blancas (6) - tamaño array: 16
		piezas[i].setTamano(AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA);
	}
	for (i = i; i < 24; i++) {
		piezas[i] = Pieza(7); //Peones negros (7) - tamaño array: 24
		piezas[i].setTamano(AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA);
	}
	piezas[i] = Pieza(8); //Rey negro (8) - tamaño array: 25
	piezas[i].setTamano(AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA);
	i++;
	piezas[i] = Pieza(9); //Dama negra (9) - tamaño array: 26
	piezas[i].setTamano(AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA);
	i++;
	for (i = i; i < 28; i++) {
		piezas[i] = Pieza(10); //Alfiles negros (10) - tamaño array: 28
		piezas[i].setTamano(AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA);
	}
	for (i = i; i < 30; i++) {
		piezas[i] = Pieza(11); //Caballos negros(11) - tamaño array: 30
		piezas[i].setTamano(AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA);
	}
	for (i = i; i < 32; i++) {
		piezas[i] = Pieza(12); //Torres negras(12) - tamaño array: 32
		piezas[i].setTamano(AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA);
>>>>>>> Stashed changes
	}
}

/**
 * @brief Esta función coloca las piezas en su lugar dado el array de piezas del juego ORDENADO
 * 
 */
<<<<<<< Updated upstream
void Tablero::InicializarPiezas() {
=======
void Tablero::inicializarPiezas() {
>>>>>>> Stashed changes
	//Recorro mi array de piezas y las voy colocando
	for (int i = 0; i < 32; i++) {
		Pieza miPieza = piezas[i]; //pieza de la iteración actual
		int miFila = miPieza.getFilaOrigen(); //fila donde debe empezar el juego

		//PIEZAS CUYO TIPO SE REPITEN
		if (i < 8) {
<<<<<<< Updated upstream
			tablero[miFila][i].SetPieza(miPieza); //Peones blancos
		}
		else if (i == 10 || i == 26) {
			tablero[miFila][2].SetPieza(miPieza); //Alfiles mitad izquierda
		}
		else if (i == 11 || i == 27) {
			tablero[miFila][5].SetPieza(miPieza); //Alfiles mitad derecha
		}
		else if (i == 12 || i == 28) {
			tablero[miFila][1].SetPieza(miPieza); //Caballos mitad izquierda
		}
		else if (i == 13 || i == 29) {
			tablero[miFila][6].SetPieza(miPieza); //Caballos mitad derecha
		}
		else if (i == 14 || i == 30) {
			tablero[miFila][0].SetPieza(miPieza); //Torres mitad izquierda
		}
		else if (i == 15 || i == 31) {
			tablero[miFila][7].SetPieza(miPieza); //Torres mitad derecha
		}
		else if (i >= 16 && i < 24) {
			tablero[miFila][i - 16].SetPieza(miPieza); //Peones negros
=======
			tablero[miFila][i].setPieza(miPieza); //Peones blancos
		}
		else if (i == 10 || i == 26) {
			tablero[miFila][2].setPieza(miPieza); //Alfiles mitad izquierda
		}
		else if (i == 11 || i == 27) {
			tablero[miFila][5].setPieza(miPieza); //Alfiles mitad derecha
		}
		else if (i == 12 || i == 28) {
			tablero[miFila][1].setPieza(miPieza); //Caballos mitad izquierda
		}
		else if (i == 13 || i == 29) {
			tablero[miFila][6].setPieza(miPieza); //Caballos mitad derecha
		}
		else if (i == 14 || i == 30) {
			tablero[miFila][0].setPieza(miPieza); //Torres mitad izquierda
		}
		else if (i == 15 || i == 31) {
			tablero[miFila][7].setPieza(miPieza); //Torres mitad derecha
		}
		else if (i >= 16 && i < 24) {
			tablero[miFila][i - 16].setPieza(miPieza); //Peones negros
>>>>>>> Stashed changes
		}

		//PIEZAS ÚNICAS (Reyes y damas)
		else {
			if(miPieza.GetTipo()==2){
				posReyB = miPieza.getOrigen();
			}
			if(miPieza.GetTipo()==8){
				posReyN = miPieza.getOrigen();
			}
			int miColumna = miPieza.getColumnaOrigen(); //columna donde debe empezar el juego
<<<<<<< Updated upstream
			tablero[miFila][miColumna].SetPieza(miPieza.GetTipo());
=======
			tablero[miFila][miColumna].setPieza(miPieza.GetTipo());
>>>>>>> Stashed changes
		}
	}
}


/**
 * @brief Esta función muestra el tablero por pantalla
 * 
 */
<<<<<<< Updated upstream
void Tablero::DibujarTablero() { //Dibuja estados
=======
void Tablero::dibujarTablero() { //Dibuja estados
>>>>>>> Stashed changes
	//CASILLAS DEL TABLERO
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//tablero[i][j].SetColor(i, j); //posible traslado a Inicializar //Puede ser interesante mantenerlo para posibles movimientos.

			//getCasilla(i, j).Dibujar();
			//getCasilla(i, j).dibujarPosible();
<<<<<<< Updated upstream
			tablero[i][j].Dibujar();
=======
			tablero[i][j].dibujar();
>>>>>>> Stashed changes
			tablero[i][j].dibujarPosible();
		}
	}

	//BORDES DEL TABLERO
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/maderaV.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);//Borde izquierdo del tablero
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(0 * lado - lado / 2 - 0.8 * lado, 0 * lado - lado / 2 - 0.8 * lado);
	glTexCoord2d(1, 1); glVertex2f(0 * lado - lado / 2, 0 * lado - lado / 2);
	glTexCoord2d(1, 0); glVertex2f(0 * lado - lado / 2, 7 * lado + lado / 2);
	glTexCoord2d(0, 0); glVertex2f(0 * lado - lado / 2 - 0.8 * lado, 7 * lado + lado / 2 + 0.8 * lado);
	glEnd();
	glBegin(GL_POLYGON);//Borde derecho del tablero
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(7 * lado + lado / 2, 0 * lado - lado / 2);
	glTexCoord2d(1, 1); glVertex2f(7 * lado + lado / 2 + 0.8 * lado, 0 * lado - lado / 2 - 0.8 * lado);
	glTexCoord2d(1, 0); glVertex2f(7 * lado + lado / 2 + 0.8 * lado, 7 * lado + lado / 2 + 0.8 * lado);
	glTexCoord2d(0, 0); glVertex2f(7 * lado + lado / 2, 7 * lado + lado / 2);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/maderaH.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);//Borde inferior del tablero
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(0 * lado - lado / 2 - 0.8 * lado, 0 * lado - lado / 2 - 0.8 * lado);
	glTexCoord2d(1, 1); glVertex2f(7 * lado + lado / 2 + 0.8 * lado, 0 * lado - lado / 2 - 0.8 * lado);
	glTexCoord2d(1, 0); glVertex2f(7 * lado + lado / 2, 0 * lado - lado / 2);
	glTexCoord2d(0, 0); glVertex2f(0 * lado - lado / 2, 0 * lado - lado / 2);
	glEnd();
	glBegin(GL_POLYGON);//Borde superior del tablero
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(0 * lado - lado / 2, 7 * lado + lado / 2);
	glTexCoord2d(1, 1); glVertex2f(7 * lado + lado / 2, 7 * lado + lado / 2);
	glTexCoord2d(1, 0); glVertex2f(7 * lado + lado / 2 + 0.8 * lado, 7 * lado + lado / 2 + 0.8 * lado);
	glTexCoord2d(0, 0); glVertex2f(0 * lado - lado / 2 - 0.8 * lado, 7 * lado + lado / 2 + 2);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

/**
 * @brief Esta función muestra las piezas por pantalla
 * 
 */
<<<<<<< Updated upstream
void Tablero::DibujarPiezas() {
=======
void Tablero::dibujarPiezas() {
>>>>>>> Stashed changes
	float x = AJUSTE_X;
	float y = AJUSTE_Y;
	for (int i = 0; i < 8; i++) {
		y -= (LIM_CASILLA - 1);
		for (int j = 0; j < 8; j++) {
			x += (LIM_CASILLA - 1);
<<<<<<< Updated upstream
			if (tablero[i][j].GetEstado()) {
				Pieza pieza = tablero[i][j].GetPieza();
=======
			if (tablero[i][j].getEstado()) {
				Pieza pieza = tablero[i][j].getPieza();
				pieza.setTamano(AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA);
>>>>>>> Stashed changes
				pieza.Dibujar(x, y, 1);
			}
		}
		x = AJUSTE_X;
	}
}

/**
 * @brief Esta función settea los parámetros referidos al ratón necesarios para la actualización de piezas. Estos parámetros se obtienen de Main utilizando la librería glut.
 * 
 * @param x int coordenada x del raton a "tiempo real" (cada 0.025 segundos)
 * @param y int coordenada y del raton a "tiempo real" (cada 0.025 segundos)
 * @param pressed bool se activa al pulsarse el clic
 * @param released se activa al soltarse el clic
 */
<<<<<<< Updated upstream
void Tablero::SetMouse(int x, int y, bool pressed, bool released) {
=======
void Tablero::setMouse(int x, int y, bool pressed, bool released) {
>>>>>>> Stashed changes
	mouse_pos.fila = x;
	mouse_pos.columna = y;
	mouse_pressed = pressed;
	mouse_released = released;
}

/**
 * @brief 
 * 
 * @return Pieza 
 */
<<<<<<< Updated upstream
Pieza Tablero::GetPieza() {
=======
Pieza Tablero::getPieza() {
>>>>>>> Stashed changes
	return *puntero_aux;
}

/**
 * @brief Esta función devuelve la posición del mouse
 * 
 * @return Pos posición del mouse
 */
<<<<<<< Updated upstream
Pos Tablero::GetMousePos() {
=======
Pos Tablero::getMousePos() {
>>>>>>> Stashed changes
	return mouse_pos;
}

/**
 * @brief Actualiza la pieza de la casilla a la que se va a mover la pieza con dicha pieza (se llama a la función cuando ya se ha confirmado que el movimiento es correcto)
 * 
 */
<<<<<<< Updated upstream
void Tablero::CambiarPieza() {
	tablero[pos_final.fila][pos_final.columna].SetPieza(*puntero_aux);
=======
void Tablero::cambiarPieza() {
	tablero[pos_final.fila][pos_final.columna].setPieza(*puntero_aux);
>>>>>>> Stashed changes
	glutPostRedisplay();
}

/**
 * @brief Esta función aplica las reglas de la pieza actual y devuelve el array de casillas posibles
 * 
 * @param pieza a la que se le aplican las reglas
 * @param pos_inicial posición desde la cual se le aplican las reglas
 * @return std::vector<Casilla> vector de casillas resultantes al aplicar las reglas desde la posición dada
 */
std::vector<Casilla> Tablero::aplicaReglas(Pieza pieza, Pos pos_inicial) {
	vector<Casilla> res;
	Pos miregla;
	int tam = pieza.getReglas().size();
	int mifila;
	int micol;
	for (int i = 0; i < tam; i++) {
		//regla en cada iteración del bucle
		miregla = pieza.getReglas().at(i);
		//coordenadas resultantes al aplicar las reglas
		mifila = pos_inicial.fila + miregla.fila;
		micol = pos_inicial.columna + miregla.columna;

		if (mifila < 0 || mifila > 7 || micol < 0 || micol>7) {
			continue;
		}
		else {
			res.push_back(tablero[mifila][micol]);//inserto la casilla con las coordenadas calculadas en el array a devolver
		}
	}
	return res;
}

/**
 * @brief Esta función comprueba si el movimiento deseado es correcto o no
 * 
 * @param pieza cuyo movimiento queremos comprobar si es correcto
 * @param pos_inicial posición desde la cual validamos si el movimiento es correcto
 * @param pos_final posición a la que se pretende mover la pieza
 * @return true cuando el movimiento se acepta
 * @return false cuando el movimiento no se acepta
 */
bool Tablero::comprueba(Pieza pieza, Pos pos_inicial, Pos pos_final) {
	std::vector<Casilla> miscasillas = aplicaReglas(pieza, pos_inicial); //casillas a las que puedo ir con mi pieza en posicion_inicial
	Casilla casilla_final = tablero[pos_final.fila][pos_final.columna];
<<<<<<< Updated upstream
	if (std::find(miscasillas.begin(), miscasillas.end(), casilla_final) != miscasillas.end()) {
		//Comprobamos que en la casilla que quiero poner mi pieza no tengo otra ya (DEL MISMO COLOR).
		if (casilla_final.GetEstado() && pieza.getColor() == casilla_final.GetPieza().getColor()) {
=======
	/*
	if (blancas_en_jaque) {
		bool flag=true;
		Casilla tablero_aux[8][8];
		//hacemos una copia del tablero para simular el movimiento de pieza a pos_final y comprobar si se soluciona el jaque
		//std::copy(std::begin(tablero), std::end(tablero), std::begin(tablero_aux));
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				tablero_aux[i][j] = tablero[i][j];
			}
		}
		//la elimino de donde estaba
		tablero_aux[pos_inicial.fila][pos_inicial.columna].quitarPieza();
		//la seteo en el nuevo sitio
		tablero_aux[pos_final.fila][pos_final.columna].setPieza(pieza);
		
		//recorro el tablero para coger las piezas del otro color
		for (int l = 0; l < 8; l++) {
			for (int m = 0; m < 8; m++) {
				if (tablero_aux[l][m].getEstado() && (tablero_aux[l][m].getPieza().getColor() != pieza.getColor())) {
					Pos pos_iteracion;
					pos_iteracion.fila = l;
					pos_iteracion.columna = m;
					if (checkJaque(posReyB, tablero_aux[l][m].getPieza(), pos_iteracion)) {
						return false;
					}
				}
			}
		}
		return flag;
	}

	if (negras_en_jaque) {
		Casilla tablero_aux[8][8];
		//hacemos una copia del tablero para simular el movimiento de pieza a pos_final y comprobar si se soluciona el jaque
		//std::copy(std::begin(tablero), std::end(tablero), std::begin(tablero_aux));
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				tablero_aux[i][j] = tablero[i][j];
			}
		}
		//la elimino de donde estaba
		tablero_aux[pos_inicial.fila][pos_inicial.columna].quitarPieza();
		//la seteo en el nuevo sitio
		tablero_aux[pos_final.fila][pos_final.columna].setPieza(pieza);

		for (int l = 0; l < 8; l++) {
			for (int m = 0; m < 8; m++) {
				if (tablero_aux[l][m].getEstado() && (tablero_aux[l][m].getPieza().getColor() != pieza.getColor())) {
					Pos pos_iteracion;
					pos_iteracion.fila = l;
					pos_iteracion.columna = m;
					if (checkJaque(posReyN, tablero_aux[l][m].getPieza(), pos_iteracion)) {
						return false;
					}
				}
			}
		}
	}*/

	if (std::find(miscasillas.begin(), miscasillas.end(), casilla_final) != miscasillas.end()) {
		//Comprobamos que en la casilla que quiero poner mi pieza no tengo otra ya (DEL MISMO COLOR).
		if (casilla_final.getEstado() && pieza.getColor() == casilla_final.getPieza().getColor()) {
>>>>>>> Stashed changes
			return false;
		}

		//find rey en miscasillas

		//PEON BLANCO (1)
		if (pieza.GetTipo() == 1) {

			//el peón quiere moverse a una diagonal
			if (tablero[pos_inicial.fila + 1][pos_inicial.columna - 1] == casilla_final || tablero[pos_inicial.fila + 1][pos_inicial.columna + 1] == casilla_final) {
				//hay una pieza de otro color ya (ya hemos comprobado que no sea del mismo)
<<<<<<< Updated upstream
				if (casilla_final.GetEstado()) {
=======
				if (casilla_final.getEstado()) {
>>>>>>> Stashed changes
					return true;
				}
			}

			//el peón quiere moverse recto 1 casilla y tiene que estar vacía
<<<<<<< Updated upstream
			if (tablero[pos_inicial.fila + 1][pos_inicial.columna] == casilla_final && (!casilla_final.GetEstado())) {
=======
			if (tablero[pos_inicial.fila + 1][pos_inicial.columna] == casilla_final && (!casilla_final.getEstado())) {
>>>>>>> Stashed changes
				return true;
			}

			//el peón está en su posición de origen, puede avanzar dos casillas
			if ((pieza.getFilaOrigen() == pos_inicial.fila) && (pos_final.fila == pos_inicial.fila + 2)
<<<<<<< Updated upstream
				&& (!casilla_final.GetEstado()) && !(tablero[pos_inicial.fila + 1][pos_inicial.columna]).GetEstado()) {
=======
				&& (!casilla_final.getEstado()) && !(tablero[pos_inicial.fila + 1][pos_inicial.columna]).getEstado()) {
>>>>>>> Stashed changes
				return true;
			}

		}

		//PEON NEGRO (7)
        else if (pieza.GetTipo() == 7) {
            //el peón quiere moverse a una diagonal
            if (tablero[pos_inicial.fila - 1][pos_inicial.columna - 1] == casilla_final || tablero[pos_inicial.fila - 1][pos_inicial.columna + 1] == casilla_final) {
                //hay una pieza de otro color ya (ya hemos comprobado que no sea del mismo)
<<<<<<< Updated upstream
                if (casilla_final.GetEstado()) {
=======
                if (casilla_final.getEstado()) {
>>>>>>> Stashed changes
                    return true;
                }
            }

            //el peón quiere moverse recto 1 casilla y tiene que estar vacía
<<<<<<< Updated upstream
            if (tablero[pos_inicial.fila - 1][pos_inicial.columna] == casilla_final && (!casilla_final.GetEstado())) {
=======
            if (tablero[pos_inicial.fila - 1][pos_inicial.columna] == casilla_final && (!casilla_final.getEstado())) {
>>>>>>> Stashed changes
                return true;
            }

            //el peón está en su posición de origen, puede avanzar dos casillas
			if ((pieza.getFilaOrigen() == pos_inicial.fila) && (pos_final.fila == pos_inicial.fila - 2)
<<<<<<< Updated upstream
				&& (!casilla_final.GetEstado()) && !(tablero[pos_inicial.fila - 1][pos_inicial.columna]).GetEstado()) {
=======
				&& (!casilla_final.getEstado()) && !(tablero[pos_inicial.fila - 1][pos_inicial.columna]).getEstado()) {
>>>>>>> Stashed changes
                return true;
            }
        }

		//REYES (2 Y 8)
        else if (pieza.GetTipo() == 2 || pieza.GetTipo() == 8) {
            for (int j = -1; j <= 1; j++) {
                for (int k = -1; k <= 1; k++) {
					if (j != 0 || k != 0) {
                        //El rey no puede caminar a un jaque
                        if (tablero[pos_inicial.fila + j][pos_inicial.columna + k] == casilla_final) {
							for (int l = 0; l < 8; l++) {
								for (int m = 0; m < 8; m++) {
<<<<<<< Updated upstream
									if (tablero[l][m].GetEstado() && (tablero[l][m].GetPieza().getColor() != pieza.getColor())) {
										Pos pos_iteracion;
										pos_iteracion.fila = l;
										pos_iteracion.columna = m;
										vector<Casilla> casillas_reglas = aplicaReglas(tablero[l][m].GetPieza(), pos_iteracion);
										for (int n = 0; n < casillas_reglas.size(); n++) {
											//Excepción peón
											if (tablero[l][m].GetPieza().GetTipo() == 1 || tablero[l][m].GetPieza().GetTipo() == 7) {
=======
									if (tablero[l][m].getEstado() && (tablero[l][m].getPieza().getColor() != pieza.getColor())) {
										Pos pos_iteracion;
										pos_iteracion.fila = l;
										pos_iteracion.columna = m;
										vector<Casilla> casillas_reglas = aplicaReglas(tablero[l][m].getPieza(), pos_iteracion);
										for (int n = 0; n < casillas_reglas.size(); n++) {
											//Excepción peón
											if (tablero[l][m].getPieza().GetTipo() == 1 || tablero[l][m].getPieza().GetTipo() == 7) {
>>>>>>> Stashed changes
												if ((casillas_reglas[n].getPos().columna != pos_iteracion.columna) && (casillas_reglas[n].getPos() == pos_final)) {
													return false;
												}
											}
											//Excepción rey (recursividad)
<<<<<<< Updated upstream
											else if (tablero[l][m].GetPieza().GetTipo() == 2 || tablero[l][m].GetPieza().GetTipo() == 8) {
=======
											else if (tablero[l][m].getPieza().GetTipo() == 2 || tablero[l][m].getPieza().GetTipo() == 8) {
>>>>>>> Stashed changes
												if (((abs(pos_iteracion.columna - casillas_reglas[n].getPos().columna) == 1) || (abs(pos_iteracion.fila - casillas_reglas[n].getPos().fila) == 1))
													&& (casillas_reglas[n].getPos() == pos_final)) {
													return false;
												}
											}
											//Funcionamiento normal
											else {
<<<<<<< Updated upstream
												if ((casillas_reglas[n].getPos() == pos_final) && comprueba(tablero[l][m].GetPieza(), pos_iteracion, casillas_reglas[n].getPos())) {
=======
												if ((casillas_reglas[n].getPos() == pos_final) && comprueba(tablero[l][m].getPieza(), pos_iteracion, casillas_reglas[n].getPos())) {
>>>>>>> Stashed changes
													return false;
												}
											}
										}
									}
								}
							}
                            return true;
                        }
                    }
                }
            }

            //Falta enroque
        }

		//DAMAS (3 Y 9)
		else if (pieza.GetTipo() == 3 || pieza.GetTipo() == 9) {
			int caso = 0;
			int difcol = pos_final.columna - pos_inicial.columna;
			int diffil = pos_final.fila - pos_inicial.fila;

			//derecha
			if (difcol > 0){
				if (diffil == difcol) caso = 1; //arriba dcha
				if (diffil == 0) caso = 2; //recto dcha
				if (-diffil == difcol) caso = 3; //abajo dcha
			}
			//izquierda
			if (difcol < 0) {
				if (diffil == difcol) caso = 5; //abajo izq
				if (diffil == 0) caso = 6; //recto izq
				if (-diffil == difcol) caso = 7; //arriba izq
			}
			//recto arriba o abajo
			if (difcol == 0) {
				if(diffil < 0) caso = 4; //abajo recto
				if(diffil > 0) caso = 8; //arriba recto
			}

			//aux tomará el valor de la casilla que se va iterando
			Casilla aux;
			//Dirección
			switch(caso){
			//Arriba derecha
			case 1:
				//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
				for (int j = 1; j <= (pos_final.fila - pos_inicial.fila); j++) {
					aux = tablero[pos_inicial.fila + j][pos_inicial.columna + j];
					//encuentro una pieza
<<<<<<< Updated upstream
					if(aux.GetEstado()){
=======
					if(aux.getEstado()){
>>>>>>> Stashed changes
						return checkFinal(aux);
					}
					else{
						continue;
					}
				}
				//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
				return true;
				break;

			//Derecha
			case 2:
				//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
				for (int j = 1; j <= (pos_final.columna - pos_inicial.columna); j++) {
					aux = tablero[pos_inicial.fila][pos_inicial.columna + j];
					//encuentro una pieza
<<<<<<< Updated upstream
					if (aux.GetEstado()) {
=======
					if (aux.getEstado()) {
>>>>>>> Stashed changes
						return checkFinal(aux);
					}
					else {
						continue;
					}
				}
				//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
				return true;
				break;

			//Abajo derecha
			case 3:
				//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
				for (int j = 1; j <= (pos_inicial.fila - pos_final.fila); j++) {
					aux = tablero[pos_inicial.fila - j][pos_inicial.columna + j];
					//encuentro una pieza
<<<<<<< Updated upstream
					if (aux.GetEstado()) {
=======
					if (aux.getEstado()) {
>>>>>>> Stashed changes
						return checkFinal(aux);
					}
					else {
						continue;
					}
				}
				//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
				return true;
				break;

			//Abajo
			case 4:
				//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
				for (int j = 1; j <= (pos_inicial.fila - pos_final.fila); j++) {
					aux = tablero[pos_inicial.fila - j][pos_inicial.columna] ;
					//encuentro una pieza
<<<<<<< Updated upstream
					if (aux.GetEstado()) {
=======
					if (aux.getEstado()) {
>>>>>>> Stashed changes
						return checkFinal(aux);
					}
					else {
						continue;
					}
				}
				//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
				return true;
				break;

			//Abajo izquierda
			case 5:
				//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
				for (int j = 1; j <= (pos_inicial.fila - pos_final.fila); j++) {
					aux = tablero[pos_inicial.fila - j][pos_inicial.columna - j];
					//encuentro una pieza
<<<<<<< Updated upstream
					if (aux.GetEstado()) {
=======
					if (aux.getEstado()) {
>>>>>>> Stashed changes
						return checkFinal(aux);
					}
					else {
						continue;
					}
				}
				//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
				return true;
				break;

			//Izquierda
			case 6:
				//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
				for (int j = 1; j <= (pos_inicial.columna - pos_final.columna); j++) {
					aux = tablero[pos_inicial.fila][pos_inicial.columna - j];
					//encuentro una pieza
<<<<<<< Updated upstream
					if (aux.GetEstado()) {
=======
					if (aux.getEstado()) {
>>>>>>> Stashed changes
						return checkFinal(aux);
					}
					else {
						continue;
					}
				}
				//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
				return true;
				break;

			//Arriba izquierda
			case 7:
				//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
				for (int j = 1; j <= (pos_final.fila - pos_inicial.fila); j++) {
					aux = tablero[pos_inicial.fila + j][pos_inicial.columna - j];
					//encuentro una pieza
<<<<<<< Updated upstream
					if (aux.GetEstado()) {
=======
					if (aux.getEstado()) {
>>>>>>> Stashed changes
						return checkFinal(aux);
					}
					else {
						continue;
					}
				}
				//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
				return true;
				break;

			//Arriba
			case 8:
				//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
				for (int j = 1; j <= (pos_final.fila - pos_inicial.fila); j++) {
					aux = tablero[pos_inicial.fila + j][pos_inicial.columna];
					//encuentro una pieza
<<<<<<< Updated upstream
					if (aux.GetEstado()) {
=======
					if (aux.getEstado()) {
>>>>>>> Stashed changes
						return checkFinal(aux);
					}
					else {
						continue;
					}
				}
				//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
				return true;
				break;

			default:
				break;
			}
			
		}

		//ALFIL (4 Y 10)
		else if (pieza.GetTipo() == 4 || pieza.GetTipo() == 10) {
			int caso = 0;
			int difcol = pos_final.columna - pos_inicial.columna;
			int diffil = pos_final.fila - pos_inicial.fila;

			//derecha
			if (difcol > 0) {
				if (diffil == difcol) caso = 1; //arriba dcha
				if (-diffil == difcol) caso = 2; //abajo dcha
			}
			//izquierda
			if (difcol < 0){
				if (diffil == difcol) caso = 3; //abajo izq
				if (-diffil == difcol) caso = 4; //arriba izq
			}

			//aux tomará el valor de la casilla que se va iterando
			Casilla aux;
			//Dirección
			switch (caso) {
			case 1:
				//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
				for (int j = 1; j <= (pos_final.fila - pos_inicial.fila); j++) {
					aux = tablero[pos_inicial.fila + j][pos_inicial.columna + j];
					//encuentro una pieza
<<<<<<< Updated upstream
					if(aux.GetEstado()){
=======
					if(aux.getEstado()){
>>>>>>> Stashed changes
						return checkFinal(aux);
					}
					else{
						continue;
					}
				}
				//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
				return true;
				break;

			case 2:
				//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
				for (int j = 1; j <= (pos_inicial.fila - pos_final.fila); j++) {
					aux = tablero[pos_inicial.fila - j][pos_inicial.columna + j];
					//encuentro una pieza
<<<<<<< Updated upstream
					if (aux.GetEstado()) {
=======
					if (aux.getEstado()) {
>>>>>>> Stashed changes
						return checkFinal(aux);
					}
					else {
						continue;
					}
				}
				//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
				return true;
				break;

			case 3:
				//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
				for (int j = 1; j <= (pos_inicial.fila - pos_final.fila); j++) {
					aux = tablero[pos_inicial.fila - j][pos_inicial.columna - j];
					//encuentro una pieza
<<<<<<< Updated upstream
					if (aux.GetEstado()) {
=======
					if (aux.getEstado()) {
>>>>>>> Stashed changes
						return checkFinal(aux);
					}
					else {
						continue;
					}
				}
				//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
				return true;
				break;

			case 4:
				//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
				for (int j = 1; j <= (pos_final.fila - pos_inicial.fila); j++) {
					aux = tablero[pos_inicial.fila + j][pos_inicial.columna - j];
					//encuentro una pieza
<<<<<<< Updated upstream
					if (aux.GetEstado()) {
=======
					if (aux.getEstado()) {
>>>>>>> Stashed changes
						return checkFinal(aux);
					}
					else {
						continue;
					}
				}
				//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
				return true;
				break;

			default:
				break;
			}
		}

		//CABALLO (5 Y 11)
		else if (pieza.GetTipo() == 5 || pieza.GetTipo() == 11) {
			return true;
		}

		//TORRES (6 Y 12)
		else if (pieza.GetTipo() == 6 || pieza.GetTipo() == 12) {
			int caso = 0;
			int difcol = pos_final.columna - pos_inicial.columna;
			int diffil = pos_final.fila - pos_inicial.fila;
			//derecha
			if (difcol > 0){
				if (diffil == 0) caso = 1; //recto dcha
			}
			//izquierda
			if (difcol < 0) {
				if (diffil == 0) caso = 2; //recto izq
			}
			//recto arriba o abajo
			if (difcol == 0) {
				if (diffil < 0) caso = 3; //abajo recto
				if (diffil > 0) caso = 4; //arriba recto
			}

			//aux tomará el valor de la casilla que se va iterando
			Casilla aux;
			//Dirección
			switch (caso) {
			//Derecha
			case 1:
				//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
				for (int j = 1; j <= (pos_final.columna - pos_inicial.columna); j++) {
					aux = tablero[pos_inicial.fila][pos_inicial.columna + j];
					//encuentro una pieza
<<<<<<< Updated upstream
					if (aux.GetEstado()) {
=======
					if (aux.getEstado()) {
>>>>>>> Stashed changes
						return checkFinal(aux);
					}
					else {
						continue;
					}
				}
				//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
				return true;
				break;

			//Izquierda
			case 2: 
				//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
				for (int j = 1; j <= (pos_inicial.columna - pos_final.columna); j++) {
					aux = tablero[pos_inicial.fila][pos_inicial.columna - j];
					//encuentro una pieza
<<<<<<< Updated upstream
					if (aux.GetEstado()) {
=======
					if (aux.getEstado()) {
>>>>>>> Stashed changes
						return checkFinal(aux);
					}
					else {
						continue;
					}
				}
				//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
				return true;
				break;

			//Abajo
			case 3:
				//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
				for (int j = 1; j <= (pos_inicial.fila - pos_final.fila); j++) {
					aux = tablero[pos_inicial.fila - j][pos_inicial.columna] ;
					//encuentro una pieza
<<<<<<< Updated upstream
					if (aux.GetEstado()) {
=======
					if (aux.getEstado()) {
>>>>>>> Stashed changes
						return checkFinal(aux);
					}
					else {
						continue;
					}
				}
				//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
				return true;
				break;

			//Arriba
			case 4:
				//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
				for (int j = 1; j <= (pos_final.fila - pos_inicial.fila); j++) {
					aux = tablero[pos_inicial.fila + j][pos_inicial.columna];
					//encuentro una pieza
<<<<<<< Updated upstream
					if (aux.GetEstado()) {
=======
					if (aux.getEstado()) {
>>>>>>> Stashed changes
						return checkFinal(aux);
					}
					else {
						continue;
					}
				}
				//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
				return true;
				break;

			default:
				break;
			}

		}

	}
	return false;
}

/**
 * @brief Esta función comprueba si la casilla donde encontré una pieza es a la que quiero ir(correcto) o pretendia saltarla(incorrecto)
 * 
 * @param aux Casilla a comprobar
 * @return true cuando hay una pieza porque me la quiero comer
 * @return false cuando hay una pieza que intentaba saltar
 */
bool Tablero::checkFinal(Casilla aux){
	bool res;
	//es a la que quiero ir, me la como
	if (aux == tablero[pos_final.fila][pos_final.columna]) {
		res = true;
	}
	//no es donde yo quiero (no pretendia comerme esa)
	else {
		res = false;
	}
	return res;
}

<<<<<<< Updated upstream
bool Tablero::checkJaque(Pos posRey) {
	vector<Casilla> casillas_posibles = aplicaReglas(pieza_aux, pos_inicial);
	vector<Casilla> casillas_posibles_validas;
	for (int i = 0; i < casillas_posibles.size(); i++) {
		if (comprueba(pieza_aux, pos_inicial, casillas_posibles[i].getPos())) {
			casillas_posibles_validas.push_back(casillas_posibles[i]);
		}
	}
=======
/**
 * @brief Esta función comprueba si la pieza en posición p le hace jaque al rey en posRey
 * 
 * @param posRey posición del posible rey amenazado
 * @param pieza pieza que se comprueba (posible amenaza)
 * @param pos posición de la pieza
 * @return true si el rey está en jaque
 * @return false si el rey no está en jaque
 */
bool Tablero::checkJaque(Pos posRey, Pieza pieza, Pos pos) {
	//obtenemos las casillas a las que puede acceder esa pieza aplicando sus reglas
	vector<Casilla> casillas_posibles = aplicaReglas(pieza, pos);
	vector<Casilla> casillas_posibles_validas;
	for (int i = 0; i < casillas_posibles.size(); i++) {
		//acotamos las casillas validas llamando a comprueba
		if (comprueba(pieza, pos, casillas_posibles[i].getPos())) {
			//casillas válidas finales
			casillas_posibles_validas.push_back(casillas_posibles[i]);
		}
	}

	//si la posición del rey está en sus válidas, es que se la puede comer y por tanto le hace jaque
>>>>>>> Stashed changes
	if (std::find(casillas_posibles_validas.begin(), casillas_posibles_validas.end(), tablero[posRey.fila][posRey.columna]) != casillas_posibles_validas.end()) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * @brief 
 * 
 * @param button 
 * @param state 
 * @param x 
 * @param y 
 */
<<<<<<< Updated upstream
void Tablero::Raton(int button, int state, int x, int y) {
=======
void Tablero::raton(int button, int state, int x, int y) {
>>>>>>> Stashed changes
	//ENCONTRAR EN QUÉ CASILLA ESTÁ EL CURSOR AL CLICAR/ SOLTAR EL CLIC
	int x0 = x - AJUSTE_X;
	int y0 = y - AJUSTE_Y; //traslado de coordenadas del ratón
	int f = 0;
	int c = 0;

	if (((x0 >= 0) && (x0 <= LIM_TABLERO)) && ((y0 <= 0) && (y0 >= -LIM_TABLERO))) {
		for (int i = 0; i < 8; i++) {
			if ((y0 <= -f) && (y0 > -(f + LIM_CASILLA))) {
				fila_raton = i;
			}
			if ((x0 >= c) && (x0 < (c + LIM_CASILLA))) {
				columna_raton = i;
			}
			//dimensiones de la casilla: 91 x 91
			f += LIM_CASILLA;
			c += LIM_CASILLA;
		}
		within_board = TRUE;
	}
	else {
		within_board = FALSE;
	}
	if (mouse_released) { //pos_inicial.fila y pos_inicial.columna deben ser las de aquella casilla donde se ha clicado pero NO soltado el clic.
		pos_inicial.fila = fila_raton;
		pos_inicial.columna = columna_raton;
<<<<<<< Updated upstream
		micolor = tablero[pos_inicial.fila][pos_inicial.columna].GetPieza().getColor();
=======
		micolor = tablero[pos_inicial.fila][pos_inicial.columna].getPieza().getColor();
>>>>>>> Stashed changes
	}
	if (mouse_pressed) {
		pos_final.fila = fila_raton;
		pos_final.columna = columna_raton;
	}
	
	//ACTUALIZACIÓN DE PIEZAS
	if (within_board) { //Acciones a ejecutar si se ha clicado/dejado de clicar dentro del tablero

<<<<<<< Updated upstream
		if (!micolor && turno_blancas) { //Acciones a ejecutar si se ha clicado/dejado de clicar dentro del tablero

			if (mouse_released && tablero[pos_inicial.fila][pos_inicial.columna].GetEstado() && puntero_aux == NULL) {
				pieza_aux = tablero[pos_inicial.fila][pos_inicial.columna].GetPieza(); //Para evitar C2102
				puntero_aux = &pieza_aux;
				borrarPosiblesCasillas();
				DibujarPosiblesCasillas();
			}
			//suelto en una casilla válida de la pieza que mueves (tienes q estar moviendo una pieza)
			if (mouse_pressed && (puntero_aux != NULL) && comprueba(pieza_aux, pos_inicial, pos_final)) {
				CambiarPieza();
				puntero_aux = NULL;
				borrarPosiblesCasillas();
				turno_blancas = false;
				turno_negras = true;
			}
			//si estás moviendo una pieza y el movimiento no es correcto, se devuelve a su casilla original
			if (mouse_pressed && (puntero_aux != NULL) && !comprueba(pieza_aux, pos_inicial, pos_final)) {
				tablero[pos_inicial.fila][pos_inicial.columna].SetPieza(pieza_aux);
				puntero_aux = NULL;
			}
		}
		if (micolor && turno_negras) { //Acciones a ejecutar si se ha clicado/dejado de clicar dentro del tablero
			if (mouse_released && tablero[pos_inicial.fila][pos_inicial.columna].GetEstado() && puntero_aux == NULL) {
				pieza_aux = tablero[pos_inicial.fila][pos_inicial.columna].GetPieza(); //Para evitar C2102
				puntero_aux = &pieza_aux;
				borrarPosiblesCasillas();
				DibujarPosiblesCasillas();
			}
			//suelto en una casilla válida de la pieza que mueves (tienes q estar moviendo una pieza)
			if (mouse_pressed && (puntero_aux != NULL) && comprueba(pieza_aux, pos_inicial, pos_final)) {
				CambiarPieza();
				puntero_aux = NULL;
				borrarPosiblesCasillas();
				turno_negras = false;
				turno_blancas = true;
			}
			//si estás moviendo una pieza y el movimiento no es correcto, se devuelve a su casilla original
			if (mouse_pressed && (puntero_aux != NULL) && !comprueba(pieza_aux, pos_inicial, pos_final)) {
				tablero[pos_inicial.fila][pos_inicial.columna].SetPieza(pieza_aux);
=======
		if (!micolor && turno_blancas) { //Turno de las blancas

			if (mouse_released && tablero[pos_inicial.fila][pos_inicial.columna].getEstado() && puntero_aux == NULL) {
				pieza_aux = tablero[pos_inicial.fila][pos_inicial.columna].getPieza(); //Para evitar C2102
				puntero_aux = &pieza_aux;
				borrarPosiblesCasillas();
				dibujarPosiblesCasillas();
			}
			//suelto en una casilla válida de la pieza que mueves (tienes q estar moviendo una pieza)
			if (mouse_pressed && (puntero_aux != NULL) && comprueba(pieza_aux, pos_inicial, pos_final)) {
				cambiarPieza();
				puntero_aux = NULL;
				borrarPosiblesCasillas();
				if (pieza_aux.GetTipo() == 2) {
					posReyB.fila = pos_final.fila;
					posReyB.columna = pos_final.columna;
				}
				turno_blancas = false;
				turno_negras = true;
				if (blancas_en_jaque) {
					blancas_en_jaque = false;
				}
				if (checkJaque(posReyN, pieza_aux, pos_final)) {
					negras_en_jaque = true;
				}
			}
			//si estás moviendo una pieza y el movimiento no es correcto, se devuelve a su casilla original
			if (mouse_pressed && (puntero_aux != NULL) && !comprueba(pieza_aux, pos_inicial, pos_final)) {
				tablero[pos_inicial.fila][pos_inicial.columna].setPieza(pieza_aux);
				puntero_aux = NULL;
			}
		}

		if (micolor && turno_negras) { //Turno de las negras
			if (mouse_released && tablero[pos_inicial.fila][pos_inicial.columna].getEstado() && puntero_aux == NULL) {
				pieza_aux = tablero[pos_inicial.fila][pos_inicial.columna].getPieza(); //Para evitar C2102
				puntero_aux = &pieza_aux;
				borrarPosiblesCasillas();
				dibujarPosiblesCasillas();
			}
			//suelto en una casilla válida de la pieza que mueves (tienes q estar moviendo una pieza)
			if (mouse_pressed && (puntero_aux != NULL) && comprueba(pieza_aux, pos_inicial, pos_final)) {
				cambiarPieza();
				puntero_aux = NULL;
				borrarPosiblesCasillas();
				if (pieza_aux.GetTipo() == 8) {
					posReyN.fila = pos_final.fila;
					posReyN.columna = pos_final.columna;
				}
				turno_negras = false;
				turno_blancas = true;
				if (negras_en_jaque) {
					negras_en_jaque = false;
				}
				if (checkJaque(posReyB, pieza_aux, pos_final)) {
					blancas_en_jaque = true;
				}
			}
			//si estás moviendo una pieza y el movimiento no es correcto, se devuelve a su casilla original
			if (mouse_pressed && (puntero_aux != NULL) && !comprueba(pieza_aux, pos_inicial, pos_final)) {
				tablero[pos_inicial.fila][pos_inicial.columna].setPieza(pieza_aux);
>>>>>>> Stashed changes
				puntero_aux = NULL;
			}
		}
	}

	//Si se suelta el clic fuera del tablero llevando una pieza no se confirma el movimiento y devuelve la pieza a la casilla inicial previa al movimiento.
	if (!within_board && mouse_pressed && (puntero_aux != NULL)) {
<<<<<<< Updated upstream
		tablero[pos_inicial.fila][pos_inicial.columna].SetPieza(pieza_aux);
=======
		tablero[pos_inicial.fila][pos_inicial.columna].setPieza(pieza_aux);
>>>>>>> Stashed changes
		puntero_aux = NULL;
	}
}

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 */
<<<<<<< Updated upstream
void Tablero::Movimiento(int x, int y) {
=======
void Tablero::movimiento(int x, int y) {
>>>>>>> Stashed changes
	int x0 = x - AJUSTE_X;
	int y0 = y - AJUSTE_Y; //traslado de coordenadas del ratón
	int f = 0;
	int c = 0;
	if (((x0 >= 0) && (x0 <= LIM_TABLERO)) && ((y0 <= 0) && (y0 >= -LIM_TABLERO))) {
		for (int i = 0; i < 8; i++) {
			if ((y0 <= -f) && (y0 > -(f + LIM_CASILLA))) {
				fila_movimiento = i;
			}
			if ((x0 >= c) && (x0 < (c + LIM_CASILLA))) {
				columna_movimiento = i;
			}
			//dimensiones de la casilla: 91 x 91
			c += LIM_CASILLA;
			f += LIM_CASILLA;
		}
	}

	//ACCIÓN DE ARRASTRAR
	if (within_board) {
		if ((!micolor && turno_blancas) || (micolor && turno_negras)) {
			//La pieza que se está moviendo (aún no se ha soltado el clic) se borra de la casilla de la que se había cogido. Esto se hace para evitar que se repita la pieza.
<<<<<<< Updated upstream
			tablero[pos_inicial.fila][pos_inicial.columna].QuitarPieza();
=======
			tablero[pos_inicial.fila][pos_inicial.columna].quitarPieza();
>>>>>>> Stashed changes
			mouse_pos.fila = x;
			mouse_pos.columna = y;
		}
	}
}

/**
 * @brief 
 * 
 */
<<<<<<< Updated upstream
void Tablero::Arrastrar() {
=======
void Tablero::arrastrar() {
>>>>>>> Stashed changes
	if (mouse_pressed && puntero_aux != NULL) {
		(*puntero_aux).Dibujar(mouse_pos.fila, mouse_pos.columna, 0);
		glutPostRedisplay();
	}
}

<<<<<<< Updated upstream
void Tablero::DibujarPosiblesCasillas() {
=======
void Tablero::dibujarPosiblesCasillas() {
>>>>>>> Stashed changes
	std::vector<Casilla> vec_aux = aplicaReglas(pieza_aux, pos_inicial);
	for (int i = 0; i < vec_aux.size(); i++) {
		if (comprueba(pieza_aux, pos_inicial, vec_aux[i].getPos())) {
			tablero[vec_aux[i].getPos().fila][vec_aux[i].getPos().columna].setPosibilidad();
		}
	}
}

void Tablero::borrarPosiblesCasillas() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tablero[i][j].delPosibilidad();
		}
	}
}
<<<<<<< Updated upstream
=======

void Tablero::setTamano(bool a) {
	if (a) {
		AJUSTE_X = 86;
		AJUSTE_Y = 813;
		LIM_TABLERO = 728;
		LIM_CASILLA = 91;
	}
	else {
		AJUSTE_X = 58;
		AJUSTE_Y = 540;
		LIM_TABLERO = 480;
		LIM_CASILLA = 60;
	}
}

bool Tablero::getTurnoB() {
	return turno_blancas;
}

bool Tablero::getTurnoN() {
	return turno_negras;
}
>>>>>>> Stashed changes
