#include "Pieza.h"
#include "freeglut.h"

Pieza::Pieza() {
	tam = 1;
	rojo = 131;
	verde = 160;
	azul = 255;
	lado = 2.5f; //PROVISIONAL
}

Pieza::~Pieza() {

}

void Pieza::Mover() {
	switch (tipo) {
	default:
		break;
	case 1: //peon
		break;
	case 2: //rey
		break;
	case 3: //dama
		break;
	case 4: //alfil
		break;
	case 5: //caballo
		break;
	case 6: //torre
		break;
	}
}

void Pieza::Dibujar(V2D pcasilla, int tipo, bool color) {
	switch (tipo) {
	case 1:
		rojo = 255;
		verde = 0;
		azul = 0;
		break;
	case 2:
		rojo = 0;
		verde = 255;
		azul = 0;
		break;
	case 3:
		rojo = 0;
		verde = 0;
		azul = 255;
		break;
	case 4:
		rojo = 255;
		verde = 255;
		azul = 0;
		break;
	case 5:
		rojo = 255;
		verde = 0;
		azul = 255;
		break;
	case 6:
		rojo = 0;
		verde = 255;
		azul = 255;
		break;
	default:
		return;
		break;
	}
	if (color == 0) {
		glColor3ub(rojo, verde, azul);
		glTranslatef(lado * pcasilla.x, lado * pcasilla.y, 0.5);
		glutSolidSphere(tam / 2, 10, 10);
		glTranslatef(-lado * pcasilla.x, -lado * pcasilla.y, -0.5);
	}
	else {
		glColor3ub(rojo, verde, azul);
		glTranslatef(lado * pcasilla.x, lado * pcasilla.y, 0.5);
		glutSolidCube(tam);
		glTranslatef(-lado * pcasilla.x, -lado * pcasilla.y, -0.5);
	}
}