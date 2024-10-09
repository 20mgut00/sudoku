#include "Juego.h"

void iniciaJuego(tJuego& juego, const tSudoku& sudoku) {
	juego.sudoku.nombreFichero = sudoku.nombreFichero;
	juego.sudoku.puntos = sudoku.puntos;
	iniciaTablero(juego.tablero);
}
void mostrarJuego(const tJuego& juego) {
	cout << "Sudoku: " << juego.sudoku.nombreFichero << "\nPuntos: " << juego.sudoku.puntos << '\n';
	dibujarTablero(juego.tablero);
}
bool cargaJuego(tJuego& juego, const tSudoku& sudoku) {
	bool cargado = false;
	if (cargarTablero(sudoku.nombreFichero, juego.tablero)) cargado = true;
	return cargado;
}
int jugarUnSudoku(const tSudoku& sudoku) {
	int puntos, opcion, fila, columna, num;
	tJuego juego;
	iniciaJuego(juego, sudoku);
	if (cargaJuego(juego, sudoku)) {
		do {
			mostrarJuego(juego);
			opcion = menuJuego();
			mostrarJuego(juego);
			if (opcion == 1) {
				cout << "Introduce fila: ";
				cin >> fila;
				cout << "Introduce columna: ";
				cin >> columna;
				system("cls");
				mostrarPosibles(juego.tablero, fila, columna);
			}
			else if (opcion == 2) {
				cout << "Introduce fila: ";
				cin >> fila;
				cout << "Introduce columna: ";
				cin >> columna;
				if (juego.tablero[fila][columna].vacia) {
					cout << "Introduce numero: ";
					cin >> num;
					system("cls");
					if (ponerNum(juego.tablero, fila, columna, num)) {
						cout << "Numero introducido\n";
					}
					else {
						cout << "El numero no se encuentra entre los posibles\n";
					}
				}
				else {
					system("cls");
					cout << "Imposible introducir numero\n";
				}
			}
			else if (opcion == 3) {
				cout << "Introduce fila: ";
				cin >> fila;
				cout << "Introduce columna: ";
				cin >> columna;
				system("cls");
				if (borrarNum(juego.tablero, fila, columna)) {
					cout << "Numero eliminado\n";
				}
				else {
					cout << "Imposible borrar elemento\n";
				}
			}
			else if (opcion == 4) {
				iniciaJuego(juego, sudoku);
				if (cargaJuego(juego, sudoku)) {
					system("cls");
					cout << "Juego reiniciado\n";
				}
			}
			else if (opcion == 5) {
				system("cls");
				rellenarSimples(juego.tablero);
			}
			if (tableroLleno(juego.tablero)) {
				mostrarJuego(juego);
				cout << "Sudoku completado\n";
				juego.relleno = true;
				system("pause");

			}
		} while (opcion > 0 && opcion <= 5 && juego.relleno == false);
		system("cls");
	}
	if (juego.relleno == true) {
		puntos = juego.sudoku.puntos;
	}
	else {
		puntos = 0;
	}
	return puntos;
}
int menuJuego() {
	int opcion;
	string aux;
	do {
		cout << "\n1- Ver posibles valores de una casilla vacia\n2- Colocar valor de una casilla\n3- Borrar valor de una casilla\n4- Reiniciar tablero\n5- Autocompletar celdas simples\n0- Abortar la resolucion y volver al menu principal\nOpcion: ";
		cin >> aux;
		opcion = atoi(aux.c_str());
		system("cls");
	} while (opcion < 0 || opcion > 5);
	return opcion;
}