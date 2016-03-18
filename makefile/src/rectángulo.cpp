
#include <iostream>
#include "punto.h"

using namespace std;

bool Leer(std::istream& is, Rectangulo& r) {    // Le pasamos un réctángulo para leerlo por teclado

  is.ignore();
  is >> r.esq_inf_izq.x;
  is.ignore();
  is >> r.esq_inf_izq.y;
  is.ignore();
  is >> r.esq_sup_der.x;
  is.ignore();
  is >> r.esq_sup_der.y;

  return is;

}

bool Escribir(ostream& os, const Rectangulo& r);      // Muestra un rectángulo como dos puntos unidos por un guión

  os << "(" << r.esq_inf_izq.x << "," << r.esq_inf_izq.y << ")-(" << r.esq_sup_der.x << "," << r.esq_sup_der.y;

  return os.fail();

}


void InicializarRectangulo (Rectangulo& r, const Punto& p1, const Punto& p2) {

  double min_x, min_y, max_x, max_y;                // Pasemos los puntos que le pasemos podemos obtener sus
                                                    // esquinas a partir de el valor de sus coordenadas
  if (p1.x < p2.x) {                                // Básicamente buscamos las x e y de menor y mayor valor para buscar la
    min_x = p1.x;                                   // esquina independientemente de los puntos dados
    max_x = p2.x;
  }

  else  {
    min_x = p2.x;
    max_x = p1.x;
  }

  if (p1.y < p2.y){
    min_y = p1.y;
    max_y = p2.y;
  }

  else  {
    min_y = p2.y;
    max_y = p1.y;
  }

  r.esq_inf_izq.x = min_x;                  // Probablemente haya un modo "más estético" de hacerlo, pero este parece bastante
  r.esq_inf_izq.y = min_y;                  // simple y comprensible
  r.esq_sup_der.x = max_x;
  r.esq_sup_der.y = max_y;

}

Punto InferiorIzquierda (const Rectangulo& r){    // Devuelve esq_inf_izq

  return r.esq_inf_izq;
}
Punto SuperiorDerecha (const Rectangulo& r){    // Devuelve esq_sup_der

  return r.esq_sup_der;
}

double Area(const Rectangulo& r){

  double area;

  area = (r.esq_sup_der.x - r.esq_inf_izq.x) * (r.esq_sup_der.y - r.esq_inf_izq.y);   // Base por altura

  return area;
}

bool Interior (const Punto& p, const Rectangulo& r) {     // Si esto falla igual sería buena idea hacer booleanos intermedios
                                                          // Si esq_inf.coord <= p1.coord <= esq_sup.coord entonces está dentro

  return (p.x <= r.esq_sup_der.x && p.x >= r.esq_inf_izq.x ) && (p.y <= r.esq_sup_der.y && p.y >= r.esq_inf_izq.y)
}
