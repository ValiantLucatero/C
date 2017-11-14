#include <stdio.h>

int main()
{
	int x,j,suma=0;
	float res;
	printf("De que tamaño quieres el arreglo?\n");
	scanf("%d",&x);
	int p[x];
	for(j=0;j<x;j++)
	{
		printf("Dame el numero %d del arreglo\n",j+1);
		scanf("%d",&p[j]);
		suma=suma+p[j];
	}
	res=suma/x;
	printf("El promedio del arreglo es %f",res);
	return 0;
}
