
  /** Moódulo que contiene las funciones "ocultar" y "revelar" usadas para
    * codificar un mensaje en una imagen
    */

#include <iostream>
#include "imagenES.h"

using namespace std;

  /**
    * La primera función ocultar recibe dos parámetros, el vector que contiene la información de la imagen, el cual lo
    * pasamos por referencia pues lo vamos a modificar, y el segundo el mensaje que queremos introducirle
    *
    * ¿Cómo? Pues la idea es, con un bucle, recorrer el vector mensaje mientras que no haya terminado (!= "\0")
    * e ir asignando en el vector imagen, en cada uno de los píxeles de ella el mensaje byte a byte
    *
    *
    * Revelar es más del mismo rollo, pero su función principal es, en vez de introducir esos bits en cada byte,
    * extraer los bytes de la posición correspondiente
    *
    *
    * Problema que me acaba de surgir: Tendremos que guardar el final de la cadena "\0" para que luego a la hora
    * de descifrarlo sepa cuando hay que parar (Problema 2.0, no se como hacer eso(Problema 3.0 No se ni meter
    * un char en un conjunto de bytes))
    */


void Ocultar (unsigned char imagen[], int filas, int columnas, char mensaje[]) {

  // Vamos iterando por los valores de la cadena char.
  for(int i = 0; mensaje[i] == '\0'; i++) {

    // Cada caracter está formado por 8 bits. Tenemos que ir insertando cada bit
    // del carácter en el bit menos significativo de cada byte de la imagen.
    // Empezamos en el último bit porque así es como lo indica el ejercicio
    // (de izquierda a derecha).
    for(int j = 7; j >= 0; j--) {

      // Con esta fórmula, podemos calcular en qué byte de la imgen Tenemos
      // que guardar el bit correspondiente.
      int byte_imagen = i*8 + (7 - j);

      // Consultamos el valor del bit del carácter i en la posición j-ésima.
      // Si ese bit es 0, mensaje[i] & 0<<j nos devuelve 0. Si es 1, nos
      // devolverá otro valor.
      if ((mensaje[i] & 1<<j) == 0) { // el bit es 0

        // Como el bit es 0, tenemos que desactivar el bit menos significativo.
        imagen[byte_imagen] = imagen[byte_imagen]&(~1);

      } else { // el bit es 1

        // Como el bit es 1, tenemos que activar el bit menos significativo.
        imagen[byte_imagen] = imagen[byte_imagen]|1;

      }

    }

  }

}


void Revelar (unsigned char im_cifrada[], int longitud_imagen, char revelacion[]){

  char caracter = 0; // el caracter que está oculto con el que trabajamos.
  int num_caracter = 1; // numero del caracter en la cadena (empezamos por 1)
  int pos_bit; // posicion del bit del caracter que estamos insertando en cada
               // iteración.

  for(int i = 0; i < longitud_imagen; i++) {

    // Comprobamos el valor del bit menos significativo del byte de la imagen
    // de la iteración actual
    int bit_menos_significativo = (im_cifrada[i]&1) == 0 ? 0 : 1;

    // Si es 0, tenemos que poner un 0 en el bit que corresponda del caracter
    // empezando de izquierda a derecha.
    // Si es distinto de 0, es 1 y por tanto, tenemos que poner un 1 de la misma
    // forma.
    if (bit_menos_significativo == 0) {
      pos_bit = 7*(num_caracter) - i;
      caracter = caracter&(~(1<<pos_bit));
    } else {
      caracter = caracter|1<<pos_bit;
    }

    // Si llegamos a un byte múltiplo de 7, ya tenemos los 8 bits del carácter
    // por tanto, pasamos al siguiente carácter y guardamos el carácter que
    // hemos descubierto en nuestra cadena char.
    if (i%7 == 0) {
      num_caracter++;
      revelacion[i/7 - 1] = caracter;
      caracter = 0;
    }

  }

}
