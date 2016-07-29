#include<stdio.h>
long int factorial(int x)
{
  long int a,y;
	a=1;
	for(y=1;y<=x;y++)
		a=a*y;
	return a;
}

int main()
{
	int x;
	long int res;
	printf("Dame un numero:");
	scanf("%i",&x);
	if(x<0)
		printf("No hay factorial de numeros negativos");
	else
	{
		res=factorial(x);
		printf("El factorial es:%ld",res);
	}
	return 0;
}
