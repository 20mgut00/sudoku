#ifndef Casilla_h
#define Casilla_h

#include "Conjunto.h"

const int vacia = 0, fija = 1;

typedef struct {
	bool vacia, fija = false;
	int n;
	tConjunto c;
}tCasilla;

void iniciaCasilla(tCasilla& casilla);
void rellenaCasilla(tCasilla& casilla, char c, bool fija = false);
void dibujaCasilla(const tCasilla& casilla);
bool esSimple(const tCasilla& casilla, int& numero);
bool pertenece(const tCasilla & casilla, int e);
void mostrar(const tCasilla & casilla);
void cjto_lleno(tCasilla & casilla);
void cjto_vacio(tCasilla & casilla);
void borraElemento(tCasilla & casilla, int e);
#endif // !Casilla.h