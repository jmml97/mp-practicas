#ifndef jugador_h
#define jugador_h

class Jugador {

  private:
    char nombre[50];
    int turno;
    int puntuacion;
    int partidas_ganadas;

  public:

    char GetNombre();
    void SetNombre(char c[]);

    int GetTurno();
    void SetTurno(int n);

    int GetPuntuacion();
    void ASetPuntuacion(int n);
    void AddPuntuacion(int n);

    void SetPartGan(int n);
    int GetPartGan();
    void AddPartGan();

    void MuestraResultados();

    void EscogeColumna(int c);

    Jugador(char c[], int t);

};

#endif
