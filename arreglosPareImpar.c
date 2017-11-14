#include <stdio.h>

int main()
{
	int x,j;
	printf("De que tamaño quieres los arreglos?\n");
	scanf("%d",&x);
	int p[x],i[x];
	printf("Arreglo par\n");
	for(j=0;j<x+4;j=j+2)
	{
		p[j]=j+2;
		printf("%d\n",p[j]);
	}
	printf("Arreglo impar\n");
	for(j=0;j<x+4;j=j+2)
	{
		i[j]=j+1;
		printf("%d\n",i[j]);
	}
	
	return 0;
}
