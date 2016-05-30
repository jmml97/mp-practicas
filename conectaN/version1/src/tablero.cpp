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

  if (turno == 2)
    turno = 1;

  else
    turno = 2;
}


int Tablero::ContenidoCasilla(int x, int y) {

  return tablero.Consulta(x, y);

}

int Tablero::PartidaFinalizada() {    // int en vez de bool para considerar el caso de empate

  int terminada = 0;
  int contador = 0;

  for (int i = 0; i < GetColumnas() && terminada != 1; i++)
    for(int j = 0; j < GetFilas() && terminada != 1; j++){       // Realizamos las comprobaciones horizontal,
                                                             // vertical y diagonal por ficha

        for (int k = 0; k < GetColumnas() - 1; k++){  // Comparamos cada uno con su siguiente para comprob. horizontal

          if(ContenidoCasilla(j,k) != 0 && ContenidoCasilla(j,k) == ContenidoCasilla(j,k+1)){
            contador++;
            cout << "Comprobación horizontal----------" << endl;
            cout << "contador: " << contador << endl;
            if (contador == GetObjetivoFichas())
              terminada = 1;
          }

          else
            contador = 0;
        }

        if(terminada != 1) {            // Check columnas
          contador = 0;
          for(int k = 0; k < GetFilas() - 1; k++) {

            if(ContenidoCasilla(j,k) != 0 && ContenidoCasilla(j,k) == ContenidoCasilla(j+1,k)) {
              contador++;
              cout << "Comprobación vertical----------" << endl;
              cout << "contador: " << contador << endl;
              if(contador == GetObjetivoFichas())
                terminada = 1;
            }
            else
              contador = 0;
          }
        }

        if (terminada != 1){            // Diagonal normal
          contador = 0;

          int minimo = GetFilas();

          if (minimo > GetColumnas())
            minimo = GetColumnas();

          for(int k = 0; (i+k < minimo - 1) && (j+k < minimo - 1) && terminada != 1 ; k++){

            if(ContenidoCasilla(j+k,i+k) == ContenidoCasilla(j+k+1,i+k+1) && ContenidoCasilla(j,k) != 0){
              contador++;
              cout << "Comprobación diagonal----------" << endl;
              cout << "contador: " << contador << endl;

              if(contador == GetObjetivoFichas())
                terminada = 1;
            }

            else
              contador = 0;

          }
        }

        if (terminada != 1){           // Diagonal inversa
          contador = 0;

          if (j > 0 && ContenidoCasilla(i,j) != 0 && ContenidoCasilla(i,j) == ContenidoCasilla(i+1, j-1)) {

            contador++;
            cout << "Comprobación diagonal inversa----------" << endl;
            cout << "contador: " << contador << endl;

            if(contador == GetObjetivoFichas())
              terminada = 1;

          }
          else
            contador = 0;

          for(int k = 0; (i+k <= GetColumnas()) && (j-k >= 0) && terminada != 1 ; k++){

            if(ContenidoCasilla(j+k,i+k) == ContenidoCasilla(j+k+1,i+k+1) && ContenidoCasilla(j,k) != '0'){
              contador++;
              cout << "Comprobación diagonal inversa----------" << endl;
              cout << "contador: " << contador << endl;

              if(contador == GetObjetivoFichas())
                terminada = 1;
            }

            else
              contador = 0;

          }

        }

    }

    if (tablero.GetUsadas() == GetFilas()*GetColumnas())
      terminada = 2;

    return terminada;

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
