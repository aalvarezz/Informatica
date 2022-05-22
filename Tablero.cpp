//Librerías
#include "Tablero.h"
#include "Casilla.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <iostream>
#include <algorithm>

//Constantes predefinidas
/*#define AJUSTE_X 58
#define AJUSTE_Y 540
#define LIM_TABLERO 480
#define LIM_CASILLA 60*/

using std::cout, std::endl;

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
	turno_b = true;
	AJUSTE_X = 58; ////////////////////////////////////////////
	AJUSTE_Y = 540;
	LIM_TABLERO = 480;
	LIM_CASILLA = 60;
	alpaso = FALSE;
	coronacion = FALSE;

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
void Tablero::Inicializar() {
	//Igualamos a constantes predefinidas
	int x = AJUSTE_X;
	int y = AJUSTE_Y;
	//Bucle anidado para cuadrar posiciones
	for (int i = 0; i < 8; i++) {
		x += (LIM_CASILLA * i);
		for (int j = 0; j < 8; j++) {
			y -= (LIM_CASILLA * j);
			tablero[i][j] = Casilla(i, j);
			tablero[i][j].SetPosicion(x, y); //obtenemos la casilla que nos interesa del tablero y la sincronizamos con su posicion
		}
	}
}

/**
* @brief Esta función nos devuelve la casilla que nos interesa del tablero
*
* @param x int coordenada x
* @param y int coordenada y
* @return Casilla del tablero con las coordenadas dadas
*/
Casilla Tablero::getCasilla(int x, int y) {
	return Casilla(x, y);
}


/**
 * @brief Esta funcion crea las piezas y las añade al array de piezas del tablero de forma ORDENADA
 *
 */
void Tablero::crearPiezas() {
	int i = 0;
	for (i = i; i < 8; i++) {
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
	}
}

/**
 * @brief Esta función coloca las piezas en su lugar dado el array de piezas del juego ORDENADO
 *
 */
void Tablero::InicializarPiezas() {
	//Recorro mi array de piezas y las voy colocando
	for (int i = 0; i < 32; i++) {
		Pieza miPieza = piezas[i]; //pieza de la iteración actual
		int miFila = miPieza.getFilaOrigen(); //fila donde debe empezar el juego

		//PIEZAS CUYO TIPO SE REPITEN
		if (i < 8) {
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
		}

		//PIEZAS ÚNICAS (Reyes y damas)
		else {
			if (miPieza.GetTipo() == 2) {
				posReyB = miPieza.getOrigen();
			}
			if (miPieza.GetTipo() == 8) {
				posReyN = miPieza.getOrigen();
			}
			int miColumna = miPieza.getColumnaOrigen(); //columna donde debe empezar el juego
			tablero[miFila][miColumna].SetPieza(miPieza.GetTipo());
		}
	}
}


/**
 * @brief Esta función muestra el tablero por pantalla
 *
 */
