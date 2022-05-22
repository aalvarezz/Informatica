#pragma once
#include <SDL.h>
#include <iostream>

class menu_jugar {
private:
	bool j;
	SDL_Surface* jugar_inicial = nullptr;
	SDL_Surface* jugar_empezar = nullptr;
	SDL_Surface* jugar_modo = nullptr;
	SDL_Surface* jugar_tiempo = nullptr;
	SDL_Surface* jugar_volver = nullptr;
public:
	void menu_jugar_inicializa();
	void menu_jugar_asigna();
	void menu_jugar_liberar();

	SDL_Surface* getInicial();
	SDL_Surface* getEmpezar();
	SDL_Surface* getModo();
	SDL_Surface* getTiempo();
	SDL_Surface* getVolver();
	bool getj();
	void setj(bool);
};