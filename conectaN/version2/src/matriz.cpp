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

Matriz::~Matriz(){              // Destructor

  delete[] matriz;
  filas = columnas = 0;

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

Matriz& Matriz::operator=(const Matriz &m){    // Operador asignación

  if(this != &m){

    delete[]matriz;
    filas = m.GetFilas();
    columnas = m.GetColumnas();
    matriz = new int[filas*columnas];

    for (int i = 0; i < filas * columnas;i++){
      matriz[i] = m.matriz[i];
    }
  }

  return *this;
}


void Matriz::SetFilas(int fils) {

  filas = fils;

}

void Matriz::SetColumnas(int col) {

  columnas = col;

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


int Matriz::Consulta(int fila, int columna) const{

  return matriz[fila*columnas + columna];

}

// Sobrecarga Consulta() para acceder dada una posición i-ésima
int Matriz::Consulta(int posicion) const{

  return matriz[posicion];

}

void Matriz::Modifica (int fila, int columna, int valor) {

  matriz[fila*columnas + columna] = valor;

}

void Matriz::Modifica (int posicion, int valor) {

  matriz[posicion] = valor;

}

// Operadores de E/S

ostream& operator<<(ostream &os, const Matriz &m) {

  os << m.GetColumnas() << '\n';
  os << m.GetFilas() << '\n';

  for (int i = 0; i < m.GetFilas() * m.GetColumnas(); i++)
    os << m.Consulta(i) << ' ';

  return os;

}

istream& operator>>(istream &is, Matriz &m) {

  int f, c, tmp;

  is >> f >> c;

  m.SetColumnas(f);
  m.SetFilas(c);

  for (int i = 0; i < m.GetFilas() * m.GetColumnas(); i++) {
    cin >> tmp;
    m.Modifica(i, tmp);
  }

  return is;

}
