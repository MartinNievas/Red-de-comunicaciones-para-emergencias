#include <Paquete.h>
#include <Config.h>

void Recepcion (void);
void Transmision(void);
void Imprimir (String);

void loop() {
  delay(2000);
  Recepcion();
  Transmision();
}

void Transmision(void){
  Paquete tx;
  String pqt=tx.Enviar(NodeID,"\"Todo OK\"");
  radio.transmit(pqt);
  radio.startReceive();
}

void Recepcion (void){
  display.clearDisplay(); 
  if(receivedFlag) {
     enableInterrupt = false;
     receivedFlag = false;
     String paqueteRecibido="";
     if (radio.readData(paqueteRecibido)==ERR_NONE && paqueteRecibido[0]!=NodeID && paqueteRecibido!="")Imprimir(paqueteRecibido);
     enableInterrupt = true;
  }
  display.display();
}

void Imprimir (String paqueteRecibido){
   Paquete rx;
   display.setCursor(0,0);
   display.print("MENSAJE RECIBIDO");
   display.setCursor(0,10);
   display.print("De: ");
   display.print(rx.Leer (paqueteRecibido,"ID"));
   display.setCursor(0,20);
   display.print("Pos: ");
   display.print(rx.Leer (paqueteRecibido,"POS"));
   display.setCursor(0,30);
   display.print("Hora: ");
   display.print(rx.Leer (paqueteRecibido,"HR"));
   display.setCursor(0,40);
   display.print("Bat: ");
   display.print(rx.Leer (paqueteRecibido,"BAT"));
   display.print("%");
   display.setCursor(0,55);
   display.print(rx.Leer (paqueteRecibido,"MSJ"));     
}
