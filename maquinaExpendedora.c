//############################################################################
//############ Programa para administrar una máquina expendedora #############
//############################################################################
// Elaborado por: José Andrés Lucatero Tenorio

//-------------------------Bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//-------------------------Estructura
typedef struct _nodo
{
  char *Nombre;
  int ID;
  float Precio;
  int Caducidad;
  int max; //5
  int tamanio;
  struct _nodo *siguiente;
} tipoNodo;
//-------------------------Tipos de dato
typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;
//-------------------------Funciones
void Clear()
{
  system("clear"); //unix
  //system("cls"); //windows
}
void Continuar()
{
  printf("Presiona enter para continuar...");
  getchar();
  getchar();
}

void verProductos(pNodo *primero)
{
  int i = (*primero)->tamanio;
	if((*primero)->tamanio == 0)
  {
		printf("No hay productos de este tipo\n\n");
  }
	else
	{
    Lista aux = *primero;
		while(i!=0)
		{
			printf("ID:%d Nombre:%s Precio:$%.2f Dias para su vencimiento:%d\n",aux->ID,aux->Nombre,aux->Precio,aux->Caducidad);
			aux = aux->siguiente;
      i--;
		}
		printf("\n");
	}
}

void agregarProductos(pNodo *primero, pNodo *ultimo, char *apNombre, float precio, int caducidad)
{
    int tam = (*primero)->tamanio + 1; //Ahora será mas grande
    char *nombre = (char *)malloc(sizeof(char) * 20);
    pNodo nuevo; //Crear un nodo nuevo
    nuevo = (pNodo)malloc(sizeof(tipoNodo)); //Apartamos la memoria para el nuevo nodo
    nuevo->ID = (*primero)->ID; //Agregamos valores al nodo
    strcpy(nombre, apNombre);
    nuevo->Nombre = nombre;
    nuevo->Precio = precio;
    nuevo->Caducidad = caducidad;
    nuevo->siguiente = NULL; //Este será el nuevo nodo, no debe tener siguiente
    nuevo->tamanio = tam; //Ponemos el tamaño
    if(*ultimo) //Si la cola tiene mas de 1 elemento, *ultimo apuntara al que acabas de agregar
    {
      (*ultimo)->tamanio++;
      (*ultimo)->siguiente = nuevo;
    }
    *ultimo = nuevo; //Ahora el ultimo elemento de la cola es el nuevo nodo
    if((*primero)->tamanio == 0)
      *primero = nuevo;
    //Si es el primer nodo, la cola estaba vacía, ahora primero apuntará también al nuevo nodo
    (*primero)->tamanio = (*ultimo)->tamanio;//Nuevo tamaño
}

void extraerProductos(pNodo *primero, pNodo *ultimo)
{
  pNodo penultimo; //variable auxiliar para encontrar el penultimo nodo

  penultimo = *primero; //le damos a penultimo la dirección del inicio de la cola
  if (penultimo) //si la cola esta vacía sale
  {
    while(penultimo->siguiente&&penultimo->siguiente!=*ultimo)
      penultimo = penultimo->siguiente; //recorremos la cola hasta encontrar el penultimo

    free(*ultimo); //liberamos el espacio del último nodo
    *ultimo = NULL;

    *ultimo = penultimo; //ahora el ultimo nodo será el penúltimo

    (*ultimo)->siguiente = NULL;
  }
}

void cambiarPrecios(pNodo *primero, pNodo *ultimo, float *precio)
{
  printf("El precio actual es de: $%f\nIngrese nuevo precio: $",*precio);
  scanf("%f",precio);
  pNodo aux = *primero;
  if(aux->tamanio > 0)
    while(aux)
    {
      aux->Precio = *precio;
      aux = aux->siguiente;
    }
  printf("Precio del elemento actualizado correctamente\n");
  Continuar();
}

