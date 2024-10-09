#ifndef Juego_h
#define Juego_h
#include "Tablero.h"

typedef struct {
	int puntos;
	string nombreFichero;
}tSudoku;

typedef struct {
	tSudoku sudoku;
	tTablero tablero;
	bool relleno = false;
}tJuego;


void iniciaJuego(tJuego& juego, const tSudoku& sudoku);
void mostrarJuego(const tJuego& juego);
bool cargaJuego(tJuego& juego, const tSudoku& sudoku);
int jugarUnSudoku(const tSudoku& sudoku);
int menuJuego();
#endif // !Juego_h

