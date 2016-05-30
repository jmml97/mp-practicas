/*
  Clase Tablero que se encarga de interactuar con Matriz para almacenar los datos del juego
*/

#include <iostream>
#include "tablero.h"

using namespace std;


Tablero::Tablero(int filas, int columnas, int objetivo) {

  tablero.SetFilas(filas);
  tablero.SetColumnas(columnas);
  SetObjetivoFichas(objetivo);
  SetTurno(2);
  ganador = 0;

}

int Tablero::GetFilas() {

  return tablero.GetFilas();

}

int Tablero::GetColumnas() {

  return tablero.GetColumnas();

}

int Tablero::GetObjetivoFichas() {

  return objetivo_fichas;

}

void Tablero::SetObjetivoFichas(int objetivo) {

  objetivo_fichas = objetivo;

}

int Tablero::GetTurno() {

  return turno;

}

void Tablero::SetTurno(int n) {

  turno = n;

}

int Tablero::GetPuntuacion() {

  return (objetivo_fichas*10 + ((GetFilas()*GetColumnas()/2) - tablero.GetUsadas()));

}

int Tablero::GetGanador() {

  return ganador;

}

void Tablero::SetGanador() {   // Establece el ganador si la partida ha finalizado

    ganador = GetTurno();

}

void Tablero::CambiaTurno(){

  turno = turno == 2 ? 1 : 2;

}


int Tablero::ContenidoCasilla(int x, int y) {

  return tablero.Consulta(x, y);

}

bool Tablero::HayNHorizontal(int fil, int col) {

  for (int i = 0; i < GetObjetivoFichas() - 1; i++)
    if (ContenidoCasilla(fil, col + i) != ContenidoCasilla(fil, col + i + 1))
      return false;

  return true;

}

bool Tablero::HayNVertical(int fil, int col) {

  for (int i = 0; i < GetObjetivoFichas() - 1; i++)
    if (ContenidoCasilla(fil + i, col) != ContenidoCasilla(fil + i + 1, col))
      return false;

  return true;

}

bool Tablero::HayNDiagonal(int fil, int col) {

  for (int i = 0; i < GetObjetivoFichas() - 1; i++)
    if (ContenidoCasilla(fil + i, col + i ) != ContenidoCasilla(fil + i + 1, col + i + 1))
      return false;

  return true;

}

bool Tablero::HayNDiagonalInv(int fil, int col) {

  for (int i = 0; i < GetObjetivoFichas() - 1; i++)
    if (ContenidoCasilla(fil - i, col + i ) != ContenidoCasilla(fil - i - 1, col + i + 1))
      return false;

  return true;

}

bool Tablero::HayNEnLinea() {

  int n = GetObjetivoFichas();

  for (int fil = 0; fil < GetFilas(); fil++) {
    for (int col = 0; col < GetColumnas(); col++) {

      if (ContenidoCasilla(fil, col) != 0) {

        if (col <= GetColumnas() - n && HayNHorizontal(fil, col))
          return true;
        if (fil <= GetFilas() - n && HayNVertical(fil, col))
          return true;
        if(col <= GetColumnas() - n&& fil <= GetFilas() - n && HayNDiagonal(fil, col))
          return true;
        if (col <= GetColumnas() - n && fil >= n - 1 && HayNDiagonalInv(fil, col))
          return true;

      }

    }
  }

  return false;
}

int Tablero::PartidaFinalizada() {

  if (HayNEnLinea())
    return 1;
  if (tablero.GetUsadas() == GetFilas() * GetColumnas())
    return 2;
  else
    return 0;

}

void Tablero::PrettyPrint(){

  char letra;

  cout << " ";

  for (int i = 0; i < GetColumnas(); i++){
    letra = ('a'+i);
    cout << letra << " ";
  }
  cout << endl;

  for (int i = GetFilas() - 1; i >= 0; i--){

    cout << "|";
    for (int j = 0; j < GetColumnas(); j++){

      // cout << GetColumnas()*i + j;
      //cout << i << "," << j;


      if (ContenidoCasilla(i,j) == 1)
        cout << "x";
      else if (ContenidoCasilla(i,j) == 2)
        cout << "o";
      else
        cout << " ";

      cout << "|";

    }
    cout << endl;
  }

  for (int i = 0; i < 2*GetColumnas() + 1; i++){
    cout << "=";
  }
  cout << endl;
}



// MÉTODOS QUE MODIFICAN EL TABLERO

bool Tablero::InsertarFicha(int columna) {

  if (columna < 0 || columna >= GetColumnas())
    return false;

  for (int i = 0; i < GetFilas(); i++){

    if (ContenidoCasilla(i, columna) == 0 && ContenidoCasilla(i + 1, columna) == 0) {
      tablero.Modifica(i, columna, GetTurno());
      return true;
    }

  }

  return false;
}

void Tablero::VaciarTablero() {

  tablero.Reset();

}
