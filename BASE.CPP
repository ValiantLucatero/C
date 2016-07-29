#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<dos.h>
char n[20][10],s[10];
int e[2][10],m,x,d;

void menu()
{
	char o;
	clrscr();
	printf("1)Alta\n2)Consulta\n3)Salir");

}
void alta()
{
	int i,y;
	char palabra;
	i=0;
	clrscr();
	printf("Nombre:");
	do
	{
		palabra=getche();
		y=isalpha(palabra);
		if(i<=20&&y!=0)
		{
		      n[i][m]=palabra;
		      i++;
		}
	}
	while(palabra!=13);
	n[i][m]='\0';
	m++;
	printf("\nSexo:");
	i=0;
	do
	{
		palabra=getche();
		y=isalpha(palabra);
		if(i<=1&&y!=0)
		{
			s[i]=palabra;
			i++;
		}
	}
	while(palabra!=13);
	s[i]='\0';
	x++;
	printf("\nEdad:");
	i=0;
	do
	{
		palabra=getche();
		y=isdigit(palabra);
		if(i<=2&&y!=0)
		{
			e[i][d]=palabra;
			i++;
		}
	}
	while(palabra!=13);
        e[i][d]='\0';
	d++;

	printf("\n1)Otro\n2)Salir");
	i=getch();
	if(i=='1')
		alta();
	else
		if(i=='2')
			menu();
	return;
}
void consulta()
{
	int i,y;
	clrscr();
	do
	{
		for(y=0;y<=10;y++)
		{
			for(i=0;i<=20;i++)
				printf("%c",n[i][y]);
                                delay(3000);
		}
	}
	while(n[i][y]!='\0');
	do
	{
		for(y=0;y<=10;y++)
			for(i=0;i<=1;i++)
				printf("%c",
	return;
}
int main ()
{
	char o;
	m=0;
	x=0;
	d=0;
	o=0;
	while (o!='3')
	{
		menu();
		o=getch();
		if(o=='1')
			alta();
		else
			if(o=='2')
				consulta();

	}
	return 0;
}