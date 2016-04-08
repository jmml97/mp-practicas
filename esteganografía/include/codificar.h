/**
  * @file codificar.h
  * @brief Fichero cabecera para las funciones de codificación del mensaje
  *
  * Permite ocultar o revelar mensajes en archivos PPG y PPM.
  *
  */

#ifndef _CODIFICAR_H_
#define _CODIFICAR_H_

/**
  * @brief Tipo de error
  *
  * Declara una serie de constantes para representar los distintos tipos
  * de error que el programa maneja
  *
  * @see ImprimirError
  */
enum TipoError { MSG_OCULTAR_GRANDE, // El mensaje a ocultar es demasiado
                                     // grande.
                 NO_TERMINADOR,      // El mensaje a revelar no contiene
                                     // terminador.
                 MSG_REVELAR_GRANDE,  // El mensaje a revelar es demasiado
                                     // grande.
                 NO_ERROR
                };

void ImprimirError(enum TipoError error);

/**
  * @brief Oculta el mensaje dado en la imagen de salida.
  *
  * @param imagen[] Vector del contenido de la imagen.
  * @param longitud_imagen Parámetro que almacena el número de bytes de la imagen dada.
  * @param mensaje[] Mensaje que queremos ocultar.
  */
void Ocultar (unsigned char imagen[], int longitud_imagen, char mensaje[], enum TipoError& error);

/**
  * @brief Revela el mensaje oculto en el archivo que le indiquemos.
  *
  * @param im_cifrada[] Vector del contenido de la imagen.
  * @param longitud_imagen Parámetro que almacena el número de bytes de la imagen dada.
  * @param revelacion[] Mensaje oculto que queremos revelar.
  */
void Revelar (unsigned char im_cifrada[], int longitud_imagen, char revelacion[], enum TipoError& error);

#endif
