#include "Pieza.h"
 
void Pieza::dibujar(Pos posicion) {
	//traslado de la posición de la matriz a coordenadas de glut. x es la columna e y la fila porque las coordenadas de glut están invertidas.
	float x = posicion.columna * lado;
	float y = posicion.fila * lado;

	draw(x, y);
}

void Pieza::dibujarArrastrar(Pos posicion) {
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
