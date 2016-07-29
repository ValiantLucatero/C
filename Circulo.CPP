#include<stdio.h>
#include<math.h>
#define pi 3.1416

int main()
{
	float r,ar,per;
	printf("Introduce el radio:");
	scanf("%f",&r);
	ar=pi*r*r;
	per=pi*(r+r);
	printf("El perimetro es:%f \n El area es:%f",per,ar);
	return 0;
}
