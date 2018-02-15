#include <stdio.h>

char cadena[5]="hola";
int a=2;

int main()
{
	printf("%c\n\r",cadena[a+1]);
	int i;
	for(i=0;i<5;i++)
	{
		printf("%c",cadena[i+a]);
	}
	return 0;
}

