#include<stdio.h>

main()
{
	int n;
	printf("Dame un numero: ");
	scanf("%d",&n);
	if(n%2==0||n%3==0||n%5==0)
		printf("No es primo\n");
	else
		printf("Es primo\n");
}
