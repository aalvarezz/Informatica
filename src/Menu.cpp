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

	menu_ajustes_activo = false;
	ajustes_inicial = nullptr;
	ajustes_tamano = nullptr;
	ajustes_sonido = nullptr;
	ajustes_volver = nullptr;

	menu_sonido_activo = false;
	sonido = true;
	sonido_inicial = nullptr;
	sonido_on = nullptr;
	sonido_off = nullptr;
	sonido_volver = nullptr;

	menu_tamano_activo = false;
	Grande = true;
	altura = 900;
	anchura = 900;
	tamano_inicial = nullptr;
	tamano_grande = nullptr;
	tamano_pequeno = nullptr;
	tamano_volver = nullptr;

}

void Menu::inicializaFin()
{
	// luego asignaremos true al que este activo en funcion del resulltado de la partida
	menu_fin_blancas_activo = false;
	menu_fin_negras_activo = false;
	blancas_inicial = nullptr;
	blancas_jugar = nullptr;
	blancas_menu = nullptr;
	blancas_salir = nullptr;
	negras_inicial = nullptr;
	negras_jugar = nullptr;
	negras_menu = nullptr;
	negras_salir = nullptr;

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

void Menu::asignaFin() 
{
	currentimage = optimatedsurface("imagenes_fin_partida/fin_blancas_inicial.bmp", windowsurface);

	blancas_inicial = SDL_LoadBMP("imagenes_fin_partida/fin_blancas_inicial.bmp");
	blancas_jugar = SDL_LoadBMP("imagenes_fin_partida/fin_blancas_jugar.bmp");
	blancas_menu = SDL_LoadBMP("imagenes_fin_partida/fin_blancas_menu.bmp");
	blancas_salir = SDL_LoadBMP("imagenes_fin_partida/fin_blancas_salir.bmp");

	negras_inicial = SDL_LoadBMP("imagenes_fin_partida/fin_negras_inicial.bmp");
	negras_jugar = SDL_LoadBMP("imagenes_fin_partida/fin_negras_jugar.bmp");
	negras_menu = SDL_LoadBMP("imagenes_fin_partida/fin_negras_menu.bmp");
	negras_salir = SDL_LoadBMP("imagenes_fin_partida/fin_negras_salir.bmp");

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


void Menu::liberarFin() 
{
	currentimage = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	windowsurface = nullptr;

	SDL_FreeSurface(blancas_inicial);
	SDL_FreeSurface(blancas_jugar);
	SDL_FreeSurface(blancas_menu);
	SDL_FreeSurface(blancas_salir);
	SDL_FreeSurface(negras_inicial);
	SDL_FreeSurface(negras_jugar);
	SDL_FreeSurface(negras_menu);
	SDL_FreeSurface(negras_salir);

	blancas_inicial = blancas_jugar = blancas_menu = blancas_salir = nullptr;
	negras_inicial = negras_jugar = negras_menu = negras_salir = nullptr;

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

				if (menu_ajustes_activo == true && e.key.keysym.sym == SDLK_ESCAPE)
				{
					currentimage = menu_inicial;
					menu_inicial_activo = true;
					menu_ajustes_activo = false;

				}

				if (menu_sonido_activo == true && e.key.keysym.sym == SDLK_ESCAPE)
				{
					currentimage = ajustes_inicial;
					menu_ajustes_activo = true;
					menu_sonido_activo = false;
				}

				if (menu_tamano_activo == true && e.key.keysym.sym == SDLK_ESCAPE)
				{
					currentimage = ajustes_inicial;
					menu_ajustes_activo = true;
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
					menu_ajustes_activo = true;
				}

				//menu ajustes
				if (e.button.clicks == 2 && currentimage == ajustes_sonido)
				{
					currentimage = sonido_inicial;
					menu_ajustes_activo = false;
					menu_sonido_activo = true;
				}

				if (e.button.clicks == 2 && currentimage == ajustes_tamano)
				{
					currentimage = tamano_inicial;
					menu_ajustes_activo = false;
					menu_tamano_activo = true;
				}

				if (e.button.clicks == 2 && currentimage == ajustes_volver)
				{
					currentimage = menu_inicial;
					menu_ajustes_activo = false;
					menu_inicial_activo = true;
				}

				//menu tamano
				if (e.button.clicks == 2 && currentimage == tamano_grande) {
					currentimage = ajustes_inicial;
					menu_ajustes_activo = true;
					menu_tamano_activo = false;
					Grande = true;
					altura = 900;
					anchura = 900;


				}

				if (e.button.clicks == 2 && currentimage == tamano_pequeno) {
					currentimage = ajustes_inicial;
					menu_ajustes_activo = true;
					menu_tamano_activo = false;
					Grande = false;
					altura = 600;
					anchura = 600;
				}

				if (e.button.clicks == 2 && currentimage == tamano_volver) {
					currentimage = ajustes_inicial;
					menu_ajustes_activo = true;
					menu_tamano_activo = false;
				}

				//menu sonido
				if (e.button.clicks == 2 && currentimage == sonido_on) {
					currentimage = ajustes_inicial;
					menu_ajustes_activo = true;
					menu_sonido_activo = false;
					sonido = true;
					ETSIDI::playMusica("Musica/WiiTheme.mp3", true);
				}

				if (e.button.clicks == 2 && currentimage == sonido_off) {
					currentimage = ajustes_inicial;
					menu_ajustes_activo = true;
					menu_sonido_activo = false;
					sonido = false;
					ETSIDI::stopMusica();
				}

				if (e.button.clicks == 2 && currentimage == sonido_volver) {
					currentimage = ajustes_inicial;
					menu_ajustes_activo = true;
					menu_sonido_activo = false;
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

			   //menu ajustes

				else if (menu_ajustes_activo == true)
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

				else if (menu_tamano_activo == true)
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
				else if (menu_sonido_activo == true)
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

void Menu::eventoFin() 
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
				if (menu_fin_blancas_activo == true && e.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}

				if (menu_fin_negras_activo == true && e.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}


			}

			//eventos botones raton
			else if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				//volver a jugar
				if (e.button.clicks == 2 && currentimage == blancas_jugar)
				{
					running = false;
					menu_fin_blancas_activo = false;
					tablero_running = true;
				}

				if (e.button.clicks == 2 && currentimage ==negras_jugar)
				{
					running = false;
					menu_fin_negras_activo = false;
					tablero_running = true;
				}

				//volver al menu
				if (e.button.clicks == 2 && currentimage == blancas_menu)
				{
					running = false;
					menu_fin_blancas_activo = false;
					menu_running = true;
				}

				if (e.button.clicks == 2 && currentimage == negras_menu)
				{
					running = false;
					menu_fin_negras_activo = false;
					menu_running = true;
				}

				//salir
				if (e.button.clicks == 2 && currentimage == blancas_salir)
				{
					running = false;
					menu_fin_blancas_activo = false;
				}

				if (e.button.clicks == 2 && currentimage == negras_salir)
				{
					running = false;
					menu_fin_negras_activo = false;
				}

			}

			//posicion del raton
			else if (e.type == SDL_MOUSEMOTION)
			{
				//menu victoria blancas
				if (menu_fin_blancas_activo == true)
				{
					if (e.button.y > 180 && e.button.y < 220)
						currentimage = blancas_jugar;
					else if (e.button.y > 220 && e.button.y < 265)
						currentimage = blancas_menu;
					else if (e.button.y > 265 && e.button.y < 320)
						currentimage = blancas_salir;
					else
						currentimage = blancas_inicial;
				}

				//menu victoria negras
				if (menu_fin_negras_activo == true)
				{
					if (e.button.y > 180 && e.button.y < 220)
						currentimage = negras_jugar;
					else if (e.button.y > 220 && e.button.y < 265)
						currentimage = negras_menu;
					else if (e.button.y > 265 && e.button.y < 320)
						currentimage = negras_salir;
					else
						currentimage = negras_inicial;
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

bool Menu::getSonido() {
	return sonido;
}

