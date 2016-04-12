

#include <iosfwd> // istream,ostream
#include <iostream>
#include <fstream>
#include "matriz_bit.h"

using namespace std;

bool Leer(std::istream& is, MatrizBit& m) {
                                                // Tenemos que comprobar que los datos del fichero sean valores numéricos
                                                // o 'X' o '.', y aplicar un tipo de lectura, comprobamos con is.peek si
                                                // es espacio en blanco o no y seguir leyendo hasta encontrar un caracter
                                                // que sea '.' o 'X', para entonces proceder al siguiente método:
                                                // Creamos un vector char que nos sirva de buffer para leer posteriormente
                                                // la matriz. Con is.getline obtenemos la fila, al ser la primera la
                                                // metemos en nuestro buffer con is.strcpy, aumentamos el numero de filas
                                                // y vamos concatenando las siguientes filas con strcat
   while (isspace(is.peek()))
      is.ignore();

   if (is.peek() == 'X' || is.peek() == '.') {

     int filas = 0 , columnas = 0, check;

     char buffer[1000];
     char linea[100];
     is.getline(linea,100);
     columnas = strlen(linea)
     filas++;
     strcpy(buffer,linea);

     while (is.peek() == 'X' || is.peek() == '.') {
       is.getline(linea,100);
       strcat(buffer,linea);

       filas++;
       check = strlen(linea);
       if (check != columnas)
        returne false;
     }


     // Falta recorrer uno a uno los elementos del vector buffer e ir asignandolos con un Set() a la matriz m



   }

  else {
    int cols, fils;

    is >> fils;
    is >> cols;

    bool exito =  is && Inicializar(m, fils, cols);
    //cout << "filas: " << Filas(m) << endl;
    //cout << "columnas: " << Columnas(m) << endl;

    if (exito) {
      for (int i = 0; i < Columnas(m); i++) {
        for (int j = 0; j < Filas(m); j++) {
          char v;
          is >> v;
          if (v == '1')
            Set(m, i, j, true);
            else
            Set(m, i, j, false);

          }
            exito = !is.fail();
          }
          exito = true;
        }
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

    cout << endl;
  }

  return !os.fail();

}

bool Leer(const char nombre[], MatrizBit& m) {

  ifstream archivo_matriz(nombre);
  bool exito = false;

  if (archivo_matriz) {

    exito = Leer(archivo_matriz, m);

  }

  return exito;

}

bool Escribir(const char nombre[], const MatrizBit& m) {

  ofstream archivo_matriz(nombre);
  bool exito = archivo_matriz.is_open();

  if (exito) {

    exito = Escribir(archivo_matriz, m);

  }

  return exito;

}

void And(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2) {

  bool elemento;

  if ((Filas(m1) == Filas(m2)) && (Columnas(m1) == Columnas(m2))) {

    Inicializar(res, Filas(m1), Columnas(m1));

    for (int i = 0; i < Filas(m1); i++) {
      for (int j = 0; j < Columnas(m1); j++) {
        elemento = Get(m1, i, j) && Get(m2, i, j);
        Set(res, i, j, elemento);

      }
    }
  }
  else {
    std::cout << "El tamaño de las matrices no coincide." << endl;
  }

}

void Or(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2) {

  bool elemento;

  if ((Filas(m1) == Filas(m2)) && (Columnas(m1) == Columnas(m2))) {

    Inicializar(res, Filas(m1), Columnas(m1));

    for (int i = 0; i < Filas(m1); i++) {
      for (int j = 0; j < Columnas(m1); j++) {
        elemento = Get(m1, i, j) || Get(m2, i, j);
        Set(res, i, j, elemento);

      }
    }
  }
  else {
    cout << "El tamaño de las matrices no coincide." << endl;
  }

}


void Not(MatrizBit& res, const MatrizBit& m) {

  Inicializar(res, Filas(m), Columnas(m));

  for (int i = 0; i < Filas(m); i++)
    for (int j = 0; j < Columnas(m); j++)
      Set(res, i, j, !Get(m, i, j));

}

void Traspuesta(MatrizBit& res, const MatrizBit& m) {

  Inicializar(res, Columnas(m), Filas(m));

  for (int i = 0; i < Filas(m); i++) {
    for (int j = 0; j < Columnas(m); j++) {
      Set(res, j, i, Get(m, i, j));

    }
  }

}
