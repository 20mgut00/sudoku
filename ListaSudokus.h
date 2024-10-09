#ifndef ListaSudokus_h
#define ListaSudokus_h

#include "Juego.h"

const int MAX_SUDOKUS = 20;

typedef struct {
	tSudoku sudoku[MAX_SUDOKUS];
	int cont;
}tListaSudokus;

bool guardar(const tListaSudokus& lista);
bool registrarSudoku(tListaSudokus& lista);
bool buscarFichero(const tListaSudokus& lista, string nombreFich);
int buscarPos(const tListaSudokus& lista, const tSudoku& sudoku);
void creaListaVacia(tListaSudokus& lista);
bool cargar(tListaSudokus& lista);
void mostrar(const tListaSudokus& lista);
//
int jugarUnSudoku(const tJuego & juego);
#endif // !ListaSudokus_h