#ifndef jugador_h
#define jugador_h

#include "tablero.hpp"

class Jugador {

  private:
    char *nombre;
    int turno;
    int puntuacion;
    int partidas_ganadas;

  public:

    inline char* GetNombre() const {
      return nombre;
    }
    void SetNombre(char c[]);
    void ImprimirNombre() const;

    inline int GetTurno() const {
      return turno;
    }
    void SetTurno(int n);

    inline int GetPuntuacion() const {
      return puntuacion;
    }
    void SetPuntuacion(int n);
    void AddPuntuacion(int n);

    void SetPartGan(int n);
    inline int GetPartGan() const {
      return partidas_ganadas;
    }
    void AddPartGan();

    void MuestraResultados();

    bool EscogeColumna(Tablero& tablero);

    Jugador(char c[], int t);
    Jugador(char c[], int t, int p, int g);
    Jugador(const Jugador &j);
    ~Jugador();

    Jugador operator=(const Jugador &j) const;

};

ostream& operator<<(ostream &os, const Jugador &j);
istream& operator>>(istream &is, Jugador &j);

#endif
