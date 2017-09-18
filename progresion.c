#include<stdio.h>
main()
{
	int A,N,D;
	int K=0;
	int res=0;
	printf("Dame A: ");
	scanf("%d",&A);
	printf("Dame D: ");
	scanf("%d",&D);
	printf("Dame N: ");
	scanf("%d",&N);
	while(K<N)
	{
		res=res+(A+(K*D));
		K=K+1;
		//K++;
	}
	printf("El resultado es: %d\n",res);
}
