#include "Coordinador.h"

Coordinador::Coordinador() {
	estado = INICIO;
}

void Coordinador::Inicializa() {
	switch (estado) {
	default:
		break;

	case INICIO:
		menu.inicializa();
		SDL_Init(SDL_INIT_VIDEO);
		menu.ventana();
		menu.asigna();
		if (menu.getMenuSonido()) {
			//ETSIDI::playMusica("Musica/WiiTheme.mp3", true);
		}
		menu.evento();

		SDL_StopTextInput();

		menu.liberar();

		menu.ventana();
		SDL_Init(SDL_INIT_VIDEO);
		menu.ventana();
		menu.asigna();
		turno_1 = true;
		//Inicializacion
		
		//damero.GetPieza().setTamano(tamano);

		break;
	case TURNO_B:
		//para el inicio del juego el primer turno
		if (turno_1) {
			juego.inicializar();
		});
		break;

	//en el turno negro no se iniializa nada
	case TURNO_N:
		
		break;
	
	case FIN_DE_PARTIDA:
		menu.inicializa_fin();
		menu.asigna_fin();
		break;
	}

}

void Coordinador::Dibuja() {
	switch (estado) {
	default:
		break;

	case INICIO:

		break;

	case TURNO_B:
		juego.arrastrar();
		juego.movimientoValido();
		break;
		

	case TURNO_N:
		juego.arrastrar();
		juego.movimientoValido();
		break;
	}


}

void Coordinador::cambioEstado(int button, int state, int x, int y) {
	switch (estado) {
	default:
		break;
	case INICIO:
		if (!menu.getTableroRunning()) {
			//juego.setTamano(menu.getMenuTamano());
			
			glEnable(GL_LIGHT0);
			glEnable(GL_LIGHTING);
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_COLOR_MATERIAL);
			glMatrixMode(GL_PROJECTION);
			gluPerspective(40.0, menu.getAltura() / menu.getAnchura(), 0.1, 150); //cuidado con tam ventana

			estado = TURNO_B;

		}
			

		break;

	case TURNO_B:
		//como hagamos el cambio de turno, lo de abajo es como lo teniamos hecho
		if (button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON) {
			bool pressed = (state == GLUT_DOWN);
			bool released = (state == GLUT_UP);
			damero.raton(button, state, x, y);
			damero.setMouse(x, y, pressed, released);
		}
		if (damero.getTurnoN()) {
			estado = TURNO_NEGRAS;
		}

		//añadir para final de partida
		if (juego.getJaqueMate() || juego.getAhogado()) {
			estado = FIN_DE_PARTIDA;
		}
		break;
	case TURNO_N:
		// como hagamos el cambio de turno, lo de abajo es como lo teniamos hecho
		if (button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON) {
			bool pressed = (state == GLUT_DOWN);
			bool released = (state == GLUT_UP);
			damero.raton(button, state, x, y);
			damero.setMouse(x, y, pressed, released);
		}
		if (damero.getTurnoB()) {
			estado = TURNO_B;
		}

		//añadir para final de partida
		if (juego.getJaqueMate() || juego.getAhogado()) {
			estado = FIN_DE_PARTIDA;
		}
		break;
	case FIN_DE_PARTIDA:
		if (menu.getTableroRunning()) {
			estado = INICIO;
		}

		if (juego.getJuegoRunning()) {
			estado = TURNO_B;
		}
	}
}