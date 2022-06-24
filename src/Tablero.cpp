#include "Tablero.h"
#include "freeglut.h"
#include "ETSIDI.h"

Tablero::Tablero() { //Relleno el damero. Muy provisional sin piezas

}

void Tablero::inicializar(Pieza* p, int i, int j) {
	piezas[i][j] = p;
}

void Tablero::dibujoDamero() {
	setLado(2.5f);
	//CASILLAS DEL TABLERO
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			
		}
	}

	//BORDES DEL TABLERO
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/maderaV.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);//Borde izquierdo del tablero
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(0 * lado - lado / 2 - 0.8 * lado, 0 * lado - lado / 2 - 0.8 * lado);
	glTexCoord2d(1, 1); glVertex2f(0 * lado - lado / 2, 0 * lado - lado / 2);
	glTexCoord2d(1, 0); glVertex2f(0 * lado - lado / 2, 7 * lado + lado / 2);
	glTexCoord2d(0, 0); glVertex2f(0 * lado - lado / 2 - 0.8 * lado, 7 * lado + lado / 2 + 0.8 * lado);
	glEnd();
	glBegin(GL_POLYGON);//Borde derecho del tablero
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(7 * lado + lado / 2, 0 * lado - lado / 2);
	glTexCoord2d(1, 1); glVertex2f(7 * lado + lado / 2 + 0.8 * lado, 0 * lado - lado / 2 - 0.8 * lado);
	glTexCoord2d(1, 0); glVertex2f(7 * lado + lado / 2 + 0.8 * lado, 7 * lado + lado / 2 + 0.8 * lado);
	glTexCoord2d(0, 0); glVertex2f(7 * lado + lado / 2, 7 * lado + lado / 2);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/maderaH.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);//Borde inferior del tablero
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(0 * lado - lado / 2 - 0.8 * lado, 0 * lado - lado / 2 - 0.8 * lado);
	glTexCoord2d(1, 1); glVertex2f(7 * lado + lado / 2 + 0.8 * lado, 0 * lado - lado / 2 - 0.8 * lado);
	glTexCoord2d(1, 0); glVertex2f(7 * lado + lado / 2, 0 * lado - lado / 2);
	glTexCoord2d(0, 0); glVertex2f(0 * lado - lado / 2, 0 * lado - lado / 2);
	glEnd();
	glBegin(GL_POLYGON);//Borde superior del tablero
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(0 * lado - lado / 2, 7 * lado + lado / 2);
	glTexCoord2d(1, 1); glVertex2f(7 * lado + lado / 2, 7 * lado + lado / 2);
	glTexCoord2d(1, 0); glVertex2f(7 * lado + lado / 2 + 0.8 * lado, 7 * lado + lado / 2 + 0.8 * lado);
	glTexCoord2d(0, 0); glVertex2f(0 * lado - lado / 2 - 0.8 * lado, 7 * lado + lado / 2 + 2);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Tablero::imprimir() { //solo imprime piezas, la impresion del tablero en sí se hace a parte
	Pos pos_pieza;
	for (int i = 0; i < 8; i++) {
		pos_pieza.fila = i;
		for (int j = 0; j < 8; j++) {
			pos_pieza.columna = j;
			piezas[i][j]->dibujar(pos_pieza);
		}
	}
}

/*void Tablero::moverPieza(Pos pos_inicial, Pos pos_final) { //actualizar posición de cierta pieza, en principio se usa la posicion del tablero
	if (piezas[pos_final.fila][pos_final.columna] == NULL) {
		*piezas[pos_final.fila][pos_final.columna] = *piezas[pos_inicial.fila][pos_inicial.columna];
		piezas[pos_inicial.fila][pos_inicial.columna] = NULL;
	}
	else {

	}
}*/

void Tablero::quitarPieza(Pos posicion) { //hacer null el puntero a la pieza deseada, hacer "0" la posición de esa pieza (suponiendo que la pieza tuviera un atributo pos). Parece prescindible
	piezas[posicion.fila][posicion.columna] = nullptr;
}

void Tablero::setPieza(Pieza* p, Pos posicion) { //otorga a una pieza una posicion
	piezas[posicion.fila][posicion.columna] = p;
}

Pieza* Tablero::getPieza(Pos posicion) {
	return piezas[posicion.fila][posicion.columna];
}

/*Pieza* Tablero::getPiezaElegida()
{
	return pieza_elegida;
}*/


//GETTERS y SETTERS PROVISIONALES
void Tablero::setLado(float l) {
	lado = l;
}

float Tablero::getLado() {
	return lado;
}
