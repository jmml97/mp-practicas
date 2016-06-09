/*
  Matriz del tablero mediante memoria estática
*/

#include <iostream>
#include "matriz.hpp"

using namespace std;


Matriz::Matriz() {

  filas = columnas = 0;

}

Matriz::Matriz(int f, int c) {

  filas = f;
  columnas = c;
  matriz = new int[filas*columnas];

}

Matriz::Matriz(const Matriz &m) {      // Constructor copia

  int fils = m.GetFilas();
  int cols = m.GetColumnas();

  filas = fils;
  columnas = cols;

  matriz = new int[fils*cols];

  for (int i = 0; i < fils*cols;i++) {

    matriz[i]= m.matriz[i];

  }

}

Matriz::~Matriz() {

  delete[] this->matriz;
  this->columnas = this->filas = 0;

}

Matriz& Matriz::operator=(const Matriz &m){    // Operador asignación

  if (&m != this) {

    this->filas = m.filas;
    this->columnas = m.columnas;
    this->matriz = new int [this->filas*this->columnas];

    for (int i = 0; i < this->filas*this->columnas; i++)
      matriz[i] = m.matriz[i];

  }

  return *this;

}

void Matriz::Reset() {

  for (int i = 0; i < filas * columnas; i++)
    matriz[i] = 0;

}

// Devuelve el número de casillas usadas en la matriz (su contenido es distinto
// de 0).
int Matriz::GetUsadas() {

    int contador = 0;

    for (int i = 0; i < GetFilas(); i++){
      for (int j = 0; j < GetColumnas(); j++){
        if (Consulta(i,j) != 0)
          contador++;
      }
    }

    return contador;
}

// Operadores de E/S

ostream& operator<<(ostream &os, const Matriz &m) {

  os << m.GetFilas() << '\n';
  os << m.GetColumnas() << '\n';

  for (int i = 0; i < m.GetFilas() * m.GetColumnas(); i++)
    os << m.Consulta(i) << ' ';

  return os;

}

istream& operator>>(istream &is, Matriz &m) {

  int f, c, tmp;

  is >> f >> c;

  m = Matriz(f, c);

  for (int i = 0; i < m.GetFilas() * m.GetColumnas(); i++) {
    is >> tmp;
    m.Modifica(i, tmp);
  }

  return is;

}
