#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>
using namespace std;

class Fecha{
    private:
    int _dia;
    int _mes;
    int _anio;
    void agregarDia();
    void restarDia();

    public:
    //CONSTRUCTOR CON PARÁMETROS
    Fecha(int dia, int mes, int anio);
    //CONSTRUCTOR SIN PARÁMETROS
    Fecha();
    int getDia();
    int getMes();
    int getAnio();
    void agregarDias(int diasParaAgregar);
    string toString(int dia,int mes,int anio);

};

#endif // FECHA_H_INCLUDED
