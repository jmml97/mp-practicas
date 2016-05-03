/**
  * Clase Tablero que se encarga de interactuar con Matriz para almacenar los datos del juego
  */

  #include <iostream>
  using namespace std;

  class Tablero {

    private:
      Matriz tablero;
      int alinear,n_turnos, ganador;
      int

    public:

      Tablero(int filas, int columnas, int conectar){

        tablero.SetFilas(filas);
        tablero.SetColumnas(columnas);
        alinear = conectar;
        turno = 0;
        ganador = 0;
      }

      int GetFilas(){
        return tablero.GetFilas();
      }

      int GetColumnas(){
        return tablero.GetColumnas();
      }

      int GetAlinear(){
        return alinear;
      }

      bool HaFinalizado(){          //Método que comprueba si se han conectado N fichas seguidas SIN TERMINAR

      }

      int ConsultaTurno(){
        return turno;
      }
      void AumentaTurno(){
        n_turnos++;
      }

      int ConsultaPuntuacion(){

        return (alinear*10 + ((tablero.GetFilas()*tablero.GetColumnas()/2) - n_turnos))
      }

      void VaciarTablero(){
        tablero.Reset();
      }

      bool InsertarFicha(int columna){    // Se me ocurre o bien comprobar si es una columna válida conno prec.
                                          // o que devuelva un bool que indique lo propio y que en el
                                          // main se vuelva a llamar a este método
        for (int i = tablero.GetFilas(); i >= 0; i--){
          if()                                

        }

      }


  }
