#pragma once
#include "Caballo.h"
#include <math.h>

bool Caballo::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	for (int j = -2; j <= 2; j++) {
		for (int k = -2; k <= 2; k++) {
			if ((abs(j) != abs(k)) && (j != 0) && (k != 0)) {
				Pos posaux(j, k);
				posaux = posaux + inicio;

				//la casilla fin entra en las reglas
				if ((posaux.fila == fin.fila) && (posaux.columna == fin.columna)) {
					//Est� vac�a
					if (tablero->getPieza(fin) == nullptr) {
						return true;
					}
					//Hay una pieza del color contrario
					else if (tablero->getPieza(fin)->getColor() != color) {
						return true;
					}
				}				
			}
		}
	}
	return false;
}

void Caballo::dibujar(Pos posicion) {
	//traslado de la posici�n de la matriz a coordenadas de glut. x es la columna e y la fila porque las coordenadas de glut est�n invertidas.
	float x = posicion.columna * lado;
	float y = posicion.fila * lado;

	draw(x, y);
}

void Caballo::dibujarArrastrar(Pos posicion) {
	float x = posicion.fila;
	float y = posicion.columna;

	//Trasladar 0
	x -= AJUSTE_X;
	y -= AJUSTE_Y;

	//traslado de la posici�n del bitmap a coordenadas de glut.
	x = lado / LIM_CASILLA * x - (lado / 2);
	y = -lado / LIM_CASILLA * y - (lado / 2);

	draw(x, y);
}

void Caballo::draw(float x, float y) {
	//en funcion del color de la pieza la dibuja en su posicion correspondiente
	bool color = this->getColor();

	switch (color) {
	case 0:
		CaballoB.setCenter(lado / 2, lado / 2);
		CaballoB.setSize(lado, lado);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		CaballoB.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	case 1:
		CaballoN.setCenter(lado / 2, lado / 2);
		CaballoN.setSize(lado, lado);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		CaballoN.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	}
}
