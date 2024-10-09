#ifndef Conjunto_h
#define Conjunto_h

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

typedef int tConjunto[9];

void cjto_vacio(tConjunto& c);
void cjto_lleno(tConjunto& c);
bool pertenece(const tConjunto& c, int e);
void annadeElemento(tConjunto& c, int e);
void borraElemento(tConjunto& c, int e);
int numElems(const tConjunto& c);
bool esUnitario(const tConjunto& c, int& e);
void mostrar(const tConjunto& c);
#endif // !Conjunto.h