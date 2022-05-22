#include "menu_jugar.h"

void menu_jugar::menu_jugar_inicializa() 
{
	j = false;
	jugar_inicial = nullptr;
	jugar_empezar = nullptr;
	jugar_modo = nullptr;
	jugar_tiempo = nullptr;
	jugar_volver = nullptr;
}

void menu_jugar::menu_jugar_asigna()
{
	jugar_inicial = SDL_LoadBMP("imagenes_jugar/jugar_inicial.bmp");
	jugar_empezar = SDL_LoadBMP("imagenes_jugar/jugar_inicial_empezar.bmp");
	jugar_modo = SDL_LoadBMP("imagenes_jugar/jugar_inicial_modo.bmp");
	jugar_tiempo = SDL_LoadBMP("imagenes_jugar/jugar_inicial_tiempo.bmp");
	jugar_volver = SDL_LoadBMP("imagenes_jugar/jugar_inicial_volver.bmp");
}

void menu_jugar::menu_jugar_liberar()
{
	SDL_FreeSurface(jugar_inicial);
	SDL_FreeSurface(jugar_empezar);
	SDL_FreeSurface(jugar_modo);
	SDL_FreeSurface(jugar_tiempo);
	jugar_empezar = jugar_inicial = jugar_modo = jugar_tiempo = jugar_volver = nullptr;
}

SDL_Surface* menu_jugar::getInicial() 
{
	return jugar_inicial;
}

SDL_Surface* menu_jugar:: getEmpezar()
{
	return jugar_empezar;
}

SDL_Surface* menu_jugar::getModo()
{
	return jugar_modo;
}

SDL_Surface* menu_jugar::getTiempo()
{
	return jugar_tiempo;
}
SDL_Surface* menu_jugar::getVolver()
{
	return jugar_volver;
}

bool menu_jugar::getj()
{
	return j;
}

void menu_jugar::setj(bool j1)
{
	j = j1;
}

