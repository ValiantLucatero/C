#include<stdio.h>
#include<conio.h>
void linea1(char caracter)
{
	printf("%c %c\n",caracter, caracter);
	return;
}
void linea2(char caracter)
{
	printf(" %c \n",caracter);
	return;
}

int main()
{       char car;
	clrscr();
	printf("Introduzca caracter");
	car=getch();
        clrscr();
	linea1(car);
	linea2(car);
	linea1(car);
	return 0;
}