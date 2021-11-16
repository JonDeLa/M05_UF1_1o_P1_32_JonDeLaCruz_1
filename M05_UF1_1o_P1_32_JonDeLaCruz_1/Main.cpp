#include <iostream>
using namespace std;

#define CONSOLE_HEIGHT 29
#define CONSOLE_WIDTH 119
//Inicializamos funciones
void ImprimirPantalla();
void RellenarMapa();
void Inputs();
void Start();
void Logica();
void SetPuntos();
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
//Var Contador de muntos
int map_points = 0;
int player_points = 0;

int main()
{
	//Vamos a crear un start antes de nada para que nos rellene el mapa y nos lo muestre nada mas empezar
	Start();
	while (run)
	{
		Inputs();
		Logica();
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

		//Vamos a hacer los tp, por lo que tendremos que vaciar un segmento de las esquinas del mapa
		CosoleScreen[12][0] = MAP_TILES::EMPTY;
		CosoleScreen[13][0] = MAP_TILES::EMPTY;
		CosoleScreen[14][0] = MAP_TILES::EMPTY;
		CosoleScreen[15][0] = MAP_TILES::EMPTY;
		CosoleScreen[12][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;
		CosoleScreen[13][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;
		CosoleScreen[14][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;
		CosoleScreen[15][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;
	}
	SetPuntos();
	
}
void SetPuntos()
{
	//Tendremos que crear los puntos en el mapa en esta función de aqui
	CosoleScreen[1][1] = MAP_TILES::POINT;
	CosoleScreen[1][46] = MAP_TILES::POINT;
	CosoleScreen[10][70] = MAP_TILES::POINT;
	CosoleScreen[15][15] = MAP_TILES::POINT;
	CosoleScreen[27][1] = MAP_TILES::POINT;
	CosoleScreen[27][56] = MAP_TILES::POINT;
	CosoleScreen[1][117] = MAP_TILES::POINT;
	CosoleScreen[17][98] = MAP_TILES::POINT;
	CosoleScreen[19][101] = MAP_TILES::POINT;
	CosoleScreen[27][117] = MAP_TILES::POINT;

	//Contamos los puntos que va a tener el mapa
	map_points = 10;
}
void Logica()
{
	//Vamos a crear la colisión para ello tenemos que saber donde estamos 
	int personaje_yPosN = personaje_yPos;
	int personaje_xPosN = personaje_xPos;
	//Aqui modificamos la posicion con los enum
	switch (input)
	{
	case UP:
		personaje_yPosN--;
		break;
	case DOWN:
		personaje_yPosN++;
		break;
	case RIGHT:
		personaje_xPosN++;
		break;
	case LEFT:
		personaje_xPosN--;
		break;
	case QUIT:
		run = false;

		break;
	}
	//Crearemos el tp de personaje
	if (personaje_xPos < 0)
	{
		personaje_xPosN = CONSOLE_WIDTH - 1;
	}
	personaje_xPosN %= CONSOLE_WIDTH;
	//Esta condición nos permitira decir que si nuestro personaje va a ir a una casilla que es un muro, este se quede donde esta
	if (CosoleScreen[personaje_yPosN][personaje_xPosN] == MAP_TILES::WALL)
	{
		personaje_yPosN = personaje_yPos;
		personaje_xPosN = personaje_xPos;
	}
	else if (CosoleScreen[personaje_yPosN][personaje_xPosN] == MAP_TILES::POINT)
	{
		//Aqui creamos el sistema de los puntos, por ejemplo, Actualizamos contadores y eliminamos los puntos 
		map_points--;
		player_points++;
		CosoleScreen[personaje_yPosN][personaje_xPosN] = MAP_TILES::EMPTY;


	}
	//Aqui terminamos de igualar nuestra posición con la posicion que hemos estado operando
	personaje_yPos = personaje_yPosN;
	personaje_xPos = personaje_xPosN;
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
		input = USER_INPUT::UP;
		break;
	case 'A':
	case'a':
		input = USER_INPUT::LEFT;
		break;
	case 'S':
	case's':
		input = USER_INPUT::DOWN;
		break;
	case 'D':
	case 'd':
		input = USER_INPUT::RIGHT;
		break;
	case'Q':
	case'q':
		input = USER_INPUT::QUIT;
		break;
	default:
		input = USER_INPUT::NONE;
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