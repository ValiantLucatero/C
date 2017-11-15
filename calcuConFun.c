#include <stdio.h>
#include <math.h>

int suma(int a,int b)
{
  int res=a+b;
  return res;
}
int resta(int a,int b)
{
  int res=a-b;
  return res;
}
int multiplicacion(int a,int b)
{
  int res=a*b;
  return res;
}
double division(int a,int b)
{
  double res=(float)a/b;
  return res;
}
double coseno(double a)
{
  a=a*0.0174533;
  double res=cos(a);
  return res;
}
double seno(double a)
{
  a=a*0.0174533;
  double res=sin(a);
  return res;
}
double potencia(double a,double b)
{
  double res=pow(a,b);
  return res;
}
double tangente(double a)
{
  a=a*0.0174533;
  double res=tan(a);
  return res;
}
int main()
{
  int x,y,s=9,res;
  double res1;
  printf("Dame un numero: ");
  scanf("%d",&x);
  printf("Dame otro numero: ");
  scanf("%d",&y);
  do
  {
    printf("Elige la operación a realizar:\n1)Suma\n2)Resta\n3)Multiplicación\n4)División\n5)Coseno\n6)Seno\n7)Potencia\n8)Tangente\n0)Salir\n");
    scanf("%d",&s);
    if(s==1)
    {
      res=suma(x,y);
      printf("%d + %d = %d\n",x,y,res);
    }
    if(s==2)
    {
      res=resta(x,y);
      printf("%d - %d = %d\n",x,y,res);
    }
    if(s==3)
    {
      res=multiplicacion(x,y);
      printf("%d x %d = %d\n",x,y,res);
    }
    if(s==4)
    {
      res1=division(x,y);
      printf("%d / %d = %f\n",x,y,res1);
    }
    if(s==5)
    {
      res1=coseno(x);
      printf("cos(%d) = %f\n",x,res1);
    }
    if(s==6)
    {
      res1=seno(x);
      printf("sen(%d) = %f\n",x,res1);
    }
    if(s==7)
    {
      res1=potencia(x,y);
      printf("%d ˆ %d = %f\n",x,y,res1);
    }
    if(s==8)
    {
      res1=tangente(x);
      printf("tan(%d) = %f\n",x,res1);
    }
    if(s>=9)
    {
      printf("Ingresa una opción válida\n");
    }
  }
  while(s!=0);
  return 0;
}
