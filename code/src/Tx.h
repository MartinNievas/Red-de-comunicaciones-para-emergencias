#include "Bateria.h"

String gps(){
    return "(146,231,22)";
}
  
String hora(){
    return "2:07";
}

String mensaje(){
    switch (random(0,4)) {
      case 0:return("\"ASISTENCIA\"");
      case 1:return("\"HERIDO\"");   
      case 2:return("\"CONTROLADO\"");   
      case 3:return("\"OK\"");   
   }
}

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
