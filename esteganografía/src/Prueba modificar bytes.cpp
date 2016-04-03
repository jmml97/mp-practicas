#include <iostream>
using namespace std;

int main () {

  unsigned char vector[50] = {'P'}, mensaje[4];
  cin.getline(mensaje,4);

  cout << "Mostramos el vector \"Imagen\": ";

  for (int i = 0; i < 50; i++)
    cout << vector[i];

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


  for (int i = 0; i < 4; i++ ){

    for (int j = 0; i < 7)


  }



  wtf = byte | cero;
  dos = byte & cero;


  cout << byte << endl;

cout << wtf << endl;
cout << dos << endl;


}
