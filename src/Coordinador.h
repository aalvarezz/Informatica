#pragma once
#include "Tablero.h"
#include "Juego.h"
#include "JuegoAciegas.h"
#include "freeglut.h"

enum Estado { MENU, PARTIDA_NORMAL, PARTIDA_ESPECIAL, FIN_DE_PARTIDA };

class Coordinador {
private:
	bool running;
	Menu menu;
	Estado estado;
public:
	//Estos atributos deben ser p�blicos para que SDL pueda funcionar correctamente
	Juego juego;
	JuegoAciegas juegoACiegas;

	//Constructor por defecto e inicializaci�n
	Coordinador();
	void inicializar();
	
	//M�todos de cambio de estado
	void cambioEstado();
	void cambioEstadoDesdeJuego(int a);

	//Getters y setters
	Menu getMenu() { return menu; }
	bool getRunning() { return running; }
	Estado getEstado() { return estado; }
};
