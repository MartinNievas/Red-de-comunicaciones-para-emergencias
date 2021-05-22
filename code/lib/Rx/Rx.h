#ifndef RX_H
  #define RX_X

  String Auxiliar(String,int);

class PaqueteRecibido{

  public:

  String ID(String str){return Auxiliar(str,0);}
  String GPS(String str){return Auxiliar(str,1);}
  String Hora(String str){return Auxiliar(str,2);}
  String Bateria(String str){return Auxiliar(str,3);}
  String Mensaje(String str){return Auxiliar(str,4);}
};

#endif
