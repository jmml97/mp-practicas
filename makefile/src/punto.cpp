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

void EscribirPunto (Punto p)
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

double GetX (Punto p)
{

  return p.x;

}

double GetY (Punto p)
{

  return p.y;

}

double Distancia (Punto p1, Punto p2)
{

  double modulo1, modulo2;

  modulo1 = sqrt(p1.x * p1.x + p1.y * p1.y);
  modulo2 = sqrt(p2.x * p2.x + p2.y * p2.y);

  return abs(modulo1 - modulo2);

}

Punto PuntoMedio (Punto p1, Punto p2)
{

  Punto medio;

  medio.x = (p1.x + p2.x) / 2;
  medio.y = (p1.y * p2.y) / 2;

  return medio;

}
