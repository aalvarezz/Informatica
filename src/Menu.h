#pragma once

#include <SDL.h>
#include <iostream>
#include "ETSIDI.h"

class Menu {
private:
	//genrales
	SDL_Window* window;
	SDL_Surface* windowsurface;
	SDL_Surface* currentimage;
	bool tablero_running;
	bool menu_running;

	//menu inicial
	bool menu_inicial_activo;
	SDL_Surface* menu_inicial;
	SDL_Surface* menu_ajustes;
	SDL_Surface* menu_jugar;
	SDL_Surface* menu_salir;


	//menu jugar
	bool menu_modo_activo;
	SDL_Surface* modo_inicial;
	SDL_Surface* modo_clasico;
	SDL_Surface* modo_especial;
	SDL_Surface* modo_salir;


	//menu ajustes
	bool menu_ajustes_activo;
	bool clasico;
	SDL_Surface* ajustes_inicial;
	SDL_Surface* ajustes_tamano;
	SDL_Surface* ajustes_sonido;
	SDL_Surface* ajustes_volver;

	//menu sonido
	bool menu_sonido_activo, sonido;
	SDL_Surface* sonido_inicial;
	SDL_Surface* sonido_on;
	SDL_Surface* sonido_off;
	SDL_Surface* sonido_volver;

	//menu tamano
	bool menu_tamano_activo;
	bool Grande;
	int altura, anchura;
	SDL_Surface* tamano_inicial;
	SDL_Surface* tamano_grande;
	SDL_Surface* tamano_pequeno;
	SDL_Surface* tamano_volver;

	//menu fin de la partida
	bool menu_fin_blancas_activo, menu_fin_negras_activo, menu_fin_empate_activo;
	SDL_Surface* blancas_inicial;
	SDL_Surface* blancas_jugar;
	SDL_Surface* blancas_menu;
	SDL_Surface* blancas_salir;
	SDL_Surface* negras_inicial;
	SDL_Surface* negras_jugar;
	SDL_Surface* negras_menu;
	SDL_Surface* negras_salir;
	SDL_Surface* empate_inicial;
	SDL_Surface* empate_jugar;
	SDL_Surface* empate_menu;
	SDL_Surface* empate_salir;

public:
	Menu();

	void inicializa();
	void inicializaFin();
	void asigna();
	void asignaFin();
	void liberar();
	void liberarFin();

	void ventana();

	SDL_Surface* optimatedsurface(std::string filepath, SDL_Surface* windowsurface);

	void evento();
	void eventoFin();

	bool getTableroRunning();
	bool getTamano();
	bool getSonido();
	int getAltura();
	int getAnchura();
	bool getMenuRunning() { return menu_running; }
	void setMenuBlanco(bool a) { menu_fin_blancas_activo = true; }
	void setMenuNegro(bool a) { menu_fin_negras_activo = true; }
	void setMenuEmpate(bool a) { menu_fin_empate_activo = true; }
	bool getMenuBlanco() { return menu_fin_blancas_activo; }
	bool getMenuNegro() { return menu_fin_negras_activo; }
	bool getMenuEmpate() { return menu_fin_empate_activo; }
	//void setTableroRunning();
};
