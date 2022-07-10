
#include "freeglut.h"
#include "Coordinador.h"
#include <iostream>
using namespace std;

//Declaración de los objetos globales donde se desarrolla toda la gestión del juego

Coordinador coordinador;

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnMouseClick(int, int, int,int);
void OnMotion(int, int);

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	while (coordinador.getRunning()) {

		coordinador.cambioEstado();
		coordinador.Inicializa();
		if (coordinador.getEstado() == PARTIDA_NORMAL || coordinador.getEstado() == PARTIDA_ESPECIAL) {
			glutDisplayFunc(OnDraw);
			glutMouseFunc(OnMouseClick);
			glutMotionFunc(OnMotion);
			glutMainLoop();
		}
	}
	return 0;

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
	if (coordinador.getEstado() == PARTIDA_NORMAL || coordinador.getMenu().getPartidaNormal() ) {
		coordinador.juego.dibujar();
		coordinador.juego.dibujarArrastrar();
	}
		
	if (coordinador.getEstado() == PARTIDA_ESPECIAL || !coordinador.getMenu().getPartidaNormal()/*|| coordinador.getEstado() == MENU*/) {
		coordinador.juegoACiegas.dibujar();
		coordinador.juegoACiegas.dibujarArrastrar();
	}
		
	
	//glutPostRedisplay();

	//Promueve el contenido del back buffer para poder realizar todos los cambios necesarios en la pantalla
	glutSwapBuffers();
}

void OnMouseClick(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) { //REVISAR CLICK DERECHO (MUY PELIGROSO) || button == GLUT_RIGHT_BUTTON
		bool pressed = (state == GLUT_DOWN);
		bool released = (state == GLUT_UP);
		//Ponemos click raton como un int de manera que cuando nos devielva un valor distinto de 0 se inicialice el menu de fin
		if(coordinador.getEstado() == PARTIDA_NORMAL || coordinador.getMenu().getPartidaNormal())
			coordinador.CambioEstadoDesdeJuego(coordinador.juego.clicRaton(pressed, released, x, y));//damero.colorear = damero.Raton(button, state, x, y);
		if (coordinador.getEstado() == PARTIDA_ESPECIAL || !coordinador.getMenu().getPartidaNormal())
			coordinador.CambioEstadoDesdeJuego(coordinador.juegoACiegas.clicRaton(pressed, released, x, y));
	}

}

void OnMotion(int x, int y) {
	//Llamada a función clicar/dejar de clicar de Coordinador, en función del estado en el que esté
	if (coordinador.getEstado() == PARTIDA_NORMAL || coordinador.getMenu().getPartidaNormal())
		coordinador.juego.movimientoRaton(x, y);
	if (coordinador.getEstado() == PARTIDA_ESPECIAL || !coordinador.getMenu().getPartidaNormal())
		coordinador.juegoACiegas.movimientoRaton(x, y);
	
	glutPostRedisplay();
}
