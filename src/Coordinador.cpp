#include "Coordinador.h"
#include "freeglut.h"
#include "math.h"
#include <iostream>

using namespace std; //revisar

/////////////////////////////////////////////////////////
//Prototipos de los callbacks

Juego juego;

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnMouseClick(int, int, int, int);
void OnMotion(int, int);


Coordinador::Coordinador() {
	estado = MENU;
	running = true;
}

void Coordinador::Inicializa(int argc, char* argv[]) {
	if (estado == MENU) {
		menu.inicializa();
		SDL_Init(SDL_INIT_VIDEO);
		menu.ventana();
		menu.asigna();
		if (menu.getSonido()) {
			ETSIDI::playMusica("Musica/WiiTheme.mp3", true);
		}
		menu.evento();
		SDL_StopTextInput();
		menu.liberar();

		cambioEstado();
	}

	else if (estado == PARTIDA) {
		glutInitWindowSize(menu.getAnchura(), menu.getAltura());
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutCreateWindow("Ajedrez");

		//habilitar luces y definir perspectiva
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_COLOR_MATERIAL);
		glMatrixMode(GL_PROJECTION);
		gluPerspective(40.0, menu.getAnchura() / menu.getAltura(), 0.1, 150);

		cout << "hola5" << endl;

		// Inicializacion
		int LT, LC, AX, AY;
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
		juego.inicializar(LT, LC, AX, AY);
		cambioEstado();

		//Registrar los callbacks
		glutDisplayFunc(OnDraw);
		glutMouseFunc(OnMouseClick);
		glutMotionFunc(OnMotion);

		glutMainLoop();
	}

	else if (estado == FIN_DE_PARTIDA) {
		menu.inicializaFin();
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
		if (menu.getTableroRunning()) {
			estado = PARTIDA;
			//asignarTamano(menu.getTamano());
      ETSIDI::stopMusica();
			cout << "cambio estado" << endl;
		}
		if (!menu.getMenuRunning() && !menu.getTableroRunning()) {
			running = false;
		}
	}

	if (estado == FIN_DE_PARTIDA) {
		if (menu.getTableroRunning()) {
			estado = PARTIDA;
			//asignarTamano(menu.getTamano());
			cout << "cambio estado" << endl;
		}
		else if (menu.getMenuRunning()) {
			estado = MENU;
			cout << "cambio estado" << endl;
		}
	}
}

Estado Coordinador::getEstado() {
	return estado;
}

void OnDraw(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(8.75, 8.75, 34,  // posicion del ojo
		8.75, 8.75, 0,      // hacia qué punto mira  (8.75, 8.75, 0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Z)                          SEGURO??  

	//Código de dibujo
	//coordinador.Dibuja();

	juego.dibujar();

	glutPostRedisplay();

	//Promueve el contenido del back buffer para poder realizar todos los cambios necesarios en la pantalla
	glutSwapBuffers();
}


void OnMouseClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) { //REVISAR CLICK DERECHO (MUY PELIGROSO) || button == GLUT_RIGHT_BUTTON
		bool pressed = (state == GLUT_DOWN);
		bool released = (state == GLUT_UP);
		juego.clicRaton(pressed, released, x, y); //damero.colorear = damero.Raton(button, state, x, y);
	}
}

void OnMotion(int x, int y) {
	juego.movimientoRaton(x, y);
}
