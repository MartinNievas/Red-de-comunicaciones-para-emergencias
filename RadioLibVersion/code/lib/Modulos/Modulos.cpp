#include <Modulos.h>

Adafruit_SSD1306 display(128, 64, &Wire, 16);

int LCD::Inicializar(void){
    pinMode(16, OUTPUT);
    digitalWrite(16, LOW);
    delay(20);
    digitalWrite(16, HIGH);
    Wire.begin(4, 15);
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false))return 1;
    display.clearDisplay();
    LCD::Letra(1);
    display.setTextColor(WHITE);
    display.display();
    return 0;
}

void LCD::Limpiar(void){
    display.clearDisplay();
    display.display();
}

void LCD::Letra(int Tam){
    display.setTextSize(Tam);
    display.display();    
}

void LCD::Escribir(String Cadena,int x, int y){
    if (x>-1&&y>-1)display.setCursor(x,y);
    if (Cadena!=NULL)display.print(Cadena);
    display.display();
}

SX1276 radio = new Module(18, 26, 14, 35);
volatile bool receivedFlag = false;
volatile bool enableInterrupt = true;

void LORA::setFlag(void){
   if(!enableInterrupt){
       return;
   }else
       receivedFlag = true;
}
   
int LORA::Inicializar(void){
    if (radio.begin()!=ERR_NONE) return 1;
    radio.setFrequency(915.0);
    radio.setBandwidth(500.0);
    radio.startReceive();
    radio.setDio0Action(LORA::setFlag);
    return 0;
}

void LORA::Enviar(String Paquete){
    radio.transmit(Paquete);
    radio.startReceive();
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

String Hora(void){
     return "23:11";
}

String Desglosador (int dato, String gpsRead){
  char aux[15];
  int i,j=0,k=0;
  for (i=0;i<gpsRead.length();i++){
         if (gpsRead[i]==',')j++;
         while(j==dato){
            i++;
            aux[k]=gpsRead[i];
            k++;
            if (gpsRead[i]==','){
              aux[k]=gpsRead[i+1];
              aux[k+1]='\0';
              j=-1;
            }
         }       
         if (j==-1)break;
  }
  String Dato = aux;
  return Dato;
}
