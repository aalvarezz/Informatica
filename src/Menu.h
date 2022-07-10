#pragma once
#include <SDL.h>
#include <iostream>
#include "ETSIDI.h"

class Menu {
private:
	//Atributos generales
	SDL_Window* window;
	SDL_Surface* windowsurface;
	SDL_Surface* currentimage;
	bool tablero_running;
	bool menu_running;

	//Menú inicial
	bool menu_inicial_activo;
	SDL_Surface* menu_inicial;
	SDL_Surface* menu_ajustes;
	SDL_Surface* menu_jugar;
	SDL_Surface* menu_salir;

	//Menú jugar
	bool menu_modo_activo,partida_normal;
	SDL_Surface* modo_inicial;
	SDL_Surface* modo_clasico;
	SDL_Surface* modo_especial;
	SDL_Surface* modo_salir;

	//Menú ajustes
	bool menu_ajustes_activo;
	SDL_Surface* ajustes_inicial;
	SDL_Surface* ajustes_tamano;
	SDL_Surface* ajustes_sonido;
	SDL_Surface* ajustes_volver;

	//Menú sonido
	bool menu_sonido_activo, sonido;
	SDL_Surface* sonido_inicial;
	SDL_Surface* sonido_on;
	SDL_Surface* sonido_off;
	SDL_Surface* sonido_volver;

	//Menú tamaño
	bool menu_tamano_activo;
	bool grande;
	int altura, anchura;
	SDL_Surface* tamano_inicial;
	SDL_Surface* tamano_grande;
	SDL_Surface* tamano_pequeno;
	SDL_Surface* tamano_volver;

	//Menú de fin de partida
	bool menu_fin_blancas_activo, menu_fin_negras_activo;
	bool menu_fin_empate_blancas_activo, menu_fin_empate_negras_activo;
	SDL_Surface* blancas_inicial;
	SDL_Surface* blancas_jugar;
	SDL_Surface* blancas_menu;
	SDL_Surface* blancas_salir;
	SDL_Surface* negras_inicial;
	SDL_Surface* negras_jugar;
	SDL_Surface* negras_menu;
	SDL_Surface* negras_salir;
	SDL_Surface* empate_blancas_inicial;
	SDL_Surface* empate_blancas_jugar;
	SDL_Surface* empate_blancas_menu;
	SDL_Surface* empate_blancas_salir;
	SDL_Surface* empate_negras_inicial;
	SDL_Surface* empate_negras_jugar;
	SDL_Surface* empate_negras_menu;
	SDL_Surface* empate_negras_salir;

	//Menú coronación
	SDL_Surface* coronacion_inicial;
	SDL_Surface* coronacion_dama;
	SDL_Surface* coronacion_alfil;
	SDL_Surface* coronacion_caballo;
	SDL_Surface* coronacion_torre;
public:
	//Constructor de Menú
	Menu();

	//Operaciones que realizan los distintos menús
	void inicializar();
	void inicializarFinDePartida(bool, bool, bool, bool);
	void inicializarCoronacion();
	void asignar();
	void asignarFinDePartida();
	void asignarCoronacion();
	void liberar();
	void liberarFinDePartida();
	void liberarCoronacion();

	//Gestión de ventanas
	void ventana();
	SDL_Surface* optimatedsurface(std::string filepath, SDL_Surface* windowsurface);

	//Gestión de eventos
	void evento(); 
	int eventoFinDePartida();
	int eventoCoronacion();

	//Getters y setters
	bool getTableroRunning() { return tablero_running; }
	bool getTamano() { return grande; }
	bool getSonido() { return sonido; }
	int getAltura() { return altura; }
	int getAnchura() { return anchura; }
	void setTamanoGrande() { grande = true; }
	bool getMenuRunning() { return menu_running; }
	void setMenuBlanco(bool a) { menu_fin_blancas_activo = true; }
	void setMenuNegro(bool a) { menu_fin_negras_activo = true; }
	void setMenuEmpateBlancas(bool a) { menu_fin_empate_blancas_activo = true; }
	void setMenuEmpateNegras(bool a) { menu_fin_empate_negras_activo = true; }
	bool getMenuBlanco() { return menu_fin_blancas_activo; }
	bool getMenuNegro() { return menu_fin_negras_activo; }
	bool getMenuEmpateBlancas() { return menu_fin_empate_blancas_activo; }
	bool getMenuEmpateNegras() { return menu_fin_empate_negras_activo; }
	bool getPartidaNormal() { return partida_normal; }
};
