
#ifndef matriz_h
#define matriz_h

/*
  Matriz del tablero mediante memoria estática
*/

class Matriz {

  private:

    int *matriz;
    int filas, columnas;

  public:

    Matriz();
    ~Matriz();
    Matriz(const Matriz &m);

    Matriz& operator=(const Matriz &m);

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
    int Consulta(int posicion);
    void Modifica (int fila, int columna, int valor);

};

#endif
