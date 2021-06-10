# PPS---Red-de-comunicaciones-para-emergencias

El objetivo del trabajo es medir las capacidades prácticas de una red de comunicación distribuida, utilizando nodos de comunicación.
Los nodos de comunicación están compuestos por el kit `Heltec WIFI Lora Kit 32 V2`, el cual, entre otros módulos, cuenta con:

- Módulo LoRa SX1276, 433MHz/915MHz
- 0.96 Inch OLED Display

<p align="center">
  <img src="https://user-images.githubusercontent.com/64157418/121102965-35d44f80-c7d5-11eb-8e0e-ae933342aa42.jpeg"
       alt = "Nodo de comunicación LoRa">
</p>

La red se puede expandir hasta n nodos, donde todos se comunican con todos, conceptualmente como en una red mesh.

<p align="center">
  <img src="https://user-images.githubusercontent.com/64157418/121569800-8cb96f00-c9f7-11eb-8e5f-ee2202dde8b4.png"
       alt = "Dos nodos de comunicación">
</p>

Los paquetes de comunicación están formados por la identificación respectiva del nodo, el mensaje que se quiere transmitir y distintos datos extraídos de módulos externos a implementar, conforme a la estructura:

<p align="center">
  <img src="https://user-images.githubusercontent.com/64157418/121571160-0a31af00-c9f9-11eb-9f95-53d2003a81c5.png"
       alt = "Arquitectura del paquete">
</p>

Un ejemplo de paquete transmitido sería "A-4916.06,N-12311.12,W-17:14-71.32-HERIDO-".
