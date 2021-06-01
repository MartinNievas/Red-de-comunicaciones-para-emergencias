#include <Arduino.h>
#include <Modulos.h>
#include <SX1276.h>
#include <Display.h>

#ifndef NODO_H
  #define NODO_X
  
  void Transmision(char,String);
  int Control(String,String,char);
  String Mensajes(void);
  int controlERR(String,String,char);
  int controlID(String,char);
  int controlSEP(String);
  int controlHR(String);
  int controlBAT(String);
  int controlMSJ(String);
  String Barra(void);
  
  class Nodo{

    private:
      char NodeID;
      String Buffer;
      int Blink=0;

    public:
      Nodo(){
        NodeID = '?';
        Buffer = "?";
      }
  
      int Inicializar(){
        if(!LORA::Inicializar()&&!LCD::Inicializar()){
           LCD::Letra(1);
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

      void ID(char x){
        NodeID = x;
      }
  
      void Enviar(String Mensaje) {
        Transmision(NodeID,Mensaje);
        Buffer=Mensaje;
      } 
  
      int Escuchar(){
        String paqueteRecibido = LORA::Leer();
        if (paqueteRecibido=="-1") return 1;
        if (Control(paqueteRecibido,Buffer,NodeID)&&paqueteRecibido[0]!=NodeID){
          LCD::Limpiar();
          LCD::Letra(1);
          LCD::Escribir("ERROR DE TRAMA",0,0);
          LCD::Escribir("Pidiendo reenvio",0,25);
          LORA::Enviar("###");
          LORA::Escuchar();
          for(int i=0;i<4;i++){
             delay(400);
             LCD::Escribir(".",-1,-1);
          }
          Escuchar();
        }
        return 0;
      }

      void Pantalla(){
         char nID[2]={NodeID,'\0'};
         LCD::Limpiar();
         LCD::Letra(4);
         LCD::Escribir(Hora(),5,15);
         LCD::Letra(1);
         LCD::Escribir(Barra(),56,57); 
         LCD::Letra(1.5);
         LCD::Escribir(nID,0,57);          
      }
  };

#endif
