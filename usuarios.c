#include <stdio.h>
#include <string.h>

int main()
{
  int edad1, edad2;
  float altura1, altura2;
  float peso1, peso2;
  long int celular1, celular2;
  float promedio1, promedio2;
  char nombre1[50], nombre2[50];

  printf("Dame el nombre del primer usuario: ");
  scanf("%s",nombre1);
  printf("Dame el nombre del segundo usuario: ");
  scanf("%s",nombre2);
  printf("Dame la edad del primer usuario: ");
  scanf("%d",&edad1);
  printf("Dame la edad del segundo usuario: ");
  scanf("%d",&edad2);
  printf("Dame la altura del primer usuario: ");
  scanf("%f",&altura1);
  printf("Dame la altura del segundo usuario: ");
  scanf("%f",&altura2);
  printf("Dame el peso del primer usuario: ");
  scanf("%f",&peso1);
  printf("Dame el peso del segundo usuario: ");
  scanf("%f",&peso2);
  printf("Dame el celular del primer usuario: ");
  scanf("%li",&celular1);
  printf("Dame el celular del segundo usuario: ");
  scanf("%li",&celular2);
  printf("Dame el promedio del primer usuario: ");
  scanf("%f",&promedio1);
  printf("Dame el promedio del segundo usuario: ");
  scanf("%f",&promedio2);

  if (edad1<edad2)
  {
    printf("\nNombre: %s\n",nombre1);
    printf("Edad: %d\n",edad1);
    printf("Altura: %f\n",altura1);
    printf("Peso: %f\n",peso1);
    printf("Celular: %li\n",celular1);
    printf("Promedio: %f\n\n",promedio1);

    printf("Nombre: %s\n",nombre2);
    printf("Edad: %d\n",edad2);
    printf("Altura: %f\n",altura2);
    printf("Peso: %f\n",peso2);
    printf("Celular: %li\n",celular2);
    printf("Promedio: %f\n",promedio2);
  }
  else
  {
    printf("\nNombre: %s\n",nombre2);
    printf("Edad: %d\n",edad2);
    printf("Altura: %f\n",altura2);
    printf("Peso: %f\n",peso2);
    printf("Celular: %li\n",celular2);
    printf("Promedio: %f\n\n",promedio2);

    printf("Nombre: %s\n",nombre1);
    printf("Edad: %d\n",edad1);
    printf("Altura: %f\n",altura1);
    printf("Peso: %f\n",peso1);
    printf("Celular: %li\n",celular1);
    printf("Promedio: %f\n",promedio1);
  }
  return 0;
}
