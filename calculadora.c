#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
  int a,b;
  float val;
  val=PI/180;
  printf("Dame un numero: ");
  scanf("%d",&a);
  printf("Dame otro numero: ");
  scanf("%d",&b);
  printf("%d+%d=%d\n",a,b,a+b);
  printf("%d-%d=%d\n",a,b,a-b);
  printf("%dx%d=%d\n",a,b,a*b);
  if (b==0)
    printf("La division entre cero esta indefinida\n");
  else
    printf("%d/%d=%f\n",a,b,(float)a/b);
  printf("%dˆ%d=%f\n",a,b,pow(a,b));
  printf("√%d = %f y √%d = %f\n",a,sqrt(a),b,sqrt(b));
  printf("Sen(%d)=%f y Sen(%d)=%f\n",a,sin(a*val),b,sin(b*val));
  printf("Cos(%d)=%f y Cos(%d)=%f\n",a,cos(a*val),b,cos(b*val));
  printf("Tan(%d)=%f y Tan(%d)=%f\n",a,tan(a*val),b,tan(b*val));
  return 0;
}
