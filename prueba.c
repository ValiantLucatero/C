#include <stdlib.h>
#include <stdio.h>

typedef struct
//struct fecha
{
	int d,m,y;
}fecha;

int main()
{
	//struct fecha hoy;
	fecha hoy;
	hoy.d=12;
	hoy.m=2;
	hoy.y=2018;
	printf("Fecha: %d/%d/%d",hoy.d,hoy.m,hoy.y);
	return 0;
}

