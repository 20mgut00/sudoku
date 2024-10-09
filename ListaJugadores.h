#ifndef ListaJugadores_h
#define ListaJugadores_h

#include "Jugador.h"

const int MAX_JUGADORES = 5;
typedef struct {
	//tJugador jugador[MAX_JUGADORES];
	tJugadorPtr jugador;
	int cont;
	int tam = MAX_JUGADORES;
}tListaJugadores;


void creaListaVacia(tListaJugadores & lista);
bool cargar(tListaJugadores & lista);
void mostrar(const tListaJugadores & lista);
bool guardar(const tListaJugadores & lista);
void puntuarJugador(tListaJugadores & lista, int puntos);
bool buscar(const tListaJugadores & lista, string id, int ini, int fin, int & pos);
tListaJugadores ordenarPorRanking(const tListaJugadores & lista);
void borrarListaJugadores(tListaJugadores & lista);
void ampliar(tListaJugadores & lista);
//tListaJugadores ordenarPorRanking(const tListaJugadores & lista);
#endif // !ListaJugadores_h
