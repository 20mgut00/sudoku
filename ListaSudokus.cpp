#include "ListaSudokus.h"

void creaListaVacia(tListaSudokus& lista) {
	for (int i = 0; i < MAX_SUDOKUS; i++) {
		lista.sudoku[i].nombreFichero = " ";
		lista.sudoku[i].puntos = 0;
	}
	lista.cont = 0;
}
bool cargar(tListaSudokus& lista) {
	ifstream fichLista;
	bool cargado = false;
	creaListaVacia(lista);
	fichLista.open("listaSudokus.txt");
	if (fichLista.is_open()) {
		while (!fichLista.eof() && lista.cont < MAX_SUDOKUS - 1) {
			fichLista >> lista.sudoku[lista.cont].nombreFichero;
			fichLista >> lista.sudoku[lista.cont].puntos;
			lista.cont++;
		}
		cargado = true;
		fichLista.close();
	}
	return cargado;
}
void mostrar(const tListaSudokus& lista) {
	for (int i = 0; i < lista.cont; i++) {
		cout << i + 1 << "-." << lista.sudoku[i].nombreFichero << " puntos: " << lista.sudoku[i].puntos << '\n';
	}
	cout << "0-. Salir\n";
}
bool guardar(const tListaSudokus& lista) {
	bool guardado = false;
	ofstream listaSudokus("listaSudokus.txt");
	if (listaSudokus.is_open()) {
		for (int i = 0; i < lista.cont - 1; i++) {
			if (lista.sudoku[i].puntos != 0) {
				listaSudokus << lista.sudoku[i].nombreFichero << ' ' << lista.sudoku[i].puntos << '\n';
			}
		}
		listaSudokus << lista.sudoku[lista.cont - 1].nombreFichero << ' ' << lista.sudoku[lista.cont - 1].puntos;
		guardado = true;
		listaSudokus.close();
	}
	return guardado;
}
bool registrarSudoku(tListaSudokus& lista) {
	string nombreFichero;
	tSudoku sudoku;
	int puntos, pos, aux = lista.cont;
	bool registrado = false;
	cout << "Introduce nombre del fichero: ";
	cin >> sudoku.nombreFichero;
	cout << "Introduce puntos a conseguir: ";
	cin >> sudoku.puntos;
	if (lista.cont < MAX_SUDOKUS) {
		if (buscarFichero(lista, sudoku.nombreFichero)) {
			cout << "No se puede anadir el sudoku\n";
		}
		else {
			pos = buscarPos(lista, sudoku);
			while (aux >= pos) {
				lista.sudoku[aux + 1].nombreFichero = lista.sudoku[aux].nombreFichero;
				lista.sudoku[aux + 1].puntos = lista.sudoku[aux].puntos;
				aux--;
			}
			lista.sudoku[pos].nombreFichero = sudoku.nombreFichero;
			lista.sudoku[pos].puntos = sudoku.puntos;
			lista.cont++;
			 
			 if (guardar(lista)) registrado = true;
		}
	}
	return registrado;
}
bool buscarFichero(const tListaSudokus& lista, string nombreFich) {
	int aux = 0;
	bool encontrado = false;
	while (aux < lista.cont && encontrado == false) {
		if (nombreFich == lista.sudoku[aux].nombreFichero) {
			encontrado = true;
		}
		aux++;
	}
	return encontrado;
}
int buscarPos(const tListaSudokus& lista, const tSudoku& sudoku) {
	int ini = 0, fin = lista.cont - 1, mitad, pos;
	bool encontrado = false;
	while (ini <= fin && !encontrado) {
		mitad = (ini + fin) / 2;
		if (sudoku.puntos < lista.sudoku[mitad].puntos) fin = mitad - 1;
		else if (sudoku.puntos > lista.sudoku[mitad].puntos) ini = mitad + 1;
		else {
			if (sudoku.nombreFichero < lista.sudoku[mitad].nombreFichero) fin = mitad - 1;
			else if (sudoku.nombreFichero > lista.sudoku[mitad].nombreFichero) ini = mitad + 1;
			else encontrado = true;
		}
	}
	if (encontrado) pos = mitad;
	else pos = ini;
	return pos;
}
		/*else encontrado = true;
	}
	if (encontrado) {
		encontrado = false;
		pos = mitad;
		while (!encontrado) {
			
			if (sudoku.nombreFichero[aux] == lista.sudoku[pos].nombreFichero[aux]) {
				aux++;
			}
			else {
				encontrado = true;
				if (sudoku.nombreFichero[aux] > lista.sudoku[pos].nombreFichero[aux]) {
					
				}
				else {
					
				}
			}
		}

		while (sudoku.puntos == lista.sudoku[pos].puntos && sudoku.nombreFichero[aux] == lista.sudoku[pos].nombreFichero[aux]) {
			aux++;
			if (sudoku.nombreFichero[aux] > lista.sudoku[pos].nombreFichero[aux]) {
				pos++;
				aux = 0;
			}
		}
		aux = 0;
		while (sudoku.puntos == lista.sudoku[pos - 1].puntos && sudoku.nombreFichero[aux] == lista.sudoku[pos - 1].nombreFichero[aux]) {
			aux++;
			if (sudoku.nombreFichero[aux] < lista.sudoku[pos - 1].nombreFichero[aux]) {
				pos--;
				aux = 0;
			}
		}
	}
	else pos = ini;
	return pos;
}*/
int jugarUnSudoku(const tJuego & juego) {
	return jugarUnSudoku(juego.sudoku);
}