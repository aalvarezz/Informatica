#pragma once
#include "Dama.h"

bool Dama::comprueba(Tablero* tablero, Pos inicio, Pos fin) {
	int sentido = 0;
	for (int j = 1; j <= 7; j++) {
		Pos aux1(0, j), aux2(0, -j), aux3(j, 0), aux4(-j, 0), aux5(j, j), aux6(j, -j), aux7(-j, -j), aux8(-j, j);
		aux1 = aux1 + inicio;
		aux2 = aux2 + inicio;
		aux3 = aux3 + inicio;
		aux4 = aux4 + inicio;
		aux5 = aux5 + inicio;
		aux6 = aux6 + inicio;
		aux7 = aux7 + inicio;
		aux8 = aux8 + inicio;

		if (aux1.fila == fin.fila && aux1.columna == fin.columna)
			sentido = 1;
		if (aux2.fila == fin.fila && aux2.columna == fin.columna)
			sentido = 2;
		if (aux3.fila == fin.fila && aux3.columna == fin.columna)
			sentido = 3;
		if (aux4.fila == fin.fila && aux4.columna == fin.columna)
			sentido = 4;
		if (aux5.fila == fin.fila && aux5.columna == fin.columna)
			sentido = 5;
		if (aux6.fila == fin.fila && aux6.columna == fin.columna)
			sentido = 6;
		if (aux7.fila == fin.fila && aux7.columna == fin.columna)
			sentido = 7;
		if (aux8.fila == fin.fila && aux8.columna == fin.columna)
			sentido = 8;
	}

	switch (sentido) {
	case 0:
		return false;
		break;

	case 1:	// 1. Hacia arriba
		for (int j = 1; j <= 7; j++) {
			Pos posaux1(0, j);
			posaux1 = posaux1 + inicio;

			if (posaux1.fila == fin.fila && posaux1.columna == fin.columna) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux1) != nullptr)
				return false;
		}
		break;

	case 2:	// 2. Hacia abajo
		for (int j = 1; j <= 7; j++) {
			Pos posaux2(0, -j);
			posaux2 = posaux2 + inicio;

			if (posaux2.fila == fin.fila && posaux2.columna == fin.columna) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux2) != nullptr)
				return false;
		}
		break;

	case 3:	// 3. Derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux3(j, 0);
			posaux3 = posaux3 + inicio;

			if (posaux3.fila == fin.fila && posaux3.columna == fin.columna) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux3) != nullptr)
				return false;
		}
		break;

	case 4:	//4. Izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux4(-j, j);
			posaux4 = posaux4 + inicio;

			if (posaux4.fila == fin.fila && posaux4.columna == fin.columna) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux4) != nullptr)
				return false;
		}
		break;

	case 5:	//5. Arriba derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux5(j, j);
			posaux5 = posaux5 + inicio;

			if (posaux5.fila == fin.fila && posaux5.columna == fin.columna) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux5) != nullptr)
				return false;
		}
		break;

	case 6:	//6. Abajo derecha
		for (int j = 1; j <= 7; j++) {
			Pos posaux6(-j, j);
			posaux6 = posaux6 + inicio;

			if (posaux6.fila == fin.fila && posaux6.columna == fin.columna) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux6) != nullptr)
				return false;
		}
		break;

	case 7:	//7. Abajo izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux7(-j, -j);
			posaux7 = posaux7 + inicio;

			if (posaux7.fila == fin.fila && posaux7.columna == fin.columna) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux7) != nullptr)
				return false;
		}
		break;

	case 8: //8. Arriba izquierda
		for (int j = 1; j <= 7; j++) {
			Pos posaux8(-j, j);
			posaux8 = posaux8 + inicio;

			if (posaux8.fila == fin.fila && posaux8.columna == fin.columna) {
				if (tablero->getPieza(fin) == nullptr) {
					return true;
				}
				else if (tablero->getPieza(fin)->getColor() != color) {
					return true;
				}
				return false;
			}
			else if (tablero->getPieza(posaux8) != nullptr)
				return false;
		}
		break;

	}
	return false;
}

void Dama::dibujar(Pos posicion) {
	//traslado de la posición de la matriz a coordenadas de glut. x es la columna e y la fila porque las coordenadas de glut están invertidas.
	float x = posicion.columna * lado;
	float y = posicion.fila * lado;

	draw(x, y);
}

void Dama::dibujarArrastrar(Pos posicion) {
	float x = posicion.fila;
	float y = posicion.columna;

	//Trasladar 0
	x -= AJUSTE_X;
	y -= AJUSTE_Y;

	//traslado de la posición del bitmap a coordenadas de glut.
	x = lado / LIM_CASILLA * x - (lado / 2);
	y = -lado / LIM_CASILLA * y - (lado / 2);

	draw(x, y);
}

void Dama::draw(float x, float y) {
	//en funcion del color de la pieza la dibuja en su posicion correspondiente
	bool color = this->getColor();

	switch (color) {
	case 0:
		DamaB.setCenter(lado / 2, lado / 2);
		DamaB.setSize(lado, lado);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		DamaB.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	case 1:
		DamaN.setCenter(lado / 2, lado / 2);
		DamaN.setSize(lado, lado);
		glTranslatef(x, y, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		DamaN.draw();
		glTranslatef(-x, -y, -0.1f);
		break;
	}
}