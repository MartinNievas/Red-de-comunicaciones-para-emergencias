#include <Arduino.h>
#include <Modulos.h>
#include <Control.h>

#ifndef NODO_H
  #define NODO_X
  
  void Transmision(char,String);
  int Control(String,String,char);
  String Mensajes(void);
  void Retransmision(void);
  void imprimirMensaje(String,String,String,String,String,String);
  void Puntos(void);
  
  class Nodo{

    private:
      char NodeID;
      String Buffer;

    public:
      Nodo(char ID){
        NodeID = ID;
      }
  
      int Inicializar(void){
        if(!LORA::Inicializar()&&!LCD::Inicializar()){
           LCD::Escribir("Inicializando",0,0);
           for(int i=0;i<4;i++){
                delay(400);
                LCD::Escribir(".",-1,-1);
           }
           return 0;
        }
        else
           return 1;
      }
  
      void Enviar(String Mensaje) {
        Transmision(NodeID,Mensaje);
        Buffer=Mensaje;
      } 
  
      int Escuchar(void){
        String paqueteRecibido = LORA::Leer();
        if (paqueteRecibido=="-1") return 1;
        if (Control(paqueteRecibido,Buffer,NodeID)&&paqueteRecibido[0]!=NodeID){
          Retransmision();
          Escuchar();
        }
        return 0;
      }

      void Pantalla(void){
         Bateria bat;
         char nID[2]={NodeID,'\0'};
         LCD::Limpiar();
         LCD::Letra(4);
         LCD::Escribir(Hora(),5,15);
         LCD::Letra(1);
         LCD::Escribir(bat.Carga(),56,57); 
         LCD::Letra(1);
         LCD::Escribir(nID,0,57);          
      }
  };

#endif
