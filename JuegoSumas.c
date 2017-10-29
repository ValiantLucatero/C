#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int vidas=3,i=1,j=2,suma,x,k=0;
	while(vidas>0)
	{
		srand(time(NULL));
		i=1+rand()%20;
		j=1+rand()%20;
		suma=i+j;
		printf("Dame la suma de %d+%d: \n",i,j);
		scanf("%d",&x);
		if(x!=suma)
		vidas--;
		k++;
	}
	printf("Felicidades llegaste a la ronda %d",k);
	return 0;
}
