#include "Coordinador.h"

Coordinador::Coordinador() {
	estado = MENU;
	running = true;
	menu.setTamanoGrande();
}

void Coordinador::inicializar() {

	//Inicialización del menú
	if (estado == MENU) {
		menu.inicializar();
		SDL_Init(SDL_INIT_VIDEO);
		menu.ventana();
		menu.asignar();
		if (menu.getSonido()) {
			ETSIDI::playMusica("Musica/WiiTheme.mp3", true);
		}
		menu.evento();
		SDL_StopTextInput();
		menu.liberar();
	}
	
	//Inicialización del juego (cualquiera de los modos)
	else if (estado == PARTIDA_NORMAL || estado == PARTIDA_ESPECIAL) {
		
		glutInitWindowSize(menu.getAnchura(), menu.getAltura());
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		
		glutCreateWindow("Ajedrez");
		
		//Habilitar luces y definir perspectiva
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_COLOR_MATERIAL);
		glMatrixMode(GL_PROJECTION);
		gluPerspective(40.0, menu.getAnchura() / menu.getAltura(), 0.1, 150); //cuidado con tam ventana
		
		//Se eligen valores para los parámetro referidos al tamaño de la ventana en función de lo que se haya escogido en el menú
		int	LT, LC, AX, AY;
		if (menu.getTamano()) {
			LT = 728;
			LC = 91;
			AX = 86;
			AY = 813;
		}
		else {
			LT = 480;
			LC = 60;
			AX = 58;
			AY = 540;
		}
    
		//Se le pasa el control a la clase Juego
		if (estado == PARTIDA_NORMAL) {
			juego.inicializar(LT, LC, AX, AY);
		}
		else if (estado == PARTIDA_ESPECIAL) {
			juegoACiegas.inicializar(LT, LC, AX, AY);
		}

		cambioEstado();			
	}

	//Inicialización del menú de fin de partida
	else if (estado == FIN_DE_PARTIDA) {
		SDL_Init(SDL_INIT_VIDEO);
		menu.ventana();
		menu.asignarFinDePartida();
		menu.eventoFinDePartida();
		menu.liberarFinDePartida();
		cambioEstado();
	}
}

void Coordinador::cambioEstado() {
	
	//Se ejecuta un modo de juego u otro en función de lo elegido en el menú
	if (estado == MENU) {

		if (menu.getTableroRunning() && menu.getPartidaNormal()) {
			estado = PARTIDA_NORMAL;
		}

		if (menu.getTableroRunning() && !menu.getPartidaNormal()) {
			estado = PARTIDA_ESPECIAL;
		}
	}
}

void Coordinador::cambioEstadoDesdeJuego(int a) {

	//Victoria de las blancas
	if (a == 1) {
		menu.inicializarFinDePartida(true, false, false, false);
	}

	//Victoria de las negras
	else if (a == 2) {
		menu.inicializarFinDePartida(false, true, false, false);
	}

	//Tablas por rey blanco ahogado
	else if (a == 3) {
		menu.inicializarFinDePartida(false, false, true, false);
	}

	//Tablas por rey negro ahogado
	else if (a == 4) {
		menu.inicializarFinDePartida(false, false, false, true);
	}

	if (a != 0) { //Si a != 0, la partida ha finalizado de alguna forma
		int evento;
		estado = FIN_DE_PARTIDA;
		SDL_Init(SDL_INIT_VIDEO);
		menu.ventana();
		menu.asignarFinDePartida();
		evento = menu.eventoFinDePartida();
		menu.liberarFinDePartida();

		//Se eligen valores para los parámetro referidos al tamaño de la ventana en función de lo que se haya escogido en el menú
		int	LT, LC, AX, AY;
		if (menu.getTamano()) {
			LT = 728;
			LC = 91;
			AX = 86;
			AY = 813;
		}
		else {
			LT = 480;
			LC = 60;
			AX = 58;
			AY = 540;
		}

		//Volver a jugar
		if (evento == 1) {
			//Modo de juego tradicional
			if (menu.getPartidaNormal()) {
				estado = PARTIDA_NORMAL;
				juego.volverAJugar();
				juego.inicializar(LT, LC, AX, AY);
				juego.dibujar();
				juego.dibujarPiezas();
			}

			//Modo de juego especial
			else if (!menu.getPartidaNormal()) {
				estado = PARTIDA_ESPECIAL;
				juegoACiegas.volverAJugar();
				juegoACiegas.inicializar(LT, LC, AX, AY);
				juegoACiegas.dibujar();
				juegoACiegas.dibujarPiezas();
			}
		}

		//Volver al menú
		if (evento == 2) {
			estado = MENU;
			inicializar();

			//Modo de juego tradicional
			if (menu.getPartidaNormal()) {
				juego.volverAJugar();
				juego.inicializar(LT, LC, AX, AY);
				juego.dibujar();
				juego.dibujarPiezas();
			}

			//Modo de juego especial
			else if (!menu.getPartidaNormal()) {
				juegoACiegas.volverAJugar();
				juegoACiegas.inicializar(LT, LC, AX, AY);
				juegoACiegas.dibujar();
				juegoACiegas.dibujarPiezas();
			}
		}

		//Salir
		if (evento == 0) {
			exit(0);
		}
	}
}
