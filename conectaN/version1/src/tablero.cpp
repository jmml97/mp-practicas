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

void Tablero::CambiaTurno(){

  if (turno == 2)
    turno = 1;

  else
    turno = 2;
}

bool Tablero::InsertarFicha(int columna) {

  bool colocada = false;

  for (int i = tablero.GetFilas() - 1; i >= 0 && !colocada; i--){

    if (ContenidoCasilla(i,columna - 1) == 0 ) {

      tablero.Modifica(i,columna - 1, GetTurno());
      colocada = true;
    }
  }

  return colocada;
}

void Tablero::VaciarTablero() {

  tablero.Reset();

}

int Tablero::ContenidoCasilla(int x, int y) {

  return tablero.Consulta(x, y);

}

bool Tablero::PartidaFinalizada() {

  bool terminada = false;
  int contador = 0;

  for (int i = 0; i < tablero.GetColumnas() && !terminada; i++)
    for(int j = 0; j < tablero.GetFilas() && !terminada; j++){       // Realizamos las comprobaciones horizontal, vertical y diagonal por ficha

        for(int k = 0; k < tablero.GetColumnas() - 1; k++){  // Comparamos cada uno con su siguiente para comprob. horizontal

          if(ContenidoCasilla(j,k) == ContenidoCasilla(j,k+1)){
            contador++;
            if (contador == GetObjetivoFichas())
              terminada = true;

            else
              contador =0;
          }
        }

        contador = 0;

        for(int k = 0; k < tablero.GetFilas() - 1; k++) {

          if(ContenidoCasilla(j,k) == ContenidoCasilla(j+1,k)) {
            contador++;
            if(contador == GetObjetivoFichas())
              terminada = true;
          }
          else
            contador = 0;
        }

        contador = 0;

        for(int k = 0; k < tablero.GetFilas() -1 || k < tablero.GetColumnas() -1; k++){

          if(ContenidoCasilla(k,k))
        }


    }

}

Tablero::Tablero(int filas, int columnas, int objetivo) {

  tablero.SetFilas(filas);
  tablero.SetColumnas(columnas);
  SetObjetivoFichas(objetivo);
  SetTurno(0);
  ganador = 0;

}
