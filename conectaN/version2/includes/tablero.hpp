
#ifndef tablero_h
#define tablero_h

/*
  Clase Tablero que se encarga de interactuar con Matriz para almacenar los datos del juego
*/

#include "matriz.hpp"
#include <iostream>

using namespace std;

class Tablero {

  private:

    Matriz tablero;
    int objetivo_fichas, fichas_por_turno, insertadas_en_turno, turno, ganador;

  public:

    int GetFilas() const;
    int GetColumnas() const;

    inline int GetObjetivoFichas() const {
      return objetivo_fichas;
    }
    void SetObjetivoFichas(int objetivo);
    inline void SetFichasPorTurno(int t) {
      fichas_por_turno = t;
    }

    inline int GetFichasPorTurno() const{
      return fichas_por_turno;
    }

    inline int GetInsertadasEnTurno() const {
      return insertadas_en_turno;
    }

    inline void SetInsertadasEnturno(int i) {
      insertadas_en_turno = i;
    }

    inline void AumentarInsertadasEnTurno() {
      insertadas_en_turno++;
    }

    inline void ResetInsertadasEnTurno() {
      insertadas_en_turno = 0;
    }

    inline int GetTurno() const {
      return turno;
    }
    void SetTurno(int n);
    void CambiaTurno();

    int GetPuntuacion();

    inline int GetGanador() const {
      return ganador;
    }
    void SetGanador();

    int ContenidoCasilla(int x, int y) const;
    void PrettyPrint(ostream &os = cout);

    bool HayNHorizontal(int fil, int col);
    bool HayNVertical(int fil, int col);
    bool HayNDiagonal(int fil, int col);
    bool HayNDiagonalInv(int fil, int col);
    bool HayNEnLinea();
    int PartidaFinalizada();

    bool InsertarFicha(int columna);
    void VaciarTablero();

    void LeerMatrizTablero(istream &is);
    void EscribirMatrizTablero(ostream &os) const;

    Tablero();
    Tablero(int filas, int columnas, int objetivo, int fichas_turno);

};

ostream& operator<<(ostream &os, const Tablero &t);
istream& operator>>(istream &is, Tablero &t);

#endif
