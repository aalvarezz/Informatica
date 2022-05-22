#pragma once
#pragma once
#include <SDL.h>

class menu_tamano {
private:
	bool t;
	bool Grande;
	int altura, anchura;
	SDL_Surface* tamano_inicial;
	SDL_Surface* tamano_grande;
	SDL_Surface* tamano_pequeno;
	SDL_Surface* tamano_volver;
public:
	void tamano_inicializa();
	void tamano_asigna();
	void tamano_liberar();

	SDL_Surface* getInicial();
	SDL_Surface* getGrande();
	SDL_Surface* getPequeno();
	SDL_Surface* getVolver();
	bool gett();
	bool getGra();
	int getAltura();
	int getAnchura();
	void sett(bool);
	void setTamano(int,int);
	void setGrande(bool a);
};