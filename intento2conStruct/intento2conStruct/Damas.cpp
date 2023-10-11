#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;
using namespace System;

struct jugadores {
	int largo_n;
	int puntuacion=12;
	char fichas;
};
void Mostrar_Instrucciones() {
	Console::Beep();
	setlocale(LC_ALL, "spanish");
	cout << "SOBRE CÓMO JUGAR ESTE JUEGO:" << endl << endl;
	cout << "Al inicio de la partida cada jugador\n";
	cout << "ingresará su nombre y escogerá las\n";
	cout << "fichas que va a usar\n";
	cout << "Para mover una ficha ingrese primero su posición\n";
	cout << "actual, después, ingrese las nuevas coordenadas\n";
	cout << "Gana el juego quien se quede sin fichas al final de la partida\n";
	cout << endl << endl;
	cout << "SOBRE EL JUEGO DAMAS:" << endl << endl;
	cout << "Las damas es un juego para dos personas en un tablero \n";
	cout << "de 64 casillas de 8x8 celdas. Cada jugador dispone de \n";
	cout << "12 fichas de un mismo color. El objetivo del juego es \n";
	cout << "capturar las fichas del oponente o acorralarlas para \n";
	cout << "que no puedan realizar movimientos. \n";
	cout << "Se juega por turnos alternos.Empieza a jugar quien tiene\n";
	cout << "las fichas blancas**.En su turno cada jugador mueve\n";
	cout << "una pieza propia. Las fichas se mueven(cuando no comen)\n";
	cout << "una posición hacia delante(nunca hacia atrás) en diagonal\n";
	cout << "a la derecha o a la izquierda, a una posición adyacente vacía. \n";
	cout << "Si una ficha se encuentra en una casilla diagonal contigua\n";
	cout << "a otra del contrario(que está delante) estando la posterior\n";
	cout << "vacía y en turno de juego, puede saltar por encima de esta \n";
	cout << "hasta la casilla vacía, retirando la ficha del contrario del\n";
	cout << "tablero. Si después de realizado un salto(comer ficha), la\n";
	cout << "ficha llega a una casilla en las mismas condiciones de la\n";
	cout << "anterior, puede continuar saltando y así todas las veces en\n";
	cout << "las que sea posible(captura múltiple). Si una ficha llega\n";
	cout << "hasta el borde del lado contrario del tablero, se convierte\n";
	cout << "en reina.La reina se mueve también una posición en diagonal,\n";
	cout << "pero hacia adelante y hacia atrás. La reina siempre tiene\n";
	cout << "prioridad para comer antes que cualquiera otra ficha.\n";
	cout << "Una partida finaliza cuando se da una de las siguientes\n";
	cout << "situaciones:\n";
	cout << "Un jugador se queda sin piezas sobre el tablero, por lo tanto,\n";
	cout << "ha perdido.\n";
	cout << "Un jugador no puede mover llegado su turno, puesto que todas las \n";
	cout << "fichas que le quedan estan bloqueadas. Este jugador pierde.";
	cout << "\n\n(**) En este juego usaremos fichas rojas en lugar de blancas\n";
	cout << "para que puedan distinguirse más facilmente";
}
void Solicitar_Cantidad_De_Letras_J1(jugadores * jugador) {
	do {
		cout << "Ingrese cantidad de letras del nombre del jugador 1 (fichas rojas): ";
		cin >> jugador[0].largo_n;
	} while (jugador[0].largo_n <= 0);
}
void Registrar_Jugador_1(char* n1, jugadores* jugador) {
	cout << "Ingrese nombre del jugador 1: ";
	for (int i = 0; i < jugador[0].largo_n; i++)
		cin >> n1[i];
}
void Preguntar_J1_Fichas(char* n1, jugadores* jugador) {
	for (int i = 0; i < jugador[0].largo_n; i++)
		cout << n1[i];
	cout << ", que caracter usaras?" << endl;
	cin >> jugador[0].fichas;
	for (int i = 0; i < 3; i++)
		cout << ".";

	_sleep(200);
	cout << jugador[0].fichas << "? Genial!";
	_sleep(1300);
	Console::Clear();
}
void Solicitar_Cantidad_De_Letras_J2(jugadores* jugador) {
	do {
		cout << "Ingrese cantidad de letras del nombre del jugador 2 (fichas negras): ";
		cin >> jugador[1].largo_n;
	} while (jugador[1].largo_n <= 0);
}
void Registrar_Jugador_2(char* n2, jugadores* jugador) {
	cout << "Ingrese nombre del jugador 2: ";
	for (int i = 0; i < jugador[1].largo_n; i++)
		cin >> n2[i];
}
void Preguntar_J2_Fichas(char* n2, jugadores* jugador) {
	do {
		for (int i = 0; i < jugador[1].largo_n; i++)
			cout << n2[i];
		cout << ", que caracter usaras?" << endl;
		cin >> jugador[1].fichas;
		if (jugador[0].fichas == jugador[1].fichas) {
			cout << "Ese caracter ya esta en uso, elige otro." << endl << endl;
			_sleep(500);
		}
	} while (jugador[0].fichas == jugador[1].fichas);
	cout << endl;
	for (int i = 0; i < 3; i++)
		cout << ".";

	_sleep(100);
	cout << jugador[1].fichas << "? Genial!";
	_sleep(1300);
	Console::Clear();
}
void Solicitar_Info_J1(char* nombre1, jugadores* jugador) {
	Registrar_Jugador_1(nombre1, jugador);
	Preguntar_J1_Fichas(nombre1,  jugador);
}
void Solicitar_Info_J2(char* nombre2, jugadores* jugador) {
	Registrar_Jugador_2(nombre2, jugador);
	Preguntar_J2_Fichas(nombre2, jugador);
}
void Establecer_Fichas_Reina(jugadores* jugador, char q1, char q2) {
	if (jugador[0].fichas + 1 == jugador[1].fichas || jugador[1].fichas + 1 == jugador[0].fichas)
		q1 = jugador[0].fichas + 2, q2 = jugador[1].fichas + 1;
	else char q1 = jugador[0].fichas + 1, q2 = jugador[1].fichas + 1;	
}
void Establecer_Posiciones_Iniciales(jugadores *jugador, char **tablero) {
	tablero[0][0] = '_';
	tablero[0][1] = jugador[0].fichas;
	tablero[0][2] = '_';
	tablero[0][3] = jugador[0].fichas;
	tablero[0][4] = '_';
	tablero[0][5] = jugador[0].fichas;
	tablero[0][6] = '_';
	tablero[0][7] = jugador[0].fichas;
	tablero[1][0] = jugador[0].fichas;
	tablero[1][1] = '_';
	tablero[1][2] = jugador[0].fichas;
	tablero[1][3] = '_';
	tablero[1][4] = jugador[0].fichas;
	tablero[1][5] = '_';
	tablero[1][6] = jugador[0].fichas;
	tablero[1][7] = '_';
	tablero[2][0] = '_';
	tablero[2][1] = jugador[0].fichas;
	tablero[2][2] = '_';
	tablero[2][3] = jugador[0].fichas;
	tablero[2][4] = '_';
	tablero[2][5] = jugador[0].fichas;
	tablero[2][6] = '_';
	tablero[2][7] = jugador[0].fichas;
	tablero[3][0] = 'v';
	tablero[3][1] = '_';
	tablero[3][2] = 'v';
	tablero[3][3] = '_';
	tablero[3][4] = 'v';
	tablero[3][5] = '_';
	tablero[3][6] = 'v';
	tablero[3][7] = '_';
	tablero[4][0] = '_';
	tablero[4][1] = 'v';
	tablero[4][2] = '_';
	tablero[4][3] = 'v';
	tablero[4][4] = '_';
	tablero[4][5] = 'v';
	tablero[4][6] = '_';
	tablero[4][7] = 'v';
	tablero[5][0] = jugador[1].fichas;
	tablero[5][1] = '_';
	tablero[5][2] = jugador[1].fichas;
	tablero[5][3] = '_';
	tablero[5][4] = jugador[1].fichas;
	tablero[5][5] = '_';
	tablero[5][6] = jugador[1].fichas;
	tablero[5][7] = '_';
	tablero[6][0] = '_';
	tablero[6][1] = jugador[1].fichas;
	tablero[6][2] = '_';
	tablero[6][3] = jugador[1].fichas;
	tablero[6][4] = '_';
	tablero[6][5] = jugador[1].fichas;
	tablero[6][6] = '_';
	tablero[6][7] = jugador[1].fichas;
	tablero[7][0] = jugador[1].fichas;
	tablero[7][1] = '_';
	tablero[7][2] = jugador[1].fichas;
	tablero[7][3] = '_';
	tablero[7][4] = jugador[1].fichas;
	tablero[7][5] = '_';
	tablero[7][6] = jugador[1].fichas;
	tablero[7][7] = '_';
	
}
void Graficar_Tablero(jugadores * jugador, int& x1, int& y1, int& x2, int& y2, char** tablero, char q2, char q1) {

	cout << endl << endl;
	for (int i = 0; i < 8; i++) {
		Console::BackgroundColor = ConsoleColor::Black;
		Console::ForegroundColor = ConsoleColor::Gray;
		cout << "   " << i + 1 << ' ';
		for (int j = 0; j < 8; j++)
			if (tablero[i][j] == '_') {
				Console::BackgroundColor = ConsoleColor::DarkRed;
				Console::ForegroundColor = ConsoleColor::DarkRed;
				cout << tablero[i][j] << ' ';
			}
			else
				if (tablero[i][j] == 'v') {

					if (i == y2 - 1 && j == x2 - 1) {
						Console::BackgroundColor = ConsoleColor::Cyan;
						Console::ForegroundColor = ConsoleColor::Cyan;
						cout << tablero[i][j] << ' ';
					}
					else {
						Console::BackgroundColor = ConsoleColor::Gray;
						Console::ForegroundColor = ConsoleColor::Gray;
						cout << tablero[i][j] << ' ';
					}

				}
				else
					if (tablero[i][j] == jugador[0].fichas) {

						if (i == y1 - 1 && j == x1 - 1) {
							Console::BackgroundColor = ConsoleColor::DarkCyan;
							Console::ForegroundColor = ConsoleColor::DarkRed;
							cout << tablero[i][j] << ' ';
						}
						else {
							Console::BackgroundColor = ConsoleColor::Gray;
							Console::ForegroundColor = ConsoleColor::DarkRed;
							cout << tablero[i][j] << ' ';

						}
					}
					else
						if (tablero[i][j] == jugador[1].fichas) {

							if (i == y1 - 1 && j == x1 - 1) {
								Console::BackgroundColor = ConsoleColor::DarkCyan;
								Console::ForegroundColor = ConsoleColor::Black;
								cout << tablero[i][j] << ' ';
							}
							else {
								Console::BackgroundColor = ConsoleColor::Gray;
								Console::ForegroundColor = ConsoleColor::Black;
								cout << tablero[i][j] << ' ';
							}
						}
						else
							if (tablero[i][j] == q2) {

								if (i == y1 - 1 && j == x1 - 1) {
									Console::BackgroundColor = ConsoleColor::DarkCyan;
									Console::ForegroundColor = ConsoleColor::Black;
									cout << jugador[1].fichas << jugador[1].fichas;
								}
								else {
									Console::BackgroundColor = ConsoleColor::Gray;
									Console::ForegroundColor = ConsoleColor::Black;
									cout << jugador[1].fichas << jugador[1].fichas;
								}
							}
							else
								if (tablero[i][j] == q1) {

									if (i == y1 - 1 && j == x1 - 1) {
										Console::BackgroundColor = ConsoleColor::DarkCyan;
										Console::ForegroundColor = ConsoleColor::DarkRed;
										cout << jugador[0].fichas << jugador[0].fichas;
									}
									else {
										Console::BackgroundColor = ConsoleColor::Gray;
										Console::ForegroundColor = ConsoleColor::DarkRed;
										cout << jugador[0].fichas << jugador[0].fichas;
									}
								}
								else
									cout << ' ';
		cout << endl;
	}
	Console::BackgroundColor = ConsoleColor::Black;
	cout << "     ";
	for (int k = 0; k < 8; k++) {
		Console::ForegroundColor = ConsoleColor::Gray;
		cout << k + 1 << ' ';
	}

}
void Mostrar_Informacion(char* n1, char* n2, jugadores * jugador) {

	Console::ForegroundColor = ConsoleColor::Gray;

	cout << "Fichas restantes de ";
	for (int i = 0; i < jugador[0].largo_n; i++)
		cout << n1[i];
	cout << ": " << jugador[0].puntuacion << endl;

	cout << "Fichas restantes de ";
	for (int i = 0; i < jugador[1].largo_n; i++)
		cout << n2[i];
	cout << ": " << jugador[1].puntuacion << endl;

	_sleep(500);
}
void Indicar_Turno(char* n1, char* n2, jugadores *jugador, int turno, int jugadaj1, int jugadaj2) {

	cout << "(Jugadas de ";
	for (int i = 0; i < jugador[0].largo_n; i++) cout << n1[i];
	cout << ": " << jugadaj1 << ")";

	cout << "\n(Jugadas de ";
	for (int i = 0; i < jugador[1].largo_n; i++) cout << n2[i];
	cout << ": " << jugadaj2 << ")";

	cout << "\nEs el turno de ";
	if (turno % 2 != 0)
		for (int i = 0; i < jugador[0].largo_n; i++) cout << n1[i];
	else
		for (int i = 0; i < jugador[1].largo_n; i++) cout << n2[i];
	cout << "!";
	if (turno % 2 != 0)	cout << " (fichas rojas):";
	else cout << " (fichas negras):";
}
void Reiniciar_Sombras(int &x1, int &y1, int &x2, int &y2){
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
}
void Solicitar_Coordenadas_Iniciales(int &x1,int & y1) {
	Console::ForegroundColor = ConsoleColor::Yellow;
	do {
		cout << "Ingrese las coordenadas de la ficha a mover: " << endl;
		cin >> x1 >> y1;
	} while (x1 < 1 || x1 >8 || y1 < 1 || y1 >8);
}
void Solicitar_Coordenadas_Finales(int& x2, int& y2) {
	Console::ForegroundColor = ConsoleColor::DarkYellow;
	do {
		cout << "\nIngrese las nuevas coordenadas de la ficha: " << endl;
		cin >> x2 >> y2;
	} while (x2 < 1 || x2 >8 || y2 < 1 || y2 >8);
}
void Mover_Fichas(char** tablero, jugadores* jugador, int x1, int y1, int x2, int y2, char q1, char q2, int &jugadaj1, int &jugadaj2) {
	if (tablero[y1 - 1][x1 - 1] == jugador[0].fichas && tablero[y2 - 1][x2 - 1] == 'v') {

		jugadaj1++;
		if (y2 - 1 == 7) 
			tablero[y2 - 1][x2 - 1] = q1;		
		else tablero[y2 - 1][x2 - 1] = jugador[0].fichas;


		Console::Beep();
		tablero[y1 - 1][x1 - 1] = 'v';
		if (int(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))) >= 2) {
			tablero[(y1 + y2) / 2 - 1][(x1 + x2) / 2 - 1] = 'v';
			Console::Beep();
			jugador[1].puntuacion--;
		}
	}
	if (tablero[y1 - 1][x1 - 1] == jugador[1].fichas && tablero[y2 - 1][x2 - 1] == 'v') {
		jugadaj2++;
		if (y2 - 1 == 0) 
			tablero[y2 - 1][x2 - 1] = q2;		
		else tablero[y2 - 1][x2 - 1] = jugador[1].fichas;

		Console::Beep();
		tablero[y1 - 1][x1 - 1] = 'v';
		if (int(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))) >= 2) {
			tablero[(y1 + y2) / 2 - 1][(x1 + x2) / 2 - 1] = 'v';
			Console::Beep();
			jugador[0].puntuacion--;
		}
	}

	if (tablero[y1 - 1][x1 - 1] == q1 && tablero[y2 - 1][x2 - 1] == 'v') {
		jugadaj1++;
		tablero[y2 - 1][x2 - 1] = q1;

		Console::Beep();
		tablero[y1 - 1][x1 - 1] = 'v';
		if (int(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))) >= 2) {
			tablero[(y1 + y2) / 2 - 1][(x1 + x2) / 2 - 1] = 'v';
			Console::Beep();
			jugador[0].puntuacion--;
		}
	}

	if (tablero[y1 - 1][x1 - 1] == q2 && tablero[y2 - 1][x2 - 1] == 'v') {
		jugadaj2++;
		tablero[y2 - 1][x2 - 1] = q2;

		Console::Beep();
		tablero[y1 - 1][x1 - 1] = 'v';
		if (int(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))) >= 2) {
			tablero[(y1 + y2) / 2 - 1][(x1 + x2) / 2 - 1] = 'v';
			Console::Beep();
			jugador[1].puntuacion--;
		}
	}
}
void Mostrar_Interfaz(jugadores * jugador, int x1, int y1, int x2, int y2, char**tablero, char q1, char q2, char * nombre1, char * nombre2, int turno, int jugadaj1, int jugadaj2) {
	Console::Clear();
	Graficar_Tablero(jugador, x1, y1, x2, y2, tablero, q1, q2);
	cout << endl << endl;
	Mostrar_Informacion(nombre1, nombre2, jugador);
	cout << endl;
	Indicar_Turno(nombre1, nombre2, jugador, turno, jugadaj1, jugadaj2);
	cout << endl << endl;
}
void Determinar_Imprimir_Ganador(jugadores* jugador, char * nombre1, char * nombre2, int turno, int jugadaj1, int jugadaj2, time_t hora_inicial, time_t hora_final) {
	Console::Beep();
	setlocale(LC_ALL, "spanish");

	cout << "Felicidades! El ganador es ";

	if (jugador[0].puntuacion > jugador[1].puntuacion)
		for (int i = 0; i < jugador[0].largo_n; i++)
			cout << nombre1[i];
	if (jugador[0].puntuacion < jugador[1].puntuacion)
		for (int i = 0; i < jugador[0].largo_n; i++)
			cout << nombre2[i];
	cout << ", en el turno " << turno << " de la partida y con ";

	if (jugador[0].puntuacion > jugador[1].puntuacion)
		cout << jugadaj1 << "jugadas!";
	if (jugador[0].puntuacion < jugador[1].puntuacion)
		cout << jugadaj2 << "jugadas!";

	cout << "\nLa partida inició en" << hora_inicial << " y terminó en " << hora_final;
}
void Ejecutar_Juego() {
	int x1 = 0, y1 = 0, x2 = 0, y2=0, turno=1, jugadaj1=0, jugadaj2=0;	
	jugadores* jugador = new jugadores[2];
	bool victoria = false;
	time_t hora_inicial;
	time_t hora_final;
	time(&hora_inicial);
	Console::Beep();
	Solicitar_Cantidad_De_Letras_J1(jugador);
	char* nombre1 = new char[jugador[0].largo_n];
	Solicitar_Info_J1(nombre1, jugador);
	Console::Beep();
	Solicitar_Cantidad_De_Letras_J2(jugador);
	char* nombre2 = new char[jugador[1].largo_n];
	Solicitar_Info_J2(nombre2, jugador);
	char q1, q2;
	Establecer_Fichas_Reina(jugador, q1, q2);
	char** tablero = new char* [8];
	for (int i = 0; i < 8; i++)
		tablero[i] = new char[8];	
	Establecer_Posiciones_Iniciales(jugador, tablero);
			
	cout << endl << endl;
	Console::Beep();
	
	while (victoria == false) {
		
		Reiniciar_Sombras(x1, y1, x2, y2);		
		Mostrar_Interfaz(jugador, x1, y1, x2, y2, tablero, q1, q2, nombre1, nombre2, turno, jugadaj1, jugadaj2);
		Solicitar_Coordenadas_Iniciales(x1, y1);
		Mostrar_Interfaz(jugador, x1, y1, x2, y2, tablero, q1, q2, nombre1, nombre2, turno, jugadaj1, jugadaj2);
		Solicitar_Coordenadas_Finales(x2, y2);
		Mostrar_Interfaz(jugador, x1, y1, x2, y2, tablero, q1, q2, nombre1, nombre2, turno, jugadaj1, jugadaj2);
		_sleep(500);
		Mover_Fichas(tablero,jugador, x1, y1,  x2, y2, q1, q2, jugadaj1, jugadaj2);
		if (jugador[0].puntuacion == 0 || jugador[1].puntuacion == 0)
			victoria = true;
		turno++;
		Console::Clear();
	}
	time(&hora_final);
	Determinar_Imprimir_Ganador(jugador, nombre1, nombre2, turno, jugadaj1, jugadaj2, hora_inicial, hora_final);
}
void DibujarLogo() {
	int matriz[20][20]=
	{ 
		{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2},
		{ 3,0,0,3,1,0,0,0,0,0,0,0,0,0,0,2,4,0,0,4 },
		{ 3,3,3,3,1,5,6,0,0,0,6,0,0,0,0,2,4,4,4,4 },
		{ 0,3,3,0,1,6,5,6,0,0,5,6,0,0,0,2,0,4,4,0 },
		{ 3,3,3,3,1,5,0,5,6,0,6,5,6,0,0,2,4,4,4,4 },
		{ 3,0,0,3,1,6,0,0,5,6,5,0,5,6,0,2,4,0,0,4 },
		{ 0,0,0,0,1,5,0,0,0,5,6,0,0,5,6,2,0,0,0,0 },
		{ 4,0,0,4,1,6,0,0,0,6,5,0,0,0,5,2,3,0,0,3 },
		{ 4,4,4,4,1,5,0,0,0,5,6,0,0,5,6,2,3,3,3,3 },
		{ 0,4,4,0,1,6,0,0,0,6,5,0,5,6,0,2,0,3,3,0 },
		{ 4,4,4,4,1,5,0,0,0,5,6,5,6,0,0,2,3,3,3,3 },
		{ 4,0,0,4,1,6,0,0,0,6,5,6,0,0,0,2,3,0,0,3 },
		{ 0,0,0,0,1,5,0,0,0,5,6,0,0,0,0,2,0,0,0,0 },
		{ 3,0,0,3,1,0,0,0,0,6,5,6,0,0,0,2,4,0,0,4 },
		{ 3,3,3,3,1,0,0,0,6,5,6,5,6,0,0,2,4,4,4,4 },
		{ 0,3,3,0,1,6,0,6,5,0,5,0,5,6,0,2,0,4,4,0 },
		{ 3,3,3,3,1,5,6,5,0,0,6,0,0,5,6,2,4,4,4,4 },
		{ 3,0,0,3,1,6,5,0,0,0,5,0,0,0,5,2,4,0,0,4 },
		{ 1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	};

	for (int i = 0; i < 20; i++) {
		for (int i = 0; i < 8; i++)
			cout << " ";
		for (int j = 0; j < 20; j++) {
			switch (matriz[i][j]) {
			case 0:	Console::ForegroundColor = ConsoleColor::Black;
				break;
			case 1:	Console::ForegroundColor = ConsoleColor::Green;
				break;
			case 2:	Console::ForegroundColor = ConsoleColor::Cyan;
				break;
			case 3:	Console::ForegroundColor = ConsoleColor::Yellow;
				break;
			case 4:	Console::ForegroundColor = ConsoleColor::DarkBlue;
				break;
			case 5:	Console::ForegroundColor = ConsoleColor::Blue;
				break;
			case 6:	Console::ForegroundColor = ConsoleColor::Red;
			}
			cout << (char)219 << (char)219;
		}
		cout << endl;
	}
}
void Presentacion() {
	int opt;
	DibujarLogo();
	Console::ForegroundColor = ConsoleColor::Gray;
	for (int i = 0; i < 55; i++)
		cout << "=";
	cout << endl << endl;
	for (int i = 0; i < 23; i++)
		cout << " ";
	cout << "Juego de damas" << endl << endl;
	for (int i = 0; i < 23; i++)
		cout << " ";
	cout << "Creado por:" << endl;
	for (int i = 0; i < 14; i++)
		cout << " ";
	cout << "Rodrigo Nieto y Daniel Zapata" << endl << endl;
	for (int i = 0; i < 18; i++)
		cout << " ";
	cout << "Presiona P para jugar"<<endl;
	for (int i = 0; i < 11; i++)
		cout << " ";
	cout << "Presiona H para ver las instrucciones\n\n";
	for (int i = 0; i < 55; i++)
		cout << "=";	

	if (!kbhit() == true)
	switch (_getch()) { 
	case 'p': case 'P': 
		Console::Clear();
		Ejecutar_Juego();
	break;	
	case 'h': case 'H': 
		Console::Clear();
		Mostrar_Instrucciones(); }
	
}
void main() {	
	Presentacion();
	_getch();
}
