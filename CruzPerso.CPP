#include<stdio.h>
#include<conio.h>
void linea1(char caracter)
{
	printf("%c %c\n",caracter,caracter);
	return;
}

void linea2(char caracter)
{
	printf(" %c \n",caracter);
	return;
}

void linea3(char caracter)
{
	printf("%c %c\n",caracter,caracter);
	return;
}
int main()
{
	char car;
	int x;
	int y;
	clrscr();
	printf("Introduzca caracter");
	car=getch();
	clrscr();
	printf("Introduzca coordenadas");
	scanf("%i,%i",&x,&y);
	clrscr();
	gotoxy(x,y);
	linea1(car);
	gotoxy(x,y+1);
	linea2(car);
	gotoxy(x,y+2);
	linea3(car);
	return 0;
}