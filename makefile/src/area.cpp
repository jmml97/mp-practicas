#include <iostream>
#include "circulo.h"
using namespace std;

int main() {

  Circulo c;

  c = LeerCirculo();

  cout << "El área del círculo es: " << Area(c) << endl;

}
