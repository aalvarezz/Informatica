#include "Menu.h"

Menu::Menu() {

}

void Menu::inicializa()
{
	window = nullptr;
	windowsurface = nullptr;
	currentimage = nullptr;
	tablero_running = true;


	menu_inicial_activo = true;
	menu_inicial = nullptr;
	menu_ajustes = nullptr;
	menu_jugar = nullptr;
	menu_salir = nullptr;

	a = false;
	ajustes_inicial = nullptr;
	ajustes_tamano = nullptr;
	ajustes_sonido = nullptr;
	ajustes_volver = nullptr;

	s = false;
	sonido = true;
	sonido_inicial = nullptr;
	sonido_on = nullptr;
	sonido_off = nullptr;
	sonido_volver = nullptr;

	t = false;
	Grande = true;
	altura = 900;
	anchura = 900;
	tamano_inicial = nullptr;
	tamano_grande = nullptr;
	tamano_pequeno = nullptr;
	tamano_volver = nullptr;

}

void Menu::asigna()
{
	currentimage = optimatedsurface("imagenes_menu/menu_inicial_2.bmp", windowsurface);

	menu_inicial = SDL_LoadBMP("imagenes_menu/menu_inicial_2.bmp");
	menu_ajustes = SDL_LoadBMP("imagenes_menu/menu_inicial_ajustes_2.bmp");
	menu_jugar = SDL_LoadBMP("imagenes_menu/menu_inicial_jugar_2.bmp");
	menu_salir = SDL_LoadBMP("imagenes_menu/menu_inicial_salir_2.bmp");

	ajustes_inicial = SDL_LoadBMP("imagenes_ajustes/menu_ajustes_inicial.bmp");
	ajustes_tamano = SDL_LoadBMP("imagenes_ajustes/menu_ajustes_tamano.bmp");
	ajustes_sonido = SDL_LoadBMP("imagenes_ajustes/menu_ajustes_sonido.bmp");
	ajustes_volver = SDL_LoadBMP("imagenes_ajustes/menu_ajustes_volver.bmp");

	sonido_inicial = SDL_LoadBMP("imagenes_ajustes/imagenes_sonido/menu_sonido_inicial.bmp");
	sonido_on = SDL_LoadBMP("imagenes_ajustes/imagenes_sonido/menu_sonido_activado.bmp");
	sonido_off = SDL_LoadBMP("imagenes_ajustes/imagenes_sonido/menu_sonido_desactivado.bmp");
	sonido_volver = SDL_LoadBMP("imagenes_ajustes/imagenes_sonido/menu_sonido_volver.bmp");

	tamano_inicial = SDL_LoadBMP("imagenes_ajustes/imagenes_tamano/menu_tamano_inicial.bmp");
	tamano_grande = SDL_LoadBMP("imagenes_ajustes/imagenes_tamano/menu_tamano_grande.bmp");
	tamano_pequeno = SDL_LoadBMP("imagenes_ajustes/imagenes_tamano/menu_tamano_pequeno.bmp");
	tamano_volver = SDL_LoadBMP("imagenes_ajustes/imagenes_tamano/menu_tamano_volver.bmp");
	
}

