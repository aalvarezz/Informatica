#include "menu_sonido.h"

void menu_sonido::sonido_inicializa()
{
	s = false;
	sonido = true;
	sonido_inicial = nullptr;
	sonido_on = nullptr;
	sonido_off = nullptr;
	sonido_volver = nullptr;
}

void menu_sonido::sonido_asigna()
{
	sonido_inicial = SDL_LoadBMP("imagenes_ajustes/imagenes_sonido/menu_sonido_inicial.bmp");
	sonido_on = SDL_LoadBMP("imagenes_ajustes/imagenes_sonido/menu_sonido_activado.bmp");
	sonido_off = SDL_LoadBMP("imagenes_ajustes/imagenes_sonido/menu_sonido_desactivado.bmp");
	sonido_volver = SDL_LoadBMP("imagenes_ajustes/imagenes_sonido/menu_sonido_volver.bmp");
}

void menu_sonido::sonido_liberar()
{
	SDL_FreeSurface(sonido_inicial);
	SDL_FreeSurface(sonido_on);
	SDL_FreeSurface(sonido_off);
	SDL_FreeSurface(sonido_volver);
	sonido_inicial = sonido_on = sonido_off = sonido_volver = nullptr;
}

SDL_Surface* menu_sonido::getInicial()
{
	return sonido_inicial;
}

SDL_Surface* menu_sonido::geton()
{
	return sonido_on;
}

SDL_Surface* menu_sonido::getoff()
{
	return sonido_off;
}

SDL_Surface* menu_sonido::getVolver()
{
	return sonido_volver;
}

bool menu_sonido::gets()
{
	return s;
}

bool menu_sonido::getSonido()
{
	return sonido;
}

void menu_sonido::sets(bool s1)
{
	s = s1;
}

void menu_sonido::setSonido(bool s2)
{
	sonido = s2;
}