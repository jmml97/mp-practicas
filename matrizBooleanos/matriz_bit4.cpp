
/** Versión nº1 de Matriz_bit,matriz 10 x 10 que tiene i,j filas/columnas usables
  *
  */

  struct MatrizBit{

    unsigned int bool_matrix[4];
    unsigned short int filas_columnas = 0;

  };


  bool Inicializar(MatrizBit& m, int fils, int cols) {

    if (fils * cols <= 128) {                       // Devuelve true si el tamaño es correcto

      m.filas_columnas = ((m.filas_columnas|fils)<<8)|cols;

      for (int i = 0; i < (fils * cols) / 32; i++) {

        m.bool_matrix[i] = 0;

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

    for (int i = 8; i < 16; i++) {
      if ((m.filas_columnas&(1<<i)) != 0)
        filas = filas|(1<<(i-8));
    }

    return filas;

  }

  int Columnas(const MatrizBit& m) {

    int columnas;

    // Extraemos los 16 primeros bits del entero filas_columnas, que se
    // corresponden a las columnas.

    for (int i = 0; i < 8; i++) {
      if ((m.filas_columnas&(1<<i)) != 0)
        columnas = columnas|(1<<(i));
    }

    return columnas;

  }

  bool Get(const MatrizBit& m, int f, int c) {

    // Obetenemos el bit al que corresponde la fila y columna especificada
    // (del total de 128).
    // num será el índice del vector de int en el que almacenamos nuestra
    // matriz de booleanos.
    int bit = f * Columnas(m) + c;
    int num = bit / 32;

    // Si el bit correspondiente es un 0, devolvemos false. Si es distinto de
    // 0, devolvemos true.
    if ((m.bool_matrix[num]&(1<<(bit-32*num))) == 0)
      return false;
    else
      return true;

  }

  void Set(MatrizBit& m, int f, int c, bool v) {

    // Obetenemos el bit al que corresponde la fila y columna especificada
    // (del total de 128).
    // num será el índice del vector de int en el que almacenamos nuestra
    // matriz de booleanos.
    int bit = f * Columnas(m) + c;
    int num = bit / 32;

    // Si el valor que queremos asignar es true, ponemos un 1 en el bit
    // correspondiente. Si es false, ponemos un 0.
    if (v)
      m.bool_matrix[num] = m.bool_matrix[num]|(1<<(bit-32*num));
    else
      m.bool_matrix[num] = m.bool_matrix[num]&~(1<<(bit-32*num));

  }
