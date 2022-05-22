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
		damero.Inicializar();
		damero.crearPiezas();
		damero.InicializarPiezas();
		//damero.GetPieza().setTamano(tamano);
		

		
		break;
	}
}

void Coordinador::Dibuja() {
	switch (estado) {
	default:
		break;
	case INICIO:
		damero.DibujarTablero();
		break;

	case TURNO_BLANCAS:
		damero.DibujarPosiblesCasillas();	
		damero.DibujarTablero();
		damero.Arrastrar();
		damero.DibujarPiezas();
		break;
	case TURNO_NEGRAS:
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
		if (button == GLUT_LEFT_BUTTON)
			estado = TURNO_BLANCAS;
		break;
		
	case TURNO_BLANCAS:

		if (button == GLUT_LEFT_BUTTON) { //REVISAR CLICK DERECHO (MUY PELIGROSO) || button == GLUT_RIGHT_BUTTON
			bool pressed = (state == GLUT_DOWN);
			bool released = (state == GLUT_UP);
			damero.Raton(button, state, x, y); //damero.colorear = damero.Raton(button, state, x, y);
			damero.SetMouse(x, y, pressed, released);
		}
		if (!damero.getTurnoB()) {
			estado = TURNO_NEGRAS;
		}
		break;
	case TURNO_NEGRAS:

		if (button == GLUT_LEFT_BUTTON) { //REVISAR CLICK DERECHO (MUY PELIGROSO) || button == GLUT_RIGHT_BUTTON
			bool pressed = (state == GLUT_DOWN);
			bool released = (state == GLUT_UP);
			damero.Raton(button, state, x, y); //damero.colorear = damero.Raton(button, state, x, y);
			damero.SetMouse(x, y, pressed, released);
		}
		if (damero.getTurnoB()) {
			estado = TURNO_BLANCAS;
		}
	}
}

void Coordinador::Movimiento(int x, int y) {
	damero.Movimiento(x, y);
}

void Coordinador::setTamano(bool a) {
	damero.setTamano(a);
}