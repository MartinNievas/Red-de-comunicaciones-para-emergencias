#include <Arduino.h>

#ifndef CTRL_H
  #define CTRL_X

  namespace CONTROL{
    int Error(String);
    int ID(String,char);
    int Separadores(String);
    int Hora(String,String);
    int Bateria(String);
    int Mensaje(String);
    String Desglosador(String,int);
    int Posicion(String,String,String,String);
  }

#endif
