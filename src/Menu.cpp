#include "Menu.h"

Menu::Menu() {
	//El constructor de Menú inicializa las variables necesarias para que funcione como Menú inicial
	window = nullptr;
	windowsurface = nullptr;
	currentimage = nullptr;
	tablero_running = false;

	menu_inicial_activo = true;
	menu_inicial = nullptr;
	menu_ajustes = nullptr;
	menu_jugar = nullptr;
	menu_salir = nullptr;

	menu_modo_activo = false;
	modo_clasico = nullptr;
	modo_inicial = nullptr;
	modo_especial = nullptr;
	modo_salir = nullptr;

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
	altura = 900;
	anchura = 900;
	tamano_inicial = nullptr;
	tamano_grande = nullptr;
	tamano_pequeno = nullptr;
	tamano_volver = nullptr;
}

void Menu::inicializar() {
	//Parámetros relativos al menú inicial. La función inicializar es una copia del constructor para poder 
	//devolver sus atributos al valor por defecto cuando se termina una partida y se elige volver al menú de inicio
	window = nullptr;
	windowsurface = nullptr;
	currentimage = nullptr;
	tablero_running = false;

	menu_inicial_activo = true;
	menu_inicial = nullptr;
	menu_ajustes = nullptr;
	menu_jugar = nullptr;
	menu_salir = nullptr;

	menu_modo_activo = false;
	modo_clasico = nullptr;
	modo_inicial = nullptr;
	modo_especial = nullptr;
	modo_salir = nullptr;

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
	altura = 900;
	anchura = 900;
	tamano_inicial = nullptr;
	tamano_grande = nullptr;
	tamano_pequeno = nullptr;
	tamano_volver = nullptr;
}

void Menu::inicializarFinDePartida(bool a, bool b, bool c, bool d) {
	//Parámetros relativos al menú de fin de partida
	tablero_running = false;
	menu_fin_blancas_activo = a;
	menu_fin_negras_activo = b;
	menu_fin_empate_blancas_activo = c;
	menu_fin_empate_negras_activo = d;
	blancas_inicial = nullptr;
	blancas_jugar = nullptr;
	blancas_menu = nullptr;
	blancas_salir = nullptr;
	negras_inicial = nullptr;
	negras_jugar = nullptr;
	negras_menu = nullptr;
	negras_salir = nullptr;
}

void Menu::inicializarCoronacion() {
	//Parámetros relativos al menú de coronación
	window = nullptr;
	windowsurface = nullptr;
	currentimage = nullptr;

	coronacion_inicial = nullptr;
	coronacion_dama = nullptr;
	coronacion_alfil = nullptr;
	coronacion_caballo = nullptr;
	coronacion_torre = nullptr;
}

