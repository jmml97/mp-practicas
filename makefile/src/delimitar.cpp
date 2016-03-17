/*

  Programa que devuelve, tras la introducción de n puntos, el rectágulo de área mínima que encierra a todos ellos
  INCOMPLETO
*/

#include <fstream>
#include <iostream>
#include "punto.h"
using namespace std;

void Avanzar(std::istream& is){
  while (isspace(is.peek()) || is.peek() == '#') {

    if (is.peek()=='#')
      is.ignore(1024,'\n'); // Suponemos una línea tiene menos de 1024

    else is.ignore();
  }
}


Punto Calc

double Sumatoria(istream& is)     // Le añadimos por referencia un punto y su siguiente para ir
                                  // sumando la distancia entre ellos ??
{
  double s=0, dato;

  Avanzar(is);

  while (is >> dato) { // Mientras tenga éxito la lectura
    s+=dato;
    Avanzar(is); // Descarta comentarios y para en siguiente dato
  }
  return s;
}

int main(int argc, char* argv[])
{
  double sumatoria= 0;
  bool fin_entrada;
  if (argc==1) { // Si no hemos dado parámetros en la línea de órdenes
    sumatoria= Sumatoria(cin);
    fin_entrada=cin.eof();
  }
  else {
    ifstream f(argv[1]); // Como parámetro, el nombre del archivo
    if (!f) {
      cerr << "Error: no se abre " << argv[1] << endl;
      return 1;
    }
    sumatoria=Sumatoria(f);
    fin_entrada=f.eof();
  }

  if (!fin_entrada) {
     cerr << "Error inesperado. No se ha leído toda la entrada" << endl;
     return 1;
  }
  cout << "Sumatoria de la entrada: " << sumatoria << endl;
}
