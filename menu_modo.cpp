#include "menu_modo.h"

void menu_modo::modo_inicializa()
{
	m = false;
	mode = false;
	modo_inicial = nullptr;
	modo_1v1 = nullptr;
	modo_IA = nullptr;
}

void menu_modo::modo_asigna()
{
	modo_inicial = SDL_LoadBMP("imagenes_jugar/imagenes_modo/menu_modo_inicial.bmp");
	modo_1v1 = SDL_LoadBMP("imagenes_jugar/imagenes_modo/menu_modo_1v1.bmp");
	modo_IA = SDL_LoadBMP("imagenes_jugar/imagenes_modo/menu_modo_1vIA.bmp");
}

void menu_modo::modo_liberar()
{
	SDL_FreeSurface(modo_inicial);
	SDL_FreeSurface(modo_1v1);
	SDL_FreeSurface(modo_IA);
	modo_inicial = modo_1v1 = modo_IA = nullptr;
}

SDL_Surface* menu_modo::getInicial()
{
	return modo_inicial;
}

SDL_Surface* menu_modo::get1v1()
{
	return modo_1v1;
}

SDL_Surface* menu_modo::getIA()
{
	return modo_IA;
}

bool menu_modo::getm()
{
	return m;
}

bool menu_modo::getMode()
{
	return mode;
}

void menu_modo::setm(bool a)
{
	m = a;
}

void menu_modo::setMode(bool a)
{
	mode = a;
}