void Menu::asignar() {
	//Se inicializan todos los atributos que almacenan las imágenes necesarias para la parte gráfica del menú inicial
	currentimage = optimatedsurface("imagenes_menu/menu_inicial.bmp", windowsurface);

	menu_inicial = SDL_LoadBMP("imagenes_menu/menu_inicial.bmp");
	menu_ajustes = SDL_LoadBMP("imagenes_menu/menu_inicial_ajustes.bmp");
	menu_jugar = SDL_LoadBMP("imagenes_menu/menu_inicial_jugar.bmp");
	menu_salir = SDL_LoadBMP("imagenes_menu/menu_inicial_salir.bmp");

	modo_inicial = SDL_LoadBMP("imagenes_jugar/menu_modo_inicial.bmp");
	modo_clasico = SDL_LoadBMP("imagenes_jugar/menu_modo_clasico.bmp");
	modo_especial = SDL_LoadBMP("imagenes_jugar/menu_modo_especial.bmp");
	modo_salir = SDL_LoadBMP("imagenes_jugar/menu_modo_volver.bmp");

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

void Menu::asignarFinDePartida()  {
	//Se inicializan todos los atributos que almacenan las imágenes necesarias para la parte gráfica del menú de fin de partida
	if (menu_fin_blancas_activo) {
		currentimage = optimatedsurface("imagenes_fin_partida/fin_blancas_inicial.bmp", windowsurface);
	}
	if (menu_fin_negras_activo) {
		currentimage = optimatedsurface("imagenes_fin_partida/fin_negras_inicial.bmp", windowsurface);
	}
	if (menu_fin_empate_blancas_activo) {
		currentimage = optimatedsurface("imagenes_fin_partida/tablas_blancas_inicial.bmp", windowsurface);
	}
	if (menu_fin_empate_negras_activo) {
		currentimage = optimatedsurface("imagenes_fin_partida/tablas_negras_inicial.bmp", windowsurface);
	}

	blancas_inicial = SDL_LoadBMP("imagenes_fin_partida/fin_blancas_inicial.bmp");
	blancas_jugar = SDL_LoadBMP("imagenes_fin_partida/fin_blancas_jugar.bmp");
	blancas_menu = SDL_LoadBMP("imagenes_fin_partida/fin_blancas_menu.bmp");
	blancas_salir = SDL_LoadBMP("imagenes_fin_partida/fin_blancas_salir.bmp");

	negras_inicial = SDL_LoadBMP("imagenes_fin_partida/fin_negras_inicial.bmp");
	negras_jugar = SDL_LoadBMP("imagenes_fin_partida/fin_negras_jugar.bmp");
	negras_menu = SDL_LoadBMP("imagenes_fin_partida/fin_negras_menu.bmp");
	negras_salir = SDL_LoadBMP("imagenes_fin_partida/fin_negras_salir.bmp");

	empate_negras_inicial = SDL_LoadBMP("imagenes_fin_partida/tablas_negras_inicial.bmp");
	empate_negras_jugar = SDL_LoadBMP("imagenes_fin_partida/tablas_negras_jugar.bmp");
	empate_negras_menu= SDL_LoadBMP("imagenes_fin_partida/tablas_negras_menu.bmp");
	empate_negras_salir = SDL_LoadBMP("imagenes_fin_partida/tablas_negras_salir.bmp");

	empate_blancas_inicial = SDL_LoadBMP("imagenes_fin_partida/tablas_blancas_inicial.bmp");
	empate_blancas_jugar = SDL_LoadBMP("imagenes_fin_partida/tablas_blancas_jugar.bmp");
	empate_blancas_menu = SDL_LoadBMP("imagenes_fin_partida/tablas_blancas_menu.bmp");
	empate_blancas_salir = SDL_LoadBMP("imagenes_fin_partida/tablas_blancas_salir.bmp");
}

void Menu::asignarCoronacion() {
	//Se inicializan todos los atributos que almacenan las imágenes necesarias para la parte gráfica del menú de coronación
	currentimage = optimatedsurface("imagenes_coronacion/coronacion_inicial.bmp", windowsurface);

	coronacion_inicial = SDL_LoadBMP("imagenes_coronacion/coronacion_inicial.bmp");
	coronacion_dama = SDL_LoadBMP("imagenes_coronacion/coronacion_dama.bmp");
	coronacion_alfil = SDL_LoadBMP("imagenes_coronacion/coronacion_alfil.bmp");
	coronacion_caballo = SDL_LoadBMP("imagenes_coronacion/coronacion_caballo.bmp");
	coronacion_torre = SDL_LoadBMP("imagenes_coronacion/coronacion_torre.bmp");
}

void Menu::liberar() {
	//Gestión de memoria relativa al menú inicial
	currentimage = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	windowsurface = nullptr;

	SDL_FreeSurface(menu_inicial);
	SDL_FreeSurface(menu_salir);
	SDL_FreeSurface(menu_ajustes);
	SDL_FreeSurface(menu_jugar);
	menu_inicial = menu_jugar = menu_ajustes = menu_salir = nullptr;

	SDL_FreeSurface(modo_inicial);
	SDL_FreeSurface(modo_clasico);
	SDL_FreeSurface(modo_especial);
	SDL_FreeSurface(modo_salir);
	modo_clasico = modo_especial = modo_inicial = modo_salir = nullptr;

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

void Menu::liberarFinDePartida() {
	//Gestión de memoria relativa al menú de fin de partida
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
	SDL_FreeSurface(empate_blancas_inicial);
	SDL_FreeSurface(empate_blancas_jugar);
	SDL_FreeSurface(empate_blancas_menu);
	SDL_FreeSurface(empate_blancas_salir);
	SDL_FreeSurface(empate_negras_inicial);
	SDL_FreeSurface(empate_negras_jugar);
	SDL_FreeSurface(empate_negras_menu);
	SDL_FreeSurface(empate_negras_salir);

	blancas_inicial = blancas_jugar = blancas_menu = blancas_salir = nullptr;
	negras_inicial = negras_jugar = negras_menu = negras_salir = nullptr;
	empate_blancas_inicial = empate_blancas_jugar = empate_blancas_menu = empate_blancas_salir = nullptr;
	empate_negras_inicial = empate_negras_jugar = empate_negras_menu = empate_negras_salir = nullptr;
}

void Menu::liberarCoronacion() {
	//Gestión de memoria relativa al menú de coronación
	currentimage = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	windowsurface = nullptr;

	SDL_FreeSurface(coronacion_inicial);
	SDL_FreeSurface(coronacion_dama);
	SDL_FreeSurface(coronacion_alfil);
	SDL_FreeSurface(coronacion_caballo);
	SDL_FreeSurface(coronacion_torre);
	coronacion_inicial = coronacion_dama = coronacion_caballo = coronacion_torre = nullptr;
}

void Menu::ventana() {
	window = SDL_CreateWindow("menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 410, SDL_WINDOW_SHOWN);
	windowsurface = SDL_GetWindowSurface(window);
}

/*
* Este método se encarga de optimizar el ajuste de la imágen o superficie de los menús a la ventana
*/
SDL_Surface* Menu::optimatedsurface(std::string filepath, SDL_Surface* windowsurface) {
	SDL_Surface* optimatedsurface = nullptr;
	SDL_Surface* surface = SDL_LoadBMP(filepath.c_str());
	if (surface == NULL) {
		std::cout << "error" << std::endl;
	}
	else {
		optimatedsurface = SDL_ConvertSurface(surface, windowsurface->format, 0);
		if (optimatedsurface == NULL)
			std::cout << "error" << std::endl;
	}
	SDL_FreeSurface(surface);
	return optimatedsurface;
}

/*
* Método encargado de la gestión de eventos en el menú inicial
*/
void Menu::evento() {
	menu_running = true;
	SDL_Event e;

	SDL_Rect drawingrect;
	drawingrect.x = drawingrect.y = 0;
	drawingrect.w = 640;
	drawingrect.h = 410;

	std::string text = "";
	SDL_StartTextInput();

	while (menu_running) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				menu_running = false;
				exit(0);
			}
				
			//Eventos del teclado
			else if (e.type == SDL_KEYDOWN) {
				if (menu_inicial_activo == true && e.key.keysym.sym == SDLK_ESCAPE) {
					menu_running = false;
					exit(0);
				}

				if (menu_modo_activo == true && e.key.keysym.sym == SDLK_ESCAPE) {
					currentimage = menu_inicial;
					menu_inicial_activo = true;
					menu_modo_activo = false;
					exit(0);
				}

				if (menu_ajustes_activo == true && e.key.keysym.sym == SDLK_ESCAPE) {
					currentimage = menu_inicial;
					menu_inicial_activo = true;
					menu_ajustes_activo = false;
				}

				if (menu_sonido_activo == true && e.key.keysym.sym == SDLK_ESCAPE) {
					currentimage = ajustes_inicial;
					menu_ajustes_activo = true;
					menu_sonido_activo = false;
				}

				if (menu_tamano_activo == true && e.key.keysym.sym == SDLK_ESCAPE) {
					currentimage = ajustes_inicial;
					menu_ajustes_activo = true;
					menu_tamano_activo = false;
				}
			}

			//Eventos de clic del ratón
			else if (e.type == SDL_MOUSEBUTTONDOWN) {
				//Menú inicial
				if (e.button.clicks == 2 && currentimage == menu_jugar) {
					currentimage = modo_inicial;
					menu_modo_activo = true;
					menu_inicial_activo = false;
				}

				if (e.button.clicks == 2 && currentimage == menu_salir) {
					menu_running = false;
					exit(0);
				}

				if (e.button.clicks == 2 && currentimage == menu_ajustes) {
					currentimage = ajustes_inicial;
					menu_inicial_activo = false;
					menu_ajustes_activo = true;
				}

				//Menú de elección de modo de juego
				if (e.button.clicks == 2 && currentimage == modo_clasico) {
					tablero_running = true;
					menu_running = false;
					partida_normal = true;
					menu_modo_activo = false;
				}

				if (e.button.clicks == 2 && currentimage == modo_especial) {
					tablero_running = true;
					menu_running = false;
					partida_normal = false;
					menu_modo_activo = false;
				}

				if (e.button.clicks == 2 && currentimage == modo_salir) {
					currentimage = menu_inicial;					
					menu_modo_activo = false;
					menu_inicial_activo = true;
				}

				//Menú de ajustes
				if (e.button.clicks == 2 && currentimage == ajustes_sonido) {
					currentimage = sonido_inicial;
					menu_ajustes_activo = false;
					menu_sonido_activo = true;
				}

				if (e.button.clicks == 2 && currentimage == ajustes_tamano) {
					currentimage = tamano_inicial;
					menu_ajustes_activo = false;
					menu_tamano_activo = true;
				}

				if (e.button.clicks == 2 && currentimage == ajustes_volver) {
					currentimage = menu_inicial;
					menu_ajustes_activo = false;
					menu_inicial_activo = true;
				}

				//Menú de elección del tamaño de la pantalla
				if (e.button.clicks == 2 && currentimage == tamano_grande) {
					currentimage = ajustes_inicial;
					menu_ajustes_activo = true;
					menu_tamano_activo = false;
					grande = true;
					altura = 900;
					anchura = 900;
				}

				if (e.button.clicks == 2 && currentimage == tamano_pequeno) {
					currentimage = ajustes_inicial;
					menu_ajustes_activo = true;
					menu_tamano_activo = false;
					grande = false;
					altura = 600;
					anchura = 600;
				}

				if (e.button.clicks == 2 && currentimage == tamano_volver) {
					currentimage = ajustes_inicial;
					menu_ajustes_activo = true;
					menu_tamano_activo = false;
				}

				//Menú sonido
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

			//Posición del raton
			else if (e.type == SDL_MOUSEMOTION) {
				//Menú inicial
				if (menu_inicial_activo == true) {
					if (e.button.y > 180 && e.button.y < 220)
						currentimage = menu_jugar;
					else if (e.button.y > 220 && e.button.y < 265)
						currentimage = menu_ajustes;
					else if (e.button.y > 265 && e.button.y < 320)
						currentimage = menu_salir;
					else
						currentimage = menu_inicial;
				}

				//Menú de elección de modo de juego
				if (menu_modo_activo == true) {
					if (e.button.y > 180 && e.button.y < 220)
						currentimage = modo_clasico;
					else if (e.button.y > 220 && e.button.y < 265)
						currentimage = modo_especial;
					else if (e.button.y > 265 && e.button.y < 320)
						currentimage = modo_salir;
					else
						currentimage = modo_inicial;
				}

			   //Menú ajustes
				else if (menu_ajustes_activo == true) {
					if (e.button.y > 180 && e.button.y < 240)
						currentimage = ajustes_tamano;
					else if (e.button.y > 240 && e.button.y < 290)
						currentimage = ajustes_sonido;
					else if (e.button.y > 290 && e.button.y < 320)
						currentimage = ajustes_volver;
					else
						currentimage = ajustes_inicial;
				}

				//Menú de elección del tamaño de la pantalla
				else if (menu_tamano_activo == true) {
					if (e.button.y > 180 && e.button.y < 240)
						currentimage = tamano_grande;
					else if (e.button.y > 240 && e.button.y < 290)
						currentimage = tamano_pequeno;
					else if (e.button.y > 290 && e.button.y < 330)
						currentimage = tamano_volver;
					else
						currentimage = tamano_inicial;
				}

				//Menú sonido
				else if (menu_sonido_activo == true) {
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

			//Escribir texto
			else if (e.type == SDL_TEXTINPUT || e.type == SDL_KEYDOWN) {
				system("cls");
				if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0)
					text = text.substr(0, text.length() - 1); //Borra
				else if (e.type == SDL_TEXTINPUT)
					text += e.text.text; //Escribe

				std::cout << text << std::endl;
			}
		}
		SDL_BlitSurface(currentimage, NULL, windowsurface, &drawingrect);
		SDL_UpdateWindowSurface(window);
	}
}

/*
* Método encargado de la gestión de eventos en el menú de fin de partida
*/
int Menu::eventoFinDePartida()  {
	SDL_Event e;

	SDL_Rect drawingrect;
	drawingrect.x = drawingrect.y = 0;
	drawingrect.w = 640;
	drawingrect.h = 410;

	std::string text = "";
	SDL_StartTextInput();

	while (menu_fin_blancas_activo || menu_fin_negras_activo || menu_fin_empate_blancas_activo || menu_fin_empate_negras_activo) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				menu_fin_blancas_activo = false;
				menu_fin_negras_activo = false;
				menu_fin_empate_blancas_activo = false;
				menu_fin_empate_negras_activo = false;
				return 0;
			}
				
			//Eventos del teclado
			else if (e.type == SDL_KEYDOWN) {
				if (menu_fin_blancas_activo == true && e.key.keysym.sym == SDLK_ESCAPE) {
					menu_fin_blancas_activo = false;
				}
				if (menu_fin_negras_activo == true && e.key.keysym.sym == SDLK_ESCAPE) {
					menu_fin_negras_activo = false;
				}
				if (menu_fin_empate_blancas_activo == true && e.key.keysym.sym == SDLK_ESCAPE) {
					menu_fin_empate_blancas_activo = false;
				}
				if (menu_fin_empate_negras_activo == true && e.key.keysym.sym == SDLK_ESCAPE) {
					menu_fin_empate_negras_activo = false;
				}
				return 0;
			}

			//Evento de clic del ratón
			else if (e.type == SDL_MOUSEBUTTONDOWN) {
				//Volver a jugar
				if (e.button.clicks == 2 && currentimage == blancas_jugar) {				
					menu_fin_blancas_activo = false;
					tablero_running = true;
					return 1;
				}

				if (e.button.clicks == 2 && currentimage ==negras_jugar) {
					
					menu_fin_negras_activo = false;
					tablero_running = true;
					return 1;
				}
				
				if (e.button.clicks == 2 && currentimage == empate_blancas_jugar) {
					menu_fin_empate_blancas_activo = false;
					tablero_running = true;
					return 1;
				}

				if (e.button.clicks == 2 && currentimage == empate_negras_jugar) {
					menu_fin_empate_negras_activo = false;
					tablero_running = true;
					return 1;
				}

				//Volver al menú
				if (e.button.clicks == 2 && currentimage == blancas_menu) {				
					menu_fin_blancas_activo = false;
					menu_running = true;
					return 2;
				}

				if (e.button.clicks == 2 && currentimage == negras_menu) {
					menu_fin_negras_activo = false;
					menu_running = true;
					return 2;
				}

				if (e.button.clicks == 2 && currentimage == empate_blancas_menu) {
					menu_fin_empate_blancas_activo = false;
					menu_running = true;
					return 2;
				}

				if (e.button.clicks == 2 && currentimage == empate_negras_menu) {
					menu_fin_empate_negras_activo = false;
					menu_running = true;
					return 2;
				}

				//Salir
				if (e.button.clicks == 2 && currentimage == blancas_salir) {
					menu_fin_blancas_activo = false;
					return 0;
				}

				if (e.button.clicks == 2 && currentimage == negras_salir) {
					menu_fin_negras_activo = false;
					return 0;
				}

				if (e.button.clicks == 2 && currentimage == empate_blancas_salir) {
					menu_fin_empate_blancas_activo = false;
					return 0;
				}

				if (e.button.clicks == 2 && currentimage == empate_negras_salir) {
					menu_fin_empate_negras_activo = false;
					return 0;
				}
			}

			//Posicion del ratón
			else if (e.type == SDL_MOUSEMOTION) {
				//Menú victoria blancas
				if (menu_fin_blancas_activo == true) {
					if (e.button.y > 180 && e.button.y < 240)
						currentimage = blancas_jugar;
					else if (e.button.y > 240 && e.button.y < 300)
						currentimage = blancas_menu;
					else if (e.button.y > 300 && e.button.y < 360)
						currentimage = blancas_salir;
					else
						currentimage = blancas_inicial;
				}

				//Menú victoria negras
				if (menu_fin_negras_activo == true) {
					if (e.button.y > 180 && e.button.y < 220)
						currentimage = negras_jugar;
					else if (e.button.y > 240 && e.button.y < 300)
						currentimage = negras_menu;
					else if (e.button.y > 300 && e.button.y < 360)
						currentimage = negras_salir;
					else
						currentimage = negras_inicial;
				}

				//Menú tablas por rey blanco ahogado
				if (menu_fin_empate_blancas_activo == true) {
					if (e.button.y > 180 && e.button.y < 220)
						currentimage = empate_blancas_jugar;
					else if (e.button.y > 240 && e.button.y < 300)
						currentimage = empate_blancas_menu;
					else if (e.button.y > 300 && e.button.y < 360)
						currentimage = empate_blancas_salir;
					else
						currentimage = empate_blancas_inicial;
				}

				//Menú tablas por rey blanco ahogado
				if (menu_fin_empate_negras_activo == true) {
					if (e.button.y > 180 && e.button.y < 220)
						currentimage = empate_negras_jugar;
					else if (e.button.y > 240 && e.button.y < 300)
						currentimage = empate_negras_menu;
					else if (e.button.y > 300 && e.button.y < 360)
						currentimage = empate_negras_salir;
					else
						currentimage = empate_negras_inicial;
				}
			}

			//Escribir texto
			else if (e.type == SDL_TEXTINPUT || e.type == SDL_KEYDOWN) {
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

/*
* Método encargado de la gestión de eventos en el menú de coronación
*/
int Menu::eventoCoronacion() {
	bool running = true;
	SDL_Event e;

	SDL_Rect drawingrect;
	drawingrect.x = drawingrect.y = 0;
	drawingrect.w = 640;
	drawingrect.h = 410;

	std::string text = "";
	SDL_StartTextInput();

	while (running) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {

			}

			//eventos con teclas
			else if (e.type == SDL_KEYDOWN)
			{

			}

			//Evento de clic del ratón
			else if (e.type == SDL_MOUSEBUTTONDOWN) {
				//Selección de la pieza
				if (e.button.clicks == 2 && currentimage == coronacion_dama) {
					running = false;
					return 3;
				}

				if (e.button.clicks == 2 && currentimage == coronacion_alfil) {
					running = false;
					return 4;
				}

				if (e.button.clicks == 2 && currentimage == coronacion_caballo) {
					running = false;
					return 5;
				}

				if (e.button.clicks == 2 && currentimage == coronacion_torre) {
					running = false;
					return 6;
				}
			}

			//Posición del ratón
			else if (e.type == SDL_MOUSEMOTION) {

				if (e.button.y > 195 && e.button.y < 230)
					currentimage = coronacion_dama;
				else if (e.button.y > 230 && e.button.y < 270)
					currentimage = coronacion_alfil;
				else if (e.button.y > 270 && e.button.y < 320)
					currentimage = coronacion_caballo;
				else if (e.button.y > 320 && e.button.y < 360)
					currentimage = coronacion_torre;
				else
					currentimage = coronacion_inicial;
			}

			//Escribir texto
			else if (e.type == SDL_TEXTINPUT || e.type == SDL_KEYDOWN) {
				system("cls");
				if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0)
					text = text.substr(0, text.length() - 1); //Borra
				else if (e.type == SDL_TEXTINPUT)
					text += e.text.text; //Escribe

				std::cout << text << std::endl;
			}
		}
		SDL_BlitSurface(currentimage, NULL, windowsurface, &drawingrect);
		SDL_UpdateWindowSurface(window);
	}
}
