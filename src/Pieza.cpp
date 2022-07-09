#include "Pieza.h"

void Pieza::dibujar(Pos posicion) {
	//traslado de la posición de la matriz a coordenadas de glut. x es la columna e y la fila porque las coordenadas de glut están invertidas.
	//setTamano(true);
	float x = posicion.columna * lado;
	float y = posicion.fila * lado;

	draw(x, y);
}

void Pieza::dibujarArrastrar(Pos posicion, Tablero* tablero) {
	//setTamano(true);
	float x = posicion.fila;
	float y = posicion.columna;
	//setTamano(grande);
	//Trasladar 0
	x -= tablero->getAjusteX();
	y -= tablero->getAjusteY();
	//traslado de la posición del bitmap a coordenadas de glut.
	x = lado / tablero->getLim() * x - (lado / 2);
	y = -lado / tablero->getLim() * y - (lado / 2);

	draw(x, y);
}

/*
void Pieza::setTamano(bool t) {
	/*
	if (t) 
	{
		LIM_CASILLA = 91;
		AJUSTE_X = 86;
		AJUSTE_Y = 813;
	}
	else 
	{
		LIM_CASILLA = 60;
		AJUSTE_X = 58;
		AJUSTE_Y = 540;
	}
	
}
*/