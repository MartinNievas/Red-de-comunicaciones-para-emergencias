#include <RadioLib.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_SDA 4
#define OLED_SCL 15 
#define OLED_RST 16
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);

SX1276 radio = new Module(18, 26, 14, 35);

void setup() {
  
  Serial.begin(9600);
  pinMode(OLED_RST, OUTPUT);
  digitalWrite(OLED_RST, LOW);
  delay(20);
  digitalWrite(OLED_RST, HIGH);
  
  Wire.begin(OLED_SDA, OLED_SCL);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); 
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  if (radio.begin() == ERR_NONE) {
    display.print("Inicializando...");
  } else {
    display.print("ERROR");
    while (true);
  } 
  display.display();
  radio.setFrequency(915.0);
  radio.setBandwidth(500.0);
  radio.startReceive();
  radio.setDio0Action(setFlag);
  delay(1000);
}

volatile bool receivedFlag = false;
volatile bool enableInterrupt = true;

void setFlag(void) {
  if(!enableInterrupt) {
    return;
  }else
  receivedFlag = true;
}

void Receptor();
void Transmisor();
String GPS();
String Hora();
String Bateria();
String Mensaje();
void Auxiliar(String);

void loop() {
  
  if(receivedFlag) {
    enableInterrupt = false;
    receivedFlag = false;
    Receptor();
    enableInterrupt = true;
  }
  Transmisor();
  radio.startReceive();
  delay(2000);
}

char aux[5][15];
const char NodeID = 'A';

void Receptor (){
  
  String str="";
  display.clearDisplay();
  if (radio.readData(str)==ERR_NONE && str[0]!=NodeID && str!=""){
   Auxiliar(str);
   display.setCursor(0,0);
   display.print("MENSAJE RECIBIDO");
   display.setCursor(0,10);
   display.print("De: ");
   display.print(aux[0]);
   display.setCursor(0,20);
   display.print("Pos: ");
   display.print(aux[1]);
   display.setCursor(0,30);
   display.print("Hora: ");
   display.print(aux[2]);
   display.setCursor(0,40);
   display.print("Bat: ");
   display.print(aux[3]);
   display.setCursor(0,55);
   display.print(aux[4]);
  }
  Serial.println(str);
  display.display();   
}

void Transmisor (){

  String dp="-";
  String pqt=NodeID+dp+GPS()+dp+Hora()+dp+Bateria()+dp+Mensaje()+dp;
  if (radio.transmit(pqt)==ERR_NONE)Serial.println("Tx Success");  
}

String GPS(){
  return "(146,231,22)";
}

String Hora(){
  return "2:07";
}

String Bateria(){
  return "1 minuto";
}

String Mensaje(){
  
  switch (random(0,4)) {
    case 0:return("\"ASISTENCIA\"");
    case 1:return("\"HERIDO\"");   
    case 2:return("\"CONTROLADO\"");   
    case 3:return("\"OK\"");   
  }
}

void Auxiliar(String str){
  int j,i=0,k=0;
  
  for (j=0;j<5;j++)strcpy(aux[j],"");
  
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
}
