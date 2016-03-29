
  /** Programa para ocultar una cadena en una imagen de tipo PPM o PGM
    *
    * @brief Se introduce el nombre del fichero original, el de salida y por último el mensaje a ocultar
    *
    */

#include <iostream>
#include "imagenEs.h"

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
