#include <stdio.h>
#include <stdlib.h>

//Estructura
struct nodo
{
  int dato;
  struct nodo *siguiente;
};

//Indicadores
struct nodo *cabeza = NULL;
short borrarPrimero = 0;

//Funciones de la lista
void imprimir();
struct nodo * buscar(int dato);
void insertar(int dato);
void borrar(struct nodo *anterior);

//Imprime lista
void imprimir()
{
  if(cabeza == NULL) //lista vacía
    printf("La lista está vacía\n");
  else
  {
    struct nodo *actual;
    actual = cabeza;
    while(actual != NULL)
    {
      printf("   %i",actual->dato);
      actual = actual->siguiente;
    }
    printf("\n");
  }
}

//Busca si el número existe en la lista
struct nodo * buscar(int dato)
{
  struct nodo *anterior = NULL;
  anterior = cabeza;
  if(cabeza == NULL) //lista vacía
    printf("La lista está vacía\n");
  else if(cabeza->dato == dato)//el número que buscas es el primero
  {
    printf("%d si está en la lista! :)\n",dato);
    borrarPrimero = 1; //activas bandera
    return anterior; //en realidad es el actual
  }
  else
  {
    while(anterior->siguiente != NULL && anterior->siguiente->dato != dato)//busca
      anterior = anterior->siguiente;
    if(anterior->siguiente == NULL) //no lo encontró
    {
      printf("%d no está en la lista! :(\n",dato);
      return NULL;
    }
    else
    {
      printf("%d si está en la lista! :)\n",dato);
      return anterior;
    }
  }
}

void insertar(int dato)
{
  struct nodo *nuevoNodo;
  nuevoNodo = malloc(sizeof(struct nodo));
  nuevoNodo->dato = dato;
  nuevoNodo->siguiente = cabeza;
  cabeza = nuevoNodo;
}

void borrar(struct nodo *anterior)
{
  if(anterior != NULL && (anterior != cabeza || (anterior == cabeza && borrarPrimero == 0)))//elimina todos menos el primero
  {
    struct nodo *eliminado;
    eliminado = anterior->siguiente;
    anterior->siguiente=eliminado->siguiente;
    printf("Se eliminó al %d de la lista\n",eliminado->dato);
    free(eliminado);
  }
  else if(anterior != NULL && borrarPrimero == 1)//elimina el primero
  {
    struct nodo *eliminado;
    eliminado = cabeza;
    cabeza = cabeza->siguiente;
    borrarPrimero = 0; //Desactivamos bandera
    printf("Se eliminó al %d de la lista\n",eliminado->dato);
    free(eliminado);
  }
  else
    printf("No puedo borrar ese número porque no está en la lista! :O\n");
}

int main()
{
  int opcion=1;
  while(opcion != 0)
  {
    printf("\nLista: ");
    imprimir();
    printf("Ingresa una opción:\n1)Insertar número\n2)Borrar elemento\n3)Buscar elemento\n0)Salir\n");
    scanf("%d",&opcion);
    switch (opcion)
    {
      case 1:
        printf("Ingresa el número: ");
        scanf("%d",&opcion);
        insertar(opcion);
        break;
      case 2:
        printf("Ingresa el número: ");
        scanf("%d",&opcion);
        borrar(buscar(opcion));
        break;
      case 3:
        printf("Ingresa el número: ");
        scanf("%d",&opcion);
        buscar(opcion);
        break;
      case 0:
        printf("Adios!\n");
        break;
      default:
        printf("Opción inválida\n");
    }
  }
  return 0;
}
