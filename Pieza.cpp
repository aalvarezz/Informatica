//Librerías
#include "Pieza.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include <iostream>
#include "Pos.h"
#include <vector>

//Constantes predefinidas
/*#define AJUSTE_X 58
#define AJUSTE_Y 540
#define LIM_TABLERO 480
#define LIM_CASILLA 60*/

using std::cout, std::endl;

Pieza::Pieza(unsigned short int t) {
	tipo = t;
	if (tipo < 7) color = 0;
	else color = 1;
	lado = 2.5f; //PROVISIONAL
	origen.fila = setFilaOrigen();
	origen.columna = setColumnaOrigen();
	pinned = 0;

	AJUSTE_X = 58;
	AJUSTE_Y = 540;
	LIM_TABLERO = 480;
	LIM_CASILLA = 60;

	vector<Pos> reglas;
}

Pieza::Pieza() {

}

/**
* Destructor
*/
Pieza::~Pieza() {

}

/**
* Esta función devuelve el tipo de pieza
* @return unsigned short int con el tipo de pieza
*/
unsigned short int Pieza::GetTipo() {
	return tipo;
}

unsigned short int Pieza::setTipo(int valor)
{
	tipo = valor;
	return tipo;
}

/**
* Esta función setea la fila en la que comienza la pieza en función de su tipo
* @return unsigned short int fila donde empieza la pieza
*/
unsigned short int Pieza::setFilaOrigen() {
	if (tipo == 1) {
		return 1; //FILA 1 (peones blancos)
	}
	else if (tipo == 2 || tipo == 3 || tipo == 4 || tipo == 5 || tipo == 6) {
		return 0; //FILA 0 (demás piezas blancas)
	}
	else if (tipo == 7) {
		return 6; //FILA 6 (peones negros)
	}
	else if (tipo == 8 || tipo == 9 || tipo == 10 || tipo == 11 || tipo == 12) {
		return 7; //FILA 7 (demás piezas negras)
	}
	else {
		return 0;
	}
}

/**
* Esta función setea la columna en la que comienza la pieza en función de su tipo
* @return unsigned short int columna donde empieza la pieza
*/
unsigned short int Pieza::setColumnaOrigen() {
	if (tipo == 2 || tipo == 8)
	{
		return 4; //Reyes
	}
	else if (tipo == 3 || tipo == 9) {
		return 3; //Damas
	}
	else {
		return 0;
	}
}

/**
* Esta función devuelve la fila en la que comienza la pieza en función de su tipo
* @return unsigned short int columna donde empieza la pieza
*/
unsigned short int Pieza::getFilaOrigen() {
	return origen.fila;
}

/**
* Esta función devuelve la columna en la que comienza la pieza en función de su tipo
* @return unsigned short int columna donde empieza la pieza
*/
unsigned short int Pieza::getColumnaOrigen() {
	return origen.columna;
}

Pos Pieza::getOrigen() {
	return origen;
}

void Pieza::setTamano(int a, int b, int c, int d)
{
	AJUSTE_X = a;
	AJUSTE_Y = b;
	LIM_TABLERO = c;
	LIM_CASILLA = d;
}

/**
 * @brief Esta función crea la regla con las coordenadas dadas
 *
 * @param a coordenada x para la nueva regla
 * @param b coordenada y para la nueva regla
 * @return Pos regla creada a partir de las coordenadas correspondientes
 */
Pos Pieza::regla(int a, int b) {
	Pos mirregla;
	mirregla.fila = a;
	mirregla.columna = b;
	return mirregla;
}

