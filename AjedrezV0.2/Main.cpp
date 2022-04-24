#include "freeglut.h"
#include "math.h"
#include "Tablero.h"

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

Tablero damero;

int main(int argc, char* argv[]) {
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Ajedrez");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Inicializacion
	damero.Inicializar();

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);

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

	//Pruebas tablero
	gluLookAt(8.75, 8.75, 30,  // posicion del ojo
		8.75, 8.75, 0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Z)   

	//aqui es donde hay que poner el código de dibujo

	damero.DibujarTablero();
	damero.DibujarPiezas();

	//borde del tablero
	/*glColor3ub(255, 255, 255);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(24.0f, 0.0f, 0.0f);
	glVertex3f(24.0f, 24.0f, 0.0f);
	glVertex3f(0.0f, 24.0f, 0.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0f, 0.0f, -2.0f);
	glVertex3f(24.0f, 0.0f, -2.0f);
	glVertex3f(24.0f, 24.0f, -2.0f);
	glVertex3f(0.0f, 24.0f, -2.0f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -2.0f);
	glVertex3f(24.0f, 0.0f, 0.0f);
	glVertex3f(24.0f, 0.0f, -2.0f);
	glVertex3f(24.0f, 24.0f, 0.0f);
	glVertex3f(24.0f, 24.0f, -2.0f);
	glVertex3f(0.0f, 24.0f, 0.0f);
	glVertex3f(0.0f, 24.0f, -2.0f);
	glEnd();*/

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t) {

}

void OnTimer(int value) {
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
