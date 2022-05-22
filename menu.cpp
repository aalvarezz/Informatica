#include <SDL.h>
#include "ETSIDI.h"
#include "menu.h"

void Menu::inicializa()
{
	window = nullptr;
	windowsurface = nullptr;
	currentimage = nullptr;
	menu_i.menu_inicial_inicializa();
	menu_a.ajustes_inicializa();
	menu_s.sonido_inicializa();
	menu_t.tamano_inicializa();
	tablero_running = false;

}

void Menu::asigna()
{
	menu_i.menu_inicial_asigna();
	menu_a.ajustes_asigna();
	menu_s.sonido_asigna();
	menu_t.tamano_asigna();

	currentimage = optimatedsurface("menu_inicial_1.bmp", windowsurface);
}

void Menu::liberar()
{
	menu_i.menu_inicial_liberar();
	menu_a.ajustes_liberar();
	menu_s.sonido_liberar();
	menu_t.tamano_liberar();

	currentimage = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	windowsurface = nullptr;
}

SDL_Surface* Menu::optimatedsurface(std::string filepath, SDL_Surface* windowsurface)
{
	SDL_Surface* optimatedsurface = nullptr;
	SDL_Surface* surface = SDL_LoadBMP(filepath.c_str());
	if (surface == NULL)
		std::cout << "error" << std::endl;
	else
	{
		optimatedsurface = SDL_ConvertSurface(surface, windowsurface->format, 0);
		if (optimatedsurface == NULL)
			std::cout << "error" << std::endl;
	}

	SDL_FreeSurface(surface);
	return optimatedsurface;
}

