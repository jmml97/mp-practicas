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
  SetTurno(1);
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

  if (turno == 2)
    turno = 1;

  else
    turno = 2;
}


int Tablero::ContenidoCasilla(int x, int y) {

  return tablero.Consulta(x, y);

}

int Tablero::PartidaFinalizada() {    // int en vez de bool para considerar el caso de empate

  bool terminada = false;
  int resultado;
  int contador = 0;

  for (int i = 0; i < GetColumnas() && !terminada; i++)
    for(int j = 0; j < GetFilas() && !terminada; j++){       // Realizamos las comprobaciones horizontal,
                                                             // vertical y diagonal por ficha

        for(int k = 0; k < GetColumnas() - 1; k++){  // Comparamos cada uno con su siguiente para comprob. horizontal

          if(ContenidoCasilla(j,k) == ContenidoCasilla(j,k+1) && ContenidoCasilla(j,k) != 0){
            contador++;
            if (contador == GetObjetivoFichas())
              terminada = true;
          }
            else
              contador =0;
          }




        if(!terminada) {            // Check columnas
          contador = 0;
          for(int k = 0; k < GetFilas() - 1; k++) {

            if(ContenidoCasilla(j,k) == ContenidoCasilla(j+1,k) && ContenidoCasilla(j,k) != 0) {
              contador++;
              if(contador == GetObjetivoFichas())
                terminada = true;
            }
            else
              contador = 0;
          }
        }


        if (!terminada){            // Diagonal normal
          contador = 0;

          int minimo = GetFilas();

          if (minimo > GetColumnas())
            minimo = GetColumnas();

          for(int k = 0; (i+k < minimo - 1) && (j+k < minimo - 1) && !terminada ; k++){

            if(ContenidoCasilla(j+k,i+k) == ContenidoCasilla(j+k+1,i+k+1) && ContenidoCasilla(j,k) != 0){
              contador++;

              if(contador == GetObjetivoFichas())
                terminada = true;
            }

            else
              contador = 0;

          }
        }

        if(!terminada){           // Diagonal inversa
          contador = 0;

          for(int k = 0; (i+k < GetColumnas() - 1) && (j-k >= 0) && !terminada ; k++){

            if(ContenidoCasilla(j+k,i+k) == ContenidoCasilla(j+k+1,i+k+1) && ContenidoCasilla(j,k) != '0'){
              contador++;

              if(contador == GetObjetivoFichas())
                terminada = true;
            }

            else
              contador = 0;

          }
        }

    }

    resultado = terminada;

    if (tablero.GetUsadas() == GetFilas()*GetColumnas())
      resultado = 2;

    return resultado;

}



void Tablero::PrettyPrint(){

  int columnas = GetColumnas();
  int filas = GetFilas();
  char letra;

  cout << " ";

  for (int i = 0; i < columnas; i++){
    letra = ('a'+i);
    cout << letra << " ";
  }
  cout << endl;

  for (int i = 0; i < filas; i++){

    cout << "|";
    for (int j = 0; j < columnas; j++){

      if (ContenidoCasilla(i,j) == 1)
        cout << "X";
      else if (ContenidoCasilla(i,j) == 2)
        cout << "O";
      else
        cout << " ";

      cout << "|";

    }
    cout << endl;
  }
}



// MÉTODOS QUE MODIFICAN EL TABLERO

bool Tablero::InsertarFicha(int columna) {

  bool colocada = false;

  if (columna < 0 || columna >= GetColumnas())
    return false;

  for (int i = GetFilas() - 1; i >= 0 && !colocada; i--){

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
