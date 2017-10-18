#include <stdio.h>

int main() {
  int x,y=0;
  //preguna 1
  printf("Definicion de Algoritmo:\n1)Algo feo\n2)Es un método de resolución de problemas mediante una serie de pasos\n3)Es frio\n4)No se\n");
  scanf("%d",&x);
  if (x==2)
    y++;
  //pregunta 2
  printf("Definicion de Diagrama de Flujo:\n1)Vida\n2)Un metodo para resolver problemas\n3)Representacion grafica de un algoritmo\n4)Nada\n");
  scanf("%d",&x);
  if (x==3)
    y++;
  //pregunta 3
  printf("Definicion de Pseudocodigo:\n1)Combinacion de un lenguaje de programacion con otro idioma como el español\n2)Tu fin\n3)En tu corazon\n4)Una unidad de memoria\n");
  scanf("%d",&x);
  if (x==1)
    y++;
  //pregunta 4
  printf("Definicion de Prueba de Escritorio:\n1)Muerte\n2)Un examen cargado\n3)Lo de arriba\n4)Darle valores al programa y ver si los resultados son correctos\n");
  scanf("%d",&x);
  if (x==4)
    y++;
  //pregunta 5
  printf("Definicion de Variable:\n1)Algo que varia en la vida\n2)Localidad de memoria\n3)Un dia\n4)Un numero\n");
  scanf("%d",&x);
  if (x==2)
    y++;
  //pregunta 6
  printf("Definicion de Operador:\n1)Las cosas que se relacionan entre si\n2)La respuesta esta en tu corazon\n3)Es algo que relaciona\n4)Un signo para decir paz\n");
  scanf("%d",&x);
  if (x==3)
    y++;
  //pregunta 7
  printf("Definicion de Operando:\n1)Las cosas que se relacionan entre si\n2)Es algo que relaciona\n3)La respuesta esta en tu corazon\n4)Un signo para decir paz\n");
  scanf("%d",&x);
  if (x==1)
    y++;
  //pregunta 8
  printf("Es un tipo de operador:\n1)Numerico\n2)La silla\n3):v\n4)Logico\n");
  scanf("%d",&x);
  if (x==4)
    y++;
  //pregunta 9
  printf("Dos tipos de datos:\n1)Silabicos\n2)Estructurados y numericos\n3)Contadores\n4):,v\n");
  scanf("%d",&x);
  if (x==2)
    y++;
  //pregunta 10
  printf("Es un tipo de variable:\n1)Raro\n2)Salvaje\n3)De trabajo\n4)xD\n");
  scanf("%d",&x);
  if (x==3)
    y++;
  //resultados
  printf("Tu puntuacion fue de %d\n",y);
  return 0;
}
