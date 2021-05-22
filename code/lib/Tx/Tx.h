#include <Bateria.h>

#ifndef TX_H
  #define TX_X

  String gps(void);
  String hora(void);
  String mensaje(void);

class PaqueteEnviado{

  public:

  String GPS(){return gps();}
  String Hora(){return hora();}
  float bateria(){
    Bateria bat;
    return bat.Restante();
    }
  String Mensaje(){return mensaje();}

};

#endif
