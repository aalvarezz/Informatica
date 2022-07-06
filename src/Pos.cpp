#include "Pos.h"

Pos::Pos(int f, int c)
{
	fila = f;
	columna = c;
}

Pos::Pos() {
	fila = columna = 0;
}

Pos::~Pos() {

}

Pos Pos::operator+(Pos &pos2) {
	Pos posaux;
	posaux.fila = fila + pos2.fila;
	posaux.columna = columna + pos2.columna;
	return posaux;
}