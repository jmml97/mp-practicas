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
  Punto p1, p2;

  Avanzar(is);
  Leer(is, p1);
  Avanzar(is);

  while (Leer(is, p2)) { // Mientras tenga éxito la lectura

    // Si el punto está en el cuadrante inferior respecto de la esquina inferior
    // izquierda, se cambia la esquina a ese punto.
    // Si el punto está en el cuadrante superior respecto de la esquina superior
    // derecha, se cambia la esquina a ese punto

    if (p2.x < r.esq_inf_izq.x) {
      r.esq_inf_izq.x = p2.x;
    } else if (p2.x > r.esq_sup_der.x) {
      r.esq_sup_der.x = p2.x;
    }

    if (p2.y < r.esq_inf_izq.y) {
      r.esq_inf_izq.y = p2.y;
    } else if (p2.y > r.esq_sup_der.y) {
      r.esq_sup_der.y = p2.y;
    }

    InicializarRectangulo(r, p1, p2);
    Avanzar(is); // Descarta comentarios y para en siguiente dato

  }

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
  Escribir(cout, mi_rectangulo.esq_sup_der);
  cout << endl;

}
