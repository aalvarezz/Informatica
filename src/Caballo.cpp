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
				if (posaux == fin) {
					//Está vacía
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

void Caballo::draw(float x, float y) {
	//en funcion del color de la pieza la dibuja en su posicion correspondiente

	switch (color) {
	case 0:
		CaballoB.setCenter(2.5f / 2, 2.5f / 2);
		CaballoB.setSize(2.5f, 2.5f);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		CaballoB.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	case 1:
		CaballoN.setCenter(2.5f / 2, 2.5f / 2);
		CaballoN.setSize(2.5f, 2.5f);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		CaballoN.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	}
}
