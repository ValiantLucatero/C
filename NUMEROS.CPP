#include<stdio.h>

int main()
{
	char num;
	do
	{
		printf("\nDame numero");
		num=getche();
		if(num=='1')
			printf("\nuno");
		else
			if(num=='2')
				printf("\ndos");
			else
				if(num=='3')
					printf("\ntres");
	}
	while(num!='s');
	return 0;
}
