#ifndef jugador_h
#define jugador_h

#include "tablero.hpp"
#include <stdlib.h>

class Jugador {

  private:
    char *nombre;
    int turno;
    int puntuacion;
    int partidas_ganadas;

  public:

    Jugador();
    Jugador(char c[], int t);
    Jugador(char c[], int t, int p, int g);
    Jugador(const Jugador &j);
    ~Jugador();

    Jugador& operator=(const Jugador &j);

    inline char* GetNombre() const {
      return nombre;
    }
    void SetNombre(char c[]);
    void ImprimirNombre(ostream &os) const;

    inline int GetTurno() const {
      return turno;
    }

    inline void SetTurno(int n) {
      turno = n;
    }

    inline int GetPuntuacion() const {
      return puntuacion;
    }

    inline void SetPuntuacion(int n) {
      puntuacion = n;
    }

    inline void AddPuntuacion(int n) {
      puntuacion += n;
    }

    inline int GetPartGan() const {
      return partidas_ganadas;
    }

    inline void SetPartGan(int n) {
      partidas_ganadas = n;
    }

    inline void AddPartGan() {
      partidas_ganadas++;
    }

    void MuestraResultados() const;

    bool EscogeColumna(Tablero& tablero);

};

ostream& operator<<(ostream &os, const Jugador &j);
istream& operator>>(istream &is, Jugador &j);

#endif
