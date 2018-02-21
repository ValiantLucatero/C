#include<stdio.h>
int main()
{
  double x[5]={1.1,2.1,3.1,4.1,5.1};
  double *p=&x[1],
         *q=&x[4];
  int n;
  n=q-p; // n=3
  printf("q-p=%i",n);
  return 0;
}
