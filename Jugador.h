#ifndef Jugador_h
#define Jugador_h

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef struct {
	string nombre;
	int puntos;
}tJugador;
typedef tJugador* tJugadorPtr;

string toString(tJugador jugador);
void modificarJugador(tJugador & jugador, int puntos);
bool operator<(const tJugador & opIzq, const tJugador & opDer);
bool menor(const tJugador & j1, const tJugador & j2);
#endif // !Jugador_h