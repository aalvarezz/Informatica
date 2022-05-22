#pragma once
#include "Pos.h"
#include "Pieza.h"

class Casilla {
private:

	float lado;
	int fila, columna;
	unsigned char rojo, verde, azul;
	bool estado, posible;
	Pos pos; //Posicion bitmap
	Pieza pieza;

public:

	Casilla(int, int);
	Casilla();
	~Casilla();

<<<<<<< Updated upstream
	void Dibujar();
	void SetPosicion(int, int);
	Pieza GetPieza();
	void SetPieza(Pieza p);
	bool GetEstado();
	void SetEstado(bool);
	Pos getPos();
	void QuitarPieza();
=======
	void dibujar();
	void setPosicion(int, int);
	Pieza getPieza();
	void setPieza(Pieza p);
	bool getEstado();
	void setEstado(bool);
	Pos getPos();
	void quitarPieza();
>>>>>>> Stashed changes
	void setPosibilidad();
	void delPosibilidad();
	void dibujarPosible();
	bool operator == (Casilla);
};
