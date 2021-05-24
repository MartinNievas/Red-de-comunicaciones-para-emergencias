#include <SPI.h>
#include <Wire.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>

#ifndef DSPY_H
  #define DSPY_X
  
  extern Adafruit_SSD1306 display;
  
  namespace LCD{
     extern int Inicializar(void);
     extern void Limpiar(void);
     extern void Escribir(String,int);   
  }

#endif
