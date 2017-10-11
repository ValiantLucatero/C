#include <stdio.h>

int main() {
  char caracter;
  int entero;
  float flotante;
  bool booleano;
  double doble;
  long int enteroLargo;
  unsigned int sinSignoEntero;
  long double dobleLargo;
  short int enteroCorto;
  unsigned short int sinSignoCortoEntero;
  unsigned long int sinSignoLargoEntero;

  printf("Dame un caracter: ");
  scanf("%c",&caracter);
  printf("Dame un entero: ");
  scanf("%d",&entero);
  printf("Dame un flotante: ");
  scanf("%f",&flotante);
  printf("Dame un booleano: ");
  scanf("%d",&booleano);
  printf("Dame un doble: ");
  scanf("%lf",&doble);
  printf("Dame un entero largo: ");
  scanf("%li",&enteroLargo);
  printf("Dame un entero sin signo: ");
  scanf("%u",&sinSignoEntero);
  printf("Dame un doble largo: ");
  scanf("%Le",&dobleLargo);
  printf("Dame un entero corto: ");
  scanf("%hi",&enteroCorto);
  printf("Dame un entero corto sin signo: ");
  scanf("%hu",&sinSignoCortoEntero);
  printf("Dame un entero largo sin signo: ");
  scanf("%lu",&sinSignoLargoEntero);

  printf("Caracter:%c\n",caracter);
  printf("Entero:%d\n",entero);
  printf("Flotante:%f\n",flotante);
  printf("Booleano:%d\n",booleano);
  printf("Doble:%lf\n",doble);
  printf("Entero Largo:%li\n",enteroLargo);
  printf("Entero sin signo:%u\n",sinSignoEntero);
  printf("Doble largo:%Le\n",dobleLargo);
  printf("Entero corto:%hi\n",enteroCorto);
  printf("Entero corto sin signo:%hu\n",sinSignoEnteroCorto);
  printf("Entero largo sin signo:%lu\n",sinSignoLargoEntero);
  return 0;
}
