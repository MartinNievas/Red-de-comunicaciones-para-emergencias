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
    display.setTextSize(1);
    display.setCursor(0,0); 
    display.display();
    return 0;
}

void LCD::Limpiar(void){
    display.clearDisplay();
    display.display();
}

void LCD::Escribir(String Cadena,int Renglon){
    switch (Renglon){
        case 0:break;
        case 1: display.setCursor(0,0);break;
        case 2: display.setCursor(0,10);break;
        case 3: display.setCursor(0,20);break;
        case 4: display.setCursor(0,30);break;
        case 5: display.setCursor(0,40);break;
        case 6: display.setCursor(0,55);break;
    }
    if (Cadena!=NULL)display.print(Cadena);
    display.display();
}