/**
* Esta función devuelve el conjunto de reglas de movimiento definido por la pieza
* @return vector<Pos> vector de cálculos necesarios para obtener las casillas a las que se le aplica la regla
* !! IMPORTANTE !! Es necesario incluir todos los movimientos posibles, SU MOVILIDAD. En tablero.cpp se limitarán en función de la situación (turno, tablero...)
* Se usa vector dinámico ya que así podemos cambiar su tamaño en tiempo de ejecución.
*/
vector<Pos> Pieza::getReglas() {
	Pos regla_aux;
	switch (tipo) {
		//Peón blanco
	case 1:
		//1.Avanza una posición en la columna (Movimiento normal)
		reglas.push_back(regla(1, 0));

		//2.Avanza dos posiciones en la columna (Primer turno)
		reglas.push_back(regla(2, 0));

		//3.Diagonal izq (Al comer otra ficha)
		reglas.push_back(regla(1, -1));

		//4.Diagonal dcha (Al comer otra ficha)
		reglas.push_back(regla(1, 1));

		break;

		//Peón negro
	case 7:
		//1.Avanza una posición en la columna (Movimiento normal)
		reglas.push_back(regla(-1, 0));

		//2.Avanza dos posiciones en la columna (Primer turno)
		reglas.push_back(regla(-2, 0));

		//3.Diagonal izq (Al comer otra ficha)
		reglas.push_back(regla(-1, -1));

		//4.Diagonal dcha (Al comer otra ficha)
		reglas.push_back(regla(-1, 1));

		break;

		//Reyes
	case 2:
	case 8:
		for (int j = -1; j <= 1; j++) {
			for (int k = -1; k <= 1; k++) {
				reglas.push_back(regla(j, k));
			}
		}

		//EnroqueReyDerecha
		reglas.push_back(regla(0, 2));

		//EnroqueReyIzquierda
		reglas.push_back(regla(0, -2));
		break;
		//Damas
	case 3:
	case 9:
		for (int j = -7; j <= 7; j++) {
			if (j != 0) {
				reglas.push_back(regla(j, j));
				reglas.push_back(regla(j, -j));
				reglas.push_back(regla(j, 0));
				reglas.push_back(regla(0, j));
			}
		}
		break;
		//Alfiles
	case 4:
	case 10:
		for (int j = -7; j <= 7; j++) {
			if (j != 0) {
				reglas.push_back(regla(j, j));
				reglas.push_back(regla(j, -j));
			}
		}

		break;
		//Caballos
	case 5:
	case 11:
		for (int j = -2; j <= 2; j++) {
			for (int k = -2; k <= 2; k++) {
				if ((abs(j) != abs(k)) && (j != 0) && (k != 0)) {
					reglas.push_back(regla(j, k));
				}
			}
		}

		break;
		//Torres
	case 6:
	case 12:
		for (int j = -7; j <= 7; j++) {
			if (j != 0) {
				reglas.push_back(regla(j, 0));
				reglas.push_back(regla(0, j));
			}
		}

		break;
	default:
		break;
	}
	//Así con todos los tipos :)
	return reglas; //devuelvo el array con las reglas
}

bool Pieza::getColor() {
	return color;
}


void Pieza::setPinned(bool b) {
	pinned = b;
}

bool Pieza::getPinned() {
	return pinned;
}

