#include "ListaJugadores.h"

void creaListaVacia(tListaJugadores & lista) {
	lista.cont = 0;
	//lista.tam = MAX_JUGADORES;
	lista.jugador = new tJugador[lista.tam];
	//for (int i = 0; i < MAX_JUGADORES; i++) {
	//	lista.jugador[i].nombre = ' ';
	//	lista.jugador[i].puntos = 0;
	//}
	//lista.cont = 0;
}
bool cargar(tListaJugadores & lista) {
	bool cargado = false;
	creaListaVacia(lista);
	ifstream listaJugadores;
	listaJugadores.open("listaJugadores.txt");
	if (listaJugadores.is_open()) {
		while (!listaJugadores.eof()) {
			if (lista.cont == lista.tam) {
				ampliar(lista);
			}
			listaJugadores >> lista.jugador[lista.cont].nombre >> lista.jugador[lista.cont].puntos;
			lista.cont++;
		}
		cargado = true;
		listaJugadores.close();
	}
	return cargado;
}
void mostrar(const tListaJugadores & lista) {
	string jugador;
	for (int i = 0; i < lista.cont; i++) {
		jugador = toString(lista.jugador[i]);
		cout << jugador << '\n';
	}
}
bool guardar(const tListaJugadores& lista) {
	bool guardado = false;
	string jugador;
	ofstream listaJugadores("listaJugadores.txt");
	if (listaJugadores.is_open()) {
		for (int i = 0; i < lista.cont - 1; i++) {
			jugador = toString(lista.jugador[i]);
			listaJugadores << jugador << '\n';
		}
		jugador = toString(lista.jugador[lista.cont - 1]);
		listaJugadores << jugador;
		guardado = true;
		listaJugadores.close();
	}
	return guardado;
}
void puntuarJugador(tListaJugadores & lista, int puntos) {
	string id;
	int pos, aux = lista.cont;
	cout << "Introduce jugador: ";
	cin >> id;
	for (int i = 0; i < id.size(); i++) id[i] = tolower(id[i]);
	if (buscar(lista, id, 0,lista.cont - 1, pos)) {
		modificarJugador(lista.jugador[pos], puntos);
	}
	//else if (lista.cont < MAX_JUGADORES) {//
	//	while (aux >= pos) {
	//		lista.jugador[aux + 1].nombre = lista.jugador[aux].nombre;
	//		lista.jugador[aux + 1].puntos = lista.jugador[aux].puntos;
	//		aux--;
	//	}
	//	lista.jugador[pos].nombre = id;
	//	lista.jugador[pos].puntos = puntos;
	//	lista.cont++;
	//}
	else {
		if (lista.cont == lista.tam - 1 || lista.cont == lista.tam) {
			ampliar(lista);
		}
		if (aux >= pos) {
			while (aux >= pos) {
				lista.jugador[aux + 1].nombre = lista.jugador[aux].nombre;
				lista.jugador[aux + 1].puntos = lista.jugador[aux].puntos;
				aux--;
			}
			lista.jugador[pos].nombre = id;
			lista.jugador[pos].puntos = puntos;
			lista.cont++;
		}
		else {
			lista.jugador[pos - 1].nombre = id;
			lista.jugador[pos - 1].puntos = puntos;
			lista.cont++;
		}
	}
	/*else if (lista.cont < MAX_JUGADORES) {
		pos = lista.cont;
		lista.jugador[lista.cont].nombre = id;
		lista.jugador[lista.cont].puntos = puntos;
		lista.cont++;

	}*/
	if (guardar(lista)) cout << "Jugador guardado\n";
	system("pause");
}
bool buscar(const tListaJugadores & lista, string id, int ini, int fin, int & pos) {
	int mitad, tam;
	bool encontrado = false;
	if (ini <= fin) {
		mitad = (ini + fin) / 2;
		if (id == lista.jugador[mitad].nombre) {
			pos = mitad;
			encontrado = true;
		}
		else {
			if (id < lista.jugador[mitad].nombre) {
				encontrado = buscar(lista, id, ini, mitad - 1, pos);
			}
			else if (id > lista.jugador[mitad].nombre) {
				encontrado = buscar(lista, id, mitad + 1, fin, pos);
			}
			/*if (id.size() <= lista.jugador[mitad].nombre.size()) tam = id.size();
			else tam = lista.jugador[mitad].nombre.size();
			for (int i = 0; i < tam; i++) {
				if (tolower(id[i]) < tolower(lista.jugador[mitad].nombre[i])) {
					encontrado = buscar(lista, id, ini, mitad - 1, pos);
				}
				else if (tolower(id[i]) > tolower(lista.jugador[mitad].nombre[i])) {
					encontrado = buscar(lista, id, mitad + 1, fin, pos);
				}
			}*/
			
		}
	}
	else {
		pos = ini;
		encontrado = false;
	}
	return encontrado;
}
/*bool buscar(const tListaJugadores & lista, string id, int & pos) {
	int ini = 0, fin = lista.cont, mitad;
	bool encontrado = false;
	while (ini <= fin && !encontrado) {
		mitad = (ini + fin) / 2;
		if (lista.jugador[mitad].nombre == id) encontrado = true;
		else {
			if (lista.jugador[mitad].nombre > id) {

				fin = mitad - 1;
			}
			else {
				ini = mitad + 1;
			}
		}
	}
	if (encontrado) pos = mitad;
	else pos = ini;
	return encontrado;
}*/
tListaJugadores ordenarPorRanking(const tListaJugadores & lista) {
	tListaJugadores listaPts = lista;
	tJugador aux;
	for (int i = 0; i < listaPts.cont; i++) {
		for (int j = 0; j < listaPts.cont - 1; j++) {
			if (menor(listaPts.jugador[j], listaPts.jugador[j + 1])) {
				aux = listaPts.jugador[j];
				listaPts.jugador[j] = listaPts.jugador[j + 1];
				listaPts.jugador[j + 1] = aux;
			}
		}
	}
	return listaPts;
}
void borrarListaJugadores(tListaJugadores & lista) {
	delete[]lista.jugador;
	lista.jugador = nullptr;
	lista.cont = 0;
	lista.tam = 0;
}
void ampliar(tListaJugadores & lista) {
	tJugadorPtr aux;
	aux = lista.jugador;
	lista.tam *= 2;
	lista.jugador = new tJugador[lista.tam];
	for (int i = 0; i < lista.cont; i++) {
		lista.jugador[i] = aux[i];
	}
	delete[]aux;
	aux = nullptr;
}