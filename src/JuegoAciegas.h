#pragma once
#include "Juego.h"
#include "TableroJardin.h"

class JuegoAciegas : public Juego
{
public:
	void dibujarPiezas(); //recorre todas las piezas de tablero y llama a su función de dibujo.
};