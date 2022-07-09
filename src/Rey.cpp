#pragma once
#include "Rey.h"

bool Rey::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	for (int j = -1; j <= 1; j++) {
		for (int k = -1; k <= 1; k++) {
			Pos posaux(j, k);
			posaux = posaux + inicio;

			if (((j != 0) || (k != 0)) && (posaux.fila == fin.fila && posaux.columna == fin.columna)) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (color != tablero->getPieza(fin)->getColor()) {
					return true;
				}
			}
		}
	}
	return false;
}

void Rey::draw(float x, float y) {
	//en funcion del color de la pieza la dibuja en su posicion correspondiente

	switch (color) {
	case 0:
		ReyB.setCenter(lado / 2, lado / 2);
		ReyB.setSize(lado, lado);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		ReyB.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	case 1:
		ReyN.setCenter(lado / 2, lado / 2);
		ReyN.setSize(lado, lado);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		ReyN.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	}
}
