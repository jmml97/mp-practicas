#include "jugador.hpp"
#include <iostream>

using namespace std;

void Jugador::SetNombre(char c[]) {

  for (int i = 0; i < 50; i++)
    nombre[i] = c[i];

}

void Jugador::ImprimirNombre() {

  for (int i = 0; nombre[i] != '\0' && i < 50; i++)
    cout << nombre[i];

}

void Jugador::SetTurno(int n) {
  turno = n;
}

void Jugador::SetPuntuacion(int n) {
  puntuacion = n;
}

void Jugador::AddPuntuacion(int n) {
  puntuacion += n;
}

void Jugador::SetPartGan(int n) {
  partidas_ganadas = n;
}

void Jugador::AddPartGan() {
  partidas_ganadas++;
}

void Jugador::EscogeColumna(Tablero& tablero) {

  tablero.PrettyPrint();

  char col;

  do {

    ImprimirNombre() ;
    cout << ", ¿en qué columna quieres poner tu ficha? ";
    cin >> col;

  } while (!tablero.InsertarFicha(col - 'a'));

  cout << "¡Listo!" << endl;

}

void Jugador::MuestraResultados(){

  cout << "El jugador ";
  ImprimirNombre();
  cout << " acumula un total de: " << GetPartGan() << " partida(s) ganadas y " << GetPuntuacion() << " puntos." << endl;

}

Jugador::Jugador(char c[], int t) {

  SetNombre(c);
  SetTurno(t);
  SetPuntuacion(0);
  SetPartGan(0);

}
