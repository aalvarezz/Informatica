#include "Casilla.h"
#include "freeglut.h"

Casilla::Casilla() {
	lado = 2.5f;
	rojo = 0;
	verde = 0;
	azul = 0;
}

Casilla::~Casilla() {

}

void Casilla::Dibujar(V2D p) {
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
	glVertex3f(p.x * lado - lado / 2, p.y * lado - lado / 2, 0);
	glVertex3f(p.x * lado + lado / 2, p.y * lado - lado / 2, 0);
	glVertex3f(p.x * lado + lado / 2, p.y * lado + lado / 2, 0);
	glVertex3f(p.x * lado - lado / 2, p.y * lado + lado / 2, 0);
	glEnd();
}

void Casilla::SetColor(V2D p) {
	if ((((int)p.y % 2) == 0 && ((int)p.x % 2) == 0) || (((int)p.y % 2) == 1 && ((int)p.x % 2) == 1)) {
		rojo = 87;
		verde = 70;
		azul = 0;
	}
	if ((((int)p.y % 2) == 1 && ((int)p.x % 2) == 0) || (((int)p.y % 2) == 0 && ((int)p.x % 2) == 1)) {
		rojo = 255;
		verde = 253;
		azul = 208;
	}
}

void Casilla::SetPosicion(float x, float y) {
	pos.x = x;
	pos.y = y;
}