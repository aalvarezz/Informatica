#pragma once
#include <SDL.h>

class menu_sonido {
private:
	bool s,sonido;
	SDL_Surface* sonido_inicial;
	SDL_Surface* sonido_on;
	SDL_Surface* sonido_off;
	SDL_Surface* sonido_volver;
public:
	void sonido_inicializa();
	void sonido_asigna();
	void sonido_liberar();

	SDL_Surface* getInicial();
	SDL_Surface* geton();
	SDL_Surface* getoff();
	SDL_Surface* getVolver();
	bool gets();
	bool getSonido();
	void sets(bool);
	void setSonido(bool);
};

