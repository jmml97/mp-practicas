#include "jugador.hpp"
#include "tablero.hpp"

#include <cctype>
#include <iostream>
#include <fstream>

#include <string.h>

// Colores para la consola.

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;

// Carga una partida a partir del nombre de archivo proporcionado.
// Hay que proporcionarle los jugadores y el tablero para que los
// modifique.
bool Cargar(const char *c, Jugador &j1, Jugador &j2, Tablero &t) {

  ifstream f(c, ios::in);

  if (f) {

    char tmp;
    const char* req = "#MP-CONECTAN-1.0";

    while (f.peek() != '#') {
      f.ignore();
    }

    for (size_t i = 0; i < strlen(req); i++) {
      f >> tmp;
      if (tmp != req[i])
        return false;
    }

    f >> j1;
    f >> j2;
    f >> t;

  }

	f.close();

	return f.good();

}

// Guarda la partida en un archivo del nombre que se le indique.
bool Guardar(char c[], Jugador j1, Jugador j2, Tablero t) {

  ofstream f(c, ios::out);

  if (f) {

    f << "#MP-CONECTAN-1.0" << endl;
    f << j1 << endl;
    f << j2 << endl;
    f << t;

    f.close();

  }

  return f.good();

}

// Presenta la interfaz de turno de cada jugador.
bool JugarTurno(Jugador &j, Tablero &t) {

  cout << "¡Turno de "; j.ImprimirNombre(cout); cout << "!";

  switch (j.GetTurno()) {
    case 1: cout << BLUE << " (x)" << RESET << endl;
            break;
    case 2: cout << RED << " (o)" << RESET << endl;
            break;
  }

  return j.EscogeColumna(t);

}

int main(int argc, char const *argv[]) {

  // Filas, columnas, objetivo de fichas y fichas por turno.
  int f = 0, c = 0, o = 0, t = 0;
  char *nombre1 = new char[0], *nombre2 = new char[0];
  // ¿Otra partida?
  bool otra, cargada = false;
  Jugador jugador1, jugador2;
  Tablero tablero;

  // CONFIRGURACIÓN DE LA PARTIDA.
  // Si recibe como argumento el nombre de un archivo (sea válido o no), intenta
  // cargarlo. Si no es posible cargarlo, pregunta por un nombre de archivo
  // válido.
  // En caso de que el programa se ejecute sin argumentos, se pide al usuario
  // información sobre la partida.

  if (argc == 2) {

    cargada = Cargar(argv[1], jugador1, jugador2, tablero);

    do {

      cout << RED << "Error al cargar archivo. Introduce un archivo válido o ejecuta el programa sin argumentos en caso de que no quieras cargar un archivo." << RESET << endl;
      char *c = new char[0];
      cin >> c;

      cargada = Cargar(c, jugador1, jugador2, tablero);

    } while (!cargada);


  }
  else if (argc == 1) {

    cout << "\n";
    cout << BOLDWHITE << "Bienvenido a ConectaN!" << RESET << endl;
    cout << BOLDWHITE << "Primero es necesario configurar la partida. ¡Responde a las siguientes preguntas!" << RESET << endl;

    do {

      cout << BOLDWHITE << "¿Cuántas filas quieres que tenga el tablero? " << RESET;
      cin >> f;

    } while (f < 1);

    do {

      cout << BOLDWHITE << "¿Cuántas columnas quieres que tenga el tablero? " << RESET;
      cin >> c;

    } while (c < 1);

    do {

      cout << BOLDWHITE << "¿Cuál será el número de fichas a alinear? " << RESET;
      cin >> o;

    } while (o > f &&  o > c);

    do {

      cout << BOLDWHITE << "¿Cuál será el número de fichas a insertar por turno? " << RESET;
      cin >> t;

    } while (t < 1 && t > o - 2);

    cout << BOLDWHITE << "Jugador 1, ¿cúal es tu nombre? " << RESET;
    cin >> nombre1;
    cout << BOLDWHITE << "Jugador 2, ¿cuál es tu nombre? " << RESET;
    cin >> nombre2;
    cout << BOLDWHITE << "¡Todo listo! ¡Disfruta de ConectaN!" << RESET << endl;
    cout << "\n" << endl;
    cout << RESET << endl;

    jugador1 = Jugador(nombre1, 1);
    jugador2 = Jugador(nombre2, 2);
    tablero = Tablero(f, c, o, t);

  }
  else
    cout << "Error. El programa se ejecuta sin parámetros o bien con el nombre del archivo de partida a cargar." << RESET << endl;

// FLUJO PRINCIPAL DEL JUEGO.
// Hay dos do-while. El primero ejecuta el programa hasta que el usuario diga
// que no quiere jugar más partidas.
// El segundo se encarga de que en cada partida, hasta que alguien gane la
// partida o haya empate, se va pidiendo a cada jugador que introduzca una
// ficha.
do {

  switch (argc) {
    case 2: cout << "¡Continúa la partida!" << endl;
            break;
    default: cout << "¡Comienza la partida!" << endl;
  }

  do {

    bool exito = false;
    char res, archivo[100];

    if (tablero.GetInsertadasEnTurno() == tablero.GetFichasPorTurno())
      tablero.CambiaTurno();

    while (!exito) {

      switch (tablero.GetTurno()) {
        case 1: exito = JugarTurno(jugador1, tablero);
                break;
        case 2: exito = JugarTurno(jugador2, tablero);
                break;
      }

      if (!exito) {
        cout << BOLDRED << "Error en la introducción de la columna. ¿Quieres guardar la partida? (S/N) " << RESET;
        cin >> res;

        if (tolower(res) == 's') {
          cout << "Nombre del archivo: ";
          cin >> archivo;

          Guardar(archivo, jugador1, jugador2, tablero);

        }

      }

      if (exito)
        tablero.AumentarInsertadasEnTurno();

    }


  } while (tablero.PartidaFinalizada() == 0);

  if (tablero.PartidaFinalizada() == 2){
    cout << BOLDYELLOW << "Se ha producido un empate :S\n" << RESET << endl;
    tablero.VaciarTablero();
  }
  else {

    tablero.PrettyPrint();
    tablero.SetGanador();
    tablero.VaciarTablero();
    int puntuacion = tablero.GetPuntuacion();
    cout << BOLDGREEN << "¡Se acabó! ¡Fin de la partida! El ganador es \n" ;

    if (tablero.GetGanador() == 1) {

      jugador1.AddPuntuacion(puntuacion);
      jugador1.AddPartGan();
      jugador1.ImprimirNombre(cout);

    }
    else if (tablero.GetGanador() == 2) {

      jugador2.AddPuntuacion(puntuacion);
      jugador2.AddPartGan();
      jugador2.ImprimirNombre(cout);

    }

    cout << ". ¡Enhorabuena!" << RESET << endl;


    cout << BOLDWHITE << endl;
    cout << "\nLos resultados por ahora son: " << endl;
    cout << "-----------" << endl;
    jugador1.MuestraResultados();
    jugador2.MuestraResultados();
    cout << RESET << endl;

  }

  char partida;

  do {
    
    cout << "¿Otra? Insert coin: (S/N): ";
    cin >> partida;
    partida = toupper(partida);

  } while (partida != 'S' && partida != 'N');

  if (partida == 'S')
    otra = true;
  else
    otra = false;

} while (otra);

cout << BOLDWHITE << endl;
cout << "Resultados finales: " << endl;
jugador1.MuestraResultados();
jugador2.MuestraResultados();
cout << "¡Gracias por jugar a Conecta-N!" << endl;
cout << RESET << endl;

return 0;

}
