

#include<iosfwd> // istream,ostream
#include "matriz_bit.h"


bool Leer(std::istream& is, MatrizBit& m) {

  for (int i = 0; i < m.Filas(); i++)
    for (int j = 0; j < m.Columnas(); j++) {
      bool v;
      is >> bool;
      Set(m, i, j, v);
    }
    
}

bool Escribir(std::ostream& os, const MatrizBit& m) {



}

bool Leer(const char nombre[], MatrizBit& m) {



}

bool Escribir(const char nombre[], const MatrizBit& m) {



}

void And(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2) {



}

void Or(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2) {



}

void Not(MatrizBit& res, const MatrizBit& m) {



}

void Traspuesta(MatrizBit& res, const MatrizBit& m) {



}
