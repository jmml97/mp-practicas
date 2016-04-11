
/** Versión nº1 de Matriz_bit,matriz 10 x 10 que tiene i,j filas/columnas usables
  *
  */

#include "matriz_bit1.h"

bool Inicializar(MatrizBit& m, int fils, int cols) {

  if (fils <= 10 && cols <= 10) {      // Devuelve true si el tamaño es correcto

    m.filas = fils;
    m.columnas = cols;

    for (int i = 0; i < m.filas; i++){

      for (int j = 0; j < m.columnas; j++)
        m.bool_matrix[i][j] = false;
    }

    return true;
  }

  else
    return false;
}

int Filas(const MatrizBit& m) {

  return m.filas;

}

int Columnas(const MatrizBit& m) {

  return m.columnas;

}

bool Get(const MatrizBit& m, int f, int c) {

  return m.bool_matrix[f][c];

}

void Set(MatrizBit& m, int f, int c, bool v) {

  m.bool_matrix[f][c] = v;

}
