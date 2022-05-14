#include "Casilla.h"
#include "freeglut.h"

Casilla::Casilla() {
	pieza = NULL;
	lado = 2.5f;
	rojo = 0;
	verde = 0;
	azul = 0;
	estado = 0;
}

Casilla::~Casilla() {

}

void Casilla::Dibujar(int x, int y) {
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
	glVertex3f(x * lado - lado / 2, y * lado - lado / 2, 0);
	glVertex3f(x * lado + lado / 2, y * lado - lado / 2, 0);
	glVertex3f(x * lado + lado / 2, y * lado + lado / 2, 0);
	glVertex3f(x * lado - lado / 2, y * lado + lado / 2, 0);
	glEnd();
}

void Casilla::SetColor(int x, int y) {
	if (((y % 2) == 0) && ((x % 2) == 0) || ((y % 2) == 1) && ((x % 2) == 1)) {
		rojo = 87;
		verde = 70;
		azul = 0;
	}
	if (((y % 2) == 1) && ((x % 2) == 0) || ((y % 2) == 0) && ((x % 2) == 1)) {
		rojo = 255;
		verde = 253;
		azul = 208;
	}
}

void Casilla::SetPosicion(int x, int y) {
	pos.x = x;
	pos.y = y;
}

Pieza Casilla::GetPieza() {
	return pieza;
}

void Casilla::SetPieza(Pieza const &p) {
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

void Casilla::SetPosibilidad(int x, int y) { //pequeña revision
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
}