void ordenarPorFecha(pNodo *primero)
{
  int cambio, temp;
  pNodo nodo;
  pNodo ultimo = NULL;

  if ((*primero)->tamanio != 0)
  {
    do
    {
      cambio = 0;
      nodo = *primero;

      while (nodo->siguiente != ultimo)
      {
        if (nodo->Caducidad > nodo->siguiente->Caducidad)
        {
          temp = nodo->Caducidad;
          nodo->Caducidad = nodo->siguiente->Caducidad;
          nodo->siguiente->Caducidad = temp;
          cambio = 1;
        }
        nodo = nodo->siguiente;
      }
      ultimo = nodo;
    }
    while (cambio);
    printf("Ordenamiento por fecha de caducidad completado\n");
    Continuar();
  }
  else
  {
    printf("No puedo ordenar la nada\n");
    Continuar();
  }
}

void compra(pNodo *primero, pNodo *ultimo)
{
  pNodo nodo; //Variable auxiliar para manipular nodo

  nodo = *primero; //Nodo apuntará al primer elemento de la cola
  if (nodo)
  {
    if((*primero)->tamanio != 1)
      *primero = nodo->siguiente; //Ahora el primero será el que era el segundo

    if((*primero)->tamanio == 1)
    {
      (*primero)->tamanio = 0;
      (*primero)->Nombre = NULL;
      (*primero)->ID = 0;
      (*primero)->Precio = 0;
      (*primero)->Caducidad = 0;
      (*primero)->siguiente = NULL; //Este será el nuevo nodo, no debe tener siguiente
      //borralo manual
    }

    if((*primero)->tamanio > 0) //Si no se vació la lista
      (*primero)->tamanio--; //Disminuimos el tamaño

    if((*primero)->tamanio != 0)
      free(nodo); //liberamos el nodo

    if((*primero)->tamanio == 0) //Si la cola queda con un solo elemento o sin elementos *ultimo apunta a nulo
     *ultimo = NULL;
  }
}
//----------------------------------Función Principal---------------------------------------
int main()
{
  //-----------------------------------Variables
  pNodo jugosP, jugosU = NULL;
  jugosP = (pNodo)malloc(sizeof(tipoNodo));
  pNodo papasP, papasU = NULL;
  papasP = (pNodo)malloc(sizeof(tipoNodo));
  pNodo cacahuatesP, cacahuatesU = NULL;
  cacahuatesP = (pNodo)malloc(sizeof(tipoNodo));
  pNodo aguaP, aguaU = NULL;
  aguaP = (pNodo)malloc(sizeof(tipoNodo));
  pNodo galletasP, galletasU = NULL;
  galletasP = (pNodo)malloc(sizeof(tipoNodo));

  jugosP->ID = 1;
  papasP->ID = 2;
  cacahuatesP->ID = 3;
  aguaP->ID = 4;
  galletasP->ID = 5;

  jugosP->tamanio = 0;
  papasP->tamanio = 0;
  cacahuatesP->tamanio = 0;
  aguaP->tamanio = 0;
  galletasP->tamanio = 0;

  float ganancias = 0,
  credito = 0,
  precioJugo = 8,
  precioPapas = 10,
  precioCacahuates = 3,
  precioAgua = 15,
  precioGalletas = 12;

  char *password,*nombre;
  password = (char *)malloc(sizeof(char) * 20);
  nombre = (char *)malloc(sizeof(char) * 20);

  unsigned short i = 0, u = 0, j, opcion, opcion2;
  int caducidad,inter;

  while(1)
  {
    Clear();
    printf("1) Administrador\n2) Usuario\n3) Salir\n");
    scanf("%hd",&opcion);
    if (opcion < 4 && opcion > 0)
      switch (opcion)
      {
        case 1:
          Clear();
          i = 0;
          while(i<3)
          {
            printf("Password: ");
            scanf("%s",password);
            if ( strcmp(password, "admin123") == 0 )
            {
              while(i<3)
              {
                Clear();
  //------------------------------------MENU PRINCIPAL ADMINISTRADOR------------------------------
                printf("1)Ver productos\n2)Agregar productos\n3)Extraer Productos\n4)Extraer todos los productos de un tipo\n5)Modificar precios\n6)Ordenar producto por fecha de caducidad\n7)Dinero total recaudado\n8)Volver\n");
                scanf("%hd",&opcion);
                if(opcion)
                  switch (opcion)
                  {
      //-------------------ver productos
                    case 1:
                      printf("Jugos:\n");
                      verProductos(&jugosP);
                      printf("Papas:\n");
                      verProductos(&papasP);
                      printf("Cacahuates:\n");
                      verProductos(&cacahuatesP);
                      printf("Aguas:\n");
                      verProductos(&aguaP);
                      printf("Galletas:\n");
                      verProductos(&galletasP);
                      Continuar();
                    break;
        //--------------------agregamos elementos
                    case 2:
                      printf("Selecciona un producto:\n1)Jugo\n2)Papas\n3)Cacahuates\n4)Agua\n5)Galletas\n");
                      scanf("%hd",&opcion);
                      if(opcion < 6 && opcion > 0)
                        switch (opcion)
                        {
                          case 1: //--------------------------------agregamos jugos
                            printf("Numero de productos a ingresar: ");
                            scanf("%hd",&opcion);
                            j = 0;
                            if (opcion < 6 && opcion > 0 && opcion <= (5 - jugosP->tamanio))
                            {
                              while(j < opcion)
                              {
                                printf("Nombre %d: ",j+1);
                                scanf("%s",nombre);
                                printf("Dias para su vencimiento: ");
                                scanf("%d",&caducidad);
                                agregarProductos(&jugosP, &jugosU, nombre, precioJugo, caducidad);
                                j++;
                              }
                              printf("%d productos agregados con exito\n",j);
                              Continuar();
                            }
                            else
                            {
                              if(opcion < 1)
                              {
                                printf("No puedes ingresar 0 productos\n");
                                Continuar();
                              }
                              else
                              {
                                printf("No puedes agregar mas de 5 productos del mismo tipo\n");
                                Continuar();
                              }
                            }
                          break;

                          case 2: //--------------------------------agregamos papas
                            printf("Numero de productos a ingresar: ");
                            scanf("%hd",&opcion);
                            j = 0;
                            if (opcion < 6 && opcion > 0 && opcion <= (5 - papasP->tamanio))
                            {
                              while(j < opcion)
                              {
                                printf("Nombre %d: ",j+1);
                                scanf("%s",nombre);
                                printf("Dias para su vencimiento: ");
                                scanf("%d",&caducidad);
                                agregarProductos(&papasP, &papasU, nombre, precioPapas, caducidad);
                                j++;
                              }
                              printf("%d productos agregados con exito\n",j);
                              Continuar();
                            }
                            else
                            {
                              if(opcion < 1)
                              {
                                printf("No puedes ingresar 0 productos\n");
                                Continuar();
                              }
                              else
                              {
                                printf("No puedes agregar mas de 5 productos del mismo tipo\n");
                                Continuar();
                              }
                            }
                          break;

                          case 3:  //--------------------------------agregamos cacahuates
                            printf("Numero de productos a ingresar: ");
                            scanf("%hd",&opcion);
                            j = 0;
                            if (opcion < 6 && opcion > 0 && opcion <= (5 - cacahuatesP->tamanio))
                            {
                              while(j < opcion)
                              {
                                printf("Nombre: ");
                                scanf("%s",nombre);
                                printf("Dias para su vencimiento: ");
                                scanf("%d",&caducidad);
                                agregarProductos(&cacahuatesP, &cacahuatesU, nombre, precioCacahuates, caducidad);
                                j++;
                              }
                              printf("%d productos agregados con exito\n",j);
                              Continuar();
                            }
                            else
                            {
                              if(opcion < 1)
                              {
                                printf("No puedes ingresar 0 productos\n");
                                Continuar();
                              }
                              else
                              {
                                printf("No puedes agregar mas de 5 productos del mismo tipo\n");
                                Continuar();
                              }
                            }
                          break;

                          case 4: //--------------------------------agregamos agua
                            printf("Numero de productos a ingresar: ");
                            scanf("%hd",&opcion);
                            j = 0;
                            if (opcion < 6 && opcion > 0 && opcion <= (5 - aguaP->tamanio))
                            {
                              while(j < opcion)
                              {
                                printf("Nombre: ");
                                scanf("%s",nombre);
                                printf("Dias para su vencimiento: ");
                                scanf("%d",&caducidad);
                                agregarProductos(&aguaP, &aguaU, nombre, precioAgua, caducidad);
                                j++;
                              }
                              printf("%d productos agregados con exito\n",j);
                              Continuar();
                            }
                            else
                            {
                              if(opcion < 1)
                              {
                                printf("No puedes ingresar 0 productos\n");
                                Continuar();
                              }
                              else
                              {
                                printf("No puedes agregar mas de 5 productos del mismo tipo\n");
                                Continuar();
                              }
                            }
                          break;

                          case 5: //--------------------------------agregamos galletas
                            printf("Numero de productos a ingresar: ");
                            scanf("%hd",&opcion);
                            j = 0;
                            if (opcion < 6 && opcion > 0 && opcion <= (5 - galletasP->tamanio))
                            {
                              while(j < opcion)
                              {
                                printf("Nombre: ");
                                scanf("%s",nombre);
                                printf("Dias para su vencimiento: ");
                                scanf("%d",&caducidad);
                                agregarProductos(&galletasP, &galletasU, nombre, precioGalletas, caducidad);
                                j++;
                              }
                              printf("%d productos agregados con exito\n",j);
                              Continuar();
                            }
                            else
                            {
                              if(opcion < 1)
                              {
                                printf("No puedes ingresar 0 productos\n");
                                Continuar();
                              }
                              else
                              {
                                printf("No puedes agregar mas de 5 productos del mismo tipo\n");
                                Continuar();
                              }
                            }
                          break;

                          default:
                            printf("Ingresa un valor del menu\n");
                            Continuar();
                        }
                      else
                      {
                        printf("Ingresa un valor valido\n");
                        Continuar();
                      }
                    break;
        //-------------------extraccion de elementos
                    case 3:
                      printf("Numero de productos a extraer: ");
                      scanf("%hd",&j);
                      if(j < 6 && j > 0)
                      {
                        printf("Selecciona un producto:\n1)Jugo\n2)Papas\n3)Cacahuates\n4)Agua\n5)Galletas\n");
                        scanf("%hd",&opcion);
                        if(opcion < 6 && opcion > 0)
                          switch (opcion)
                          {
                            case 1://---------------------extraemos jugos
                              if(jugosP->tamanio >= j)
                              {
                                for (int k = 0; k < j; k++)
                                {
                                  extraerProductos(&jugosP, &jugosU);
                                  jugosP->tamanio--;
                                }
                                printf("Se extrayeron exitosamente %d jugos\n",j);
                                Continuar();
                              }
                              else
                              {
                                printf("No puedes extraer %d jugos si solo hay %d\n",j,jugosP->tamanio);
                                Continuar();
                              }
                            break;

                            case 2://---------------------extraemos papas
                              if(papasP->tamanio >= j)
                              {
                                for (int k = 0; k < j; k++)
                                {
                                  extraerProductos(&papasP, &papasU);
                                  papasP->tamanio--;
                                }
                                printf("Se extrayeron exitosamente %d papas\n",j);
                                Continuar();
                              }
                              else
                              {
                                printf("No puedes extraer %d papas si solo hay %d\n",j,papasP->tamanio);
                                Continuar();
                              }
                            break;

                            case 3://---------------------extraemos cacahuates
                              if(cacahuatesP->tamanio >= j)
                              {
                                for (int k = 0; k < j; k++)
                                {
                                  extraerProductos(&cacahuatesP, &cacahuatesU);
                                  cacahuatesP->tamanio--;
                                }
                                printf("Se extrayeron exitosamente %d cacahuates\n",j);
                                Continuar();
                              }
                              else
                              {
                                printf("No puedes extraer %d cacahuates si solo hay %d\n",j,cacahuatesP->tamanio);
                                Continuar();
                              }
                            break;

                            case 4://---------------------extraemos agua
                              if(aguaP->tamanio >= j)
                              {
                                for (int k = 0; k < j; k++)
                                {
                                  extraerProductos(&aguaP, &aguaU);
                                  aguaP->tamanio--;
                                }
                                printf("Se extrayeron exitosamente %d aguas\n",j);
                                Continuar();
                              }
                              else
                              {
                                printf("No puedes extraer %d aguas si solo hay %d\n",j,aguaP->tamanio);
                                Continuar();
                              }
                            break;

                            case 5://---------------------extraemos galletas
                              if(galletasP->tamanio >= j)
                              {
                                for (int k = 0; k < j; k++)
                                {
                                  extraerProductos(&galletasP, &galletasU);
                                  galletasP->tamanio--;
                                }
                                printf("Se extrayeron exitosamente %d galletas\n",j);
                                Continuar();
                              }
                              else
                              {
                                printf("No puedes extraer %d galletas si solo hay %d\n",j,galletasP->tamanio);
                                Continuar();
                              }
                            break;
                          }
                        else
                        {
                          printf("Ingresa una opcion valida\n");
                          Continuar();
                        }
                      }
                      else
                      {
                        if(j < 1)
                        {
                          printf("¿Vas a sacar algo o no?\n");
                          Continuar();
                        }
                        else
                        {
                          printf("El maximo de elementos de un solo tipo es 5\n");
                          Continuar();
                        }
                      }
                    break;
        //---------------extraer todos de un solo tipo
                    case 4:
                      printf("Selecciona un producto:\n1)Jugo\n2)Papas\n3)Cacahuates\n4)Agua\n5)Galletas\n");
                      scanf("%hd",&opcion);
                      if(opcion < 6 && opcion > 0)
                        switch (opcion)
                        {
                          case 1://-------------------todos los jugos
                            if(jugosP->tamanio > 0)
                            {
                              for (int k = 0; k < jugosP->tamanio; k++)
                                extraerProductos(&jugosP, &jugosU);
                              jugosP->tamanio = 0;
                              printf("Se extrayeron exitosamente todos los jugos\n");
                              Continuar();
                            }
                            else
                            {
                              printf("No puedes extraer jugos si no hay\n");
                              Continuar();
                            }
                          break;

                          case 2: //-------------------todas las papas
                            if(papasP->tamanio > 0)
                            {
                              for (int k = 0; k < papasP->tamanio; k++)
                                extraerProductos(&papasP, &papasU);
                              papasP->tamanio = 0;
                              printf("Se extrayeron exitosamente todas las papas\n");
                              Continuar();
                            }
                            else
                            {
                              printf("No puedes extraer papas si no hay\n");
                              Continuar();
                            }
                          break;

                          case 3: //-------------------todos los cacahuates
                            if(cacahuatesP->tamanio > 0)
                            {
                              for (int k = 0; k < cacahuatesP->tamanio; k++)
                                extraerProductos(&cacahuatesP, &cacahuatesU);
                              cacahuatesP->tamanio = 0;
                              printf("Se extrayeron exitosamente todos los cacahuates\n");
                              Continuar();
                            }
                            else
                            {
                              printf("No puedes extraer cacahuates si no hay\n");
                              Continuar();
                            }
                          break;

                          case 4://-------------------todas las aguas
                            if(aguaP->tamanio > 0)
                            {
                              for (int k = 0; k < aguaP->tamanio; k++)
                                extraerProductos(&aguaP, &aguaU);
                              aguaP->tamanio = 0;
                              printf("Se extrayeron exitosamente todas las aguas\n");
                              Continuar();
                            }
                            else
                            {
                              printf("No puedes extraer aguas si no hay\n");
                              Continuar();
                            }
                          break;

                          case 5://-------------------todas las galletas
                            if(galletasP->tamanio > 0)
                            {
                              for (int k = 0; k < galletasP->tamanio; k++)
                                extraerProductos(&galletasP, &galletasU);
                              galletasP->tamanio = 0;
                              printf("Se extrayeron exitosamente todas las galletas\n");
                              Continuar();
                            }
                            else
                            {
                              printf("No puedes extraer galletas si no hay\n");
                              Continuar();
                            }
                          break;
                        }
                      else
                      {
                        printf("Ingresa una opcion valida\n");
                        Continuar();
                      }
                    break;
        //----------------cambiamos precios
                    case 5:
                      printf("Selecciona un producto:\n1)Jugo\n2)Papas\n3)Cacahuates\n4)Agua\n5)Galletas\n");
                      scanf("%hd",&opcion);
                      if(opcion < 6 && opcion > 0)
                        switch (opcion)
                        {
                          case 1:
                            cambiarPrecios(&jugosP, &jugosU, &precioJugo);
                          break;

                          case 2:
                            cambiarPrecios(&papasP, &papasU, &precioPapas);
                          break;

                          case 3:
                            cambiarPrecios(&cacahuatesP, &cacahuatesU, &precioCacahuates);
                          break;

                          case 4:
                            cambiarPrecios(&aguaP, &aguaU, &precioAgua);
                          break;

                          case 5:
                            cambiarPrecios(&galletasP, &galletasU, &precioGalletas);
                          break;
                        }
                      else
                      {
                        printf("Ingresa una opcion valida\n");
                        Continuar();
                      }
                    break;
        //----------------ordenamos por fecha
                    case 6:
                      printf("Selecciona un producto:\n1)Jugo\n2)Papas\n3)Cacahuates\n4)Agua\n5)Galletas\n");
                      scanf("%hd",&opcion);
                      if(opcion < 6 && opcion > 0)
                        switch (opcion)
                        {
                          case 1:
                            ordenarPorFecha(&jugosP);
                          break;

                          case 2:
                            ordenarPorFecha(&papasP);
                          break;

                          case 3:
                            ordenarPorFecha(&cacahuatesP);
                          break;

                          case 4:
                            ordenarPorFecha(&aguaP);
                          break;

                          case 5:
                            ordenarPorFecha(&galletasP);
                          break;
                        }
                      else
                      {
                        printf("Ingresa una opcion valida\n");
                        Continuar();
                      }
                    break;
        //----------------obtenemos dinero total
                    case 7:
                      printf("Ganancias Totales: $%.2f\n",ganancias);
                      Continuar();
                      Clear();
                    break;
        //----------------volvemos al inicio
                    case 8:
                      Clear();
                      i=3;
                    break;

                    default:
                      printf("Ingresa un valor del menu\n");
                      Continuar();
                  }
                  else
                  {
                    printf("Ingresa un valor valido\n");
                    Continuar();
                  }
              }
            }
            else
            {
              i++;
              printf("Incorrecta\n");
            }
          }
        break;

        case 2:
//------------------------------------MENU PRINCIPAL USUARIO------------------------------
          u = 0;
          Clear();
          while(u == 0)
          {
            printf("1)Insertar dinero\n2)Comprar producto\n3)Pedir cambio\n4)Volver\nSaldo: $%.2f\n",credito);
            scanf("%hd",&opcion);
            switch (opcion)
            {
            //-----------------------inserta dinero
              case 1:
                printf("Ingresa el dinero en multiplos de 10: $");
                scanf("%d",&inter);
                if(inter % 10 == 0)
                  credito += inter;
                else
                {
                  printf("Solo se aceptan multiplos de 10\n");
                  Continuar();
                }
                Clear();
              break;

            //-----------------------compra
              case 2:
                printf("Selecciona un producto:\n1)Jugo\n2)Papas\n3)Cacahuates\n4)Agua\n5)Galletas\n");
                scanf("%hd",&opcion2);
                switch (opcion2)
                {
                  case 1://----------compra jugos
                    if(jugosP->tamanio > 0 && credito > precioJugo)
                    {
                      compra(&jugosP,&jugosU);
                      printf("Crédito: $%.2f\nJugo: $%.2f\nCrédito Restante: $%.2f\n",credito,precioJugo,credito-precioJugo);
                      credito -= precioJugo;
                      ganancias += precioJugo;
                      Continuar();
                      Clear();
                    }
                    else
                    {
                      if(jugosP->tamanio == 0)
                        printf("Lo sentimos, no hay jugos\n");
                      if(credito < precioJugo)
                        printf("Crédito insuficiente\n");
                      Continuar();
                      Clear();
                    }
                  break;

                  case 2://----------compra papas
                    if(papasP->tamanio > 0 && credito > precioPapas)
                    {
                      compra(&papasP,&papasU);
                      printf("Crédito: $%.2f\nJugo: $%.2f\nCrédito Restante: $%.2f\n",credito,precioPapas,credito-precioPapas);
                      credito -= precioPapas;
                      ganancias += precioPapas;
                      Continuar();
                      Clear();
                    }
                    else
                    {
                      if(papasP->tamanio == 0)
                        printf("Lo sentimos, no hay papas\n");
                      if(credito < precioPapas)
                        printf("Crédito insuficiente\n");
                      Continuar();
                      Clear();
                    }
                  break;

                  case 3://----------compra cacahuates
                    if(cacahuatesP->tamanio > 0 && credito > precioCacahuates)
                    {
                      compra(&cacahuatesP,&cacahuatesU);
                      printf("Crédito: $%.2f\nJugo: $%.2f\nCrédito Restante: $%.2f\n",credito,precioCacahuates,credito-precioCacahuates);
                      credito -= precioCacahuates;
                      ganancias += precioCacahuates;
                      Continuar();
                      Clear();
                    }
                    else
                    {
                      if(cacahuatesP->tamanio == 0)
                        printf("Lo sentimos, no hay cacahuates\n");
                      if(credito < precioCacahuates)
                        printf("Crédito insuficiente\n");
                      Continuar();
                      Clear();
                    }
                  break;

                  case 4://----------compra agua
                    if(aguaP->tamanio > 0 && credito > precioAgua)
                    {
                      compra(&aguaP,&aguaU);
                      printf("Crédito: $%.2f\nJugo: $%.2f\nCrédito Restante: $%.2f\n",credito,precioAgua,credito-precioAgua);
                      credito -= precioAgua;
                      ganancias += precioAgua;
                      Continuar();
                      Clear();
                    }
                    else
                    {
                      if(aguaP->tamanio == 0)
                        printf("Lo sentimos, no hay aguas\n");
                      if(credito < precioAgua)
                        printf("Crédito insuficiente\n");
                      Continuar();
                      Clear();
                    }
                  break;

                  case 5://----------compra galletas
                    if(galletasP->tamanio > 0 && credito > precioGalletas)
                    {
                      compra(&galletasP,&galletasU);
                      printf("Crédito: $%.2f\nJugo: $%.2f\nCrédito Restante: $%.2f\n",credito,precioGalletas,credito-precioGalletas);
                      credito -= precioGalletas;
                      ganancias += precioGalletas;
                      Continuar();
                      Clear();
                    }
                    else
                    {
                      if(galletasP->tamanio == 0)
                        printf("Lo sentimos, no hay galletas\n");
                      if(credito < precioGalletas)
                        printf("Crédito insuficiente\n");
                      Continuar();
                      Clear();
                    }
                  break;

                  default:
                    printf("Ingresa una opcion válida\n");
                    Continuar();
                    Clear();
                }
              break;
            //----------------------pide cambio
              case 3:
                printf("Cambio: $%.2f\n",credito);
                credito = 0;
                Continuar();
                Clear();
              break;

              case 4:
                u = 1;
              break;

              default:
                printf("Ingresa una opcion valida\n");
                Continuar();
                Clear();
            }
          }
        break;

        case 3:
          exit(0);
        break;

        default:
          printf("Ingresa un valor del menu\n");
          Continuar();
          Clear();
      }
    else
    {
      printf("Ingresa un valor valido\n");
      Continuar();
      Clear();
    }
  }
  return 0;
}
