#include <Nodo.h>

void Transmision (char NodeID,String Mensaje){
  String guion = "-";
  LORA::Enviar(NodeID+guion+Posicion()+guion+Hora()+guion+bateria()+guion+Mensaje+guion);
  LORA::Escuchar();
  LCD::Limpiar();
  LCD::Letra(2);
  LCD::Escribir(Mensaje,0,0);
  LCD::Letra(1);
  LCD::Escribir("Enviando",0,20);
  LCD::Escribir(".",47,20);
  for(int i=0;i<4;i++){
     delay(400);
     LCD::Escribir(".",-1,-1);
  }
}

String Mensajes(){
  String Msj[3]={"ASISTENCIA","OK","HERIDO"};
  return Msj[random(0,3)];
}

int Control(String paqueteRecibido, String Buffer, char NodeID){
  int j,i=0,k=0;  
  char aux[5][15]; 

  if (controlERR(paqueteRecibido,Buffer,NodeID))return 0;
  if (controlID(paqueteRecibido,NodeID))return 1;
  if (controlSEP(paqueteRecibido))return 1;

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

   if (controlHR(aux[2]))return 1;
   if (controlBAT(aux[3]))return 1;
   if (controlMSJ(aux[4]))return 1;
   
   LCD::Limpiar();
   LCD::Letra(1);
   LCD::Escribir("MENSAJE RECIBIDO",0,0);
   LCD::Escribir("De: ",0,10);LCD::Escribir(aux[0],-1,-1);
   LCD::Escribir("Pos: ",0,20);LCD::Escribir(aux[1],-1,-1);
   LCD::Escribir("Hora: ",0,30);LCD::Escribir(aux[2],-1,-1);LCD::Escribir("hs",-1,-1);
   LCD::Escribir("Bat: ",0,40);LCD::Escribir(aux[3],-1,-1);LCD::Escribir("%",-1,-1);
   LCD::Escribir("\"",0,55);LCD::Escribir(aux[4],-1,-1);LCD::Escribir("\"",-1,-1);
   delay(3000);
   return 0;
}

int controlERR(String paqueteRecibido,String Buffer,char NodeID){
  if(paqueteRecibido[0]=='#'||paqueteRecibido[1]=='#'||paqueteRecibido[2]=='#'){
    Transmision(NodeID,Buffer);
    return 1;
  }  
  else return 0;
}

int controlID(String paqueteRecibido, char NodeID){//Control de ID, suponiendo 4 nodos
  int cantidadNodos = 4; 
  int flag=0;
  char IDPosibles [cantidadNodos] = {'A','B','C','D'};
  for(int j=0;j<cantidadNodos;j++){
     if (paqueteRecibido[0]==IDPosibles[j]&&paqueteRecibido[0]!=NodeID)flag=1;
  }
  if (!flag)return 1;  
  else return 0;
}

int controlSEP(String paqueteRecibido){//Control de separadores (guiones) de los componentes del paquete
  int k=0;
  for (int i=0;i<paqueteRecibido.length();i++){ 
       if(paqueteRecibido[i]=='-')k++;
  }
  if (k!=5)return 1; 
  else return 0;
}

int controlHR(String componenteHora){//Control de hora, suponiendo mensaje instantaneo 
  if(componenteHora!=Hora())return 1; 
  else return 0;
}

int controlBAT(String componenteBateria){//Control de carga de bateria, asumiendo que no puede ser mayor a dos digitos
  if(componenteBateria.length()>5)return 1; 
  else return 0;
}

int controlMSJ(String componenteMensaje){//Control de mensajes, suponiendo 3 mensajes posibles
   int cantidadMensajes = 3; 
   int flag=0;
   String mensajesPosibles[cantidadMensajes] = {"ASISTENCIA","OK","HERIDO"};
   for(int j=0;j<cantidadMensajes;j++){
      if (componenteMensaje==mensajesPosibles[j]) flag=1;
   }
   if (!flag) return 1;
   else return 0;
}

String Barra(){
  if (bateria()>=0.0&&bateria()<10.0) return "|o---------|"; 
  if (bateria()>=10.0&&bateria()<20.0) return "|oo--------|"; 
  if (bateria()>=20.0&&bateria()<30.0) return "|ooo-------|"; 
  if (bateria()>=30.0&&bateria()<40.0) return "|oooo------|"; 
  if (bateria()>=40.0&&bateria()<50.0) return "|ooooo-----|"; 
  if (bateria()>=50.0&&bateria()<60.0) return "|oooooo----|"; 
  if (bateria()>=60.0&&bateria()<70.0) return "|ooooooo---|"; 
  if (bateria()>=70.0&&bateria()<80.0) return "|oooooooo--|"; 
  if (bateria()>=80.0&&bateria()<90.0) return "|ooooooooo-|"; 
  if (bateria()>=90.0&&bateria()<100.0) return "|oooooooooo|"; 
  return "/?/";
}