void Menu::liberar()
{
	currentimage = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	windowsurface = nullptr;

	SDL_FreeSurface(menu_inicial);
	SDL_FreeSurface(menu_salir);
	SDL_FreeSurface(menu_ajustes);
	SDL_FreeSurface(menu_jugar);
	menu_inicial = menu_jugar = menu_ajustes = menu_salir = nullptr;

	SDL_FreeSurface(ajustes_inicial);
	SDL_FreeSurface(ajustes_tamano);
	SDL_FreeSurface(ajustes_sonido);
	SDL_FreeSurface(ajustes_volver);
	ajustes_inicial = ajustes_tamano = ajustes_sonido = ajustes_volver = nullptr;

	SDL_FreeSurface(sonido_inicial);
	SDL_FreeSurface(sonido_on);
	SDL_FreeSurface(sonido_off);
	SDL_FreeSurface(sonido_volver);
	sonido_inicial = sonido_on = sonido_off = sonido_volver = nullptr;


	SDL_FreeSurface(tamano_inicial);
	SDL_FreeSurface(tamano_grande);
	SDL_FreeSurface(tamano_pequeno);
	SDL_FreeSurface(tamano_volver);
	tamano_inicial = tamano_grande = tamano_pequeno = tamano_volver = nullptr;


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
				if (menu_inicial_activo == true && e.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}

				if (a == true && e.key.keysym.sym == SDLK_ESCAPE)
				{
					currentimage = menu_inicial;
					menu_inicial_activo = true;
					a = false;

				}

				if (s == true && e.key.keysym.sym == SDLK_ESCAPE)
				{
					currentimage = ajustes_inicial;
					a = true;
					s = false;
				}

				if (t == true && e.key.keysym.sym == SDLK_ESCAPE)
				{
					currentimage = ajustes_inicial;
					a = true;
					t = false;
				}

			}

			//eventos botones raton

			else if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				//menu inicial
				if (e.button.clicks == 2 && currentimage == menu_jugar)
				{
					running = false;
					menu_inicial_activo = false;
					tablero_running = true;
				}

				if (e.button.clicks == 2 && currentimage == menu_salir)
				{
					running = false;
				}

				if (e.button.clicks == 2 && currentimage == menu_ajustes)
				{
					currentimage = ajustes_inicial;
					menu_inicial_activo = false;
					a = true;
				}

				//menu ajustes
				if (e.button.clicks == 2 && currentimage == ajustes_sonido)
				{
					currentimage = sonido_inicial;
					a = false;
					s = true;
				}

				if (e.button.clicks == 2 && currentimage == ajustes_tamano)
				{
					currentimage = tamano_inicial;
					a=false;
					t = true;
				}

				if (e.button.clicks == 2 && currentimage == ajustes_volver)
				{
					currentimage = menu_inicial;
					a = false;
					menu_inicial_activo = true;
				}

				//menu tamano
				if (e.button.clicks == 2 && currentimage == tamano_grande) {
					currentimage = ajustes_inicial;
					a = true;
					t = false;
					Grande = true;
					altura = 900;
					anchura = 900;


				}

				if (e.button.clicks == 2 && currentimage == tamano_pequeno) {
					currentimage = ajustes_inicial;
					a = true;
					t = false;
					Grande = false;
					altura = 600;
					anchura = 600;
				}

				if (e.button.clicks == 2 && currentimage == tamano_volver) {
					currentimage = ajustes_inicial;
					a = true;
					t = false;
				}

				//menu sonido
				if (e.button.clicks == 2 && currentimage == sonido_on) {
					currentimage = ajustes_inicial;
					a = true;
					s = false;
					sonido = true;
					ETSIDI::playMusica("Musica/WiiTheme.mp3", true);
				}

				if (e.button.clicks == 2 && currentimage == sonido_off) {
					currentimage = ajustes_inicial;
					a = true;
					s = false;
					sonido = false;
					ETSIDI::stopMusica();
				}

				if (e.button.clicks == 2 && currentimage == sonido_volver) {
					currentimage = ajustes_inicial;
					a = true;
					s = false;
				}
			}

			//posicion del raton
			else if (e.type == SDL_MOUSEMOTION)
			{
				//menu inicial
				if (menu_inicial_activo == true)
				{
					if (e.button.y > 180 && e.button.y < 220)
						currentimage = menu_jugar;
					else if (e.button.y > 220 && e.button.y < 265)
						currentimage = menu_ajustes;
					else if (e.button.y > 265 && e.button.y < 320)
						currentimage = menu_salir;
					else
						currentimage = menu_inicial;
				}
				//menu jugar

			   //menu ajustes

				else if (a == true)
				{
					if (e.button.y > 180 && e.button.y < 240)
						currentimage = ajustes_tamano;
					else if (e.button.y > 240 && e.button.y < 290)
						currentimage = ajustes_sonido;
					else if (e.button.y > 290 && e.button.y < 320)
						currentimage = ajustes_volver;
					else
						currentimage = ajustes_inicial;
				}


				//menu tamaño

				else if (t == true)
				{
					if (e.button.y > 180 && e.button.y < 240)
						currentimage = tamano_grande;
					else if (e.button.y > 240 && e.button.y < 290)
						currentimage = tamano_pequeno;
					else if (e.button.y > 290 && e.button.y < 330)
						currentimage = tamano_volver;
					else
						currentimage = tamano_inicial;
				}

				//menu sonido
				else if (s == true)
				{
					if (e.button.y > 180 && e.button.y < 240)
						currentimage = sonido_on;
					else if (e.button.y > 240 && e.button.y < 290)
						currentimage = sonido_off;
					else if (e.button.y > 290 && e.button.y < 330)
						currentimage = sonido_volver;
					else
						currentimage = sonido_inicial;
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

bool Menu::getMenuTamano() {
	return Grande;
}

bool Menu::getSonido() {
	return sonido;
}

bool Menu::getTableroRunning() {
	return tablero_running;
}

int Menu::getAltura() {
	return altura;
}

int Menu::getAnchura() {
	return anchura;
}