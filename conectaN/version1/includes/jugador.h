#ifndef jugador_h
#define jugador_h
#include "tablero.h"

class Jugador {

  private:
    char nombre[50];
    int turno;
    int puntuacion;
    int partidas_ganadas;

  public:

    char GetNombre();
    void SetNombre(char c[]);
    void CoutNombre();

    int GetTurno();
    void SetTurno(int n);

    int GetPuntuacion();
    void SetPuntuacion(int n);
    void AddPuntuacion(int n);

    void SetPartGan(int n);
    int GetPartGan();
    void AddPartGan();

    void MuestraResultados();

    void EscogeColumna(Tablero& tablero);

    Jugador(char c[], int t);

};

#endif
