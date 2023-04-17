#include <iostream>
#include "Fecha.h"
using namespace std;

Fecha::Fecha(int dia, int mes, int anio){
bool fechaCorrecta=false;
bool bisiesto=false;

    if(anio%4==0){
        if(anio%100!=0){
            bisiesto=true;
        }
    }

    if(anio%4==0&&anio%100==0){
        if(anio%400==0){
            bisiesto=true;
        }
    }

    //FEBRERO. CASO AÑO BISIESTO

        if(mes==2){
            if(bisiesto==true){
                if(dia>=0&&dia<=29){
                _dia=dia;
                _mes=mes;
                _anio=anio;
                fechaCorrecta=true;
                }
            }
        }
    //FEBRERO NO BISIESTO
    if(mes==2){
            if(bisiesto==false){
                if(dia>=0&&dia<=28){
                _dia=dia;
                _mes=mes;
                _anio=anio;
                fechaCorrecta=true;
                }
            }else if(dia>=29&&bisiesto==false){
            _dia=1;
            _mes=1;
            _anio=2023;}
        }


    //MESES CON 30 DIAS
    if(mes==4||mes==6||mes==9||mes==11){
        if(dia>=0&&dia<=30){
            _dia=dia;
            _mes=mes;
            _anio=anio;
            fechaCorrecta=true;
        }
    }

    //MESES CON 31 DIAS
    if(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12){
        if(dia>=0&&dia<=31){
            _dia=dia;
            _mes=mes;
            _anio=anio;
            fechaCorrecta=true;
        }
    }

    //FECHA INGRESADA INCORRECTA
    if(fechaCorrecta!=true){
        _dia=1;
        _mes=1;
        _anio=2023;
    }

}

Fecha::Fecha(){
    _dia=1;
    _mes=1;
    _anio=2023;
}

void Fecha::agregarDia(){
bool bisiesto=false;
_dia++;

if(_anio%4==0){
        if(_anio%100!=0){
            bisiesto=true;
        }
    }

    if(_anio%4==0&&_anio%100==0){
        if(_anio%400==0){
            bisiesto=true;
        }
    }


    //SUMAR DIA A FEBRERO BISIESTO Y NO BISIESTO
    if(bisiesto==true){
        if(_dia==30&&_mes==2){
        _dia=1;
        _mes=3;
        }
    }else if(bisiesto==false){
    if(_dia==29&&_mes==2){
        _dia=1;
        _mes=3;
        }
    }
    //PARA MESES CON 30 DIAS
    if(_dia==31&&_mes==4||_dia==31&&_mes==6||_dia==31&&_mes==9||_dia==31&&_mes==11){
        switch(_mes){
        case 4:_mes=5;_dia=1;
        break;
        case 6:_mes=7;_dia=1;
        break;
        case 9:_mes=10;_dia=1;
        break;
        case 11:_mes=12;_dia=1;
        break;
        }
    }

    //PARA MESES CON 31 DIAS
    if(_dia==32&&_mes==1||_dia==32&&_mes==3||_dia==32&&_mes==5||_dia==32&&_mes==7||_dia==32&&_mes==8||_dia==32&&_mes==10){
        switch(_mes){
        case 1: _mes=2;_dia=1;
        break;
        case 2:_mes=3;_dia=1;
        break;
        case 3:_mes=4;_dia=1;
        break;
        case 5:_mes=6;_dia=1;
        break;
        case 7:_mes=8;_dia=1;
        break;
        case 8:_mes=9;_dia=1;
        break;
        case 10:_mes=11;_dia=1;
        break;
        }
    }
    //CAMBIO DE AÑO
    if(_mes==12&&_dia==32){
        _dia=1;
        _mes=1;
        _anio++;
    }
}

void Fecha::restarDia(){
_dia--;
bool bisiesto=false;

if(_anio%4==0){
        if(_anio%100!=0){
            bisiesto=true;
        }
    }

    if(_anio%4==0&&_anio%100==0){
        if(_anio%400==0){
            bisiesto=true;
        }
    }

    //RESTAR DIA A FEBRERO BISIESTO Y NO BISIESTO
    if(bisiesto==true){
        if(_dia==0&&_mes==3){
        _dia=29;
        _mes=2;
        }
    }else if(bisiesto==false){
    if(_dia==0&&_mes==3){
        _dia=28;
        _mes=2;
        }
    }

   //PARA VOLVER A MESES DE 30
   if(_dia==0){
    switch(_mes){
    case 5: _dia=30;_mes=4;
    break;
    case 7:_dia=30;_mes=6;
    break;
    case 10:_dia=30;_mes=9;
    break;
    case 12:_dia=30;_mes=11;
    break;
        }
   }

   //PARA VOLVER A MESES DE 31
   if(_dia==0){
    switch(_mes){
    case 2:_dia=31;_mes=1;
    break;
    case 4:_dia=31;_mes=3;
    break;
    case 6:_dia=31;_mes=5;
    break;
    case 8:_dia=31;_mes=7;
    break;
    case 9:_dia=31;_mes=8;
    break;
    case 11:_dia=31;_mes=10;
    break;
    }
   }

   //CASO ESPECIAL ENERO. VUELVE UN AÑO ATRÁS
   if(_mes==1&&_dia==0){
    _dia=31;
    _mes=12;
    _anio--;
   }

}

int Fecha::getDia(){
    return _dia;
}
int Fecha::getMes(){
    return _mes;
}
int Fecha::getAnio(){
    return _anio;
}

void Fecha::agregarDias(int diasParaAgregar){
bool bisiesto=false;
int x;

if(diasParaAgregar==0){
    _dia=_dia;}

if(diasParaAgregar>0){
    for(x=0;x<diasParaAgregar;x++){
        agregarDia();
    }
}

if(diasParaAgregar<0){
    for(x=0;x>diasParaAgregar;x--){
        restarDia();
        }
    }
}

string Fecha::toString(int dia,int mes,int anio){
string diaString,mesString,anioString,fechaString;
string cero="0";
bool diaConCero=false,mesConCero=false;
int x;

diaString=to_string(dia);
mesString=to_string(mes);
anioString=to_string(anio);

//PARA CASOS CON DIAS QUE EMPIEZAN CON CERO
if(dia>=1&&dia<=9){
    diaConCero=true;
}

//PARA CASOS CON MESES QUE EMPIEZAN CON CERO
if(mes<=9){
    mesConCero=true;
}

if(diaConCero==true&&mesConCero==true){
    fechaString="0"+diaString+"/"+"0"+mesString+"/"+anioString;
}else if(diaConCero==true&&mesConCero==false){
fechaString="0"+diaString+"/"+mesString+"/"+anioString;
}else if(diaConCero==false&&mesConCero==true){
fechaString=diaString+"/"+"0"+mesString+"/"+anioString;}else if(diaConCero==false&&mesConCero==false){
fechaString=diaString+"/"+mesString+"/"+anioString;}

return fechaString;

}
