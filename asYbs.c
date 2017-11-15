#include <stdio.h>
#include <string.h>

int main()
{
  char x[100];
  int i;
  printf("Dame una cadena: ");
  scanf("%s",x);
  if(x[0]=='b' && x[strlen(x)-2]=='a' && x[strlen(x)-1]=='a') //que empieze con b y termine con 2 a
    printf("La cadena es válida\n");
  else
    printf("La cadena no es válida\n");
  return 0;
}
