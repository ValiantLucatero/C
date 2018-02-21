#include<stdio.h>
#include<stdlib.h>
int main()
{
  float *p;
  p=(float*)malloc(5*sizeof(float));
  //apartamos 5 espacios float y guardamos la direccion de esa zona apartada en p
  //si no pudiera hacerlo devuelve un nulo
  free(p); //liberamos la zona
  return 0;
}
