#include "Tablero.h"

void iniciaTablero(tTablero tablero) {
	for (int i = 0; i < numFil; i++) {
		for (int j = 0; j < numCol; j++) {
			iniciaCasilla(tablero[i][j]);
		}
	}
	
}
bool cargarTablero(string nombreFichero, tTablero tablero) {
	ifstream ficheroSudoku;
	string aux;
	ficheroSudoku.open(nombreFichero);
	if (ficheroSudoku.is_open()) {
		for (int i = 0; i < numFil; i++) {
			getline(ficheroSudoku, aux);
			for (int j = 0; j < numCol; j++) {
				if (aux[j] != char(32)) {
					tablero[i][j].fija = true;
				}
				rellenaCasilla(tablero[i][j], aux[j], tablero[i][j].fija);
			}
		}
		actualizarTablero(tablero);
	}
	else {
		cout << "Fichero no encontrado\n";
		system("pause");
		system("cls");
	}
	return ficheroSudoku.is_open();
	ficheroSudoku.close();
}
/*void dibujarTablero(const tTablero tablero) {
	for (int n = 0; n < numFil; n++) {
		for (int m = 0; m < numCol; m++) {
			if (tablero[n][m].vacia == false) {
				dibujaCasilla(tablero[n][m]);
				cout << tablero[n][m].n;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else {
				cout << ' ';
			}
		}
	}*/
void dibujarTablero(const tTablero tablero) {
	int aux = 0, auxi = 0, num = 0, n = 0, m = 0, p = 0, q = 0;
	for (int i = 0; i < 20; i++) {
		num = i % 2;
		if (num == 0 && i != 0) {
			for (int j = 0; j < 39; j++) {
				aux = j % 2;
				auxi = (j / 2) % 2;
				if (aux == 0 && auxi != 1) cout << char(179);
				else if (aux == 0 && auxi == 1 && j != 38) {
					if (tablero[m][n].vacia == false) {
						dibujaCasilla(tablero[m][n]);
						cout << tablero[m][n].n;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						n++;
					}
					else {
						cout << ' ';
						n++;
					}
					
				}
				else if (aux == 1) cout << " ";
				else if (j == 38) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
					cout << q;
					q++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
			}
			cout << endl;
			if (m < numCol) m++;
			n = 0;
		}
		else if (i == 1) {
			for (int j = 0; j < 37; j++) {
				aux = j % 2;
				auxi = (j / 2) % 2;
				if (j == 0) cout << char(218);
				else if (aux == 0 && auxi == 0 && j != 0 && j != 36) cout << char(194);
				else if (j == 36) cout << char(191);
				else cout << char(196);
			}
			cout << endl;
		}
		else if (i == 0) {
			for (int j = 0; j < 37; j++) {
				aux = j % 2;
				auxi = (j / 2) % 2;
				if (aux == 0 && auxi == 1) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
					cout << p;
					p++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				else cout << " ";
			}
			cout << endl;
		}
		else if (i == 19) {
			for (int j = 0; j < 37; j++) {
				aux = j % 2;
				auxi = (j / 2) % 2;
				if (j == 0) cout << char(192);
				else if (aux == 0 && auxi == 0 && j != 0 && j != 36) cout << char(193);
				else if (j == 36) cout << char(217);
				else cout << char(196);
			}
			cout << endl;
		}
		else {
			for (int j = 0; j < 37; j++) {
				aux = j % 2;
				auxi = (j / 2) % 2;
				if (j == 0) cout << char(195);
				else if (aux == 0 && auxi == 0 && j != 0 && j != 36) cout << char(197);
				else if (j == 36) cout << char(180);
				else cout << char(196);
			}
			cout << endl;
		}
	}
}
bool ponerNum(tTablero tablero, int fila, int col, int c) {
	bool puesto = false;
	if (pertenece(tablero[fila][col], c)) {
		rellenaCasilla(tablero[fila][col], c + 48, fija);
		puesto = true;
		actualizarTablero(tablero);
	}

	return puesto;
}
bool borrarNum(tTablero tablero, int fila, int col) {
	bool borrado = false;
	if (tablero[fila][col].vacia == false && tablero[fila][col].fija == false) {
		tablero[fila][col].vacia = true;
		tablero[fila][col].n = 0;
		actualizarTablero(tablero);
		borrado = true;
	}
	return borrado;
}
bool tableroLleno(const tTablero tablero) {
	bool lleno = true;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (tablero[i][j].vacia == true)
			{
				lleno = false;
			}
		}
	}
	return lleno;
}
void mostrarPosibles(const tTablero tablero, int fila, int col) {
	if (tablero[fila][col].vacia == true) {
		cout << "Los valores posibles para la casilla [" << fila << "][" << col << "] son: ";
		mostrar(tablero[fila][col]);
	}
}
void rellenarSimples(tTablero tablero) {
	int aux = 0;
	for (int i = 0; i < numFil; i++) {
		for (int j = 0; j < numCol; j++) {
			if (esSimple(tablero[i][j], aux)) {
				tablero[i][j].n = aux;
				tablero[i][j].vacia = false;
			}
		}
	}
	actualizarTablero(tablero);
}
void actualizarTablero(tTablero tablero) {
	for (int i = 0; i < numFil; i++) {
		for (int j = 0; j < numCol; j++) {
			if (tablero[i][j].vacia == true) {
				cjto_lleno(tablero[i][j]);
				actualizarConjunto(tablero, i, j);
			}
			else {
				cjto_vacio(tablero[i][j]);
			}
		}
	}
}
void actualizarConjunto(tTablero tablero, int fila, int col) {
	int filIni = (fila / 3) * 3, colIni = (col / 3) * 3;
	for (int i = 0; i < numFil; i++) {
		if (pertenece(tablero[fila][col], tablero[i][col].n) && i != fila) {
			borraElemento(tablero[fila][col], tablero[i][col].n);
		}
	}
	for (int i = 0; i < numCol; i++) {
		if (pertenece(tablero[fila][col], tablero[fila][i].n) && i != col) {
			borraElemento(tablero[fila][col], tablero[fila][i].n);
		}
	}
	for (int i = filIni; i < filIni + 3; i++) {
		for (int j = colIni; j < colIni + 3; j++) {
			if (pertenece(tablero[fila][col], tablero[i][j].n) && i != fila && j != col) {
				borraElemento(tablero[fila][col], tablero[i][j].n);
			}
		}
	}
}
