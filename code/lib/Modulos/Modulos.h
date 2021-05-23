#include <Bateria.h>
#include <Arduino.h>

#ifndef MDL_H
  #define MDL_X

  String Pos(void);
  String Hr(void);
  float Bat(void);
  
  class Modulos{

  public:
  
  String Posicion(){
     return Pos();
  }
  String Hora(){
     return Hr();
  }
  float bateria(){
    return Bat();
  }

};

#endif
