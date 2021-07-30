#include <Arduino.h>
#include <RadioLib.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#ifndef MODULOS_H
  #define MODULOS_X

  extern Adafruit_SSD1306 display;
  namespace LCD{
     extern int Inicializar(void);
     extern void Limpiar(void);
     extern void Letra(int);
     extern void Escribir(String,int,int);   
  }

  extern SX1276 radio;
  extern volatile bool receivedFlag;
  extern volatile bool enableInterrupt;
  namespace LORA{
     extern void setFlag(void);
     extern int Inicializar();
     extern void Enviar(String);
     extern String Leer(void);
  }
  
  String Hora(void);
  String Desglosador(int,String);

  class Bateria {
   private:
     float carga;

   public:
     Bateria(){
       carga = nivelADC();  
     }
  
     float nivelADC(){
       float ADC = 1000.5;
       carga = ADC;
       return carga;
     }
  
     float Nivel(){
       return carga;
     }

     float Restante (){
       int maxCarga = 2200;
       return (carga*100/maxCarga);
     }   
     String Carga(){
       float Charge = Restante();
       if (Charge>=0.0&&Charge<10.0) return "|o---------|"; 
       if (Charge>=10.0&&Charge<20.0) return "|oo--------|"; 
       if (Charge>=20.0&&Charge<30.0) return "|ooo-------|"; 
       if (Charge>=30.0&&Charge<40.0) return "|oooo------|"; 
       if (Charge>=40.0&&Charge<50.0) return "|ooooo-----|"; 
       if (Charge>=50.0&&Charge<60.0) return "|oooooo----|"; 
       if (Charge>=60.0&&Charge<70.0) return "|ooooooo---|"; 
       if (Charge>=70.0&&Charge<80.0) return "|oooooooo--|"; 
       if (Charge>=80.0&&Charge<90.0) return "|ooooooooo-|"; 
       if (Charge>=90.0&&Charge<100.0) return "|oooooooooo|"; 
       return "|Error de lectura|";
     } 
  };
  
  class Posicion{
    private:
      String Lectura;

    public:
      Posicion(void){
        String gpsRead="$GPRMC,225446,A,4916.06,N,12311.12,W,000.5,054.7,191194,020.3,E*68";
        //Trama obtenida de un NEO-6 operado con libreria <SoftwareSerial.h>
        Lectura=gpsRead;
      }

      String Latitud(void){       
        return Desglosador(3,Lectura);
      }

      String Longitud(void){
        return Desglosador(5,Lectura);
      }
  };
#endif
