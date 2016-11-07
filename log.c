#include <stdio.h>
#include <math.h>

int main()
{
	float num,res;
	char x;
	printf("Dame un numero:");
	scanf("%f",&num);
	if(num==0)
		printf("No hay logaritmo de cero");
	else
		if(num<0)
			printf("No hat logaritmo de numeros negativos");
		else
		{
			printf("Selecciona una opcion:\na)Logaritmo base 10\nb)Logaritmo Natural\n");
			setbuf(stdin,NULL);
			x=getchar();
			if(x=='a')
			{
				res=log10(num);
				printf("El logaritmo base 10 de %f es %f",num,res);
			}
			else
				if(x=='b')
				{
					res=log(num);
					printf("El logaritmo natural de %f es %f",num,res);
				}
		}
		return 0;
}
