#include <iostream>
#include <cmath>

#include "punto.h"

using namespace std;

// OBSOLETO
Punto LeerPunto()
{

  Punto p;
  char c;

  cin >> c >> p.x >> c >> p.y >> c;

  return p;

}

void EscribirPunto (const Punto& p)
{

  cout << "(" << p.x <<"," << p.y << ")" << endl;

}

bool Leer(std::istream& is, Punto& p) {

  is.ignore();
  is >> p.x;
  is.ignore();
  is >> p.y;
  is.ignore();

  return is;

}

bool Escribir(std::ostream& os, const Punto& p) {

  os << "(" << p.x << "," << p.y << ")";

  return os.fail();

}

void InicializarPunto (Punto &p, double cx, double cy)
{

  p.x = cx;
  p.y = cy;

}

double GetX (const Punto& p)
{

  return p.x;

}

double GetY (const Punto& p)
{

  return p.y;

}

double Distancia (const Punto& p1, const Punto& p2)
{

  double a = (p2.x - p1.x) * (p2.x - p1.x);
  double b = (p2.y - p1.y) * (p2.y - p1.y);

  double modulo = sqrt(a + b);

  return modulo;

}

Punto PuntoMedio (const Punto& p1, const Punto& p2)
{

  Punto medio;

  medio.x = (p1.x + p2.x) / 2;
  medio.y = (p1.y * p2.y) / 2;

  return medio;

}
