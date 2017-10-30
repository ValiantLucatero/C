#include <stdio.h>

int main()
{
	int n=4,i,j,c=10;
	for(i=0;i<n;i++)
	{
		printf("\n"); //salto de linea para cada renglon
		
		for(j=i;j<n-1;j++)
			printf(" ");  //espacios
		
		for(j=i;j>0;j--)//numeros
			printf("%d",c-j);
			
		printf("%d",c); //cifra columna
		
		for(j=1;j<i+1;j++)//numeros
			printf("%d",c-j);
		
		for(j=i;j<n-1;j++)
			printf(" ");  //espacios
	}
	return 0;
}
