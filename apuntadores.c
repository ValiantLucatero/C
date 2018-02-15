#include<stdio.h>

typedef int entero;

struct ropa
{
	char fabricante[20];
	int coste;
	char descripcion[40];
} *ap;


int main()
{
	int a=10,*p,c;
	entero b=10;
	p=&a;
	c=*p; //b=10
	printf("a=%i,b=%i,c=%i",a,b,c);
	ap->coste=1000;//Acceso al campo coste a traves del puntero ap
	return 0;
}
