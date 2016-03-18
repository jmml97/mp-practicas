#include <fstream>
#include <iostream>

#include "rectangulo.h"

using namespace std;

void Avanzar(std::istream& is) {
  while (isspace(is.peek()) || is.peek()=='#') {
    if (is.peek()=='#')
      is.ignore(1024,'\n'); // Suponemos una línea tiene menos de 1024
    else is.ignore();
  }
}


Rectangulo RectanguloDelimitador(istream &is) {

  Rectangulo r;
  Punto p1, p2, p;

  Avanzar(is);
  Leer(is, p1);
  Avanzar(is);

  // Guardamos nuestras esquinas como el primer punto que introducimos.
  p1 = p; // Nuestra esquina inferior izquierda
  p2 = p; // Nuestra esquina superior derecha

  while (Leer(is, p)) { // Mientras tenga éxito la lectura

    if (p.x < p1.x) {
      p1.x = p.x;
    } else if (p.x > p2.x) {
      p2.x = p.x;
    }

    if (p.y < p1.y) {
      p1.y = p.y;
    } else if (p.y > p2.y) {
      p2.y = p.y;
    }

    Avanzar(is); // Descarta comentarios y para en siguiente dato

  }

  InicializarRectangulo(r, p1, p2);
  return r;
}

int main(int argc, char* argv[]) {

  Rectangulo mi_rectangulo;
  bool fin_entrada;

  if (argc == 1) { // Si no hemos dado parámetros en la línea de órdenes
    mi_rectangulo = RectanguloDelimitador(cin);
    fin_entrada = cin.eof();
  }
  else {
    ifstream f(argv[1]); // Como parámetro, el nombre del archivo
    if (!f) {
      cerr << "Error: no se abre " << argv[1] << endl;
      return 1;
    }
    mi_rectangulo = RectanguloDelimitador(f);
    fin_entrada = f.eof();
  }

  if (!fin_entrada) {
     cerr << "Error inesperado. No se ha leído toda la entrada" << endl;
     return 1;
  }

  Escribir(cout, mi_rectangulo.esq_inf_izq);
  cout <<  "-";
  Escribir(cout, mi_rectangulo.esq_sup_der);
  cout << endl;

}
