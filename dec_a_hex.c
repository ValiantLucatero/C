#include<stdio.h>
#include<string.h>

main()
{
	int x,div,i,j;
	char resi[100];
	i=0;
	int resp;
	printf("Ingresa un numero: ");
	scanf("%d",&x);
	div=x;
	while(div>=1)
	{
		resi=div%16;
		div=div/16;
		if (resi==10)
		{
			resi=65;
		}
		if (resi=="11")
		{
			resi="B";
		}
		if (resi=="12")
		{
			resi="C";
		}
		if (resi=="13")
		{
			resi="D";
		}
		if (resi=="14")
		{
			resi="E";
		}
		if (resi=="15")
		{
			resi="F";
		}
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
