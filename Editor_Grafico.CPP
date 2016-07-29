#include<stdio.h>
#include<conio.h>

int main()
{
	char m;
	int x,y;
	x=10;
	y=10;
        clrscr();
	do
	{
		m=getch();

		if(m=='a')
		{
			gotoxy(--x,y);
			printf("8");
		}
		else
			if(m=='s')
			{
				gotoxy(x,++y);
				printf("8");
			}
			else
				if(m=='d')
				{
					gotoxy(++x,y);
					printf("8");
				}
				else
					if(m=='w')
					{
						gotoxy(x,--y);
						printf("8");
					}
					else
						if(m=='c')
							clrscr();
	}
	while(m!='x');
	return 0;
}