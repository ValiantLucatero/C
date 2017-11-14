#include <stdio.h>

int main()
{
	int n,a,b=0;
	printf("Cuantas variables quieres en el arreglo: \n");
	scanf("%d",&n);
	
	int x[n];
	
	for(int i=0;i<n;i++)
	{
		printf("Dame el valor de la variable X[%d]\n",i);
		scanf("%d",&x[i]);
	}
	printf("Que valor deseas buscar?\n");
	scanf("%d",&a);
	
	for(int i=0;i<n;i++)
	if(a==x[i])
	{
		printf("\nLa variable %d se encuentra en la posicion %d ",a,i);
		b=1;
	}
	if(b==0)
	printf("La variable no se encuentra");
	return 0;
}
