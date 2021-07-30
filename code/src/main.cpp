#include <Nodo.h>

Nodo nodo('A');

void setup(){
  if (nodo.Inicializar())while(1);
}

void loop() {

  nodo.Pantalla();
  delay(1000);
  nodo.Escuchar();
  nodo.Enviar(Mensajes());

}