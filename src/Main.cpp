#include "Coordinador.h"

//Prototipos de los callbacks
void OnDraw(void);
void OnMouseClick(int, int, int, int);
void OnMotion(int, int);

//Declaración de los objetos globales donde se desarrolla toda la gestión del juego
Coordinador coordinador;

int main(int argc, char* argv[]) {

	//Inicialización del gestor de glut, debe ser llamado en main
	glutInit(&argc, argv);

	//Bucle general del programa, está activo mientras el coordinador esté realizando alguna acción
	while (coordinador.getRunning()) {
		//Inicialización del coordinador. Aquí se gestiona la parte de SDL
		coordinador.cambioEstado();
		coordinador.inicializar();

		//En el caso de que se elija jugar una partida se registran los callbacks de GLUT y se le cede el control
		if (coordinador.getEstado() == PARTIDA_NORMAL || coordinador.getEstado() == PARTIDA_ESPECIAL) {
			//Se registran los callbacks
			glutDisplayFunc(OnDraw);
			glutMouseFunc(OnMouseClick);
			glutMotionFunc(OnMotion);

			//Se le pasa el control a GLUT, que llamará a los callbacks cuando detecte su respectivo evento
			glutMainLoop();
		}
	}
	return 0;
}

void OnDraw(void) {
	//Borrado de la pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(8.75, 8.75, 34,  //Posición del punto de vista
		8.75, 8.75, 0,      //Hacia qué punto mira (8.75, 8.75, 0) 
		0.0, 1.0, 0.0);      //Se define hacia arriba el eje Y

	//Código de dibujo para la el modo de partida tradicional
	if (coordinador.getEstado() == PARTIDA_NORMAL || coordinador.getMenu().getPartidaNormal()) {
		coordinador.juego.dibujar();
	}
	
	//Código de dibujo para la el modo de partida especial
	if (coordinador.getEstado() == PARTIDA_ESPECIAL || !coordinador.getMenu().getPartidaNormal()) {
		coordinador.juegoACiegas.dibujar();
	}

	//Promueve el contenido del back buffer para poder realizar todos los cambios necesarios en la pantalla
	glutSwapBuffers();
}

void OnMouseClick(int button, int state, int x, int y) {
	//Llamada a función que realiza las acciones correspondientes a arrastrar el raton (glut detecta que el clic está presionado y el cursor está en movimiento)
	if (button == GLUT_LEFT_BUTTON) {
		bool pressed = (state == GLUT_DOWN);
		bool released = (state == GLUT_UP);

		//clicRaton() devuelve un int para gestionar el fin de partida en función del valor devuelto
		if (coordinador.getEstado() == PARTIDA_NORMAL || coordinador.getMenu().getPartidaNormal()) {
			coordinador.cambioEstadoDesdeJuego(coordinador.juego.clicRaton(pressed, released, x, y));
		}
		if (coordinador.getEstado() == PARTIDA_ESPECIAL || !coordinador.getMenu().getPartidaNormal()) {
			coordinador.cambioEstadoDesdeJuego(coordinador.juegoACiegas.clicRaton(pressed, released, x, y));
		}
	}
}

void OnMotion(int x, int y) {
	//Llamada a función que realiza las acciones correspondientes a clicar/dejar de clicar
	if (coordinador.getEstado() == PARTIDA_NORMAL || coordinador.getMenu().getPartidaNormal()) {
		coordinador.juego.movimientoRaton(x, y);
	}
	if (coordinador.getEstado() == PARTIDA_ESPECIAL || !coordinador.getMenu().getPartidaNormal()) {
		coordinador.juegoACiegas.movimientoRaton(x, y);
	}
	
	glutPostRedisplay();
}
