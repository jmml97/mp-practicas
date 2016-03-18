// circulo.h

#ifndef _CIRCULO_H_
#define _CIRCULO_H_

#include "punto.h"


struct Circulo {
    Punto centro;
    double radio;
};

// OBSOLETO
Circulo LeerCirculo();

// OBSOLETO
void EscribirCirculo(const Circulo& c);

bool Leer(std::istream& is, Circulo& c);

bool Escribir(std::ostream& os, const Circulo& c);

void InicializarCirculo (Circulo& c, const Punto& centro, double radio);

Punto Centro (const Circulo& c);

double Radio (const Circulo& c);

double Area (const Circulo& c);

bool Interior (const Punto& p, const Circulo& c);

double Distancia (const Circulo& c1, const Circulo& c2);

#endif
