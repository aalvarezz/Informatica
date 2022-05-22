#include <iostream>
#include "freeglut.h"
#include "math.h"
#include "Tablero.h"
<<<<<<< Updated upstream

#define TAM_VENTANA 900
=======
#include <SDL.h>
#include <iostream>
#include "menu.h"
#include "Coordinador.h"
>>>>>>> Stashed changes

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnMouseClick(int, int, int, int);
void Motion(int, int);
<<<<<<< Updated upstream

Tablero damero;

int main(int argc, char* argv[]) {
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventanaç
	glutInit(&argc, argv);
	glutInitWindowSize(TAM_VENTANA, TAM_VENTANA);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Ajedrez");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, TAM_VENTANA / TAM_VENTANA, 0.1, 150); //cuidado con tam ventana

	//Inicializacion
	damero.Inicializar();
	damero.crearPiezas();
	damero.InicializarPiezas();

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutMouseFunc(OnMouseClick);
	glutMotionFunc(Motion);
	//glutTimerFunc(25, OnTimer, 0); //le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer() //NO USADO
	//glutKeyboardFunc(OnKeyboardDown); //NO USADO

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

=======
Coordinador coordinador;
Menu menu;

int main(int argc, char* argv[]) {

	menu.inicializa();

	SDL_Init(SDL_INIT_VIDEO);

	menu.ventana();

	menu.asigna();
	if (menu.getMenuSonido().getSonido()) {
		ETSIDI::playMusica("Musica/WiiTheme.mp3", true);
	}

	menu.evento();

	SDL_StopTextInput();

	menu.liberar();

	if (menu.getTableroRunning()) {

		coordinador.setTamano(menu.getMenuTamano().getGra());

		//Inicializar el gestor de ventanas GLUT y crear la ventana
		glutInit(&argc, argv);
		glutInitWindowSize(menu.getMenuTamano().getAltura(), menu.getMenuTamano().getAnchura());
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutCreateWindow("Ajedrez");

		//habilitar luces y definir perspectiva
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_COLOR_MATERIAL);
		glMatrixMode(GL_PROJECTION);
		gluPerspective(40.0, menu.getMenuTamano().getAltura() / menu.getMenuTamano().getAnchura(), 0.1, 150); //cuidado con tam ventana

		//Inicializacion
		coordinador.Inicializa();

		//Registrar los callbacks
		glutDisplayFunc(OnDraw);
		glutMouseFunc(OnMouseClick);
		glutMotionFunc(Motion);

		//pasarle el control a GLUT,que llamara a los callbacks
		glutMainLoop();
	}
>>>>>>> Stashed changes
	return 0;
}

void OnDraw(void) {
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(8.75, 8.75, 34,  // posicion del ojo
		8.75, 8.75, 0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Z)   

<<<<<<< Updated upstream
	//Código de dibujo
	damero.DibujarTablero();
	damero.Arrastrar();
	//damero.DibujarPosiblesCasillas();
	damero.DibujarPiezas();
=======
	//aqui es donde hay que poner el código de dibujo
	coordinador.Dibuja();
>>>>>>> Stashed changes

	//Promueve el contenido del back buffer para poder realizar todos los cambios necesarios en la pantalla
	glutSwapBuffers();
}

void OnMouseClick(int button, int state, int x, int y) {
<<<<<<< Updated upstream
	if (button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON) {
		bool pressed = (state == GLUT_DOWN);
		bool released = (state == GLUT_UP);
		damero.Raton(button, state, x, y);
		damero.SetMouse(x, y, pressed, released);
	}
=======
	coordinador.Tecla(button, state, x, y);
>>>>>>> Stashed changes
	glutPostRedisplay();
}

void Motion(int x, int y) {
<<<<<<< Updated upstream
	damero.Movimiento(x, y);
=======
	coordinador.Movimiento(x, y);
>>>>>>> Stashed changes
	glutPostRedisplay();
}
