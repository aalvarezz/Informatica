#pragma once
#include <SDL.h>

class menu_modo {
private:
	bool m, mode;
	SDL_Surface* modo_inicial;
	SDL_Surface* modo_1v1;
	SDL_Surface* modo_IA;
public:
	void modo_inicializa();
	void modo_asigna();
	void modo_liberar();

	SDL_Surface* getInicial();
	SDL_Surface* get1v1();
	SDL_Surface* getIA();

	bool getm();
	bool getMode();
	void setm(bool);
	void setMode(bool);
};
