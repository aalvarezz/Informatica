#include "Pieza.h"
 
void Pieza::dibujar(Pos posicion) {
	//tras2.5f de la posici�n de la matriz a coordenadas de glut. x es la columna e y la fila porque las coordenadas de glut est�n invertidas.
	float x = posicion.columna * 2.5f;
	float y = posicion.fila * 2.5f;

	draw(x, y);
}

void Pieza::dibujarArrastrar(Pos posicion, Tablero* tablero) {
	float x = posicion.fila;
	float y = posicion.columna;

	//Trasladar 0
	x -= tablero->getAjusteX();
	y -= tablero->getAjusteY();
	//tras2.5f de la posici�n del bitmap a coordenadas de glut.
	x = 2.5f / tablero->getLim() * x - (2.5f / 2);
	y = -2.5f / tablero->getLim() * y - (2.5f / 2);

	draw(x, y);
}
