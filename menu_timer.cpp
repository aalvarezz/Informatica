#include "menu_timer.h"

void menu_timer::timer_inicializa()
{
	t = false;
	timer = false;
	timer_inicial = nullptr;
	timer_on = nullptr;
	timer_off = nullptr;
}

void menu_timer::timer_asigna()
{
	timer_inicial = SDL_LoadBMP("imagenes_jugar/imagenes_timer/menu_timer_inicial.bmp");
	timer_on = SDL_LoadBMP("imagenes_jugar/imagenes_timer/menu_timer_activado.bmp");
	timer_off = SDL_LoadBMP("imagenes_jugar/imagenes_timer/menu_timer_desactivado.bmp");
}

void menu_timer::timer_liberar()
{
	SDL_FreeSurface(timer_inicial);
	SDL_FreeSurface(timer_on);
	SDL_FreeSurface(timer_off);
	timer_inicial = timer_on = timer_off = nullptr;
}

SDL_Surface* menu_timer::getInicial()
{
	return timer_inicial;
}

SDL_Surface* menu_timer::geton()
{
	return timer_on;
}

SDL_Surface* menu_timer::getoff()
{
	return timer_off;
}

bool menu_timer::gett()
{
	return t;
}

bool menu_timer::getTimer()
{
	return timer;
}

void menu_timer::sett(bool a)
{
	t = a;
}

void menu_timer::setTimer(bool a)
{
	timer = a;
}