#include<stdio.h>

int x1, x2, x3, x4, x5, x6, op;

main(){


printf ("\nElige un numero: 8 o 3\n");
scanf ("%d", &op);

if(op==3){
	x1=3;
}
else{
	x1=8;
}
printf ("\nElige un numero: 1 o 6\n");
scanf ("%d", &op);

if(op==1){
	x2=1;
}
else{
	x2=6;
}

printf ("\nElige un numero: 2 o 6\n");
scanf ("%d", &op);

if(op==2){
	x3=2;
}
else{
	x3=6;
}

printf ("\nElige un numero: 3 o 6\n");
scanf ("%d", &op);

if(op==3){
	x4=3;
}
else{
	x4=6;
}

printf ("\nElige un numero: 4 o 6\n");
scanf ("%d", &op);

if(op==4){
	x5=4;
}
else{
	x5=6;
}

printf ("\nElige un numero: 5 o 6\n");
scanf ("%d", &op);

if(op==5){
	x2=5;
}
else{
	x2=6;
}

printf ("\nLa suma conseguida es: %d ", x1+x2+x3+x4+x5+x6);

}
