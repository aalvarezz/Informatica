#include "Tablero.h"
#include "freeglut.h"
#include "ETSIDI.h"

#include <iostream>
using namespace std;

void Tablero::dibujoDamero() {
	//CASILLAS DEL TABLERO
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (((j % 2) == 0) && ((i % 2) == 0) || ((j % 2) == 1) && ((i % 2) == 1)) {
				rojo = 87;
				verde = 70;
				azul = 0;
			}
			else {
				rojo = 255;
				verde = 253;
				azul = 208;
			}

			glColor3ub(rojo, verde, azul);
			glBegin(GL_POLYGON);
			glVertex3f(i * lado - lado / 2, j * lado - lado / 2, 0);
			glVertex3f(i * lado + lado / 2, j * lado - lado / 2, 0);
			glVertex3f(i * lado + lado / 2, j * lado + lado / 2, 0);
			glVertex3f(i * lado - lado / 2, j * lado + lado / 2, 0);
			glEnd();
		}
	}
	//BORDES DEL TABLERO
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/maderaV.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON); //Borde izquierdo del tablero
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(0 * lado - lado / 2 - 0.8 * lado, 0 * lado - lado / 2 - 0.8 * lado);
	glTexCoord2d(1, 1); glVertex2f(0 * lado - lado / 2, 0 * lado - lado / 2);
	glTexCoord2d(1, 0); glVertex2f(0 * lado - lado / 2, 7 * lado + lado / 2);
	glTexCoord2d(0, 0); glVertex2f(0 * lado - lado / 2 - 0.8 * lado, 7 * lado + lado / 2 + 0.8 * lado);
	glEnd();
	glBegin(GL_POLYGON); //Borde derecho del tablero
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
	glBegin(GL_POLYGON); //Borde inferior del tablero
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(0 * lado - lado / 2 - 0.8 * lado, 0 * lado - lado / 2 - 0.8 * lado);
	glTexCoord2d(1, 1); glVertex2f(7 * lado + lado / 2 + 0.8 * lado, 0 * lado - lado / 2 - 0.8 * lado);
	glTexCoord2d(1, 0); glVertex2f(7 * lado + lado / 2, 0 * lado - lado / 2);
	glTexCoord2d(0, 0); glVertex2f(0 * lado - lado / 2, 0 * lado - lado / 2);
	glEnd();
	glBegin(GL_POLYGON); //Borde superior del tablero
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(0 * lado - lado / 2, 7 * lado + lado / 2);
	glTexCoord2d(1, 1); glVertex2f(7 * lado + lado / 2, 7 * lado + lado / 2);
	glTexCoord2d(1, 0); glVertex2f(7 * lado + lado / 2 + 0.8 * lado, 7 * lado + lado / 2 + 0.8 * lado);
	glTexCoord2d(0, 0); glVertex2f(0 * lado - lado / 2 - 0.8 * lado, 7 * lado + lado / 2 + 2);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Tablero::borrarPiezas() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; i < 8; i++) {
			if (piezas[i][j] != nullptr)
				delete piezas[i][j];
		}
	}
}

void Tablero::quitarPieza(Pos posicion) { //hacer null el puntero a la pieza deseada, hacer "0" la posición de esa pieza (suponiendo que la pieza tuviera un atributo pos). Parece prescindible
	piezas[posicion.fila][posicion.columna] = nullptr;
}

void Tablero::quitarPiezaTablero(Pos posicion) { //hacer null el puntero a la pieza deseada, hacer "0" la posición de esa pieza (suponiendo que la pieza tuviera un atributo pos). Parece prescindible
	delete piezas[posicion.fila][posicion.columna];
	piezas[posicion.fila][posicion.columna] = nullptr;
}

void Tablero::setPieza(Pieza* p, Pos posicion) { //otorga a una pieza una posicion	
	piezas[posicion.fila][posicion.columna] = p;
}

void Tablero::setPiezaTablero(Pieza* p, Pos posicion) { //otorga a una pieza una posicion

	//En el caso en el que haya una pieza que vaya a ser comida utilizamos el delete
	if (piezas[posicion.fila][posicion.columna] != nullptr) {
		delete piezas[posicion.fila][posicion.columna];
		cout << "deleteada" << endl;
	}

	piezas[posicion.fila][posicion.columna] = p;
}

Pieza* Tablero::getPieza(Pos posicion) {
	return piezas[posicion.fila][posicion.columna];
}

void Tablero::dibujarPosibleCasilla(Pos posicion) { //se le da la posicion de los posibles movimientos para que sean graficados
	int n = 20; //Resolución
	float PI = 3.1415926f;
	float R = lado / 3; //Radio
	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; i++) {
		float theta = 2.0f * PI * i / n; //Obtencion del angulo
		float a = R * cos(theta); //Obtencion de la componente x
		float b = R * sin(theta); //Obtencion de la componente y
		glVertex3f(a + posicion.columna * lado, b + posicion.fila * lado, 0.05f);
	}
	glEnd();
}

//GETTERS y SETTERS PROVISIONALES
void Tablero::setLado(float l) {
	lado = l;
}

float Tablero::getLado() {
	return lado;
}

void Tablero::setValores(bool t) {
	if (t) {
		AJUSTE_X = 86;
		AJUSTE_Y = 813;
		LIM_CASILLA = 91;

	}
	else {
		AJUSTE_X = 58;
		AJUSTE_Y = 540;
		LIM_CASILLA = 60;
	}
	LIM_CASILLA, AJUSTE_X, AJUSTE_Y;
}
