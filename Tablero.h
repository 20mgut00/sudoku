#ifndef Tablero_h
#define Tablero_h

#include "Casilla.h"

const int numCol = 9, numFil = 9;

typedef tCasilla tTablero[numFil][numCol];

void iniciaTablero(tTablero tablero);
bool cargarTablero(string nombreFichero, tTablero tablero);
void dibujarTablero(const tTablero tablero);
bool ponerNum(tTablero tablero, int fila, int col, int c);
bool borrarNum(tTablero tablero, int fila, int col);
bool tableroLleno(const tTablero tablero);
void mostrarPosibles(const tTablero tablero, int fila, int col);
void rellenarSimples(tTablero tablero);
void actualizarConjunto(tTablero tablero, int fila, int columna);
void actualizarTablero(tTablero tablero);
#endif // !Tablero.h
