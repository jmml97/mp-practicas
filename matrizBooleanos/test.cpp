#include <iostream>
using namespace std;

int main() {

  int dos = 4;
  int tres = 6;
  int cero = 0;

  cero = ((cero|dos)<<16)|tres; // 131075

  cout << cero << endl;

  int primeros = 0, segundos = 0, bit;

  for (int i = 16; i < 32; i++) {
    if ((cero&(1<<i)) != 0)
      primeros = primeros|(1<<(i-16));
  }

  for (int i = 0; i < 16; i++) {
    if ((cero&(1<<i)) != 0)
      segundos = segundos|(1<<(i));
  }

  cout << primeros << endl;
  cout << segundos << endl;

}
