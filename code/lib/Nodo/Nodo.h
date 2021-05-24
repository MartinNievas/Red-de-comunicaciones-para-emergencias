#include <Arduino.h>
#include "Modulos.h"
#include "SX1276.h"
#include "Display.h"

#ifndef NODO_H
  #define NODO_X
  
  void Transmision(char,String);
  void Auxiliar(String);
  
  class Nodo{

    private:
      char NodeID;
  
    public:
      Nodo(){
        NodeID = '?';
      }
  
      int Inicializar(){
        if(!LORA::Inicializar()&&!LCD::Inicializar()){
           LCD::Escribir("Inicializando...",1);
           delay (1000);
           LCD::Limpiar();
           return 0;
        }
        else
           return 1;
      }

      void ID(char x){
        NodeID = x;
      }
  
      void Enviar(String Mensaje) {
        Transmision(NodeID,Mensaje);
      } 

      void Escuchar(void){
        LORA::Escuchar();
      }
  
      void Leer(){
        String paqueteRecibido = LORA::Leer();
        if (paqueteRecibido != "-1"&&paqueteRecibido[0]!=NodeID)Auxiliar(paqueteRecibido);
      }
  
  };

#endif
