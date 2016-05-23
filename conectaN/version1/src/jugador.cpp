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

void Jugador::CoutNombre() {

  for (int i = 0; nombre[i] != '\0' && i < 50; i++)
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

void Jugador::SetPartGan(int n){

  partidas_ganadas = n;
}

int Jugador::GetPartGan(){
  return partidas_ganadas;
}

void Jugador::AddPartGan(){
  partidas_ganadas++;
}


void Jugador::EscogeColumna(Tablero& tablero) {

  tablero.PrettyPrint();

  char col;       // Usamos char para poder pedir la columna con su letra correspondiente
  do{

    cout << "Introduzca una la columna: ";
    cin >> col;

  } while (!tablero.InsertarFicha(col - 'a'));

}

void Jugador::MuestraResultados(){

  cout << "El jugador " << GetNombre() << " acumula un total de: " << GetPartGan() << " y " << GetPuntuacion() << " puntos." << endl;
}

Jugador::Jugador(char c[], int t) {

  SetNombre(c);
  SetTurno(t);
  SetPuntuacion(0);

}
