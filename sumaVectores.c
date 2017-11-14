#include <stdio.h>

int main()
{
	int x,j;
	printf("De que tamaño quieres los arreglos?\n");
	scanf("%d",&x);
	int p[x],i[x],r[x];
	for(j=0;j<x;j++)
	{
		printf("Dame el numero %d del primer arreglo\n",j+1);
		scanf("%d",&p[j]);
	}
	for(j=0;j<x;j++)
	{
		printf("Dame el numero %d del segundo arreglo\n",j+1);
		scanf("%d",&i[j]);
	}
	for(j=0;j<x;j++)
	{
		r[j]=p[j]+i[j];
		printf("%d + %d = %d\n",p[j],i[j],r[j]);
	}
	return 0;
}
