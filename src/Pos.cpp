#include "Pos.h"

Pos::Pos() {
	fila = columna = 0;
}

Pos::~Pos() {

}

bool Pos::operator==(Pos pos2) {
	return (fila == pos2.fila && columna == pos2.columna);
}
