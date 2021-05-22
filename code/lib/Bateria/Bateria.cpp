#include <Bateria.h>

class Bateria {
  private:
     float carga;

  public:

  Bateria(){
    carga = nivelADC();  
  }
  
  float nivelADC(){
    float ADC = 462.5;
    carga = ADC;
    return carga;
  }

  float nivel(){
    return carga;
  }

  float Restante (){
    int maxCarga = 2200;
    return (carga*100/maxCarga);
  }    
};