
/** Versión nº1 de Matriz_bit,matriz 10 x 10 que tiene i,j filas/columnas usables
  *
  */

  struct MatrizBit{

    bool bool_matrix[10][10];
    int filas = 0;
    int columnas = 0;
  };


  bool Inicializar(MatrizBit& m, int fils, int cols) {

    if (fils <= 10 && cols <= 10) {                       // Devuelve true si el tamaño es correcto

      filas = fils;
      columnas = cols;

      for (int i = 0; i < filas; i++){

        for (int j = 0; j < columnas; j++)
          bool_matrix[i][j] = false;
      }

      return true;
    }

    else
      return false;
  }
