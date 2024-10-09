#include "Conjunto.h"

void cjto_vacio(tConjunto& c) {
	for (int i = 0; i < 9; i++) {
		c[i] = 0;
	}
}
void cjto_lleno(tConjunto& c) {
	for (int i = 0; i < 9; i++) {
		c[i] = i + 1;
	}
}
bool pertenece(const tConjunto& c, int e) {
	bool encontrado = false;
	for (int i = 0; i < 9; i++) {
		if (e == c[i]) encontrado = true;
	}
	return encontrado;
}
void annadeElemento(tConjunto & c, int e) {
	c[e - 1] = e;
}
void borraElemento(tConjunto & c, int e) {
	c[e - 1] = 0;
}
int numElems(const tConjunto & c) {
	int aux = 0;
	for (int i = 0; i < 9; i++) {
		if (c[i] != 0) {
			aux++;
		}
	}
	return aux;
}
bool esUnitario(const tConjunto & c, int& e) {
	int aux = numElems(c);
	bool encontrado = false;
	e = 0;
	if (aux == 1) {
		while (e < 9 && encontrado == false) {
			if (c[e] != 0) {
				encontrado = true;
			}
			e++;
		}
	}
	return encontrado;
}
void mostrar(const tConjunto & c) {
	for (int i = 0; i < 9; i++) {
		if (c[i] != 0) cout << c[i] << ' ';
	}
	cout << '\n';
}