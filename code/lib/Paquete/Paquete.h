#include <Arduino.h>
#include <Modulos.h>

#ifndef PQT_H
  #define PQT_X

  String Transmision(char,String);
  String Auxiliar(String,String);
  int Index(String);
  
  class Paquete{
  
  public:

  String Enviar(char ID,String Mensaje) {
    return Transmision(ID,Mensaje);
  } 
  String Leer(String paqueteRecibido, String Componente){
    return Auxiliar(paqueteRecibido,Componente);
  }
  
  };

#endif
