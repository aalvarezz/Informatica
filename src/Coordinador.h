#pragma once
#include "tablero.h"
#include "juego.h"
#include "JuegoAciegas.h"
#include "Menu.h"
#include "ETSIDI.h"
#include "freeglut.h"


enum Estado { MENU, PARTIDA_NORMAL, PARTIDA_ESPECIAL, FIN_DE_PARTIDA };

// libreria para final de juego?

class Coordinador {
private:
	bool running;
	Menu menu;
	Estado estado;
	
	//Juego juego;
	
public:
	Juego juego;
	JuegoAciegas juegoACiegas;
	Coordinador();
	void Inicializa();
	
	void cambioEstado();
	
	void asignarTamano(bool);
	Estado getEstado();
	
	//bool getRunningJuego();
	bool getRunning() { return running; }
	Menu getMenu() { return menu; }
	//Juego getJuego() { return juego; }
	void CambioEstadoDesdeJuego(int a);
		
	
};
