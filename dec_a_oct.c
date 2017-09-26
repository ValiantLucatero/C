#include<stdio.h>

main()
{
	int x,div,i,j,resi;
	i=0;
	int resp[100];
	printf("Ingresa un numero: ");
	scanf("%d",&x);
	div=x;
	while(div>=1)
	{
		resi=div%8;
		div=div/8;
		resp[i]=resi;
		i++;
	}
	printf("%d en binario es: ",x);
	for(j=i-1;j>=0;j--)
	{
		printf("%d",resp[j]);
	}
	printf("\n");
}
