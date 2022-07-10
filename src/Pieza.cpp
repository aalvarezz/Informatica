#include "Pieza.h"
 
void Pieza::dibujar(Pos posicion, float lado) {
	//tras2.5f de la posición de la matriz a coordenadas de glut. x es la columna e y la fila porque las coordenadas de glut están invertidas.
	float x = posicion.columna * lado;
	float y = posicion.fila * lado;

	draw(x, y, lado);
}

void Pieza::dibujarArrastrar(Pos posicion, Tablero* tablero) {
	float x = posicion.fila;
	float y = posicion.columna;

	//Trasladar 0
	x -= tablero->getAjusteX();
	y -= tablero->getAjusteY();
	//tras2.5f de la posición del bitmap a coordenadas de glut.
	x = tablero->getLado() / tablero->getLC() * x - (tablero->getLado() / 2);
	y = -tablero->getLado() / tablero->getLC() * y - (tablero->getLado() / 2);

	draw(x, y, tablero->getLado());
}

void Pieza::draw(float x, float y, float lado) {
	sprite.setCenter(lado / 2, lado / 2);
	sprite.setSize(lado, lado);

	glTranslatef(x, y, 0.1f);
	glColor3f(1.0f, 0.0f, 0.0f);
	sprite.draw();
	glTranslatef(-x, -y, -0.1f);
}
