#include "Pieza.h"

Pieza::Pieza() {
	posoriginal = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Tablero::comprueba(Pieza pieza, Pos pos_inicial, Pos pos_final) {
	std::vector<Casilla> miscasillas = aplicaReglas(pieza, pos_inicial); //casillas a las que puedo ir con mi pieza_aux en posicion_inicial
	Casilla casilla_final = tablero[pos_final.fila][pos_final.columna];
	bool resultado = false;

	if (std::find(miscasillas.begin(), miscasillas.end(), casilla_final) != miscasillas.end()) {

		//Comprobamos que en la casilla que quiero poner mi pieza no tengo otra ya (DEL MISMO COLOR).
		if (casilla_final.GetEstado() && pieza.getColor() == casilla_final.GetPieza().getColor()) {
			resultado = false;
			return resultado;
		}
		if (turno_b)
		{
			//PEON BLANCO (1)
			if (pieza_aux.GetTipo() == 1) {

				//el peón quiere moverse a una diagonal
				if (tablero[pos_inicial.fila + 1][pos_inicial.columna - 1] == casilla_final || tablero[pos_inicial.fila + 1][pos_inicial.columna + 1] == casilla_final) {
					//hay una pieza de otro color ya (ya hemos comprobado que no sea del mismo)
					if (casilla_final.GetEstado()) {
						return true;
					}
				}

				//el peón quiere moverse recto 1 casilla y tiene que estar vacía
				if (tablero[pos_inicial.fila + 1][pos_inicial.columna] == casilla_final && (!casilla_final.GetEstado())) {
					resultado = true;
					return resultado;
				}

				//el peón está en su posición de origen, puede avanzar dos casillas
				if ((pieza.getFilaOrigen() == pos_inicial.fila) && (pos_final.fila == pos_inicial.fila + 2) && (!casilla_final.GetEstado())) { //hay que comparar tambien la columna?
					resultado = true;
					return resultado;
				}

			}
			//REYES 2
			if (pieza_aux.GetTipo() == 2) {

				for (int j = -1; j <= 1; j++) {
					for (int k = -1; k <= 1; k++) {

						if (!((j == 0) && (k == 0))) {

							//el rey quiere moverse a una diagonal
							if (tablero[pos_inicial.fila + j][pos_inicial.columna + k] == casilla_final) {
								return true;
							}
						}
					}
				}

				//Falta enroque
			}
			//DAMAS (3 Y 9)
			if (pieza_aux.GetTipo() == 3) {
				int caso = 0;
				int difcol = pos_final.columna - pos_inicial.columna;
				int diffil = pos_final.fila - pos_inicial.fila;

				//derecha
				if (difcol > 0) {
					if (diffil == difcol) caso = 1; //arriba dcha
					if (diffil == 0) caso = 2; //recto dcha
					if (-diffil == difcol) caso = 3; //abajo dcha
				}
				//izquierda
				if (difcol < 0) {
					if (diffil == difcol) caso = 5; //abajo izq
					if (diffil == 0) caso = 6; //recto izq
					if (-diffil == difcol) caso = 7; //arriba izq
				}
				//recto arriba o abajo
				if (difcol == 0) {
					if (diffil < 0) caso = 4; //abajo recto
					if (diffil > 0) caso = 8; //arriba recto
				}

				if (caso % 2 == 0)
					return MovimTorre();
				else
					return MovimAlfil();

			}
			//ALFIL 4
			if (pieza_aux.GetTipo() == 4)
			{
				return MovimAlfil();
			}
			//CABALLO 5
			if (pieza_aux.GetTipo() == 5) {
				resultado = true;
				return resultado;
			}

			//TORRES 6
			if (pieza_aux.GetTipo() == 6) {
				return MovimTorre();

			}
		}

		else
		{
			//PEON NEGRO (7)
			if (pieza_aux.GetTipo() == 7) {
				//el peón quiere moverse a una diagonal
				if (tablero[pos_inicial.fila - 1][pos_inicial.columna - 1] == casilla_final || tablero[pos_inicial.fila - 1][pos_inicial.columna + 1] == casilla_final) {
					//hay una pieza de otro color ya (ya hemos comprobado que no sea del mismo)
					if (casilla_final.GetEstado()) {
						return true;
					}
				}

				//el peón quiere moverse recto 1 casilla y tiene que estar vacía
				if (tablero[pos_inicial.fila - 1][pos_inicial.columna] == casilla_final && (!casilla_final.GetEstado())) {
					resultado = true;
					return resultado;
				}

				//el peón está en su posición de origen, puede avanzar dos casillas
				if ((pieza_aux.getFilaOrigen() == pos_inicial.fila) && (pos_final.fila == pos_inicial.fila - 2) && (!casilla_final.GetEstado())) { //hay que comparar tambien la columna?
					resultado = true;
					return resultado;
				}
			}

			//REYES 8
			if (pieza_aux.GetTipo() == 8) {

				for (int j = -1; j <= 1; j++) {
					for (int k = -1; k <= 1; k++) {

						if (!((j == 0) && (k == 0))) {

							//el rey quiere moverse a una diagonal
							if (tablero[pos_inicial.fila + j][pos_inicial.columna + k] == casilla_final) {
								return true;
							}
						}
					}
				}

				//Falta enroque
			}

			//DAMAS 9
			if (pieza_aux.GetTipo() == 9) {
				int caso = 0;
				int difcol = pos_final.columna - pos_inicial.columna;
				int diffil = pos_final.fila - pos_inicial.fila;

				//derecha
				if (difcol > 0) {
					if (diffil == difcol) caso = 1; //arriba dcha
					if (diffil == 0) caso = 2; //recto dcha
					if (-diffil == difcol) caso = 3; //abajo dcha
				}
				//izquierda
				if (difcol < 0) {
					if (diffil == difcol) caso = 5; //abajo izq
					if (diffil == 0) caso = 6; //recto izq
					if (-diffil == difcol) caso = 7; //arriba izq
				}
				//recto arriba o abajo
				if (difcol == 0) {
					if (diffil < 0) caso = 4; //abajo recto
					if (diffil > 0) caso = 8; //arriba recto
				}

				if (caso % 2 == 0)
					return MovimTorre();
				else
					return MovimAlfil();

			}

			//ALFIL 10
			if (pieza_aux.GetTipo() == 10) {
				return MovimAlfil();
			}

			//CABALLO 11
			if (pieza_aux.GetTipo() == 11) {
				resultado = true;
				return resultado;
			}

			//TORRES 12
			if (pieza_aux.GetTipo() == 12) {
				return MovimTorre();
			}
		}

	}
	return resultado;
}

bool Tablero::MovimAlfil()
{
	int caso = 0;
	int difcol = pos_final.columna - pos_inicial.columna;
	int diffil = pos_final.fila - pos_inicial.fila;

	//derecha
	if (difcol > 0) {
		if (diffil == difcol) caso = 1; //arriba dcha
		if (-diffil == difcol) caso = 2; //abajo dcha
	}
	//izquierda
	if (difcol < 0) {
		if (diffil == difcol) caso = 3; //abajo izq
		if (-diffil == difcol) caso = 4; //arriba izq
	}

	//aux tomará el valor de la casilla que se va iterando
	Casilla aux;
	//Dirección
	switch (caso) {
	case 1:
		//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
		for (int j = 1; j <= (pos_final.fila - pos_inicial.fila); j++) {
			aux = tablero[pos_inicial.fila + j][pos_inicial.columna + j];
			//encuentro una pieza
			if (aux.GetEstado()) {
				return checkFinal(aux);
			}
			else {
				continue;
			}
		}
		//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
		return true;
		break;

	case 2:
		//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
		for (int j = 1; j <= (pos_inicial.fila - pos_final.fila); j++) {
			aux = tablero[pos_inicial.fila - j][pos_inicial.columna + j];
			//encuentro una pieza
			if (aux.GetEstado()) {
				return checkFinal(aux);
			}
			else {
				continue;
			}
		}
		//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
		return true;
		break;

	case 3:
		//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
		for (int j = 1; j <= (pos_inicial.fila - pos_final.fila); j++) {
			aux = tablero[pos_inicial.fila - j][pos_inicial.columna - j];
			//encuentro una pieza
			if (aux.GetEstado()) {
				return checkFinal(aux);
			}
			else {
				continue;
			}
		}
		//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
		return true;
		break;

	case 4:
		//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
		for (int j = 1; j <= (pos_final.fila - pos_inicial.fila); j++) {
			aux = tablero[pos_inicial.fila + j][pos_inicial.columna - j];
			//encuentro una pieza
			if (aux.GetEstado()) {
				return checkFinal(aux);
			}
			else {
				continue;
			}
		}
		//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
		return true;
		break;

	default:
		break;
	}
}

bool Tablero::MovimTorre()
{
	int caso = 0;
	int difcol = pos_final.columna - pos_inicial.columna;
	int diffil = pos_final.fila - pos_inicial.fila;
	//derecha
	if (difcol > 0) {
		if (diffil == 0) caso = 1; //recto dcha
	}
	//izquierda
	if (difcol < 0) {
		if (diffil == 0) caso = 2; //recto izq
	}
	//recto arriba o abajo
	if (difcol == 0) {
		if (diffil < 0) caso = 3; //abajo recto
		if (diffil > 0) caso = 4; //arriba recto
	}

	//aux tomará el valor de la casilla que se va iterando
	Casilla aux;
	//Dirección
	switch (caso) {
		//Derecha
	case 1:
		//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
		for (int j = 1; j <= (pos_final.columna - pos_inicial.columna); j++) {
			aux = tablero[pos_inicial.fila][pos_inicial.columna + j];
			//encuentro una pieza
			if (aux.GetEstado()) {
				return checkFinal(aux);
			}
			else {
				continue;
			}
		}
		//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
		return true;
		break;

		//Izquierda
	case 2:
		//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
		for (int j = 1; j <= (pos_inicial.columna - pos_final.columna); j++) {
			aux = tablero[pos_inicial.fila][pos_inicial.columna - j];
			//encuentro una pieza
			if (aux.GetEstado()) {
				return checkFinal(aux);
			}
			else {
				continue;
			}
		}
		//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
		return true;
		break;

		//Abajo
	case 3:
		//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
		for (int j = 1; j <= (pos_inicial.fila - pos_final.fila); j++) {
			aux = tablero[pos_inicial.fila - j][pos_inicial.columna];
			//encuentro una pieza
			if (aux.GetEstado()) {
				return checkFinal(aux);
			}
			else {
				continue;
			}
		}
		//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
		return true;
		break;

		//Arriba
	case 4:
		//itero hasta la distancia donde esta mi casilla final (no me interesa comprobar las que hay más allá, solo las que hay entre medias)
		for (int j = 1; j <= (pos_final.fila - pos_inicial.fila); j++) {
			aux = tablero[pos_inicial.fila + j][pos_inicial.columna];
			//encuentro una pieza
			if (aux.GetEstado()) {
				return checkFinal(aux);
			}
			else {
				continue;
			}
		}
		//sale del bucle porque no ha habido ninguna pieza de camino ni se come ninguna
		return true;
		break;

	default:
		break;
	}
}