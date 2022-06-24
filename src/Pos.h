#pragma once

class Pos {
public:
	Pos();
	Pos(int _fila, int _columna) : fila(_fila), columna(_columna) {};
	~Pos();

	int fila, columna;

	bool operator == (Pos);
	Pos operator+ (Pos&);
private:

};
