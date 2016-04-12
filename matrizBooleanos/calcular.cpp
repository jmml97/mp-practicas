#include <iostream>
#include "string.h"
#include "matriz_operaciones.h"
#include "matriz_bit.h"

using namespace std;


int main(int argc, char* argv[]) {

  MatrizBit m1, m2, res;
  bool exito_lectura;

  if (strcmp(argv[1], "NOT") == 0 ||strcmp(argv[1], "TRS") == 0) {
    if (argc == 3)
      Leer(argv[2], m1);
    else
      Leer(cin, m1);
  }
  else if (strcmp(argv[1], "AND") == 0 ||strcmp(argv[1], "OR") == 0) {
    if (argc == 3) {
      Leer(argv[2], m2);
      Leer(cin, m1);
    }
    else if (argc == 4) {
      Leer(argv[2], m1);
      Leer(argv[3], m2);
    }
    else {
      Leer(cin, m1);
      Leer(cin, m2);
    }

  }

  cout << "m1: " << endl;
  Escribir(cout, m1);

  if (strcmp(argv[1], "NOT") == 0 )
    Not(res, m1);
  else if (strcmp(argv[1], "TRS") == 0)
    Traspuesta(res, m1);
  else if (strcmp(argv[1], "AND") == 0)
    And(res, m1, m2);
  else if (strcmp(argv[1], "OR") == 0)
    Or(res, m1, m2);



  cout << "res: " << endl;
  Escribir(cout, res);

}
