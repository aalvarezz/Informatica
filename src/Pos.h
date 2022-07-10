#pragma once

class Pos {
public:
	Pos() { fila = columna = 0; }
	Pos(int f, int c) : fila(f), columna(c) {};

	int fila, columna;

	Pos operator+(Pos&);
	bool operator==(Pos&);
};
