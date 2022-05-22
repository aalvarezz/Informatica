#include "menu_inicio.h"


void menu_inicio::menu_inicial_inicializa()
{
	m = true;
	SDL_Surface* menu_inicial = nullptr;
	SDL_Surface* menu_ajustes = nullptr;
	SDL_Surface* menu_jugar = nullptr;
	SDL_Surface* menu_salir = nullptr;
}

void menu_inicio::menu_inicial_asigna()
{
	menu_inicial = SDL_LoadBMP("imagenes_menu/menu_inicial_2.bmp");
	menu_ajustes = SDL_LoadBMP("imagenes_menu/menu_inicial_ajustes_2.bmp");
	menu_jugar = SDL_LoadBMP("imagenes_menu/menu_inicial_jugar_2.bmp");
	menu_salir = SDL_LoadBMP("imagenes_menu/menu_inicial_salir_2.bmp");
}

void menu_inicio::menu_inicial_liberar()
{
	SDL_FreeSurface(menu_inicial);
	SDL_FreeSurface(menu_salir);
	SDL_FreeSurface(menu_ajustes);
	SDL_FreeSurface(menu_jugar);

	menu_inicial = menu_jugar = menu_ajustes = menu_salir = nullptr;
}

SDL_Surface* menu_inicio::getInicial()
{
	return menu_inicial;
}

SDL_Surface* menu_inicio::getAjustes()
{
	return menu_ajustes;
}

SDL_Surface* menu_inicio::getJugar()
{
	return menu_jugar;
}

SDL_Surface* menu_inicio::getSalir()
{
	return menu_salir;
}

bool menu_inicio::getm()
{
	return m;
}

void menu_inicio::setm(bool a1)
{
	m = a1;
}