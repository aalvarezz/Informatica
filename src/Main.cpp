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