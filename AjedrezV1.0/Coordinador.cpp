#include "Coordinador.h"
#include "freeglut.h"

Coordinador::Coordinador() {
	estado = INICIO;		
}

void Coordinador::Inicializa() {
	switch (estado) {
	default:
		break;

	case INICIO:
		
		//Inicializacion
		damero.inicializar();
		damero.crearPiezas();
		damero.inicializarPiezas();
		//damero.GetPieza().setTamano(tamano);
		

		
		break;
	}
}

void Coordinador::Dibuja() {
	switch (estado) {
	default:
		break;
	case INICIO:
		damero.dibujarTablero();
		damero.dibujarPiezas();
		break;
	case TURNO_BLANCAS:
		damero.dibujarTablero();
		damero.arrastrar();
		damero.dibujarPiezas();
		break;
	case TURNO_NEGRAS:
		damero.dibujarTablero();
		damero.arrastrar();
		damero.dibujarPiezas();
	}
}

void Coordinador::Tecla(int button, int state, int x, int y) {
	switch (estado) {
	default:
		break;
	case INICIO:
		if (button == GLUT_LEFT_BUTTON)
			estado = TURNO_BLANCAS;
		break;
		
	case TURNO_BLANCAS:

		if (button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON) {
			bool pressed = (state == GLUT_DOWN);
			bool released = (state == GLUT_UP);
			damero.raton(button, state, x, y);
			damero.setMouse(x, y, pressed, released);
		}
		if (damero.getTurnoN()) {
			estado = TURNO_NEGRAS;
		}
		break;
	case TURNO_NEGRAS:

		if (button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON) {
			bool pressed = (state == GLUT_DOWN);
			bool released = (state == GLUT_UP);
			damero.raton(button, state, x, y);
			damero.setMouse(x, y, pressed, released);
		}
		if (damero.getTurnoB()) {
			estado = TURNO_BLANCAS;
		}
	}
}

void Coordinador::Movimiento(int x, int y) {
	damero.movimiento(x, y);
}

void Coordinador::setTamano(bool a) {
	damero.setTamano(a);
}