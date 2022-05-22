#include <iostream>
#include "freeglut.h"
#include "math.h"
#include "Tablero.h"
#include <SDL.h>
#include <iostream>
#include "menu.h"
#include "Coordinador.h"
#include "ETSIDI.h"
//#define TAM_VENTANA 600

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
//void OnTimer(int); //esta funcion sera llamada cuando transcurra una temporizacion
//void OnKeyboardDown(unsigned char, int, int); //cuando se pulse una tecla
void OnMouseClick(int, int, int, int);
void Motion(int, int);
Coordinador coordinador;
Menu menu;
//Pieza fichas; //??
//bool mouse_pressed, mouse_released;

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




	if (menu.getTableroRunning()) //yo pondira while cuando lo tenga implementado lo cambio
	{

		coordinador.setTamano(menu.getMenuTamano().getGra());

		//Inicializar el gestor de ventanas GLUT
		//y crear la ventana
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
		//glutTimerFunc(25, OnTimer, 0); //le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer() //NO USADO
		//glutKeyboardFunc(OnKeyboardDown); //NO USADO

		//pasarle el control a GLUT,que llamara a los callbacks
		glutMainLoop();
	}
	return 0;
}

void OnDraw(void) {
	//V2D mouse_pos;
	//int mouseposx, mouseposy;
	//Pieza pieza_aux; //?

	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(8.75, 8.75, 34,  // posicion del ojo
		8.75, 8.75, 0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Z)   

	//aqui es donde hay que poner el código de dibujo

		//if con el que se mostrarán los posibles movimientos de la pieza en función del tipo de pieza seleccionada
	//if (damero.colorear > 0 && damero.colorear < 13)
		//fichas.Posibilidades(damero.colorear, damero.columna0, damero.fila0);
	coordinador.Dibuja();

	//Promueve el contenido del back buffer para poder realizar todos los cambios necesarios en la pantalla
	glutSwapBuffers();
}

void OnMouseClick(int button, int state, int x, int y) {
	coordinador.Tecla(button, state, x, y);
	glutPostRedisplay();
}

void Motion(int x, int y) {
	coordinador.Movimiento(x, y);
	glutPostRedisplay();
}
