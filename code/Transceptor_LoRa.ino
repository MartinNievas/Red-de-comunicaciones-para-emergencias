
#include "Tx.h"
#include "Rx.h"
#include "Ini.h"

const char NodeID = 'B';
void Receptor();
void Transmisor();

void loop() {
  delay(2000);
  if(receivedFlag) {
    enableInterrupt = false;
    receivedFlag = false;
    Receptor();
    enableInterrupt = true;
  }
  Transmisor();
  radio.startReceive();
}

void Transmisor (){
  PaqueteEnviado tx;
  String dp = "-";
  String pqt=NodeID+dp+tx.GPS()+dp+tx.Hora()+dp+tx.Bateria()+dp+tx.Mensaje()+dp;
  radio.transmit(pqt);  
}

void Receptor (){
  String cdn="";
  display.clearDisplay();
  if (radio.readData(cdn)==ERR_NONE && cdn[0]!=NodeID && cdn!=""){
   PaqueteRecibido rx;
   display.setCursor(0,0);
   display.print("MENSAJE RECIBIDO");
   display.setCursor(0,10);
   display.print("De: ");
   display.print(rx.ID(cdn));
   display.setCursor(0,20);
   display.print("Pos: ");
   display.print(rx.GPS(cdn));
   display.setCursor(0,30);
   display.print("Hora: ");
   display.print(rx.Hora(cdn));
   display.setCursor(0,40);
   display.print("Bat: ");
   display.print(rx.Bateria(cdn));
   display.setCursor(0,55);
   display.print(rx.Mensaje(cdn));
  }
  display.display();   
}
