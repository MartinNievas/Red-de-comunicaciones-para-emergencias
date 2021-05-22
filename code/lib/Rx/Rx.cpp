#include <Rx.h>

String Auxiliar(String str, int h){
  int j,i=0,k=0;  
  char aux[5][15]; 
  for(j=0;j<str.length();j++){
       if (str[j]!='-'){
          aux[i][k]=str[j];
          k++;
       }
       else{   
          aux[i][k]='\0';     
          i++;
          k=0;
       } 
    }
   return aux[h];
}

class PaqueteRecibido{
  
  public:

  String ID(String str){return Auxiliar(str,0);}
  String GPS(String str){return Auxiliar(str,1);}
  String Hora(String str){return Auxiliar(str,2);}
  String Bateria(String str){return Auxiliar(str,3);}
  String Mensaje(String str){return Auxiliar(str,4);}
};