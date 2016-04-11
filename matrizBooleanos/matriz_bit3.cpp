
/** Versión nº1 de Matriz_bit,matriz 10 x 10 que tiene i,j filas/columnas usables
  *
  */

#include "matriz_bit3.h"

bool Inicializar(MatrizBit& m, int fils, int cols) {

  if (fils * cols <= 100) {                       // Devuelve true si el tamaño es correcto

    m.filas_columnas = ((m.filas_columnas|fils)<<16)|cols;

    for (int i = 0; i < fils * cols; i++){

      m.bool_matrix[i] = '0';

    }

    return true;
  }

  else
    return false;
}

int Filas(const MatrizBit& m) {

  int filas = 0;

  // Extraemos los 16 últimos bits del entero filas_columnas, que se
  // corresponden a las filas.

  for (int i = 16; i < 32; i++) {
    if ((m.filas_columnas&(1<<i)) != 0)
      filas = filas|(1<<(i-16));
  }

  return filas;

}

int Columnas(const MatrizBit& m) {

  int columnas;

  // Extraemos los 16 primeros bits del entero filas_columnas, que se
  // corresponden a las columnas.

  for (int i = 0; i < 16; i++) {
    if ((m.filas_columnas&(1<<i)) != 0)
      columnas = columnas|(1<<(i));
  }

  return columnas;

}

bool Get(const MatrizBit& m, int f, int c) {

  // Obtenemos la posición correcta y devolvemos según el valor de esa
  // posición.
  if (m.bool_matrix[f*Columnas(m)] + c == '1')
    return true;
  else
    return false;

}

void Set(MatrizBit& m, int f, int c, bool v) {

  // Obtenemos la posición correcta y fijamos el valor según nos indiquen.
  if (v)
    m.bool_matrix[f*Columnas(m) + c] = '1';
  else
    m.bool_matrix[f*Columnas(m) + c] = '0';

}