void Tablero::DibujarTablero() { //Dibuja estados
	//CASILLAS DEL TABLERO
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//tablero[i][j].SetColor(i, j); //posible traslado a Inicializar //Puede ser interesante mantenerlo para posibles movimientos.

			getCasilla(i, j).Dibujar(i, j);
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
void Tablero::DibujarPiezas() {
	float x = AJUSTE_X;
	float y = AJUSTE_Y;
	for (int i = 0; i < 8; i++) {
		y -= (LIM_CASILLA - 1);
		for (int j = 0; j < 8; j++) {
			x += (LIM_CASILLA - 1);
			if (tablero[i][j].GetEstado()) {
				Pieza pieza = tablero[i][j].GetPieza();
				pieza.setTamano(AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA);
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
void Tablero::SetMouse(int x, int y, bool pressed, bool released) {
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
Pieza Tablero::GetPieza() {
	return *puntero_aux;
}

/**
 * @brief Esta función devuelve la posición del mouse
 *
 * @return Pos posición del mouse
 */
Pos Tablero::GetMousePos() {
	return mouse_pos;
}

/**
 * @brief Actualiza la pieza de la casilla a la que se va a mover la pieza con dicha pieza (se llama a la función cuando ya se ha confirmado que el movimiento es correcto)
 *
 */
void Tablero::CambiarPieza() {
	tablero[pos_final.fila][pos_final.columna].SetPieza(*puntero_aux);
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
	std::vector<Casilla> miscasillas = aplicaReglas(pieza, pos_inicial); //casillas a las que puedo ir con mi pieza_aux en posicion_inicial
	Casilla casilla_final = tablero[pos_final.fila][pos_final.columna];
	bool resultado = false;
	
	if (std::find(miscasillas.begin(), miscasillas.end(), casilla_final) != miscasillas.end()) {
		
		//Comprobamos que en la casilla que quiero poner mi pieza no tengo otra ya (DEL MISMO COLOR).
		if (casilla_final.GetEstado() && pieza.getColor() == casilla_final.GetPieza().getColor()) {
			resultado = false;
			return resultado;
		}
		if (turno_b)
		{
			//PEON BLANCO (1)
			if (pieza_aux.GetTipo() == 1) {

				//el peón quiere moverse a una diagonal
				if (tablero[pos_inicial.fila + 1][pos_inicial.columna - 1] == casilla_final || tablero[pos_inicial.fila + 1][pos_inicial.columna + 1] == casilla_final) {
					//comprobación de si hay peón que pueda comer al paso
					if (pos_inicial.fila == doblemov_negra.fila && (pos_inicial.columna + 1 == doblemov_negra.columna || pos_inicial.columna - 1 == doblemov_negra.columna))
					{
						if (pos_final.fila == doblemov_negra.fila + 1 && pos_final.columna == doblemov_negra.columna)
						{
							if (alpaso == TRUE)
								tablero[doblemov_negra.fila][doblemov_negra.columna].QuitarPieza();
							return true;
						}
						// FALTA AÑADIR EL POSIBLE MOVIMIENTO DE COMER AL PASO Y SINCRONIZARLO CON EL SISTEMA DE TURNOS. 
					}
					//hay una pieza de otro color ya (ya hemos comprobado que no sea del mismo)
					if (casilla_final.GetEstado()) { 
						if (coronacion == TRUE)
							CoronacionBlanca();
						return true;
					}
				}

				//el peón quiere moverse recto 1 casilla y tiene que estar vacía
				if (tablero[pos_inicial.fila + 1][pos_inicial.columna] == casilla_final && (!casilla_final.GetEstado())) {
					if (coronacion == TRUE)
						CoronacionBlanca();
					resultado = true;
					return resultado;
				}

				//el peón está en su posición de origen, puede avanzar dos casillas
				if ((pieza.getFilaOrigen() == pos_inicial.fila) && (pos_final.fila == pos_inicial.fila + 2) && (!casilla_final.GetEstado())) { //hay que comparar tambien la columna?
					doblemov_blanca = pos_final;
					resultado = true;
					return resultado;
				}

			}
			//REYES 2
			if (pieza_aux.GetTipo() == 2) {

				for (int j = -1; j <= 1; j++) {
					for (int k = -1; k <= 1; k++) {

						if (!((j == 0) && (k == 0))) {

							//el rey quiere moverse a una diagonal
							if (tablero[pos_inicial.fila + j][pos_inicial.columna + k] == casilla_final) {
								return true;
							}
						}
					}
				}

				//Falta enroque
			}
			//DAMAS (3 Y 9)
			if (pieza_aux.GetTipo() == 3) {
				int caso = 0;
				int difcol = pos_final.columna - pos_inicial.columna;
				int diffil = pos_final.fila - pos_inicial.fila;

				//derecha
				if (difcol > 0) {
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
					if (diffil < 0) caso = 4; //abajo recto
					if (diffil > 0) caso = 8; //arriba recto
				}

				if (caso % 2 == 0)
					return MovimTorre();
				else
					return MovimAlfil();

			}
			//ALFIL 4
			if (pieza_aux.GetTipo() == 4) 
			{
				return MovimAlfil();
			}
			//CABALLO 5
			if (pieza_aux.GetTipo() == 5) {
				resultado = true;
				return resultado;
			}

			//TORRES 6
			if (pieza_aux.GetTipo() == 6) {
				return MovimTorre();

			}
		}
		
		else
		{
			//PEON NEGRO (7)
			if (pieza_aux.GetTipo() == 7) {
				//el peón quiere moverse a una diagonal
				if (tablero[pos_inicial.fila - 1][pos_inicial.columna - 1] == casilla_final || tablero[pos_inicial.fila - 1][pos_inicial.columna + 1] == casilla_final) {
					//comprobación de si hay peón que pueda comer al paso
					if (pos_inicial.fila == doblemov_blanca.fila && (pos_inicial.columna + 1 == doblemov_blanca.columna || pos_inicial.columna - 1 == doblemov_blanca.columna))
					{
						if (pos_final.fila == doblemov_blanca.fila - 1 && pos_final.columna == doblemov_blanca.columna)
						{
							if (alpaso == TRUE)
								tablero[doblemov_blanca.fila][doblemov_blanca.columna].QuitarPieza();
							return true;
						}
						// FALTA AÑADIR EL POSIBLE MOVIMIENTO DE COMER AL PASO Y SINCRONIZARLO CON EL SISTEMA DE TURNOS. 
					}
					//hay una pieza de otro color ya (ya hemos comprobado que no sea del mismo)
					if (casilla_final.GetEstado()) {
						if (coronacion == TRUE)
							CoronacionNegra();
						return true;
					}
				}

				//el peón quiere moverse recto 1 casilla y tiene que estar vacía
				if (tablero[pos_inicial.fila - 1][pos_inicial.columna] == casilla_final && (!casilla_final.GetEstado())) {
					if (coronacion == TRUE)
						CoronacionNegra();
					resultado = true;
					return resultado;
				}

				//el peón está en su posición de origen, puede avanzar dos casillas
				if ((pieza_aux.getFilaOrigen() == pos_inicial.fila) && (pos_final.fila == pos_inicial.fila - 2) && (!casilla_final.GetEstado())) { //hay que comparar tambien la columna?
					doblemov_negra = pos_final;
					resultado = true;
					return resultado;
				}
			}

			//REYES 8
			if (pieza_aux.GetTipo() == 8) {

				for (int j = -1; j <= 1; j++) {
					for (int k = -1; k <= 1; k++) {

						if (!((j == 0) && (k == 0))) {

							//el rey quiere moverse a una diagonal
							if (tablero[pos_inicial.fila + j][pos_inicial.columna + k] == casilla_final) {
								return true;
							}
						}
					}
				}

				//Falta enroque
			}

			//DAMAS 9
			if (pieza_aux.GetTipo() == 9) {
				int caso = 0;
				int difcol = pos_final.columna - pos_inicial.columna;
				int diffil = pos_final.fila - pos_inicial.fila;

				//derecha
				if (difcol > 0) {
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
					if (diffil < 0) caso = 4; //abajo recto
					if (diffil > 0) caso = 8; //arriba recto
				}

				if (caso % 2 == 0) 
					return MovimTorre();
				else
					return MovimAlfil();

			}

			//ALFIL 10
			if (pieza_aux.GetTipo() == 10) {
				return MovimAlfil();
			}

			//CABALLO 11
			if (pieza_aux.GetTipo() == 11) {
				resultado = true;
				return resultado;
			}

			//TORRES 12
			if (pieza_aux.GetTipo() == 12) {
				return MovimTorre();
			}
		}

	}
	return resultado;
}

/**
 * @brief Esta función comprueba si la casilla donde encontré una pieza es a la que quiero ir(correcto) o pretendia saltarla(incorrecto)
 *
 * @param aux Casilla a comprobar
 * @return true cuando hay una pieza porque me la quiero comer
 * @return false cuando hay una pieza que intentaba saltar
 */
bool Tablero::checkFinal(Casilla aux) {
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

/**
 * @brief
 *
 * @param button
 * @param state
 * @param x
 * @param y
 */
void Tablero::Raton(int button, int state, int x, int y) {
	//ENCONTRAR EN QUÉ CASILLA ESTÁ EL CURSOR AL CLICAR/ SOLTAR EL CLIC
	int x0 = x - AJUSTE_X;
	int y0 = y - AJUSTE_Y; //traslado de coordenadas del ratón
	int f = 0;
	int c = 0;

	//cout << "x: " << x0 << ", y: " << y0 << endl;

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
		cout << fila_raton << "," << columna_raton << " cogido" << endl; //te dice la fila y la columna en la que has hecho click
		within_board = TRUE;
	}
	else {
		cout << "MOVIMIENTO NO VALIDO" << endl;
		within_board = FALSE;
	}
	if (mouse_released) { //fila inicial y pos_inicial.columna deben ser las de aquella casilla donde se ha clicado pero NO soltado el clic.
		pos_inicial.fila = fila_raton;
		pos_inicial.columna = columna_raton;
	}
	if (mouse_pressed) {
		pos_final.fila = fila_raton;
		pos_final.columna = columna_raton;
	}

	//ACTUALIZACIÓN DE PIEZAS
	if (within_board == TRUE) { //Acciones a ejecutar si se ha clicado/dejado de clicar dentro del tablero

		if (mouse_released && tablero[fila_raton][columna_raton].GetEstado() && puntero_aux == NULL) {
			pieza_aux = tablero[fila_raton][columna_raton].GetPieza(); //Para evitar C2102
			puntero_aux = &pieza_aux;
		}
		//suelto en una casilla válida de la pieza que mueves (tienes q estar moviendo una pieza)
		if (mouse_pressed && (puntero_aux != NULL))
		{ 
			alpaso = TRUE;
			coronacion = TRUE;
			if (comprueba(pieza_aux, pos_inicial, pos_final))
			{
				CambiarPieza();
				if (turno_b) {
					turno_b = false;
					cout << "TURNO N" << endl;
					//se deja de guardar la posición del peón al que se le podía comer al paso
					doblemov_negra.columna = 8;
					doblemov_negra.fila = 8;
				}

				else if (!turno_b) {
					turno_b = true;
					cout << "TURNO B" << endl;
					//se deja de guardar la posición del peón al que se le podía comer al paso
					doblemov_blanca.columna = 8;
					doblemov_blanca.fila = 8;
				}
				puntero_aux = NULL;
			}
			alpaso = FALSE;
			coronacion = FALSE;
		}
		//si estás moviendo una pieza y el movimiento no es correcto, se devuelve a su casilla original
		if (mouse_pressed && (puntero_aux != NULL) && !comprueba(pieza_aux, pos_inicial, pos_final)) {
			tablero[pos_inicial.fila][pos_inicial.columna].SetPieza(pieza_aux);
			puntero_aux = NULL;
		}
	}

	//Si se suelta el clic fuera del tablero llevando una pieza no se confirma el movimiento y devuelve la pieza a la casilla inicial previa al movimiento.
	if (within_board == FALSE && mouse_pressed && (puntero_aux != NULL)) {
		tablero[pos_inicial.fila][pos_inicial.columna].SetPieza(pieza_aux);
		puntero_aux = NULL;
	}

}

/**
 * @brief
 *
 * @param x
 * @param y
 */
void Tablero::Movimiento(int x, int y) {
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
	if (within_board == TRUE) {
		//La pieza que se está moviendo (aún no se ha soltado el clic) se borra de la casilla de la que se había cogido. Esto se hace para evitar que se repita la pieza.
		tablero[fila_raton][columna_raton].QuitarPieza();
		mouse_pos.fila = x;
		mouse_pos.columna = y;
		//cout << x << "," << y << endl;
	}
}

/**
 * @brief
 *
 */
void Tablero::Arrastrar() {
	if (mouse_pressed && puntero_aux != NULL) {
		(*puntero_aux).Dibujar(mouse_pos.fila, mouse_pos.columna, 0);
		glutPostRedisplay();
	}
}

/**
 * @brief
 *
 * @param poscol
 * @param posfil
 * @param piezabaja
 * @param piezaalta
 * @return true
 * @return false
 */
/*bool Tablero::PosibDesplazamiento(int poscol, int posfil, int piezabaja, int piezaalta)
{
	if (poscol < 8 && (posfil) < 8)
	{
		if (tablerillo[poscol][posfil] == 0 && (posfil) < 8)
			tablero[poscol][posfil].SetPosibilidad(poscol, posfil);
		else if (tablerillo[poscol][posfil] > piezabaja&& tablerillo[poscol][posfil] < piezaalta && (posfil) < 8)
		{
			tablero[poscol][posfil].SetPosibilidad(poscol, posfil);
			return 0;
		}
		else
			return 0;
	}
	return 1;
}*/

bool Tablero::getTurnoB()
{
	return turno_b;
}

void Tablero::setTamano(bool a)
{
	if (a)
	{
		AJUSTE_X = 86;
		AJUSTE_Y = 813;
		LIM_TABLERO = 728;
		LIM_CASILLA = 91;
	}
	else
	{
		AJUSTE_X = 58;
		AJUSTE_Y = 540;
		LIM_TABLERO = 480;
		LIM_CASILLA = 60;
	}
}

void Tablero::CoronacionBlanca()
{
	//coronación del peón blanco
	if (pos_inicial.fila + 1 == 7)
	{
		int elegido = 0;
		cout << endl << "Dama: 3" << endl;
		cout << "Alfil: 4" << endl;
		cout << "Caballo: 5" << endl;
		cout << "Torre: 6" << endl;
		do
		{
			elegido = 0;
			cout << "Elige que pieza quieres: ";
			std::cin >> elegido;
			switch (elegido)
			{
			case 3:
				pieza_aux.setTipo(3);
				break;
			case 4:
				pieza_aux.setTipo(4);
				break;
			case 5:
				pieza_aux.setTipo(5);
				break;
			case 6:
				pieza_aux.setTipo(6);
				break;
			default:
				cout << endl << "Pieza no valida. ";
			}

		} while (elegido > 6 || elegido < 3);
	}
}

void Tablero::CoronacionNegra()
{
	//coronación del peón negro
	if (pos_inicial.fila - 1 == 0)
	{
		int elegido = 0;
		cout << endl << "Dama: 9" << endl;
		cout << "Alfil: 10" << endl;
		cout << "Caballo: 11" << endl;
		cout << "Torre: 12" << endl;
		do
		{
			elegido = 0;
			cout << "Elige que pieza quieres: ";
			std::cin >> elegido;
			switch (elegido)
			{
			case 9:
				pieza_aux.setTipo(9);
				break;
			case 10:
				pieza_aux.setTipo(10);
				break;
			case 11:
				pieza_aux.setTipo(11);
				break;
			case 12:
				pieza_aux.setTipo(12);
				break;
			default:
				cout << endl << "Pieza no valida. ";
			}

		} while (elegido > 12 || elegido < 9);
	}
}

bool Tablero::MovimAlfil()
{
	int caso = 0;
	int difcol = pos_final.columna - pos_inicial.columna;
	int diffil = pos_final.fila - pos_inicial.fila;

	//derecha
	if (difcol > 0) {
		if (diffil == difcol) caso = 1; //arriba dcha
		if (-diffil == difcol) caso = 2; //abajo dcha
	}
	//izquierda
	if (difcol < 0) {
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
			if (aux.GetEstado()) {
				return checkFinal(aux);
			}
			else {
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
			if (aux.GetEstado()) {
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
			if (aux.GetEstado()) {
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
			if (aux.GetEstado()) {
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

bool Tablero::MovimTorre()
{
	int caso = 0;
	int difcol = pos_final.columna - pos_inicial.columna;
	int diffil = pos_final.fila - pos_inicial.fila;
	//derecha
	if (difcol > 0) {
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
			if (aux.GetEstado()) {
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
			if (aux.GetEstado()) {
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
			aux = tablero[pos_inicial.fila - j][pos_inicial.columna];
			//encuentro una pieza
			if (aux.GetEstado()) {
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
			if (aux.GetEstado()) {
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




void Tablero::DibujarPosiblesCasillas() { //REVISAR

										  //Posible implementacion junto a Pieza::MovimientoValido(); 
										  //Debemos implementar atributos en Casilla que determinen que casilla de las 64 es (N. de columna/fila).
										  //Posible implementacion justo a sistema de turnos para el caso de los peones negros (ambos peones se mueven hacia delante, 
										  //estando definido "delante" según su color. 
										  //Para el resto de piezas, piezas blancas = piezas negras. 
										  //Falta condición GENERAL de límites del tablero. (probablemente debería estar en Casilla::SetPosibilidad();)

	std::vector<Casilla> vec_aux = aplicaReglas(pieza_aux, pos_inicial);
	for (int i = 0; i < vec_aux.size(); i++) {
		if (comprueba(pieza_aux, pos_inicial, vec_aux[i].getPos())) {
			//vec_aux[i].SetPosibilidad(vec_aux[i].getPos().columna, vec_aux[i].getPos().fila);
			tablero[vec_aux[i].getPos().columna][vec_aux[i].getPos().fila].SetPosibilidad(vec_aux[i]);
		}
	}
}