/*
*
*/
void Pieza::Dibujar(float x, float y, bool casilla) { //POSIBLE SEPARACI�N EN DOS FUNCIONES (DibujarCentro(), Dibujar()) PARA CLARIDAD DE C�DIGO 
													  //Posible utilizacion de atributo centro de Casilla
	x -= AJUSTE_X; //Trasladar 0
	y -= AJUSTE_Y;
	if (casilla) {
		int f = 0;
		int c = 0;
		if (((x >= 0) && (x <= LIM_TABLERO)) && ((y <= 0) && (y >= -LIM_TABLERO))) {
			for (int i = 0; i < 8; i++) {
				if ((y <= -f) && (y > -(f + LIM_CASILLA))) {
					y = i;
				}
				if ((x >= c) && (x < (c + LIM_CASILLA))) {
					x = i;
				}
				//dimensiones de la casilla: 91 x 91
				f += LIM_CASILLA;
				c += LIM_CASILLA;
			}
		}
		x *= lado;
		y *= lado;
	}
	else {
		//BITMAP 91x91, GLUT 2.5x2.5
		x = 2.5f / LIM_CASILLA * x - 1.25f; //revisar
		y = -2.5f / LIM_CASILLA * y - 1.25f;
	}

	switch (tipo) {
	case 1:
		PeonB.setCenter(lado / 2, lado / 2);
		PeonB.setSize(lado, lado);
		glTranslatef(x, y, 0.1);
		glColor3f(1.0f, 0.0f, 0.0f);
		PeonB.draw();
		glTranslatef(-x, -y, -0.1);
		break;
	case 2:
		ReyB.setCenter(lado / 2, lado / 2);
		ReyB.setSize(lado, lado);
		glTranslatef(x, y, 0.1);
		glColor3f(1.0f, 0.0f, 0.0f);
		ReyB.draw();
		glTranslatef(-x, -y, -0.1);
		break;
	case 3:
		DamaB.setCenter(lado / 2, lado / 2);
		DamaB.setSize(lado, lado);
		glTranslatef(x, y, 0.1);
		glColor3f(1.0f, 0.0f, 0.0f);
		DamaB.draw();
		glTranslatef(-x, -y, -0.1);
		break;
	case 4:
		AlfilB.setCenter(lado / 2, lado / 2);
		AlfilB.setSize(lado, lado);
		glTranslatef(x, y, 0.1);
		glColor3f(1.0f, 0.0f, 0.0f);
		AlfilB.draw();
		glTranslatef(-x, -y, -0.1);
		break;
	case 5:
		CaballoB.setCenter(lado / 2, lado / 2);
		CaballoB.setSize(lado, lado);
		glTranslatef(x, y, 0.1);
		glColor3f(1.0f, 0.0f, 0.0f);
		CaballoB.draw();
		glTranslatef(-x, -y, -0.1);
		break;
	case 6:
		TorreB.setCenter(lado / 2, lado / 2);
		TorreB.setSize(lado, lado);
		glTranslatef(x, y, 0.1);
		glColor3f(1.0f, 0.0f, 0.0f);
		TorreB.draw();
		glTranslatef(-x, -y, -0.1);
		break;
	case 7:
		PeonN.setCenter(lado / 2, lado / 2);
		PeonN.setSize(lado, lado);
		glTranslatef(x, y, 0.1);
		glColor3f(1.0f, 0.0f, 0.0f);
		PeonN.draw();
		glTranslatef(-x, -y, -0.1);
		break;
	case 8:
		ReyN.setCenter(lado / 2, lado / 2);
		ReyN.setSize(lado, lado);
		glTranslatef(x, y, 0.1);
		glColor3f(1.0f, 0.0f, 0.0f);
		ReyN.draw();
		glTranslatef(-x, -y, -0.1);
		break;
	case 9:
		DamaN.setCenter(lado / 2, lado / 2);
		DamaN.setSize(lado, lado);
		glTranslatef(x, y, 0.1);
		glColor3f(1.0f, 0.0f, 0.0f);
		DamaN.draw();
		glTranslatef(-x, -y, -0.1);
		break;
	case 10:
		AlfilN.setCenter(lado / 2, lado / 2);
		AlfilN.setSize(lado, lado);
		glTranslatef(x, y, 0.1);
		glColor3f(1.0f, 0.0f, 0.0f);
		AlfilN.draw();
		glTranslatef(-x, -y, -0.1);
		break;
	case 11:
		CaballoN.setCenter(lado / 2, lado / 2);
		CaballoN.setSize(lado, lado);
		glTranslatef(x, y, 0.1);
		glColor3f(1.0f, 0.0f, 0.0f);
		CaballoN.draw();
		glTranslatef(-x, -y, -0.1);
		break;
	case 12:
		TorreN.setCenter(lado / 2, lado / 2);
		TorreN.setSize(lado, lado);
		glTranslatef(x, y, 0.1);
		glColor3f(1.0f, 0.0f, 0.0f);
		TorreN.draw();
		glTranslatef(-x, -y, -0.1);
		break;
	default:
		return;
		break;
	}
}