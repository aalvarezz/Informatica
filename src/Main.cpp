/*#include "freeglut.h"

#include "Juego.h"

#define TAM_VENTANA 900 //PROVISIONAL

//Prototipos de los callbacks
void OnDraw(void);
void OnMouseClick(int, int, int, int);
void OnMotion(int, int);

//Declaración de los objetos globales donde se desarrolla toda la gestión del juego
//Coordinador coordinador;
//Menu menu;

Juego juego;

int main(int argc, char* argv[]) {

	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
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
	juego.inicializar();

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutMouseFunc(OnMouseClick);
	glutMotionFunc(OnMotion);

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void) {
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(8.75, 8.75, 34,  //Posicion del ojo
		8.75, 8.75, 0,      //Hacia qué punto mira  (8.75, 8.75, 0) 
		0.0, 1.0, 0.0);      //Definimos el eje Y hacia arriba 

	//Código de dibujo
	//coordinador.Dibuja();
	juego.dibujar();
	juego.dibujarArrastrar();
	//glutPostRedisplay();

	//Promueve el contenido del back buffer para poder realizar todos los cambios necesarios en la pantalla
	glutSwapBuffers();
}

void OnMouseClick(int button, int state, int x, int y) {
	//Llamada a función clicar/dejar de clicar de Juego/Coordinador
	if (button == GLUT_LEFT_BUTTON) { //REVISAR CLICK DERECHO (MUY PELIGROSO) || button == GLUT_RIGHT_BUTTON
		bool pressed = (state == GLUT_DOWN);
		bool released = (state == GLUT_UP);
		juego.clicRaton(pressed, released, x, y); //damero.colorear = damero.Raton(button, state, x, y);
	}
	//glutPostRedisplay();
}

void OnMotion(int x, int y) {
	//Llamada a función arrastrar de Juego/Coordinador
	juego.movimientoRaton(x, y);
	glutPostRedisplay();
}*/

//#include "freeglut.h"
#include "Coordinador.h"

#include <iostream>
using namespace std;

//Declaración de los objetos globales donde se desarrolla toda la gestión del juego

Coordinador coordinador;


int main(int argc, char* argv[]) {

	glutInit(&argc, argv);

	while (coordinador.getRunning()) {
		coordinador.Inicializa(argc, argv);
		//cout << "hola7" << endl;
	}

	return 0;
}