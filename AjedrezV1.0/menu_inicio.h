#pragma once
#include <SDL.h>

class menu_inicio {
private:
	bool m;
	SDL_Surface* menu_inicial;
	SDL_Surface* menu_ajustes;
	SDL_Surface* menu_jugar;
	SDL_Surface* menu_salir;

public:
	void menu_inicial_inicializa();
	void menu_inicial_asigna();
	void menu_inicial_liberar();
	//void menu_incial_tecla(SDL_Surface&);
	
	SDL_Surface* getInicial();
	SDL_Surface* getAjustes();
	SDL_Surface* getJugar();
	SDL_Surface* getSalir();
	bool getm();
	void setm(bool);
};