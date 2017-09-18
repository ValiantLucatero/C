#include<stdio.h>

main()
{
	int n,i;
	printf("De cuantos valores quieres sacar promedio? ");
	scanf("%d",&n);
	float sum=0,x=0,res;
	for(i=0;i<n;i++)
	{
		printf("Dame el dato %d: ",i+1);
		scanf("%f",&x);
		sum=sum+x;
	}
	res=sum/n;
	printf("El promedio es:%.3f\n",res);
}
