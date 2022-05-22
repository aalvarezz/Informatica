#pragma once
#include "ETSIDI.h"
#include <vector>
#include "Pos.h"

using ETSIDI::Sprite, std::vector;

class Pieza {
private:
	vector<Pos> reglas;
	Pos origen;
	unsigned short int tipo, fila_origen, columna_origen;
	bool color, pinned;
	float lado;
	int AJUSTE_X, AJUSTE_Y, LIM_TABLERO, LIM_CASILLA;

	Sprite ReyB{ "imagenes/ReyB.png" };
	Sprite ReyN{ "imagenes/ReyN.png" };
	Sprite DamaB{ "imagenes/DamaB.png" };
	Sprite DamaN{ "imagenes/DamaN.png" };
	Sprite AlfilB{ "imagenes/AlfilB.png" };
	Sprite AlfilN{ "imagenes/AlfilN.png" };
	Sprite CaballoB{ "imagenes/CaballoB.png" };
	Sprite CaballoN{ "imagenes/CaballoN.png" };
	Sprite TorreB{ "imagenes/TorreB.png" };
	Sprite TorreN{ "imagenes/TorreN.png" };
	Sprite PeonB{ "imagenes/PeonB.png" };
	Sprite PeonN{ "imagenes/PeonN.png" };

public:

	Pieza(unsigned short int);
	Pieza();
	~Pieza();

	void Dibujar(float, float, bool);
	unsigned short int GetTipo();
	unsigned short int setTipo(int);
	unsigned short int setFilaOrigen();
	unsigned short int setColumnaOrigen();
	unsigned short int getFilaOrigen();
	unsigned short int getColumnaOrigen();
	Pos regla(int, int);
	vector<Pos> getReglas();
	bool getColor();
	void setPinned(bool);
	bool getPinned();
	Pos getOrigen();

	void setTamano(int, int, int, int);

	bool MovimTorreVert(int, int, int, int, int, int, int);
	bool MovimTorreHor(int, int, int, int, int, int, int);
	bool MovimAlfil1(int, int, int, int, int, int, int);
	bool MovimAlfil2(int, int, int, int, int, int, int);

};