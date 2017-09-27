#include<stdio.h>
#include<string.h>

main()
{
	int x,div,i,j;
	char resi;
	i=0;
	int resp[100];
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
		if (resi==11)
		{
			resi=66;
		}
		if (resi==12)
		{
			resi=67;
		}
		if (resi==13)
		{
			resi=68;
		}
		if (resi==14)
		{
			resi=69;
		}
		if (resi==15)
		{
			resi=70;
		}
		resp[i]=resi;
		i++;
	}
	printf("%d en hexadecimal es: ",x);
	for(j=i-1;j>=0;j--)
	{
		printf("%c",resp[j]);
	}
	printf("\n");
}
