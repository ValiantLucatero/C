#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
//#include<dos.h>
#include<ncurses.h>
int j,c;

int menu()
{
       clear();
       initscr();
       start_color();
       init_pair(1, COLOR_RED, COLOR_BLACK);
       //textbackground(15);
       gotoxy(30,20);
       textcolor(5);
       cprintf("Piedra Papel O Tijeras",1);
       gotoxy(20,30);
       textcolor(4);
       cprintf("Presiona cualquier tecla para continuar...",2);
       getch();
       clear();
       return 0;
}
int fondo()
{
	j=0;
	c=0;
	textcolor(8);
	gotoxy(20,15);
	cprintf("Jugador",8);
	gotoxy(23,16);
	textcolor(3);
	cprintf("%i",j,3);
	gotoxy(60,15);
	textcolor(9);
	cprintf("IA",9);
	gotoxy(60,16);
        textcolor(3);
	cprintf("%i",c,3);
	gotoxy(35,20);
	textcolor(6);
	cprintf("Elige una opcion:",6);
	gotoxy(40,21);
	printf("r)Piedra");
	gotoxy(40,22);
	printf("p)Papel");
	gotoxy(40,23);
	printf("s)Tijeras");
	gotoxy(1,30);
	textcolor(6);
	cprintf("Instrucciones:En este juego el objetivo es ganarle a la IA en el clasico juego  de Piedra, Papel o Tijeras!",6);
	return 0;
}
int gameplay()
{
	char e,i;
	j=0;
	c=0;
	do
	{
	e=getch();
	srand(time(NULL));
	i=rand()%3+1;


		if(e=='r'&&i==1)
		{
			gotoxy(20,18);
			printf("Piedra");
			gotoxy(60,18);
			printf("Piedra");
			gotoxy(40,25);
			printf("Empate!");
			gotoxy(20,18);
			delay(2000);
			clreol();
			gotoxy(40,25);
			clreol();
		}
		else
		{
			if(e=='r'&&i==2)
			{
				gotoxy(20,18);
				printf("Piedra");
				gotoxy(60,18);
				printf("Papel");
				gotoxy(40,25);
				printf("IA gana!");
				c=c+1;
				gotoxy(60,16);
				printf("%i",c);
				gotoxy(20,18);
				delay(2000);
				clreol();
				gotoxy(40,25);
				clreol();
			}
			else
			{
				if(e=='r'&&i==3)
				{
					gotoxy(20,18);
					printf("Piedra");
					gotoxy(60,18);
					printf("Tijeras");
					gotoxy(40,25);
					printf("Jugador gana!");
					j=j+1;
					gotoxy(23,16);
					printf("%i",j);
					gotoxy(20,18);
					delay(2000);
					clreol();
					gotoxy(40,25);
					clreol();
				}
				else
				{
				if(e=='p'&&i==1)
					{
						gotoxy(20,18);
						printf("Papel");
						gotoxy(60,18);
						printf("Piedra");
						gotoxy(40,25);
						printf("Jugador gana!");
						j=j+1;
						gotoxy(23,16);
						printf("%i",j);
						gotoxy(20,18);
						delay(2000);
						clreol();
						gotoxy(40,25);
						clreol();
					}
					else
					      {
						if(e=='p'&&i==2)
						{
							gotoxy(20,18);
							printf("Papel");
							gotoxy(60,18);
							printf("Papel");
							gotoxy(40,25);
							printf("Empate!");
							gotoxy(20,18);
							delay(2000);
							clreol();
							gotoxy(40,25);
							clreol();
						}
						else
						{
							if(e=='p'&&i==3)
							{
								gotoxy(20,18);
								printf("Papel");
								gotoxy(60,18);
								printf("Tijeras");
								gotoxy(40,25);
								printf("IA gana!");
								c=c+1;
								gotoxy(60,16);
								printf("%i",c);
								gotoxy(20,18);
								delay(2000);
								clreol();
								gotoxy(40,25);
								clreol();
							}
							else
							{
								if(e=='s'&&i==1)
								{
									gotoxy(20,18);
									printf("Tijeras");
									gotoxy(60,18);
									printf("Piedra");
									gotoxy(40,25);
									printf("IA gana!");
									c=c+1;
									gotoxy(60,16);
									printf("%i",c);
									gotoxy(20,18);
									delay(2000);
									clreol();
									gotoxy(40,25);
									clreol();
								}
								else
								{
									if(e=='s'&&i==2)
									{
										gotoxy(20,18);
										printf("Tijeras");
										gotoxy(60,18);
										printf("Papel");
										gotoxy(40,25);
										printf("Jugador gana!");
										j=j+1;
										gotoxy(23,16);
										printf("%i",j);
										gotoxy(20,18);
										delay(2000);
										clreol();
										gotoxy(40,25);
										clreol();
									}
									else

										if(e=='s'&&i==3)
										{
											gotoxy(20,18);
											printf("Tijeras");
											gotoxy(60,18);
											printf("Tijeras");
											gotoxy(40,25);
											printf("Empate!");
											gotoxy(20,18);
											delay(2000);
											clreol();
											gotoxy(40,25);
											clreol();
										}
										}
										}
										}
										}
										}
										}
										}
	}
	while(e!='x'&&j!=3&&c!=3);
	return 0;
	}
int final ()
{
	if(j==3)
	{
		clear();
		//meter cosa drogada de Kevin
	}
	if(c==3)
	{
		clear();
		//meter cascada en blanco y negro
	}
	return 0;
}
int main()
{
	clear();
	menu();
	fondo();
	gameplay();
	final();
	return 0;
}
