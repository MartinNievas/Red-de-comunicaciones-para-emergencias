#include <Modulos.h>

String Posicion(){
     return "(12,N;151,O)"; //latitud,longitud
}

String Hora(){
     return "23:11";
}

float bateria(){
    Bateria bat;
    return bat.Restante();
}
