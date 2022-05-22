#include "Casilla.h"
#include "freeglut.h"

#include <iostream>

Casilla::Casilla(int i, int j) {
	fila = i;
	columna = j;

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

	pieza = NULL;
	lado = 2.5f;
	estado = false;
	posible = false;
}

Casilla::Casilla() {

}

Casilla::~Casilla() {

}

<<<<<<< Updated upstream
void Casilla::Dibujar() {
=======
void Casilla::dibujar() {
>>>>>>> Stashed changes
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
	glVertex3f(fila * lado - lado / 2, columna * lado - lado / 2, 0);
	glVertex3f(fila * lado + lado / 2, columna * lado - lado / 2, 0);
	glVertex3f(fila * lado + lado / 2, columna * lado + lado / 2, 0);
	glVertex3f(fila * lado - lado / 2, columna * lado + lado / 2, 0);
	glEnd();
}

<<<<<<< Updated upstream
void Casilla::SetPosicion(int x, int y) {
=======
void Casilla::setPosicion(int x, int y) {
>>>>>>> Stashed changes
	pos.fila = x;
	pos.columna = y;
}

<<<<<<< Updated upstream
Pieza Casilla::GetPieza() {
	return pieza;
}

void Casilla::SetPieza(Pieza p) {
=======
Pieza Casilla::getPieza() {
	return pieza;
}

void Casilla::setPieza(Pieza p) {
>>>>>>> Stashed changes
	pieza = p;
	estado = 1;
}

<<<<<<< Updated upstream
bool Casilla::GetEstado() {
	return estado;
}

void Casilla::SetEstado(bool e) {
=======
bool Casilla::getEstado() {
	return estado;
}

void Casilla::setEstado(bool e) {
>>>>>>> Stashed changes
	estado = e;
}

Pos Casilla::getPos() {
	Pos res;
	res.fila = fila;
	res.columna = columna;
	return res;
}

<<<<<<< Updated upstream
void Casilla::QuitarPieza() {
=======
void Casilla::quitarPieza() {
>>>>>>> Stashed changes
	estado = 0;
	//AÑADIR CODIGO PARA DESREFERENCIAR LA PIEZA
	pieza = NULL;
}

void Casilla::setPosibilidad() {
	posible = true;
}

void Casilla::delPosibilidad() {
	posible = false;
}

void Casilla::dibujarPosible() {
	if (posible) {
		int n = 20; // Resolución
		float PI = 3.1415926f;
		float R = lado / 3; // radio
		glColor3ub(255, 0, 0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < n; i++) {
			float theta = 2.0f * PI * i / n; //get the current angle 
			float a = R * cos(theta); //calculate the x component 
			float b = R * sin(theta); //calculate the y component 
			glVertex3f(a + columna * lado, b + fila * lado, 0.05f); //output vertex 
		}
		glEnd();
		glutPostRedisplay();
	}
}

bool Casilla::operator==(Casilla c) {
	return (c.fila == fila && c.columna == columna);
}
