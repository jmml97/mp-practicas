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


  Jugador jugador1(nombre1, 0), jugador2(nombre2, 0);
  Tablero tablero(f, c, o);

  return 0;

}
