

#include <iosfwd> // istream,ostream
#include "matriz_bit.h"


<<<<<<< HEAD
bool Leer(std::istream& is, MatrizBit& m) {   // Estamos leyendo m, por lo cual no está inicializada
                                              // leemos dos valores y llamamos a inicializar, además Filas no es
                                              // un método de una clase matriz, sino una función global, tenemos
                                              // que usar Filas (m), eso se aplica a todo lo demás
  int fils, colms;
  is >> fils >> colms;

  if (Inicializar(m,fils,colms)){


    for (int i = 0; i < Filas(m); i++) {
      for (int j = 0; j < Columnas(m); j++) {
        char v;
        is >> v;
        if (v == '1')
          Set(m, i, j, true);
        else if (v == '0')
          Set(m, i, j, false);
        else
          return false;

        }
=======
bool Leer(std::istream& is, MatrizBit& m) {

  int cols, fils;

  is >> cols;
  is >> fils;

  bool init = Inicializar(m, fils, cols);

  for (int i = 0; i < m.Filas(); i++) {
    for (int j = 0; j < m.Columnas(); j++) {
      char v
      is >> v;
      if (v == '1')
        Set(m, i, j, true);
      else
        Set(m, i, j, false);

>>>>>>> f82d344fe3bb72f413415033cadde511b05c276f
    }
    return true;
  }

<<<<<<< HEAD
  else
    return false;
=======
  return init;

>>>>>>> f82d344fe3bb72f413415033cadde511b05c276f
}

bool Escribir(std::ostream& os, const MatrizBit& m) {

<<<<<<< HEAD
  for (int i = 0; i < Filas(m); i++) {
    for (int j = 0; j < Columnas(m); j++) {
=======
  os << Filas(m) << " " << Columnas(m) << endl;

  for (int i = 0; i < m.Filas(); i++) {
    for (int j = 0; j < m.Columnas(); j++) {
>>>>>>> f82d344fe3bb72f413415033cadde511b05c276f
      bool v = Get(m, i, j);
      if (v == true)
        os << '1';
      else
        os << '0';
    }
  }

  return os.fail(); // ?¿?¿?¿

}

bool Leer(const char nombre[], MatrizBit& m) {    // Tenemos  que crear un flujo para que al pasarle el nombre del archivo
                                                  // repita el  mismo proceso que antes

<<<<<<< HEAD
  std::istream f;

=======
  ofstream archivo_matriz(nombre[]);
>>>>>>> f82d344fe3bb72f413415033cadde511b05c276f

}

bool Escribir(const char nombre[], const MatrizBit& m) {



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
