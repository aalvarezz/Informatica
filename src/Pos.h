#pragma once

class Pos {
public:
	Pos(int f, int c);
	Pos();
	~Pos();

	int fila, columna;

	bool operator == (Pos);
private:

};