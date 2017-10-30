#include <stdio.h> 
#include <time.h> 
 
void wait(unsigned int seg) 
{ 
	unsigned int retTime = time(0) + seg; //obtiene el tiempo de finalizacion 
	while (time(0)< retTime); //loopea hasta completar el tiempo solicitado
} 
 
int main() 
{ 
	int T=5,i;
	printf("Despegue en T menos\n");
	for (i=0;i<5;i++)
	{ 
		printf("%d\n",T); 
		T--; 
		wait(1); 
	}
	printf("Despegue!!!");
return 0; 
} 
