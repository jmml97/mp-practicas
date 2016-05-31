/*
  Matriz del tablero mediante memoria estática
*/

#include <iostream>
#include "matriz.hpp"

using namespace std;


Matriz::Matriz() { // Constructor vacío, inicializa a 0

  for (int i = 0; i < 20; i++)
      for (int j = 0; j < 20;j++)
        matriz[i][j] = 0;

  filas = columnas = 0;

}

void Matriz::SetFilas(int fils) {

  filas = fils;

}

void Matriz::SetColumnas(int col) {

  columnas = col;

}

void Matriz::Reset() {

  for (int i = 0; i < 20; i++)
      for (int j = 0; j < 20;j++)
        matriz[i][j] = 0;

}

int Matriz::GetFilas() {

  return filas;

}

int Matriz::GetColumnas() {

  return columnas;

}

// Cambiar a tablero.cpp
int Matriz::GetUsadas() {   // Devuelve el número de fichas usadas, lo usamos para el recuento de puntos y la finalización
                            // de la partida
    int contador = 0;

    for (int i = 0; i < GetFilas(); i++){
      for (int j = 0; j < GetColumnas(); j++){
        if (Consulta(i,j) != 0)
          contador++;
      }
    }

    return contador;
}


int Matriz::Consulta(int fila, int columna) {

  return matriz[fila][columna];

}

void Matriz::Modifica (int fila, int columna, int valor){

  matriz[fila][columna] = valor;

}
