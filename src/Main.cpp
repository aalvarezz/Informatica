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

	while (coordinador.getRunning()) {
		coordinador.Inicializa(argc, argv);
		//cout << "hola7" << endl;
	}

void OnMotion(int x, int y) {
	//Llamada a función arrastrar de Juego/Coordinador
	juego.movimientoRaton(x, y);
	glutPostRedisplay();
}*/

#include "freeglut.h"
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