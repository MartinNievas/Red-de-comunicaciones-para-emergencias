#include "Nodo.h"

void Transmision (char NodeID,String Mensaje){
  String guion = "-";
  LORA::Enviar(NodeID+guion+Posicion()+guion+Hora()+guion+bateria()+guion+Mensaje+guion);
}

void Auxiliar(String paqueteRecibido){
  int j,i=0,k=0;  
  char aux[5][15]; 
  for(j=0;j<paqueteRecibido.length();j++){
       if (paqueteRecibido[j]!='-'){
          aux[i][k]=paqueteRecibido[j];
          k++;
       }
       else{   
          aux[i][k]='\0';     
          i++;
          k=0;
       } 
   }
   LCD::Limpiar();
   LCD::Escribir("MENSAJE RECIBIDO",1);
   LCD::Escribir("De: ",2);LCD::Escribir(aux[0],0);
   LCD::Escribir("Pos: ",3);LCD::Escribir(aux[1],0);
   LCD::Escribir("Hora: ",4);LCD::Escribir(aux[2],0);
   LCD::Escribir("Bat: ",5);LCD::Escribir(aux[3],0);LCD::Escribir("%",0);
   LCD::Escribir(aux[4],6);
}
