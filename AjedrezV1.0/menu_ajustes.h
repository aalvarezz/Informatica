#pragma once
#include <SDL.h>

class menu_ajustes {
private:
	bool a;
	SDL_Surface* ajustes_inicial;
	SDL_Surface* ajustes_tamano;
	SDL_Surface* ajustes_sonido;
	SDL_Surface* ajustes_volver;
public:
	void ajustes_inicializa();
	void ajustes_asigna();
	void ajustes_liberar();

	SDL_Surface* getInicial();
	SDL_Surface* getTamano();
	SDL_Surface* getSonido();
	SDL_Surface* getVolver();
	bool geta();
	void seta(bool);

};