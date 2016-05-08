/*
  Clase Tablero que se encarga de interactuar con Matriz para almacenar los datos del juego
*/

#include <iostream>
#include "tablero.h"

using namespace std;

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

  return (objetivo_fichas*10 + ((tablero.GetFilas()*tablero.GetColumnas()/2) - turno));

}

int Tablero::GetGanador() {

  return ganador;

}

void Tablero::SetGanador(int n) {

  ganador = n;

}

bool Tablero::InsertarFicha(int columna) {



}

void Tablero::VaciarTablero() {

  tablero.Reset();

}

int Tablero::ContenidoCasilla(int x, int y) {

  return tablero.Consulta(x, y);

}

bool Tablero::PartidaFinalizada() {



}

Tablero::Tablero(int filas, int columnas, int objetivo) {

  tablero.SetFilas(filas);
  tablero.SetColumnas(columnas);
  SetObjetivoFichas(objetivo);
  SetTurno(0);
  ganador = 0;

}
