#pragma once

class Pos {
public:
	Pos(int f, int c);
	Pos();
	~Pos();

	int fila, columna;

	Pos operator+ (Pos&);
};
