#include <stdio.h>

int main()
{
  int a,b;
  printf("Dame un numero: ");
  scanf("%d",&a);
  printf("Dame otro numero: ");
  scanf("%d",&b);
  printf("%d+%d=%d\n",a,b,a+b);
  printf("%d-%d=%d\n",a,b,a-b);
  printf("%dx%d=%d\n",a,b,a*b);
  if (b==0)
    printf("La division entre cero esta indefinida");
  else
    printf("%d/%d=%f\n",a,b,(float)a/b);
  return 0;
}
