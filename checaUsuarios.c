#include <stdio.h>
#include <string.h>

int main()
{
	char nombre [30];
	char u1[30]="Manuel";
	char u2[30]="Andres";
	printf("Dame tu nombre: \n");
	fflush(stdin);
	gets(nombre);
	
	if(strcmp(nombre,"Manuel")==0)//string comparation
	printf("El usuario ya existe :)");
	else if(strcmp(nombre,"Andres")==0)
	printf("El usuario ya existe :)");
	else
	printf("Usuario no registrado");
	return 0;
}
