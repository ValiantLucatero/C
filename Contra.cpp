#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char contra[30] = "hola"; 
char con[30];
 

main (){ 
	printf("Dame la contraseña del sistema : \n");
	gets(con);

	if (strcmp(contra,con)== 0) {

		system("cls");
		printf("Iniciando sesion"); 
		printf(".");
		printf(".");
		printf(".");
	}
else { 
	printf ("Que bobo X2, dame la constraseña de nuevo") ; 
	printf("\nDame la constraseña bobo : ");
	gets(con); 

		if (strcmp(contra,con)== 0) {
		system("cls");
		printf("Iniciando sesion"); 
		printf(".");
		printf("."); 
		printf(".");
	}
	else {
			printf ("Que bobo X3, dame la constraseÃ±a de nuevo") ; 
			printf("\nDame la constraseña bobo : ");
			gets(con); 

				if (strcmp(contra,con)== 0) {
				system("cls");
				printf("Iniciando sesion");
				printf(".");
				printf("."); 
				printf(".");
				}
				else {
				printf ("Que bobo X4, dame la constraseña de nuevo") ; 
				printf("\nDame la constraseña bobo : ");
				gets(con); 

						if (strcmp(contra,con)== 0) {

						system("cls");						
						printf("Iniciando sesion");
						 
						printf(".");
					
						printf(".");
					
						printf(".");
						}
						else {
							system("cls");
							printf("Ya valio, la Destruccion del mundo es inminente\n Fin de la Transmision");

						}
			}


	}




}



}
