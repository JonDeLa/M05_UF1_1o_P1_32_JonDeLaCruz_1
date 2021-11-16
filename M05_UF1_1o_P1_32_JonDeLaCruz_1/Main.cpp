#include <iostream>
using namespace std;

#define CONSOLE_HEIGHT 29
#define CONSOLE_WIDTH 119
//Inicializamos funciones
void ImprimirPantalla();
void RellenarMapa();
void Inputs();
void Start();
//Vamos a crear un enum para controlar los tiles del mapa
enum MAP_TILES { EMPTY = ' ', WALL = '#', POINT = '*' };
//Ahora vamos a crear lo que seria el mapa mediante una array bidimensional
MAP_TILES CosoleScreen[CONSOLE_HEIGHT][CONSOLE_WIDTH];
//Enum para los imputs
enum USER_INPUT { NONE, UP, DOWN, RIGHT, LEFT, QUIT };
USER_INPUT input = USER_INPUT::NONE;
//Var del personaje
char personaje = '@';
//Var de posición
int personaje_xPos = 10;
int personaje_yPos = 5;
//Bool para controlar el bucle del programa
bool run = true;
int main()
{
	//Vamos a crear un start antes de nada para que nos rellene el mapa y nos lo muestre nada mas empezar
	Start();
	while (run)
	{
		Inputs();
		ImprimirPantalla();
	}
	//Imprimimos los datos y finalizamos el juego.
	system("CLS");
	cout <<  " gracias por haber jugado :)" << endl;
}
void Start() {

	RellenarMapa();
	ImprimirPantalla();
}
void RellenarMapa()
{
	//Vamos a crear el marco del mapa
	for (int i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (int j = 0; j < CONSOLE_WIDTH; j++)
		{
			//Lo he puesto de dos maneras diferntes
			if (i == 0 || i == CONSOLE_HEIGHT - 1 || j == 0 || j == 118)
			{
				CosoleScreen[i][j] = MAP_TILES::WALL;
			}
			else
			{
				CosoleScreen[i][j] = MAP_TILES::EMPTY;
			}
		}

	}
	
	
}
void Inputs() {
	//Dato Curioso: Variables Locales en azul, variables globales blancas 
	char input_local;
	cin >> input_local;
	//Este switch lo utilizamos para el Enum de USER_INPUT, lo modificamos para posteriormente trabajar con el 
	switch (input_local)
	{
	case 'W':
	case'w':
		personaje_yPos--;
		break;
	case 'A':
	case'a':
		personaje_xPos--;
		break;
	case 'S':
	case's':
		personaje_yPos++;
		break;
	case 'D':
	case 'd':
		personaje_xPos++;
		break;
	case'Q':
	case'q':
		run = false;
		break;
	default:
		break;
	}
}
void ImprimirPantalla()
{
	
		system("CLS");
		for (int i = 0; i < CONSOLE_HEIGHT; i++)
		{
			for (int j = 0; j < CONSOLE_WIDTH; j++)
			{
				if (personaje_xPos == j && personaje_yPos == i)
				{
					cout << personaje;
				}
				else
				{
					//ALERTA: si no lo transformamos a char nos dara numeros por el enum
					cout << (char)CosoleScreen[i][j];
				}
			}
			cout << endl;
		}
		
	}
	

//Trabajo PacMan_JonDeLaCruz