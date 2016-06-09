
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

    Tablero();
    Tablero(int filas, int columnas, int objetivo, int fichas_turno);

    inline int GetFilas() const {
      return tablero.GetFilas();
    }

    inline int GetColumnas() const {
      return tablero.GetColumnas();
    }

    inline int GetObjetivoFichas() const {
      return objetivo_fichas;
    }

    inline void SetObjetivoFichas(int objetivo) {
      objetivo_fichas = objetivo;
    }

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

    inline void SetTurno(int n) {
      turno = n;
    }

    void CambiaTurno();

    inline int GetGanador() const {
      return ganador;
    }

    void SetGanador();

    int GetPuntuacion();

    // Consulta del trablero.
    inline int ContenidoCasilla(int x, int y) const {
        return tablero.Consulta(x, y);
    }

    // Comprobación de las N fichas en línea de las distintas formas.
    bool HayNHorizontal(int fil, int col);
    bool HayNVertical(int fil, int col);
    bool HayNDiagonal(int fil, int col);
    bool HayNDiagonalInv(int fil, int col);

    // Comprueba si hay N fichas en línea. Recorre el tablero y cuando llega a // una ficha, comprueba si hay n fichas adyacentes en línea (de todas las
    // formas posibles).
    bool HayNEnLinea();

    // Comprueba si la partida ha finalizado.
    int PartidaFinalizada();

    bool InsertarFicha(int columna);

    inline void VaciarTablero() {
      tablero.Reset();
    }

    inline void LeerMatrizTablero(istream &is) {
      is >> tablero;
    }
    
    inline void EscribirMatrizTablero(ostream &os) const {
      os << tablero;
    }

    // Impresión del tablero.
    void PrettyPrint(ostream &os = cout);

};

ostream& operator<<(ostream &os, const Tablero &t);
istream& operator>>(istream &is, Tablero &t);

#endif
