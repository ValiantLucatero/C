#include<stdio.h>

int main()
{
    int i,r,vec[5];
    r=0;
    for(i=0;i<5;i++)
    {
      printf("Ingresa numero:");
      scanf("%i",&vec[i]);
      vec[i]=vec[i]*(i+1);
      printf("Resultado:%i\n",vec[i]);
    }
    for(i=0;i<5;i++)
      r=r+vec[i];
    printf("La suma final es:%i",r);
    return 0;
}
