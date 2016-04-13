#include <iostream>
#include "string.h"
#include "matriz_operaciones.h"
#include "matriz_bit.h"

using namespace std;


int main(int argc, char* argv[]) {

  MatrizBit m1, m2, res;

  bool exito_lectura = false;

  if (!strcmp(argv[1], "NOT") || !strcmp(argv[1], "TRS")) {
    if (argc == 3)
      exito_lectura = Leer(argv[2], m1);
    else
      exito_lectura = Leer(cin, m1);
  }
  else if (!strcmp(argv[1], "AND") || !strcmp(argv[1], "OR")) {
    if (argc == 3)
      exito_lectura = Leer(argv[2], m2) && Leer(cin, m1);
    else if (argc == 4)
      exito_lectura = Leer(argv[2], m1) && Leer(argv[3], m2);
    else
      exito_lectura = Leer(cin, m1) && Leer(cin, m2);
  }

  if (exito_lectura) {
    if (!strcmp(argv[1], "NOT"))
      Not(res, m1);
    else if (!strcmp(argv[1], "TRS"))
      Traspuesta(res, m1);
    else if (!strcmp(argv[1], "AND"))
      And(res, m1, m2);
    else if (!strcmp(argv[1], "OR"))
      Or(res, m1, m2);

    Escribir(cout, res);
  }
  else
    cout << "\n Se ha producido un error en la lectura" << endl;
}
