

#include<iosfwd> // istream,ostream
#include "matriz_bit.h"


bool Leer(std::istream& is, MatrizBit& m) {

  for (int i = 0; i < m.Filas(); i++) {
    for (int j = 0; j < m.Columnas(); j++) {
      bool v;
      is >> bool;
      Set(m, i, j, v);
    }
  }

}

bool Escribir(std::ostream& os, const MatrizBit& m) {

  for (int i = 0; i < m.Filas(); i++) {
    for (int j = 0; j < m.Columnas(); j++) {
      os << Get(m, i, j);
    }
  }

}

bool Leer(const char nombre[], MatrizBit& m) {

  

}

bool Escribir(const char nombre[], const MatrizBit& m) {



}

void And(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2) {

  bool elemento;

  if ((m1.Filas() == m2.Filas()) && (m1.Columnas() == m2.Columnas())) {

    for (int i = 0; i < m.Filas(); i++) {
      for (int j = 0; j < m.Columnas(); j++) {
        elemento = Get(m1, i, j) && Get(m2, i, j);
        Set(res, i, j, elemento);

      }
    }
  }
  else {
    cout << "El tamaño de las matrices no coincide." << endl;
  }

}

void Or(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2) {

  bool elemento;

  if ((m1.Filas() == m2.Filas()) && (m1.Columnas() == m2.Columnas())) {

    for (int i = 0; i < m.Filas(); i++) {
      for (int j = 0; j < m.Columnas(); j++) {
        elemento = Get(m1, i, j) || Get(m2, i, j);
        Set(res, i, j, elemento);

      }
    }
  }
  else {
    cout << "El tamaño de las matrices no coincide." << endl;
  }

}

}

void Not(MatrizBit& res, const MatrizBit& m) {

  for (int i = 0; i < m.Filas(); i++) {
    for (int j = 0; j < m.Columnas(); j++) {
      elemento = !Get(m1, i, j);
      Set(res, i, j, elemento);

    }
  }

}

void Traspuesta(MatrizBit& res, const MatrizBit& m) {

  for (int i = 0; i < m.Filas(); i++) {
    for (int j = 0; j < m.Columnas(); j++) {
      elemento = Get(m1, i, j);
      Set(res, j, i, elemento);

    }
  }

}
