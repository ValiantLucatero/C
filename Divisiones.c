#include <stdio.h>
#define tol .001
#define p printf
#define s scanf
#define PI 3.141516923495
#define Manuel main
Manuel()
{
	float x;
	p("Dame un numero");
	s("%f",&x);
	int i=0;
	while(x>tol)
	{
		x=x/2;
		i++;
	}
	p("Se realizaron %d divisiones",i);
}
