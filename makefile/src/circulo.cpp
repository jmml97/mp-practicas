#include <iostream>
#include <cmath>
#include "circulo.h"

using namespace std;

// OBSOLETO
Circulo LeerCirculo()
{

  Circulo circulo;
  char c;

  cin >> circulo.radio >> c;
  circulo.centro = LeerPunto();

  return circulo;

}

// OBSOLETO
void EscribirCirculo(Circulo c)
{

  cout << c.radio << "-";
  EscribirPunto(c.centro);

}

bool Leer(istream& is, Circulo& c) {

  is >> c.radio;
  is.ignore();
  c.centro = Leer(is, c.centro)

  return is;

}

void InicializarCirculo (Circulo& c, Punto centro, double radio)
{

  c.centro = centro;
  c.radio = radio;

}

Punto Centro (Circulo c)
{

  return c.centro;

}

double Radio (Circulo c)
{

  return c.radio;

}

double Area (Circulo c)
{

  return M_PI * c.radio * c.radio;

}

bool Interior (Punto p, Circulo c)
{

  return Distancia(p, c.centro) < c.radio;

}

double Distancia (Circulo c1, Circulo c2)
{

  return Distancia(c1.centro, c2.centro) - c1.radio - c2.radio;

}
