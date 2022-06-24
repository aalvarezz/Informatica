#include "Tablero.h"
#include "freeglut.h"
#include "ETSIDI.h"

Tablero::Tablero() { //Relleno el damero. Muy provisional sin piezas
	for (int fila = 0; fila < 8; fila++) {
		for (int columna = 0; columna < 8; columna++) {
			if (fila > 1 && fila < 6) // Vacías las casillas centrales
				piezas[fila][columna] = NULL;
			if (fila == 1 || fila == 6) { //Peones, hay que diferenciar entre color
				piezas[i][j] = new Pieza();
			}
			if (fila == 0) { //blancas
				switch (columna) {
				case 0: case 7: //chequear si esto vale
					piezas[i][j] = new Pieza(); //torres
					break;
				case 1: case 6:
					piezas[i][j] = new Pieza(); //caballos
					break;
				case 2: case 5:
					piezas[i][j] = new Pieza(); //alfiles
					break;
				case 3: 
					piezas[i][j] = new Pieza(); //dama 
					break;
				case 4: 
					piezas[i][j] = new Pieza(); //rey 
					break;
				default: break;
				}	
			}
			if (fila == 7) { //negras
				switch (columna) {
				case 0: case 7: //chequear si esto vale
					piezas[i][j] = new Pieza(); //torres
					break;
				case 1: case 6:
					piezas[i][j] = new Pieza(); //caballos
					break;
				case 2: case 5:
					piezas[i][j] = new Pieza(); //alfiles
					break;
				case 3:
					piezas[i][j] = new Pieza(); //rey 
					break;
				case 4:
					piezas[i][j] = new Pieza(); //dama 
					break;
				default: break;
				}
			}
		}
	}
}

void Tablero::dibujoDamero()
{
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
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			piezas[i][j]->dibujar();
	}
}

void Tablero::moverPieza(Pos pos_inicial, Pos pos_final) { //actualizar posición de cierta pieza, en principio se usa la posicion del tablero
	if (piezas[pos_final.fila][pos_final.columna] == NULL) {
		*piezas[pos_final.fila][pos_final.columna] = *piezas[pos_inicial.fila][pos_inicial.columna];
		piezas[pos_inicial.fila][pos_inicial.columna] = NULL;
	}
	else {

	}
	/* //Si se utiliza la pos de dentro de la pieza hay que pasar pieza y pos

	void Tablero::moverPieza(Pieza* p, Pos pos_final){
		quitarPieza(p->getPos());
		setPieza(piezas[x][x], pos_final);
	}
	*/
}

void Tablero::comerPieza(Pieza* p)
{
	delete p;
}

void Tablero::quitarPieza(Pos posicion) { //hacer null el puntero a la pieza deseada, hacer "0" la posición de esa pieza (suponiendo que la pieza tuviera un atributo pos). Parece prescindible
	piezas[posicion.fila][posicion.columna] = NULL;
}

void Tablero::setPieza(Pieza* p, Pos pos) { //otorga a una pieza una posicion
	p->setPos(pos);
}

Pieza* Tablero::getPieza(Pos p)
{
	return pieza[p.fila][p.columna];
}

Pieza* Tablero::getPiezaElegida()
{
	return pieza_elegida;
}

void Tablero::setLado(float l)
{
	lado = l;
}

float Tablero::getLado()
{
	return lado;
}
