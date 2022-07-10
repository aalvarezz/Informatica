#include "JuegoAciegas.h"

void JuegoAciegas::dibujarPiezas() {
	Pieza* pieza_aux;
	Pos pos_aux;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			pos_aux.fila = i;
			pos_aux.columna = j;
			pieza_aux = tablero.getPieza(pos_aux);
			if (pieza_aux != nullptr) {
				if (pieza_aux->getColor() != turno_blancas || pieza_aux->getColor() == turno_negras)
					pieza_aux->dibujar(pos_aux,tablero.getLado());
			}
		}
	}
}
