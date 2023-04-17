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
    //CONSTRUCTOR CON PAR�METROS
    Fecha(int dia, int mes, int anio);
    //CONSTRUCTOR SIN PAR�METROS
    Fecha();
    int getDia();
    int getMes();
    int getAnio();
    void agregarDias(int diasParaAgregar);
    string toString(int dia,int mes,int anio);

};

#endif // FECHA_H_INCLUDED
