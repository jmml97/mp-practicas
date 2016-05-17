#include "jugador.h"
#include <iostream>

using namespace std;

char Jugador::GetNombre() {

  return *nombre;

}

void Jugador::SetNombre(char c[]) {

  for (int i = 0; i < 50; i++)
    nombre[i] = c[i];

}

void Jugador::GetNombre() {

  for (int i = 0; nombre[i] != \0 && i < 50; i++)
    cout << nombre[i];
}

int Jugador::GetTurno() {

  return turno;

}

void Jugador::SetTurno(int n) {

  turno = n;

}

int Jugador::GetPuntuacion() {

  return puntuacion;

}

void Jugador::SetPuntuacion(int n) {

  puntuacion = n;

}

void Jugador::AddPuntuacion(int n) {
  puntuacion += n;
}

void Jugador::EscogeColumna(Tablero tablero) {

  tablero.PrettyPrint();

  char col;       // Usamos char para poder pedir la columna con su letra correspondiente
  do{

    cout << "Introduzca una la columna: ";
    cin >> col;

  } while (!tablero.InsertarFicha(col - 'a'));

}

Jugador::Jugador(char c[], int t) {

  SetNombre(c);
  SetTurno(t);
  SetPuntuacion(0);

}
