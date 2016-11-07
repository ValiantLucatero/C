#include <math.h>
#include <stdio.h>
#include <ctype.h>
#define pi acos(-1.0)

int main()
{
	float num;
	char x;
	float res;
	num=0;
	x=0;
	res=0;
	printf("Dame un numero ");
	num = getchar();
	if(isdigit(num))
	{
		num=num*pi/180;
		printf("Que quieres sacar?\na)Seno\nb)Coseno\nc)Tangente\n");
		setbuf(stdin,NULL);
		x=getchar();
		if(x=='a')
			res=sin(num);
		else
			if(x=='b')
				res=cos(num);
			else
				if(x=='c')
					res=tan(num);
		printf("Tu resultado es:%f\n",num);
	}
	else
		printf("El valor que ingresado no es numerico");
	return 0;
}
