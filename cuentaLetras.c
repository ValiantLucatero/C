#include <stdio.h>
#include <string.h>

int main()
{
	char cad[50];
	int i,l,p=0;
	//fflush(stdin);
	gets(cad);
	for(i=0;i<strlen(cad);i++)
		if(cad[i]==' ')
			p++;
	p++;
	l=strlen(cad)-p;
	printf("En esta cadena hay %d letras y %d palabras",l,p);
	return 0;
}
