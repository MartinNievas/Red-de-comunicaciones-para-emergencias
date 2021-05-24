#include <RadioLib.h>
#include <Arduino.h>

#ifndef SX1276_H
  #define SX1276_X

  extern SX1276 radio;
  extern volatile bool receivedFlag;
  extern volatile bool enableInterrupt;

  namespace LORA{
     extern void setFlag(void);
     extern void Escuchar(void);
     extern int Inicializar();
     extern void Enviar(String);
     extern String Leer(void);
  }
  
#endif
