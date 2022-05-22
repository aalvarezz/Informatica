#pragma once
#include <SDL.h>

class menu_timer {
private:
	bool t, timer;
	SDL_Surface* timer_inicial;
	SDL_Surface* timer_on;
	SDL_Surface* timer_off;
public:
	void timer_inicializa();
	void timer_asigna();
	void timer_liberar();

	SDL_Surface* getInicial();
	SDL_Surface* geton();
	SDL_Surface* getoff();

	bool gett();
	bool getTimer();
	void sett(bool);
	void setTimer(bool);
};
