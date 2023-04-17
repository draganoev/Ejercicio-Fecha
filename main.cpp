#include <iostream>
#include "Fecha.h"

using namespace std;

int main()
{
int dia,mes,anio;
int diasParaAgregar;
Fecha f;

cout<<"Dia: "<<f.getDia()<<endl;
cout<<"Mes: "<<f.getMes()<<endl;
cout<<"Anio: "<<f.getAnio()<<endl;

cout<<"Dias para agregar: ";
cin>>diasParaAgregar;
cout<<endl;
f.agregarDias(diasParaAgregar);

cout<<"DIAS AGREGADOS: "<<endl;
cout<<"Dia: "<<f.getDia()<<endl;
cout<<"Mes: "<<f.getMes()<<endl;
cout<<"Anio: "<<f.getAnio()<<endl;

cout<<"Fecha to string: "<<endl;
cout<<f.toString(f.getDia(),f.getMes(),f.getAnio());

    return 0;
}
