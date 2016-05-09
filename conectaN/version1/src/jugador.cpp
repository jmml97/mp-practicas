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

void Jugador::EscogeColumna(int c) {



}

Jugador::Jugador(char c[], int t) {

  SetNombre(c);
  SetTurno(t);

}
