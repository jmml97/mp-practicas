#include "jugador.hpp"
#include <iostream>

using namespace std;

void Jugador::SetNombre(char c[]) {

  nombre = c;

}

void Jugador::ImprimirNombre(ostream &os) const {

  for (int i = 0; nombre[i] != '\0'; i++)
    os << nombre[i];

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

bool Jugador::EscogeColumna(Tablero& tablero) {

  bool exito = false;

  tablero.PrettyPrint();

  if (nombre[0] == '@') {
    while(!exito)
      exito = tablero.InsertarFicha(rand() % tablero.GetColumnas());
  } else {

    char col;

    ImprimirNombre(cout) ;
    cout << ", ¿en qué columna quieres poner tu ficha? ";
    cin >> col;
    exito = tablero.InsertarFicha(col - 'a');

  }

  return exito;

}

void Jugador::MuestraResultados(){

  cout << "El jugador ";
  ImprimirNombre(cout);
  cout << " acumula un total de: " << GetPartGan() << " partida(s) ganadas y " << GetPuntuacion() << " puntos." << endl;

}

Jugador::Jugador() {

  nombre = 0;
  SetTurno(0);
  SetPuntuacion(0);
  SetPartGan(0);

}

Jugador::Jugador(char c[], int t) {

  SetNombre(c);
  SetTurno(t);
  SetPuntuacion(0);
  SetPartGan(0);

}

Jugador::Jugador(char c[], int t, int p, int g) {

  SetNombre(c);
  SetTurno(t);
  SetPuntuacion(p);
  SetPartGan(g);

}

Jugador::Jugador(const Jugador &j) {

  this->SetNombre(j.GetNombre());
  this->SetTurno(j.GetTurno());
  this->SetPuntuacion(j.GetPuntuacion());
  this->SetPartGan(j.GetPartGan());

}

Jugador::~Jugador() {



}

Jugador& Jugador::operator=(const Jugador &j) {

  SetNombre(j.GetNombre());
  SetTurno(j.GetTurno());
  SetPuntuacion(j.GetPuntuacion());
  SetPartGan(j.GetPartGan());

  return *this;

}

// Operadores de E/S

ostream& operator<<(ostream &os, const Jugador &j) {

  os << '#';
  j.ImprimirNombre(os);
  os << '\n';
  os << j.GetTurno() << ' ';
  os << j.GetPuntuacion() << ' ';
  os << j.GetPartGan() << ' ';

  return os;

}

istream& operator>>(istream &is, Jugador &j) {

  char *n = new char[0];
  int t = 0, p = 0, g = 0;

  while (is.peek() != '#')
    is.ignore();

  is.ignore();
  is >> n >> t >> p >> g;

  j.SetNombre(n);
  j.SetTurno(t);
  j.SetPuntuacion(p);
  j.SetPartGan(g);

  return is;

}
