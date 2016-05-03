/**
  * Matriz del tablero mediante memoria estática
  */

#include <iostream>
using namespace std;

class Matriz {

  private:

    int matriz[20][20];
    int filas, columnas;

  public:

    Matriz (){                      // Constructor vacío, inicializa a 0

      for (int i = 0; i < 20; i++){
          for (int j = 0; j < 20;j++){

            matriz[i][j] = 0;
          }
      }
      filas = columnas = 0;
    }

    void SetFilas(int fils){
      filas = fils;
    }

    void SetColumnas(int col){
      columnas = col;
    }

    void Reset(){
      for (int i = 0; i < 20; i++){
          for (int j = 0; j < 20;j++){

            matriz[i][j] = 0;
          }
    }
  }

    int GetFilas(){
      return filas;
    }
    int GetColumnas() {
      return columnas;
    }


    int Consulta(int fila, int columna){

      return matriz[fila][columna];
    }

    void Modifica (int fila, int columna, int valor){

      matriz[fila][columna] = valor;
    }
};
