#include <iostream>
#include "Tablero.h"

Tablero::Tablero() {

}

Tablero::~Tablero() {

}

void Tablero::Inicializar() { //vacio=0, peon=1, rey=2, dama=3, alfil=4, caballo=5, torre=6
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == 0 || i == 1) //Color blanco
				tablero[i][j].color = 0;
			if (i == 6 || i == 7) //Color negro
				tablero[i][j].color = 1;
			if (i == 0 || i == 7) {
				if (j == 0 || j == 7) //torres
					tablero[i][j].estado = 6;
				if (j == 1 || j == 6) //caballos
					tablero[i][j].estado = 5;
				if (j == 2 || j == 5) //alfiles
					tablero[i][j].estado = 4;
				if (j == 3) //damas
					tablero[i][j].estado = 3;
				if (j == 4) //reyes
					tablero[i][j].estado = 2;
			}
			if (i == 1 || i == 6) //peones
				tablero[i][j].estado = 1;
			if (i >= 2 && i <= 5) //Huecos vacios
				tablero[i][j].estado = 0;
			tablero[i][j].pos.x = 0;
			tablero[i][j].pos.y = 0;
		}
	}
}

void Tablero::DibujarTablero() { //Dibuja estados
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			if (((j % 2) == 0 && ((i % 2)) == 0) || ((j % 2) == 1 && ((i % 2) == 1))) {
				tablero[i][j].SetPosicion(i, j);
				tablero[i][j].SetColor(tablero[i][j].pos);
				tablero[i][j].Dibujar(tablero[i][j].pos);
			}
			if (((j % 2) == 1 && ((i % 2)) == 0) || ((j % 2) == 0 && ((i % 2) == 1))) {
				tablero[i][j].SetPosicion(i, j);
				tablero[i][j].SetColor(tablero[i][j].pos);
				tablero[i][j].Dibujar(tablero[i][j].pos);
			}
		}
	}
}

void Tablero::DibujarPiezas()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			d.x = j;
			d.y = i;
			piezatest.Dibujar(d, tablero[i][j].estado, tablero[i][j].color);
		}
	}
}