//Miguel Guti�rrez V�zquez y Javier Fern�ndez Parrondo

#include "ListaSudokus.h"
#include "ListaJugadores.h"

int menu();

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	tJuego juego;
	//tSudoku sudoku;
	tListaSudokus lista;
	tListaJugadores listaJ;
	int opcion, puntos, aux;
	string saux;
	//bool encontrado = false;
	if (cargar(lista) && cargar(listaJ)) {
		do {
			opcion = menu();
			if (opcion == 1) {
				cout << "Elija un sudoku\n";
				mostrar(lista);
				cout << "Opcion: ";
				cin >> saux;
				system("cls");
				aux = atoi(saux.c_str()); //cambiar str a int -> escribir !digit = 0
				if (aux <= lista.cont && aux > 0) {
					juego.sudoku.nombreFichero = lista.sudoku[aux - 1].nombreFichero;
					juego.sudoku.puntos = lista.sudoku[aux - 1].puntos;
					puntos = jugarUnSudoku(juego);
					if (puntos != 0) {
						puntuarJugador(listaJ, puntos);
						system("cls");
					}
					//encontrado = false;
					aux = 0;
					/*for (int i = 0; i < MAX_SUDOKUS; i++) {
						sudoku.puntos = lista.sudoku[i].puntos;
						encontrado = true;
					}*/
					//encontrado = true;
					//system("cls");
					/*for (int i = 0; i < MAX_SUDOKUS; i++) {
						if (sudoku.nombreFichero == lista.sudoku[i].nombreFichero) {
							sudoku.puntos = lista.sudoku[i].puntos;
							encontrado = true;
						}
					}*/
					/*if (encontrado) {
						sudoku.puntos = lista.sudoku[aux - 1].puntos;
						puntos = jugarUnSudoku(sudoku);
						if (puntos != 0) {
							puntuarJugador(listaJ, puntos);
							system("cls");
						}
						encontrado = false;
						aux = 0;
					}
					else {
						cout << "sudoku no encontrado\n";
						system("pause");
					}*/
				}
				else if (aux > lista.cont || aux < 0) {
					cout << "sudoku no encontrado\n";
					system("pause");
					system("cls");
				}
				else system("cls");
				
			}
			else if (opcion == 2) {
				mostrar(listaJ);
				system("pause");
				system("cls");
			}
			else if (opcion == 3) {
				mostrar(ordenarPorRanking(listaJ));
				delete[] listaJ.jugador;
				cargar(listaJ);
				system("pause");
				system("cls");
			}
			else if (opcion == 4) {
				if (registrarSudoku(lista)) cout << "Sudoku registrado\n";
				system("pause");
				system("cls");
			}
		} while (opcion > 0 && opcion <= 4);
	}
	borrarListaJugadores(listaJ);
	return 0;
}
int menu() {
	int opcion;
	do {
		cout << "1- Jugar\n2- Ver jugadores ordenados por identificador\n3- Ver jugadores ordenados por puntos\n4- Incorporar sudoku\n0- Salir\nOpcion: ";
		cin >> opcion;
		system("cls");
	} while (opcion < 0 || opcion > 5);
	return opcion;
}

