#include <Paquete.h>

String Transmision (char ID,String Mensaje){
  Modulos mod;
  String guion = "-";
  return (ID+guion+mod.Posicion()+guion+mod.Hora()+guion+mod.bateria()+guion+Mensaje+guion);
}

String Auxiliar(String paqueteRecibido, String Componente){
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
   return aux[Index(Componente)];
}

int Index(String Componente){
    if (Componente == "ID") return 0;
    if (Componente == "POS") return 1;
    if (Componente == "HR") return 2;
    if (Componente == "BAT") return 3;
    if (Componente == "MSJ") return 4;  
}
