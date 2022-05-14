#include "Coordinador.h"

Coordinador::Coordinador() {
	estado = JUEGO;		//No cambiar hasta incorporar menus
}

void Coordinador::Inicializa() {
	switch (estado) {
	default:
		break;
	case INICIO:
		
		break;
	case JUEGO:

		//Inicializacion
		damero.Inicializar();
		damero.InicializarPiezas();
		break;
	}
}

void Coordinador::Dibuja() {
	switch (estado) {
	default:
		break;
	case INICIO:

		break;
	case JUEGO:

		damero.DibujarPosiblesCasillas();
		damero.DibujarTablero();
		damero.Arrastrar();
		damero.DibujarPiezas();
	}
}

void Coordinador::Tecla(int button, int state, int x, int y) {
	//Podríamos añadir que cambie de menú tambien con el ratón??
	switch (estado) {
	default:
		break;
	case INICIO:

		break;
	case JUEGO:

		if (button == GLUT_LEFT_BUTTON) { //REVISAR CLICK DERECHO (MUY PELIGROSO) || button == GLUT_RIGHT_BUTTON
			bool pressed = (state == GLUT_DOWN);
			bool released = (state == GLUT_UP);
			damero.Raton(button, state, x, y); //damero.colorear = damero.Raton(button, state, x, y);
			damero.SetMouse(x, y, pressed, released);
		}
	}
}

void Coordinador::Movimiento(int x, int y) {
	damero.Movimiento(x, y);
}