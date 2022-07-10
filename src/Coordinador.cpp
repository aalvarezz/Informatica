#include "Coordinador.h"
#include "freeglut.h"
#include "math.h"
#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////
//Prototipos de los callbacks



Coordinador::Coordinador() {
	estado = MENU;
	running = true;
}

void Coordinador::Inicializa() {
	if (estado == MENU) {
		menu.inicializa();
		SDL_Init(SDL_INIT_VIDEO);
		menu.ventana();
		menu.asigna();
		if (menu.getSonido()) {
			//ETSIDI::playMusica("Musica/WiiTheme.mp3", true);
		}
		menu.evento();
		SDL_StopTextInput();
		menu.liberar();
	}
	
	else if (estado == PARTIDA_NORMAL || estado == PARTIDA_ESPECIAL) {
		
		//glutInit(&argc, argv);
		glutInitWindowSize(menu.getAnchura(), menu.getAltura());
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		
		glutCreateWindow("Ajedrez");
		
		//habilitar luces y definir perspectiva
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_COLOR_MATERIAL);
		glMatrixMode(GL_PROJECTION);
		gluPerspective(40.0, menu.getAnchura() / menu.getAltura(), 0.1, 150); //cuidado con tam ventana
		

		cout << "hola5" << endl;

			
		asignarTamano(menu.getTamano());
		// Inicializacion
		if (estado == PARTIDA_NORMAL)
			juego.inicializar();
		else if (estado == PARTIDA_ESPECIAL)
			juegoACiegas.inicializar();
		cambioEstado();			
	}

	else if (estado == FIN_DE_PARTIDA) {
		//menu.inicializaFin();
		SDL_Init(SDL_INIT_VIDEO);
		menu.ventana();
		menu.asignaFin();
		menu.eventoFin();
		menu.liberarFin();
		cambioEstado();
		
	}

}

void Coordinador::cambioEstado() {

	if (estado == MENU) {
		if (menu.getTableroRunning() && menu.getPartidaNormal()) {
			//juego.setTamano(menu.getMenuTamano());
			estado = PARTIDA_NORMAL;
			asignarTamano(menu.getTamano());
			cout << "cambio estado" << endl;
		}

		if (menu.getTableroRunning() && !menu.getPartidaNormal()) {
			//juego.setTamano(menu.getMenuTamano());
			estado = PARTIDA_ESPECIAL;
			asignarTamano(menu.getTamano());
			cout << "cambio estado" << endl;
		}
	}
}

Estado Coordinador::getEstado() {
	return estado;
}

void Coordinador::asignarTamano(bool t) {
	juego.setValores(t);
	juegoACiegas.setValores(t);
}

void Coordinador::CambioEstadoDesdeJuego(int a) {
	{

		if (a == 1) {			
			menu.inicializaFin(true,false,false,false);	
		}
		else if (a == 2) {
			menu.inicializaFin(false,true, false, false);
		}
		else if (a == 3) {
			menu.inicializaFin(false, false, true, false);
		}
		else if (a == 4) {
			menu.inicializaFin(false, false, false, true);
		}
		
		if (a != 0) {
			int evento;
			estado = FIN_DE_PARTIDA;
			SDL_Init(SDL_INIT_VIDEO);
			menu.ventana();
			menu.asignaFin();
			evento = menu.eventoFin();
			menu.liberarFin();
			if (evento == 1) {
				if (menu.getPartidaNormal()) {
					estado = PARTIDA_NORMAL;
					juego.volverAJugar();
					juego.inicializar();
					juego.dibujar();
					juego.dibujarPiezas();
				}
				else if (!menu.getPartidaNormal()) {
					estado = PARTIDA_ESPECIAL;
					juegoACiegas.volverAJugar();
					juegoACiegas.inicializar();
					juegoACiegas.dibujar();
					juegoACiegas.dibujarPiezas();
				}
			}
			if (evento == 2) {
				estado = MENU;
				Inicializa();
				if (menu.getPartidaNormal()) {
					juego.volverAJugar();
					juego.inicializar();
					juego.dibujar();
					juego.dibujarPiezas();	
					juego.setValores(menu.getTamano());
				}
				else if (!menu.getPartidaNormal()) {
					juegoACiegas.volverAJugar();
					juegoACiegas.inicializar();
					juegoACiegas.dibujar();
					juegoACiegas.dibujarPiezas();
					juegoACiegas.setValores(menu.getTamano());
				}
				
			}
			if (evento == 0)
				exit(0);
		}
	}

}