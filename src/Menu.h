#pragma once

#include <SDL.h>
#include <iostream>
#include "ETSIDI.h"

class Menu {
private:
	//genrales
	SDL_Window* window;
	SDL_Surface* windowsurface;
	SDL_Surface* currentimage;
	bool tablero_running;

	//menu inicial
	bool menu_inicial_activo;
	SDL_Surface* menu_inicial;
	SDL_Surface* menu_ajustes;
	SDL_Surface* menu_jugar;
	SDL_Surface* menu_salir;

	//menu ajustes
	bool a;
	SDL_Surface* ajustes_inicial;
	SDL_Surface* ajustes_tamano;
	SDL_Surface* ajustes_sonido;
	SDL_Surface* ajustes_volver;

	//menu sonido
	bool s, sonido;
	SDL_Surface* sonido_inicial;
	SDL_Surface* sonido_on;
	SDL_Surface* sonido_off;
	SDL_Surface* sonido_volver;

	//menu tamano
	bool t;
	bool Grande;
	int altura, anchura;
	SDL_Surface* tamano_inicial;
	SDL_Surface* tamano_grande;
	SDL_Surface* tamano_pequeno;
	SDL_Surface* tamano_volver;

public:
	Menu();

	void inicializa();
	void asigna();
	void liberar();

	void ventana();
	//bool getTableroRunning();

	SDL_Surface* optimatedsurface(std::string filepath, SDL_Surface* windowsurface);

	void evento();

	//bool getMenuTamano();

};
