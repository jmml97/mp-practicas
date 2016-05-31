
#ifndef matriz_h
#define matriz_h

#include <ostream>

/*
  Matriz del tablero mediante memoria estática
*/

class Matriz {

  private:

    int *matriz;
    int filas, columnas;

  public:

    Matriz();
    Matriz(int f, int c);
    Matriz(const Matriz &m);

    ~Matriz();

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

    int Consulta(int fila, int columna) const;
    int Consulta(int posicion) const;
    void Modifica (int fila, int columna, int valor);
    void Modifica (int posicion, int valor);

};

std::ostream& operator<<(std::ostream &os, const Matriz &m);
std::istream& operator>>(std::istream &is, Matriz &m);

#endif
