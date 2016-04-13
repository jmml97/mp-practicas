

#include <iosfwd> // istream,ostream
#include <iostream>
#include <fstream>
#include "matriz_bit.h"
#include "string.h"       // Necesario para funciones strlen, strcpy y strcat

using namespace std;

bool Leer(std::istream& is, MatrizBit& m) {

  // Tenemos que comprobar que los datos del fichero sean valores numéricos o
  // 'X' o '.', y aplicar un tipo de lectura. Para ello comprobamos con is.peek
  // si el siguiente caracter es un espacio en blanco o no y seguiremos leyendo
  // hasta encontrar un caracter que sea ''.' o 'X', para entonces proceder a
  // la lectura. Si no es así, entonces tendremos valores numéricos y el proceso
  // es mucho más sencillo.

  bool exito = true;
  int cols = 0, fils = 0;

  while (isspace(is.peek()))
    is.ignore();

  if (is.peek() == 'X' || is.peek() == '.') {

    char buffer[1000];    // Aquí almacenaremos todos los caracteres.
    char linea[100];      // Aquí almacenaremos cada línea, con tamaño máx. 100.


    is.getline(linea, 100); // Copiamos una línea entera al vector linea.
    cols = strlen(linea);   // El número de columnas será el número de
                            // caracteres de la primera fila.
    fils++;
    strcpy(buffer, linea);  // Copia al principio de buffer el valor de linea.

    // Continuamos leyendo hasta que no haya más 'X' o '.'.
    while ((is.peek() == 'X' || is.peek() == '.') && exito) {
      is.getline(linea, 100);
      strcat(buffer, linea);  // Copia al final de buffer el valor de linea.

      fils++;

      // Si la línea leida no tiene la misma longitud que la primera (número de
      // columnas), la matriz no es válida.
      // Conversión a int porque strlen() devuelve un size_t.
      if (int(strlen(linea)) != cols)
        exito = false;
    }

    if (exito)
      exito = Inicializar(m, fils, cols);

    // Asignamos valores a la matriz según lo que tengamos en el vector.
    for (int i = 0; i < fils; i++) {
      for (int j = 0; j < cols && exito; j++) {
        if (buffer[i*cols + j] == 'X')
          Set(m, i, j, true);
        else if (buffer[i*cols + j] == '.')
          Set(m, i, j, false);
        else
          exito = false;
      }
    }

  }
  else {

    // Primero leemos los valores de las filas y las columnas.
    is >> fils;
    is >> cols;

    // Si se han leído correctamente, procedemos a la inicialización.
    bool exito =  is && Inicializar(m, fils, cols);
    char v; // Aquí almacenaremos el caracter que nos proporcione el flujo.

    // Si todo ha ido correctamente, asignamos a la matriz los valores que nos
    // indica el flujo.
    if (exito) {
      for (int i = 0; i < Filas(m); i++) {
        for (int j = 0; j < Columnas(m); j++) {
          is >> v;
          if (v == '1')
            Set(m, i, j, true);
          else if (v == '0')
            Set(m, i, j, false);
          }
        exito = !is.fail();
      }
    }

  }

  return exito;

}


bool Leer(const char nombre[], MatrizBit& m) {

  // Abrimos el flujo para leer el archivo.
  ifstream archivo_matriz(nombre);
  bool exito = false;

  // Si se ha abierto, pasamos el flujo a la función Leer.
  if (archivo_matriz) {

    exito = Leer(archivo_matriz, m);

  }

  return exito;

}

bool Escribir(std::ostream& os, const MatrizBit& m) {

  // Escribimos las filas y columnas.
  os << Filas(m) << ' ' << Columnas(m) << endl;

  // Dependiendo de los valores del vector, escribimos 0 o 1.
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

  return os.good();

}


bool Escribir(const char nombre[], const MatrizBit& m) {

  // Abrimos el flujo para lescribir el archivo.
  ofstream archivo_matriz(nombre);
  bool exito = false;

  // Si se ha abierto, pasamos el flujo a la función Escribir.
  if (archivo_matriz) {

    exito = Escribir(archivo_matriz, m);

  }

  return exito;

}

void And(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2) {

  bool elemento;

  // Las matrices deben tener el mismo tamaño para realizar operaciones
  // binarias.
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
    cout << "El tamaño de las matrices no coincide." << endl;
  }

}

void Or(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2) {

  bool elemento;

  // Las matrices deben tener el mismo tamaño para realizar operaciones
  // binarias.
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

  for (int i = 0; i < Filas(m); i++) {
    for (int j = 0; j < Columnas(m); j++) {
      Set(res, i, j, !Get(m, i, j));
    }
  }

}

void Traspuesta(MatrizBit& res, const MatrizBit& m) {

  Inicializar(res, Columnas(m), Filas(m));

  for (int i = 0; i < Filas(m); i++) {
    for (int j = 0; j < Columnas(m); j++) {
      Set(res, j, i, Get(m, i, j));
    }
  }

}
