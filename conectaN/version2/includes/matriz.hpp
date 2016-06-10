
#ifndef matriz_h
#define matriz_h

#include <ostream>

/*
  Matriz del tablero mediante memoria dinámica.
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

    inline void SetFilas(int fils) {
      filas = fils;
    }

    inline int GetFilas() const {
      return filas;
    }

    inline void SetColumnas(int col) {
      columnas = col;
    }

    inline int GetColumnas() const {
      return columnas;
    }

    // Vacía la matriz.
    void Reset();

    // Devuelve el número de elementos de la matriz distintos de 0.
    int GetUsadas();

    inline int Consulta(int fila, int columna) const {
      return matriz[fila*columnas + columna];
    }

    inline int Consulta(int posicion) const {
      return matriz[posicion];
    }

    inline void Modifica (int fila, int columna, int valor) {
      matriz[fila*columnas + columna] = valor;
    }

    inline void Modifica (int posicion, int valor) {
      matriz[posicion] = valor;
    }

};

std::ostream& operator<<(std::ostream &os, const Matriz &m);
std::istream& operator>>(std::istream &is, Matriz &m);

#endif
