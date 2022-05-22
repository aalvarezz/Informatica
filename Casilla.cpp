#include "Casilla.h"
#include "freeglut.h"

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
	estado = 0;
}

Casilla::Casilla() {

}

Casilla::~Casilla() {

}

void Casilla::Dibujar(int x, int y) { //Implementar aqui el dibujo de la casilla posible
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
	glVertex3f(x * lado - lado / 2, y * lado - lado / 2, 0);
	glVertex3f(x * lado + lado / 2, y * lado - lado / 2, 0);
	glVertex3f(x * lado + lado / 2, y * lado + lado / 2, 0);
	glVertex3f(x * lado - lado / 2, y * lado + lado / 2, 0);
	glEnd();
}

void Casilla::SetColor(int x, int y) {
	/*if (((y % 2) == 0) && ((x % 2) == 0) || ((y % 2) == 1) && ((x % 2) == 1)) {
		rojo = 87;
		verde = 70;
		azul = 0;
	}
	if (((y % 2) == 1) && ((x % 2) == 0) || ((y % 2) == 0) && ((x % 2) == 1)) {
		rojo = 255;
		verde = 253;
		azul = 208;
	}*/
}

void Casilla::SetPosicion(int x, int y) {
	pos.fila = x;
	pos.columna = y;
}

Pieza Casilla::GetPieza() {
	return pieza;
}

void Casilla::SetPieza(Pieza p) {
	pieza = p;
	estado = 1;
}

bool Casilla::GetEstado() {
	return estado;
}

void Casilla::SetEstado(bool e) {
	estado = e;
}

void Casilla::QuitarPieza() {
	estado = 0;
	//AÑADIR CODIGO PARA DESREFERENCIAR LA PIEZA
	pieza = NULL;
}

/*void Casilla::SetPosibilidad(int x, int y) { //Programacion muy criminal, con un flag vale
	if (((y % 2) == 0) && ((x % 2) == 0) || ((y % 2) == 1) && ((x % 2) == 1)) {

		//glTranslatef(0, 0, 0);
		glColor3ub(255, 0, 0);
		glBegin(GL_POLYGON);
		glVertex3f(x * lado - lado / 2, y * lado - lado / 2, 0);
		glVertex3f(x * lado + lado / 2, y * lado - lado / 2, 0);
		glVertex3f(x * lado + lado / 2, y * lado + lado / 2, 0);
		glVertex3f(x * lado - lado / 2, y * lado + lado / 2, 0);
		glEnd();
		//glTranslatef(0, 0, 0);
		glutPostRedisplay();
	}
	if (((y % 2) == 1) && ((x % 2) == 0) || ((y % 2) == 0) && ((x % 2) == 1)) {

		//glTranslatef(0, 0, 0);
		glColor3ub(0, 0, 255);
		glBegin(GL_POLYGON);
		glVertex3f(x * lado - lado / 2, y * lado - lado / 2, 0);
		glVertex3f(x * lado + lado / 2, y * lado - lado / 2, 0);
		glVertex3f(x * lado + lado / 2, y * lado + lado / 2, 0);
		glVertex3f(x * lado - lado / 2, y * lado + lado / 2, 0);
		glEnd();
		//glTranslatef(0, 0, 0);
		glutPostRedisplay();
	}
}*/

void Casilla::SetPosibilidad(Casilla c) { //Programacion muy criminal, con un flag vale
	posible = true;
	if (posible) {
		int n = 20; // Resolución
		float PI = 3.1415926f;
		float R = lado / 3; // radio
		glColor3ub(255, 0, 0);
		glBegin(GL_POLYGON);
		for (int ii = 0; ii < n; ii++) {
			float theta = 2.0f * PI * ii / n;//get the current angle 
			float a = R * cos(theta);//calculate the x component 
			float b = R * sin(theta);//calculate the y component 
			glVertex3f(a + c.getPos().columna * lado, b + c.getPos().fila * lado, 0.05f);//output vertex 
		}

		glEnd();
		posible = false;
		glutPostRedisplay();
	}

}

bool Casilla::operator==(Casilla c) {
	return (c.fila == fila && c.columna == columna);
}

Pos Casilla::getPos()
{
	Pos res;
	res.fila = fila;
	res.columna = columna;
	return res;
}