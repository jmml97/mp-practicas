#ifndef jugador_h
#define jugador_h

class Jugador {

  private:
    char nombre[50];
    int turno;
    int puntuacion;

  public:

    char GetNombre();
    void SetNombre(char c[]);

    int GetTurno();
    void SetTurno(int n);

    int GetPuntuacion();
    void SetPuntuacion(int n);

    void EscogeColumna(int c);

    Jugador(char c[], int t);

};

#endif