void Menu::ventana()
{
	window = SDL_CreateWindow("menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 410, SDL_WINDOW_SHOWN);
	windowsurface = SDL_GetWindowSurface(window);
}

void Menu::evento()
{
	bool running = true;
	SDL_Event e;


	SDL_Rect drawingrect;
	drawingrect.x = drawingrect.y = 0;
	drawingrect.w = 640;
	drawingrect.h = 410;

	std::string text = "";
	SDL_StartTextInput();

	while (running)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				running = false;
			//eventos con teclas

			else if (e.type == SDL_KEYDOWN)
			{
				if (menu_i.getm() == true && e.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}

				if (menu_a.geta() == true && e.key.keysym.sym == SDLK_ESCAPE)
				{
					currentimage = menu_i.getInicial();
					menu_i.setm(true);
					menu_a.seta(false);

				}

				if (menu_s.gets() == true && e.key.keysym.sym == SDLK_ESCAPE)
				{
					currentimage = menu_a.getInicial();
					menu_a.seta(true);
					menu_s.sets(false);
				}

				if (menu_t.gett() == true && e.key.keysym.sym == SDLK_ESCAPE)
				{
					currentimage = menu_a.getInicial();
					menu_a.seta(true);
					menu_t.sett(false);
				}
			}

			//eventos botones raton

			else if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				//menu inicial
				if (e.button.clicks == 2 && currentimage == menu_i.getJugar())
				{
					running = false;
					menu_i.setm(false);
					tablero_running = true;
				}

				if (e.button.clicks == 2 && currentimage == menu_i.getSalir())
				{
					running = false;
				}

				if (e.button.clicks == 2 && currentimage == menu_i.getAjustes())
				{
					currentimage = menu_a.getInicial();
					menu_i.setm(false);
					menu_a.seta(true);
				}

				//menu ajustes
				if (e.button.clicks == 2 && currentimage == menu_a.getSonido())
				{
					currentimage = menu_s.getInicial();
					menu_a.seta(false);
					menu_s.sets(true);
				}

				if (e.button.clicks == 2 && currentimage == menu_a.getTamano())
				{
					currentimage = menu_t.getInicial();
					menu_a.seta(false);
					menu_t.sett(true);
				}

				if (e.button.clicks == 2 && currentimage == menu_a.getVolver())
				{
					currentimage = menu_i.getInicial();
					menu_a.seta(false);
					menu_i.setm(true);
				}

				//menu tamano
				if (e.button.clicks == 2 && currentimage == menu_t.getGrande()) {
					currentimage = menu_a.getInicial();
					menu_a.seta(true);
					menu_t.sett(false);
					menu_t.setGrande(true);
					menu_t.setTamano(900, 900);


				}

				if (e.button.clicks == 2 && currentimage == menu_t.getPequeno()) {
					currentimage = menu_a.getInicial();
					menu_a.seta(true);
					menu_t.sett(false);
					menu_t.setGrande(false);
					menu_t.setTamano(600, 600);
				}

				if (e.button.clicks == 2 && currentimage == menu_t.getVolver()) {
					currentimage = menu_a.getInicial();
					menu_a.seta(true);
					menu_t.sett(false);
				}

				//menu sonido
				if (e.button.clicks == 2 && currentimage == menu_s.geton()) {
					currentimage = menu_a.getInicial();
					menu_a.seta(true);
					menu_s.sets(false);
					menu_s.setSonido(true);
					ETSIDI::playMusica("Musica/WiiTheme.mp3", true);
				}

				if (e.button.clicks == 2 && currentimage == menu_s.getoff()) {
					currentimage = menu_a.getInicial();
					menu_a.seta(true);
					menu_s.sets(false);
					menu_s.setSonido(false);
					ETSIDI::stopMusica();
				}

				if (e.button.clicks == 2 && currentimage == menu_s.getVolver()) {
					currentimage = menu_a.getInicial();
					menu_a.seta(true);
					menu_s.sets(false);
				}



			}

			//posicion del raton
			else if (e.type == SDL_MOUSEMOTION)
			{
				//menu inicial
				if (menu_i.getm() == true)
				{
					if (e.button.y > 180 && e.button.y < 220)
						currentimage = menu_i.getJugar();
					else if (e.button.y > 220 && e.button.y < 265)
						currentimage = menu_i.getAjustes();
					else if (e.button.y > 265 && e.button.y < 320)
						currentimage = menu_i.getSalir();
					else
						currentimage = menu_i.getInicial();
				}
				//menu jugar

			   //menu ajustes

				else if (menu_a.geta() == true)
				{
					if (e.button.y > 180 && e.button.y < 240)
						currentimage = menu_a.getTamano();
					else if (e.button.y > 240 && e.button.y < 290)
						currentimage = menu_a.getSonido();
					else if (e.button.y > 290 && e.button.y < 320)
						currentimage = menu_a.getVolver();
					else
						currentimage = menu_a.getInicial();
				}


				//menu tamaño

				else if (menu_t.gett() == true)
				{
					if (e.button.y > 180 && e.button.y < 240)
						currentimage = menu_t.getGrande();
					else if (e.button.y > 240 && e.button.y < 290)
						currentimage = menu_t.getPequeno();
					else if (e.button.y > 290 && e.button.y < 330)
						currentimage = menu_t.getVolver();
					else
						currentimage = menu_t.getInicial();
				}

				//menu sonido
				else if (menu_s.gets() == true)
				{
					if (e.button.y > 180 && e.button.y < 240)
						currentimage = menu_s.geton();
					else if (e.button.y > 240 && e.button.y < 290)
						currentimage = menu_s.getoff();
					else if (e.button.y > 290 && e.button.y < 330)
						currentimage = menu_s.getVolver();
					else
						currentimage = menu_s.getInicial();
				}




			}




			//escribir texto
			else if (e.type == SDL_TEXTINPUT || e.type == SDL_KEYDOWN)
			{
				system("cls");
				if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0)
					text = text.substr(0, text.length() - 1); //borra
				else if (e.type == SDL_TEXTINPUT)
					text += e.text.text; //escribe

				std::cout << text << std::endl;
			}


		}

		SDL_BlitSurface(currentimage, NULL, windowsurface, &drawingrect);
		SDL_UpdateWindowSurface(window);
	}


}

bool Menu::getTableroRunning()
{
	return tablero_running;
}

menu_tamano Menu::getMenuTamano()
{
	return menu_t;
}

menu_sonido Menu::getMenuSonido()
{
	return menu_s;
}
