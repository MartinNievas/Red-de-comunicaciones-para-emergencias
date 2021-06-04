#include <Control.h>

String CONTROL::Desglosador(String paqueteRecibido, int Index){
  int j,i=0,k=0;  
  char aux[6][15];
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
  String Componente=aux[Index];
  return Componente;
}

int CONTROL::Error(String paqueteRecibido){
  if(paqueteRecibido[0]=='#'||paqueteRecibido[1]=='#'||paqueteRecibido[2]=='#')return 1; 
  else return 0;
}

int CONTROL::ID(String paqueteRecibido, char NodeID){//Control de ID, suponiendo 4 nodos
  int cantidadNodos = 4; 
  int flag=0;
  char IDPosibles [cantidadNodos] = {'A','B','C','D'};
  for(int j=0;j<cantidadNodos;j++){
     if (paqueteRecibido[0]==IDPosibles[j]&&paqueteRecibido[0]!=NodeID)flag=1;
  }
  if (!flag)return 1;  
  else return 0;
}

int CONTROL::Separadores(String paqueteRecibido){//Control de separadores (guiones) de los componentes del paquete
  int k=0;
  for (int i=0;i<paqueteRecibido.length();i++){ 
       if(paqueteRecibido[i]=='-')k++;
  }
  if (k!=6)return 1; 
  else return 0;
}

int CONTROL::Hora(String componenteHora, String Hora){//Control de hora, suponiendo mensaje instantaneo 
  if(componenteHora!=Hora)return 1; 
  else return 0;
}

int CONTROL::Bateria(String componenteBateria){//Control de carga de bateria, asumiendo que no puede ser mayor a dos digitos
  if(componenteBateria.length()>5)return 1; 
  else return 0;
}

int CONTROL::Posicion(String Latitud_1, String Longitud_1, String Latitud_2, String Longitud_2){
//Control de posicion suponiendo que las coordenadas, de acuerdo al alcance máximo de la comunicación, sólo podrían diferir en segundos y la unidad del minuto
  Latitud_1[3]=0;
  Latitud_1[5]=0;
  Latitud_1[6]=0;
  Latitud_2[3]=0;
  Latitud_2[5]=0;
  Latitud_2[6]=0;
  if (Latitud_1!=Latitud_2) return 1;
  Longitud_1[4]=0;
  Longitud_1[6]=0;
  Longitud_1[7]=0;
  Longitud_2[4]=0;
  Longitud_2[6]=0;
  Longitud_2[7]=0;  
  if (Longitud_1!=Longitud_2) return 1;
  return 0;
}

int CONTROL::Mensaje(String componenteMensaje){//Control de mensajes, suponiendo 3 mensajes posibles
   int cantidadMensajes = 3; 
   int flag=0;
   String mensajesPosibles[cantidadMensajes] = {"ASISTENCIA","OK","HERIDO"};
   for(int j=0;j<cantidadMensajes;j++){
      if (componenteMensaje==mensajesPosibles[j]) flag=1;
   }
   if (!flag) return 1;
   else return 0;
}
