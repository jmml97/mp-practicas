
#ifndef tablero_h

#define tablero_h

/*
  Clase Tablero que se encarga de interactuar con Matriz para almacenar los datos del juego
*/

#include "matriz.h"

class Tablero {

  private:

    Matriz tablero;
    int objetivo_fichas, turno, ganador;

  public:

    int GetFilas();
    int GetColumnas();

    int GetObjetivoFichas();
    void SetObjetivoFichas(int objetivo);

    int GetTurno();
    void SetTurno(int n);

    int GetPuntuacion();

    int GetGanador();
    void SetGanador(int n);

    bool InsertarFicha(int columna);
    void VaciarTablero();
    int ContenidoCasilla(int x, int y);
    bool PartidaFinalizada();
    void PrettyPrint();

    Tablero(int filas, int columnas, int objetivo);


};

#endif
