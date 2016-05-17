#include "jugador.h"
#include "tablero.h"

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  int f, c, o;
  char nombre1[50], nombre2[50];

  cout << "Bienvenido a ConectaN" << endl;
  cout << "Introduce el número de filas del tablero: ";
  cin >> f;
  cout << "Introduce el número de columnas del tablero: ";
  cin >> c;
  cout << "Introduce el número de fichas objetivo: ";
  cin >> o;

  cout << "Introduce el nombre del primer jugador: ";
  cin >> nombre1;
  cout << "Introduce el nombre del segundo jugador: ";
  cin >> nombre2;


  Jugador jugador1(nombre1, 1), jugador2(nombre2, 2);
  Tablero tablero(f, c, o);

do {
  cout << "¡Comienza la partida!" << endl;

  do {
    if (tablero.GetTurno() == 1){
      cout << " Jugador " << jugador1.GetNombre() << ", su turno" << endl;
      jugador1.EscogeColumna();
    }
    else{
      cout << " Jugador " << jugador2.GetNombre() << ", su turno" << endl;
      jugador2.EscogeColumna();
    }


  } while (tablero.PartidaFinalizada() == 0);

  if (tablero.PartidaFinalizada() == 2)
    cout << "Se ha producido un empate :S" << endl;

  else  {

    tablero.SetGanador();
    int puntuacion = tablero.GetPuntuacion();
    cout << "El ganador es:"

    if (tablero.GetGanador() == 1)
      jugador1.AddPuntuacion(puntuacion);

    else if (tablero.GetGanador() == 2)
      jugador2.AddPuntuacion();
  }

  char partida;
  bool otra;
  do {
    cout << "¿Otra? (S/N)" << endl;
    cin >> partida;
  }while (partida != S && partida != N);

  if (partida == "S")
    otra = true;
  else
    otra = false;
} while (otra);


cout << "Fin de la partida \nResultados:" << endl;



  return 0;

}
