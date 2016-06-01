#include "jugador.hpp"
#include "tablero.hpp"

#include <cctype>
#include <iostream>
#include <fstream>

using namespace std;

bool Cargar(char c[], Jugador &j1, Jugador &j2, Tablero &t) {

  ifstream f(c, ios::in);

  if (f) {

    char tmp[17];
    f.getline(tmp, 17);

    const char* s1 = tmp;
    const char* s2 = "#MP-CONECTAN-1.0";

    if (strcmp(s1, s2) == 0) {
      f >> j1;
      f >> j2;
      f >> t;
    }

    f.close();

  }

  return f.good();

}

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

int main(int argc, char const *argv[]) {

  int f, c, o;
  char *nombre1 = new char[0], *nombre2 = new char[0];

  cout << "\n";
  cout << "¡Bienvenido a ConectaN!" << endl;
  cout << "Primero es necesario configurar la partida. ¡Responde a las siguientes preguntas!" << endl;

  do{
  cout << "¿Cuántas filas quieres que tenga el tablero? ";
  cin >> f;

} while (f < 1);

  do {
  cout << "¿Cuántas columnas quieres que tenga el tablero? ";
  cin >> c;

} while (c < 1);

  do {
  cout << "¿Cuál será el número de fichas a alinear? ";
  cin >> o;

} while (o > f &&  o > c);

  cout << "Jugador 1, ¿cúal es tu nombre? ";
  cin >> nombre1;
  cout << "Jugador 2, ¿cuál es tu nombre? ";
  cin >> nombre2;
  cout << "¡Todo listo! ¡Disfruta de ConectaN!" << endl;
  cout << "\n" << endl;


  Jugador jugador1(nombre1, 1), jugador2(nombre2, 2);
  Tablero tablero(f, c, o);
  bool otra;

do {

  tablero.VaciarTablero();
  cout << "¡Comienza la partida!" << endl;

  do {

    tablero.CambiaTurno();

    cout << "¡Turno de ";

    bool exito;

    if (tablero.GetTurno() == 1) {

      jugador1.ImprimirNombre(cout);
      cout << " (x)!" << endl;

      do {
        exito = jugador1.EscogeColumna(tablero);
        if (!exito)
          cout << "Error. Introduce una columna correcta." << endl;
      } while (!exito);



    }
    else {

      jugador2.ImprimirNombre(cout);
      cout << " (o)!" << endl;

      do {
        exito = jugador2.EscogeColumna(tablero);
        if (!exito)
          cout << "Error. Introduce una columna correcta." << endl;
      } while (!exito);

    }


  } while (tablero.PartidaFinalizada() == 0);

  if (tablero.PartidaFinalizada() == 2)
    cout << "Se ha producido un empate :S" << endl;
  else {

    tablero.PrettyPrint();
    tablero.SetGanador();
    int puntuacion = tablero.GetPuntuacion();
    cout << "¡Se acabó! ¡Fin de la partida! El ganador es ";

    if (tablero.GetGanador() == 1){

      jugador1.AddPuntuacion(puntuacion);
      jugador1.AddPartGan();
      jugador1.ImprimirNombre(cout);

    }
    else if (tablero.GetGanador() == 2){

      jugador2.AddPuntuacion(puntuacion);
      jugador2.AddPartGan();
      jugador2.ImprimirNombre(cout);

    }

    cout << ". ¡Enhorabuena!" << endl;

    cout << "\nLos resultados por ahora son: " << endl;
    cout << "-----------" << endl;
    jugador1.MuestraResultados();
    jugador2.MuestraResultados();

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

cout << "Resultados finales: " << endl;
jugador1.MuestraResultados();
jugador2.MuestraResultados();
cout << "¡Gracias por jugar a Conecta-N!" << endl;

Cargar("datos_inventados.txt", jugador1, jugador2, tablero);
Guardar("datos.txt", jugador1, jugador2, tablero);

return 0;

}
