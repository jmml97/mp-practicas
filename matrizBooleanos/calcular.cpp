#include <iostream>
#include "string.h"
#include "matriz_operaciones.h"
#include "matriz_bit.h"

using namespace std;


int main(int argc, char* argv[]) {

  MatrizBit m1, m2, res;

  int se_ha_leido = false;

  if (!strcmp(argv[1], "NOT") || !strcmp(argv[1], "TRS")) {
    if (argc == 3) {
      if(Leer(argv[2], m1))
        se_ha_leido = true;
    }
    else
      if(Leer(cin, m1))
        se_ha_leido = true;
  }
  else if (!strcmp(argv[1], "AND")||strcmp(argv[1], "OR")) {
    if (argc == 3) {
      if(Leer(argv[2], m2) && Leer(cin, m1))
        se_ha_leido = true;
    }
    else if (argc == 4) {
      if(Leer(argv[2], m1) && Leer(argv[3], m2))
        se_ha_leido = true;
    }
    else {
      if(Leer(cin, m1) && Leer(cin, m2))
        se_ha_leido = true;
    }

  }

/*
  cout << "m1: " << endl;
  Escribir(cout, m1);

  Estas líneas de mensaje las podemos suprimir por si queremos
  usar el resultado como entrada de otra operación con un pipe
*/

  if (se_ha_leido) {
    if (!strcmp(argv[1], "NOT"))
      Not(res, m1);
    else if (!strcmp(argv[1], "TRS"))
      Traspuesta(res, m1);
    else if (!strcmp(argv[1], "AND"))
      And(res, m1, m2);
    else if (!strcmp(argv[1], "OR"))
      Or(res, m1, m2);



  // cout << "res: " << endl;       Igual que hemos explicado ahí arriba
  Escribir(cout, res);
  }

  else
    std::cout << "\nSe ha producido un error en la lectura" << std::endl;
}
