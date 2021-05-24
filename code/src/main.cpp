#include "Nodo.h"

Nodo nodo;

void setup(){
  if (nodo.Inicializar())while(1);
  nodo.ID('B');
}

void loop() {
  nodo.Leer();
  nodo.Enviar("\"Asistencia\"");
  nodo.Escuchar();
  delay(2000);
}
