#include <SX1276.h>

SX1276 radio = new Module(18, 26, 14, 35);
volatile bool receivedFlag = false;
volatile bool enableInterrupt = true;

void LORA::setFlag(void){
   if(!enableInterrupt){
       return;
   }else
       receivedFlag = true;
   }

void LORA::Escuchar(void){
    radio.startReceive();
}
   
int LORA::Inicializar(){
    if (radio.begin()!=ERR_NONE) return 1;
    radio.setFrequency(915.0);
    radio.setBandwidth(500.0);
    LORA::Escuchar();
    radio.setDio0Action(LORA::setFlag);
    return 0;
}

void LORA::Enviar(String Paquete){
    radio.transmit(Paquete);
}

String LORA::Leer(void){
    String Paquete="";
    if(receivedFlag) {
    enableInterrupt = false;
    receivedFlag = false;
    radio.readData(Paquete);
    enableInterrupt = true;
    }
    if (Paquete != "")return Paquete;
    else return "-1";
}
   
