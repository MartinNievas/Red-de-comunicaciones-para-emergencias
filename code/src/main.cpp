#include <Nodo.h>

Nodo nodo;

void setup(){
  if (nodo.Inicializar())while(1);
  nodo.ID('A');
}


void loop() {

  nodo.Pantalla();
  delay(1000);
  nodo.Escuchar();
  nodo.Enviar(Mensajes());

}