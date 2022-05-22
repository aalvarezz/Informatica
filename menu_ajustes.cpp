#include "menu_ajustes.h"

void menu_ajustes::ajustes_inicializa()
{
	a = false;
	ajustes_inicial = nullptr;
	ajustes_tamano = nullptr;
	ajustes_sonido = nullptr;
	ajustes_volver = nullptr;
}


void menu_ajustes::ajustes_asigna()
{
	ajustes_inicial = SDL_LoadBMP("imagenes_ajustes/menu_ajustes_inicial.bmp");
	ajustes_tamano = SDL_LoadBMP("imagenes_ajustes/menu_ajustes_tamano.bmp");
	ajustes_sonido = SDL_LoadBMP("imagenes_ajustes/menu_ajustes_sonido.bmp");
	ajustes_volver = SDL_LoadBMP("imagenes_ajustes/menu_ajustes_volver.bmp");
}

void menu_ajustes::ajustes_liberar()
{
	SDL_FreeSurface(ajustes_inicial);
	SDL_FreeSurface(ajustes_tamano);
	SDL_FreeSurface(ajustes_sonido);
	SDL_FreeSurface(ajustes_volver);
	ajustes_inicial = ajustes_tamano = ajustes_sonido = ajustes_volver = nullptr;
}

SDL_Surface* menu_ajustes::getInicial()
{
	return ajustes_inicial;
}

SDL_Surface* menu_ajustes::getTamano()
{
	return ajustes_tamano;
}

SDL_Surface* menu_ajustes::getSonido()
{
	return ajustes_sonido;
}

SDL_Surface* menu_ajustes::getVolver()
{
	return ajustes_volver;
}

bool menu_ajustes::geta()
{
	return a;
}
void menu_ajustes::seta(bool a1)
{
	a = a1;
}