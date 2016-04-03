#include <iostream>
using namespace std;

int main () {

  unsigned char vectorcillo[50] = {'P'};
  char mensaje[4];
  cin.getline(mensaje,4);

  cout << "Mostramos el vector \"Imagen\": ";

  for (int i = 0; i < 49; i++)
    cout << vectorcillo[i];

    /** IDEA: Suponiendo que el uno se representa como 00000001 tenemos que consultar cada bit de nuestro mensaje
      *       e introducirlo en el de la información de la imagen, nuestro mensaje tiene 8 bits por caracter, por lo
      *       cual tenemos que hacer lo siguiente: creamos un caracter 'uno' y lo movemos a la j-esima posicion de ese byte
      *       con uno = 1 << j, y ahora hacemos un and & con nuestro caracter a ocultar , como son todos ceros menos la
      *       posición que nos interesa consultar nos devolverá un 1 o un 0 según lo que haya en esa posición, si deshacemos
      *       el desplazamiento obtenemos un 1 o un 0 en la posición más a la derecha de nuestro byte "uno", y tenemos que
      *       introducirlo en nuestro mensaje,¿cómo? Pues si queremos introducir un 1 al final es sencillo, utilizamos
      *       simplemente un OR |, porque XXXXXXXX | 00000001 va a devolver XXXXXXX1, fácil.
      *
      *
      *       Pero si queremos meter un cero aquí viene la gracia creo que tendíamos que hacer un NOT uno primero
      *       y luego hacer un uno AND loquesea ya que 11111110 & XXXXXXXX dan de resultado XXXXXXX0
      *
      *       Entonces habría que, antes que empezar a modificar, cuando consultamos el valor del j-esimo bit de nuestro
      *       mensaje, comprobar si es 0 o 1 y hacer las respectivas operaciones
      *
      *
      */

  unsigned char uno = 1, a_cifrar, bit_pos_j;
                                            //  VERY IMPORTANT
  for (int i = 0; i < 3; i++ ){             // Aquí hay que modificar una precondición que vea cual tiene más tamaño, si
                                            // el mensaje * 8 bits o la capacidad del vector imagen en sí


    a_cifrar = mensaje[i];                    //                                      XYYYYYYY
                                              //                                    & 10000000
                                              //         uno << 7-0          --->    _________ uno >> 7-0
      for (int j = 0; i < 7; j++) {           // 00000001     --->   10000000       = X0000000 -----> 0000000X = 1 ó 0
                                              //                                                      segun el valor de X

      bit_pos_j =  ((uno << (7-j)) & mensaje[i]) >> (7-j);




// Distinción de casos segun el valor de ese bit

      if (bit_pos_j == 1)                                          // "XXXXXXXX OR 00000001 = XXXXXXX1"

        vectorcillo[i * 8 + j] = vectorcillo[i * 8 + j] | uno;

      else if (bit_pos_j == 0) {                                   //11111110 AND XXXXXXXX = XXXXXXX0

        vectorcillo[i * 8 + j] = vectorcillo[i * 8 + j] & ~uno;
      }

      else

        cout << vectorcillo[i * 8 + j] << "\tAlgo has hecho mal pillín";

    }
  }

  cout << "El vectorcillo (nuestra imagen) ahora es: ";

  for (int i = 0; i < 49; i++)
    cout << vectorcillo[i] << " ";

  cout << "\n\nY el mensaje: ";

  for (int i = 0; i < 3;i++)
    cout << mensaje[i];


  // A PARTIR DE AQUÍ COMIENZA EL CÓMO DESCIFRAR EL MENSAJE



//  IGNORE ALL THE WAY DOWN PLZ


}
