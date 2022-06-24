#pragma once

class Pos {
public:
	Pos();
	~Pos();

	int fila, columna;

	bool operator == (Pos);
private:

};