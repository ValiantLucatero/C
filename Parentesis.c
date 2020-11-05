#include <stdio.h>
#include <stdlib.h>

//Estructura
struct nodo
{
  char dato;
  struct nodo *siguiente;
};

//Indicadores
struct nodo *cabeza = NULL; //cabeza de la pila
long contador = 1;
long linea = 1;

//Banderas de chequeo = activa o no | posicion donde se actvo | linea donde se activo
int parentesis[3];
int corchetes[3];
int llaves[3];

//Funciones de la pila
void recorre();
void insertar(char dato);

//Recorre la pila
void recorre()
{
  struct nodo *actual; //Creamos apuntador para iterar sobre la pila
  actual = cabeza; //Le decimos que inicie en la cima de la pila
  while(actual != NULL) //Mientras haya elementos en la pila..
  {
    if(actual->dato == ')') //Abre parentesis
    {
      parentesis[0] = 1;
      parentesis[1] = contador;
      parentesis[2] = linea;
    }
    else if(actual->dato == ']') //Abre corchetes
    {
      corchetes[0] = 1;
      corchetes[1] = contador;
      corchetes[2] = linea;
    }
    else if(actual->dato == '}') //Abre llaves
    {
      llaves[0] = 1;
      llaves[1] = contador;
      llaves[2] = linea;
    }
    else if(actual->dato == '(' && parentesis[0] == 0)
    {
      printf("Cierra parentesis que no estaban abiertos en la linea %d",linea);
      return;
    }
    else if(actual->dato == '[' && corchetes[0] == 0)
    {
      printf("Cierra corchetes que no estaban abiertos en la linea %d",linea);
      return;
    }
    else if(actual->dato == '{' && llaves[0] == 0)
    {
      printf("Cierra llaves que no estaban abiertas en la linea %d",linea);
      return;
    }
    else if(actual->dato == '(' && parentesis[0] == 1 && parentesis[1] > corchetes[1] && parentesis[1] > llaves[1]) //Cierra bien parentesis
    {
      parentesis[0] = 0;
      parentesis[1] = 0;
      parentesis[2] = 0;
    }
    else if(actual->dato == '[' && corchetes[0] == 1 && corchetes[1] > parentesis[1] && corchetes[1] > llaves[1]) //Cierra bien corchetes
    {
      corchetes[0] = 0;
      corchetes[1] = 0;
      corchetes[2] = 0;
    }
    else if(actual->dato == '{' && llaves[0] == 1 && llaves[1] > parentesis[1] && llaves[1] > corchetes[1]) //Cierra bien llaves
    {
      llaves[0] = 0;
      llaves[1] = 0;
      llaves[2] = 0;
    }
    else if(actual->dato == '(' && parentesis[0] == 1 && (parentesis[1] < corchetes[1] || parentesis[1] < llaves[1]))
    {
      printf("Cierra antes corchetes o llaves que parentesis en la linea %d",linea);
      return;
    }
    else if(actual->dato == '[' && corchetes[0] == 1 && (corchetes[1] < parentesis[1] || corchetes[1] < llaves[1]))
    {
      printf("Cierra antes parentesis o llaves que corchetes en la linea %d",linea);
      return;
    }
    else if(actual->dato == '{' && llaves[0] == 1 && (llaves[1] < parentesis[1] || llaves[1] < corchetes[1]))
    {
      printf("Cierra antes parentesis o corchetes que llaves en la linea %d",linea);
      return;
    }
    if(actual->dato == '\n') //Si encuentra un salto de linea
      linea --; //Se lo resta al total
    contador ++; //Aumentamos el contador de caracteres
    actual = actual->siguiente; //Avanzamos en la pila
  }
  if(parentesis[0] == 1)
  {
    printf("Deja parentesis abiertos en la linea %d",parentesis[2]);
    return;
  }
  if(corchetes[0] == 1)
  {
    printf("Deja corchetes abiertos en la linea %d",corchetes[2]);
    return;
  }
  if(llaves[0] == 1)
  {
    printf("Deja llaves abiertas en la linea %d",llaves[2]);
    return;
  }
  printf("Archivo correcto :D");
}

void insertar(char dato)
{
  struct nodo *nuevoNodo; //Creamos nuevo apuntador
  nuevoNodo = malloc(sizeof(struct nodo)); //Le asignamos espacio en memoria
  nuevoNodo->dato = dato; //Metemos el caracter en el nodo
  nuevoNodo->siguiente = cabeza; //Lo ponemos en la cima de la pila
  cabeza = nuevoNodo; //Decimos que es la nueva cima
}

int main()
{
  FILE *fp; //Declaramos el apuntador del archivo
  char con; //Variable para leer el contenido
  char ruta[100]; //Variable para la ruta del archivo
  printf("Ingresa la ruta del archivo a analizar: ");
  scanf("%99s",&ruta); //Recibimos ruta del archivo
  fp = fopen(ruta,"r"); //Abriendo el archivo
  if (!fp) //Revisa si hay error
    return 1; //Termina el programa
  while (!feof(fp)) //Lee el contenido del archivo
  {
    con = fgetc(fp); //Obtenemos un caracter
    insertar(con); //Lo insertamos a la pila
    if(con == '\n') //Si encuentra un salto de linea
      linea ++; //Agrega al numero de lineas del archivo
  }
  fclose(fp); // Cierra el archivo
  recorre(); //Funcion que recorre la pila
  return 0;
}
