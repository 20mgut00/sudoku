#include "Casilla.h"

void iniciaCasilla(tCasilla& casilla) {
	casilla.vacia = true;
	cjto_lleno(casilla.c);
}
void rellenaCasilla(tCasilla& casilla, char c, bool fija) {
	if (c != char(32)) {
		casilla.n = c - 48;
		casilla.vacia = false;
	}
	else {
		casilla.n = 0;
		casilla.vacia = true;
	}
}
void dibujaCasilla(const tCasilla& casilla) {
	if (casilla.fija == true) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
	}
	else if (casilla.fija == false) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	}
}
bool esSimple(const tCasilla& casilla, int& numero) {
	bool simple = false;
	if (casilla.vacia == true && esUnitario(casilla.c, numero)) {
		simple = true;
	}
	return simple;
}
bool pertenece(const tCasilla & casilla, int e) {
	return pertenece(casilla.c, e);
}
void mostrar(const tCasilla & casilla) {
	mostrar(casilla.c);
}
void cjto_lleno(tCasilla & casilla) {
	cjto_lleno(casilla.c);
}
void cjto_vacio(tCasilla & casilla) {
	cjto_vacio(casilla.c);
}
void borraElemento(tCasilla & casilla, int e) {
	borraElemento(casilla.c, e);
}