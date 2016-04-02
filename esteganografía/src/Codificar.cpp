
  /** Moódulo que contiene las funciones "ocultar" y "revelar" usadas para
    * codificar un mensaje en una imagen
    */

#include <iostream>
#include "imagenEs.h"

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


void Ocultar (unsigned char& imagen[], unsigned char mensaje[]) {

  for(int i = 0, mensaje[i] != "\0", i++)
}


void Revelar (unsigned char im_cifrada, unsigned char& revelacion){


}



// IGNORAR DE AQUÍ EN ADELANTE
int main () {

  /*
      Creamos vectores para almacenar el nombre de las imágenes y el mensaje a cifrar,
      antes habiendo definido unas cuantas constantes para su tamaño máximo (El cual desconozco a ciencia cierta)
  */


  const int MAX_BUFFER =
  const int MAX_N_IMAGEN =
  const int MAX_MENSAJE = MAX_BUFFER / 8;

  unsigned char mensaje[MAX_MENSAJE];
  char im_entrada[MAX_N_IMAGEN], im_salida[MAX_N_IMAGEN];


  /*
      Usamos cin.getline para almacenar en los vectores los nombres que les iremos asignando
  */


  cout << "Indique la imagen de entrada: ";
  cin.getline(im_entrada,MAX_N_IMAGEN);

  /*
      La idea aquí es hacer una condicional que según el nombre del archivo introducido compruebe si es un tipo de archivo
      válido y actúe según corresponda o devolver un error si es un tipo desconocido

      Posteriormente hay que seguir con "ocultar", descubrir como meter en el buffer la imagen para ir modificandola y
      guardandolo
  */


  cout << "Introduzca el nombre de la imagen de salida: ";

  cout << "Introduzca el mensaje a cifrar: ";
}
