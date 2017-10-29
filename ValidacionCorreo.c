#include <stdio.h>
#include <string.h>

int main()
{
	char cad[30];
	int b=0;
	do
	{
		fflush(stdin);
		gets(cad);
		for(int i=0;i<strlen(cad);i++)
		if(cad[i]=='@')
		b=1;
		else
		b=0;
	}
	while(b==0);
	if(b==1)
	printf("Correo valido");
	else
	printf("Correo no valido");
	return 0;
}
