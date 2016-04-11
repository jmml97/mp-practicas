

#include <iosfwd> // istream,ostream
#include "matriz_bit.h"


bool Leer(std::istream& is, MatrizBit& m) {

  int cols, fils;

  is >> cols;
  is >> fils;

  bool exito =  is && Inicializar(m, fils, cols);

  if (exito) {
    for (int i = 0; i < Filas() && init; i++) {
      for (int j = 0; j < Columnas(); j++) {
        char v
        is >> v;
        if (v == '1')
          Set(m, i, j, true);
        else
          Set(m, i, j, false);

      }
      exito = is;
    }
    return true;
  }

  return exito;

}

bool Escribir(std::ostream& os, const MatrizBit& m) {

  os << Filas(m) << ' ' << Columnas(m) << endl;

  for (int i = 0; i < Filas(m); i++) {
    for (int j = 0; j < Columnas(m); j++) {
      bool v = Get(m, i, j);
      if (v)
        os << '1';
      else
        os << '0';
      os << ' ';
    }

  }

  return os;

}

bool Leer(const char nombre[], MatrizBit& m) {

  ofstream archivo_matriz(nombre[]);
  bool exito = archivo_matriz.is_open();

  if (exito) {

    bool exito = Leer(archivo_matriz, m);

  }

  return exito;

}

bool Escribir(const char nombre[], const MatrizBit& m) {

  ofstream archivo_matriz(nombre[]);
  bool exito = archivo_matriz.is_open();

  if (exito) {

    bool exito = Escribir(archivo_matriz, m);

  }

  return exito;

}

void And(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2) {

  bool elemento;

  if ((Filas(m1) == Filas(m2)) && (Columnas(m1) == Columnas(m2))) {

    for (int i = 0; i < Filas(m); i++) {
      for (int j = 0; j < Columnas(m); j++) {
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

  if ((Filas(m1) == Filas(m2)) && (Columnas(m1) == Columnas(m2))) {

    for (int i = 0; i < Filas(m); i++) {
      for (int j = 0; j < Columnas(m); j++) {
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

  for (int i = 0; i < Filas(m); i++) {
    for (int j = 0; j < Columnas(m); j++) {
      elemento = !Get(m1, i, j);
      Set(res, i, j, elemento);

    }
  }

}

void Traspuesta(MatrizBit& res, const MatrizBit& m) {

  for (int i = 0; i < Filas(m); i++) {
    for (int j = 0; j < Columnas(m); j++) {
      elemento = Get(m1, i, j);
      Set(res, j, i, elemento);

    }
  }

}
