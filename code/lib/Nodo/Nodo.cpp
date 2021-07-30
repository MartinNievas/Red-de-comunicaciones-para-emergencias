#include <Nodo.h>

void Transmision (char NodeID,String Mensaje){
  String Separador="-";
  Bateria carga;
  Posicion GPS;
  String Paquete = NodeID+Separador+GPS.Latitud()+Separador+GPS.Longitud()+Separador+Hora()+Separador+carga.Restante()+Separador+Mensaje+Separador;
  LORA::Enviar(Paquete);
  LCD::Limpiar();
  LCD::Escribir("\""+Mensaje+"\"",0,0);
  LCD::Escribir("Enviando",0,15);
  LCD::Escribir(".",47,15);
  Puntos();
}

String Mensajes(void){
  String Msj[3]={"ASISTENCIA","OK","HERIDO"};
  return Msj[random(0,3)];
}

int Control(String paqueteRecibido, String Buffer, char NodeID){ 

  if (CONTROL::Error(paqueteRecibido)){
     Transmision(NodeID,Buffer);
     return 0;
  }
  if (CONTROL::ID(paqueteRecibido,NodeID))return 1;
  if (CONTROL::Separadores(paqueteRecibido))return 1;
  
  String ID=CONTROL::Desglosador(paqueteRecibido,0);
  String LATITUD=CONTROL::Desglosador(paqueteRecibido,1);
  String LONGITUD=CONTROL::Desglosador(paqueteRecibido,2);
  String HORA=CONTROL::Desglosador(paqueteRecibido,3);
  String CARGA=CONTROL::Desglosador(paqueteRecibido,4);
  String MENSAJE=CONTROL::Desglosador(paqueteRecibido,5);
  Posicion GPS;
  
  if (CONTROL::Hora(HORA,Hora()))return 1;
  if (CONTROL::Bateria(CARGA))return 1;
  if (CONTROL::Posicion(GPS.Latitud(),GPS.Longitud(),LATITUD,LONGITUD)) return 1;
  if (CONTROL::Mensaje(MENSAJE))return 1;
  imprimirMensaje(ID,LATITUD,LONGITUD,HORA,CARGA,MENSAJE); 
  return 0;
}

void imprimirMensaje(String ID,String LATITUD,String LONGITUD,String HORA,String CARGA,String MENSAJE){
   LCD::Limpiar();
   LCD::Escribir(MENSAJE,0,0);
   LCD::Escribir("De: "+ID,0,10);
   LCD::Escribir("Pos: "+LATITUD,0,20);
   LCD::Escribir("     "+LONGITUD,0,30);
   LCD::Escribir("Hora: "+HORA+"hs",0,40);
   LCD::Escribir("Bat: "+CARGA+"%",0,50);
   delay(3000);  
}

void Retransmision(void){
   LCD::Limpiar();
   LCD::Escribir("ERROR DE TRAMA",0,0);
   LCD::Escribir("Pidiendo reenvio",0,25);
   LORA::Enviar("###");
   Puntos();
}

void Puntos (void){
   for(int i=0;i<4;i++){
       delay(400);
       LCD::Escribir(".",-1,-1);
   }
}
