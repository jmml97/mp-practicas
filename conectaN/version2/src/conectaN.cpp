#include "jugador.hpp"
#include "tablero.hpp"

#include <cctype>
#include <iostream>
#include <fstream>

#include <string.h>

using namespace std;

bool Cargar(const char c[], Jugador &j1, Jugador &j2, Tablero &t) {

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

bool JugarTurno(Jugador &j, Tablero &t) {

  cout << "¡Turno de "; j.ImprimirNombre(cout); cout << "!";

  switch (j.GetTurno()) {
    case 1: cout << " (x)" << endl;
            break;
    case 2: cout << " (o)" << endl;
            break;
  }

  return j.EscogeColumna(t);

}

int main(int argc, char const *argv[]) {

  int f = 0, c = 0, o = 0, t = 0;
  char *nombre1 = new char[0], *nombre2 = new char[0];
  bool otra;
  Jugador jugador1, jugador2;
  Tablero tablero;

  if (argc == 2) {
    Cargar(argv[1], jugador1, jugador2, tablero);
  }
  else if (argc == 1) {

    cout << "\n";
    cout << "¡Bienvenido a ConectaN!" << endl;
    cout << "Primero es necesario configurar la partida. ¡Responde a las siguientes preguntas!" << endl;

    do {

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

    do {

      cout << "¿Cuál será el número de fichas a insertar por turno? ";
      cin >> t;

    } while (t < 1 && t > o - 2);

    cout << "Jugador 1, ¿cúal es tu nombre? ";
    cin >> nombre1;
    cout << "Jugador 2, ¿cuál es tu nombre? ";
    cin >> nombre2;
    cout << "¡Todo listo! ¡Disfruta de ConectaN!" << endl;
    cout << "\n" << endl;

    jugador1 = Jugador(nombre1, 1);
    jugador2 = Jugador(nombre2, 2);
    tablero = Tablero(f, c, o, t);

  }
  else
    cout << "Error. El programa se ejecuta sin parámetros o bien con el nombre del archivo de partida a cargar." << endl;

do {

  cout << "¡Comienza la partida!" << endl;

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
        cout << "Error en la introducción de la columna. ¿Quieres guardar la partida?" << endl;
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

  if (tablero.PartidaFinalizada() == 2)
    cout << "Se ha producido un empate :S" << endl;
  else {

    tablero.PrettyPrint();
    tablero.SetGanador();
    tablero.VaciarTablero();
    int puntuacion = tablero.GetPuntuacion();
    cout << "¡Se acabó! ¡Fin de la partida! El ganador es ";

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

return 0;

}
