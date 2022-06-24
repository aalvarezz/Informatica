#include "freeglut.h"

//Prototipos de los callbacks
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnMouseClick(int, int, int, int);
void OnMotion(int, int);

//Declaración de los objetos globales donde se desarrolla toda la gestión del juego
//Coordinador coordinador;
//Menu menu;

int main(int argc, char* argv[]) {

	/*
	//Inicialización
	menu.inicializa();

	SDL_Init(SDL_INIT_VIDEO);

	menu.ventana();

	menu.asigna();
	if (menu.getMenuSonido().getSonido()) {
		//ETSIDI::playMusica("Musica/WiiTheme.mp3", true);
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
		glutMotionFunc(OnMotion);

		//pasarle el control a GLUT,que llamara a los callbacks
		glutMainLoop();
	}*/
	return 0;
}

void OnDraw(void) {
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(8.75, 8.75, 34,  // posicion del ojo
		8.75, 8.75, 0,      // hacia qué punto mira  (8.75, 8.75, 0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Z)                          SEGURO??  

	//Código de dibujo
	//coordinador.Dibuja();

	//Promueve el contenido del back buffer para poder realizar todos los cambios necesarios en la pantalla
	glutSwapBuffers();
}

void OnMouseClick(int button, int state, int x, int y) {
	//coordinador.Tecla(button, state, x, y);

		//Llamada a función clicar/dejar de clicar de Juego/Coordinador

	glutPostRedisplay();
}

void OnMotion(int x, int y) {
	//coordinador.Movimiento(x, y);

		//Llamada a función arrastrar de Juego/Coordinador

	glutPostRedisplay();
}
