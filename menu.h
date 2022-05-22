#pragma once
#include "menu_inicio.h"
#include "menu_ajustes.h"
#include "menu_sonido.h"
#include "menu_tamano.h"
#include "menu_timer.h"
#include <iostream>

class Menu
{
private:
	SDL_Window* window;
	SDL_Surface* windowsurface;
	SDL_Surface* currentimage;
	menu_inicio menu_i;
	menu_ajustes menu_a;
	menu_sonido menu_s;
	menu_tamano menu_t;
	bool tablero_running;

public:
	void inicializa();
	void asigna();
	void liberar();

	void ventana();
	bool getTableroRunning();

	SDL_Surface* optimatedsurface(std::string filepath, SDL_Surface* windowsurface);

	void evento();

	menu_tamano getMenuTamano();

	menu_sonido getMenuSonido();

};