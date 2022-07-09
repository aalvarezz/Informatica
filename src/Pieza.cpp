#include "Pieza.h"

void Pieza::dibujar(Pos posicion) {
	//traslado de la posición de la matriz a coordenadas de glut. x es la columna e y la fila porque las coordenadas de glut están invertidas.
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
	//traslado de la posiciÃ³n del bitmap a coordenadas de glut.
	x = lado / tablero->getLim() * x - (lado / 2);
	y = -lado / tablero->getLim() * y - (lado / 2);

	draw(x, y);
}

void Pieza::draw(float x, float y) {

	sprite.setCenter(lado / 2, lado / 2);
	sprite.setSize(lado, lado);

	glTranslatef(x, y, 0.1f);
	glColor3f(1.0f, 0.0f, 0.0f);
	sprite.draw();
	glTranslatef(-x, -y, -0.1f);
}