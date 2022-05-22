#include "menu_tamano.h"

void menu_tamano::tamano_inicializa()
{
	t = false;
	Grande = false;
	altura = 600;
	anchura = 600;
	tamano_inicial = nullptr;
	tamano_grande = nullptr;
	tamano_pequeno = nullptr;
	tamano_volver = nullptr;
}

void menu_tamano::tamano_asigna()
{
	tamano_inicial = SDL_LoadBMP("imagenes_ajustes/imagenes_tamano/menu_tamano_inicial.bmp");
	tamano_grande = SDL_LoadBMP("imagenes_ajustes/imagenes_tamano/menu_tamano_grande.bmp");
	tamano_pequeno = SDL_LoadBMP("imagenes_ajustes/imagenes_tamano/menu_tamano_pequeno.bmp");
	tamano_volver = SDL_LoadBMP("imagenes_ajustes/imagenes_tamano/menu_tamano_volver.bmp");
}

void menu_tamano::tamano_liberar()
{
	SDL_FreeSurface(tamano_inicial);
	SDL_FreeSurface(tamano_grande);
	SDL_FreeSurface(tamano_pequeno);
	SDL_FreeSurface(tamano_volver);
	tamano_inicial = tamano_grande = tamano_pequeno = tamano_volver = nullptr;
}

SDL_Surface* menu_tamano::getInicial()
{
	return tamano_inicial;
}

SDL_Surface* menu_tamano::getGrande()
{
	return tamano_grande;
}

SDL_Surface* menu_tamano::getPequeno()
{
	return tamano_pequeno;
}

SDL_Surface* menu_tamano::getVolver()
{
	return tamano_volver;
}

bool menu_tamano::gett()
{
	return t;
}

int menu_tamano::getAltura()
{
	return altura;
}

int menu_tamano::getAnchura()
{
	return anchura;
}

void menu_tamano::sett(bool t1)
{
	t = t1;
}

void menu_tamano::setTamano(int a, int b)
{
	altura = b;
	anchura = a;
}

bool menu_tamano::getGra()
{
	return Grande;
}

void menu_tamano::setGrande(bool a)
{
	Grande = a;
}