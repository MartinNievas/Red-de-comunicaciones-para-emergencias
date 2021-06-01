#include <Display.h>

Adafruit_SSD1306 display(128, 64, &Wire, 16);

int LCD::Inicializar(void){
    pinMode(16, OUTPUT);
    digitalWrite(16, LOW);
    delay(20);
    digitalWrite(16, HIGH);
    Wire.begin(4, 15);
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false))return 1;
    display.clearDisplay();
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
