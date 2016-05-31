
#ifndef matriz_h
#define matriz_h

/*
  Matriz del tablero mediante memoria estática
*/

class Matriz {

  private:

    int matriz[20][20];
    int filas, columnas;

  public:

    Matriz();

    void SetFilas(int fils);
    inline int GetFilas() const {
      return filas;
    }

    void SetColumnas(int col);
    inline int GetColumnas() const {
      return columnas;
    }

    void Reset();
    int GetUsadas();

    int Consulta(int fila, int columna);
    void Modifica (int fila, int columna, int valor);

};

#endif
