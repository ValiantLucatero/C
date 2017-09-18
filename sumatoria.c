#include <stdio.h>

int main()
{
	int n,n1,n2,sum;
	sum=0;
	printf("Dame un numero: ");
	scanf("%i",&n1);
	printf("Dame otro numero: ");
	scanf("%i",&n2);
	if(n1==n2||n1>n2)
		printf("El segundo numero debe de ser mayor al primero\n");
	else
	{
		for(n=n1;n<n2;n++)
		{
			sum=sum+n;
			printf("%i+",n);
		}
		sum=sum+n;
		printf("%i",n);
		printf("=%i\n",sum);
	}
	return 0;
}
