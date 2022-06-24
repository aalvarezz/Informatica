#include "Pieza.h"

Pieza::Pieza() {

}

void Pieza::setPos(Pos p) {
	pos.fila = p.fila;
	pos.columna = p.columna;
}

Pos Pieza::getPos() {
	return pos;
}