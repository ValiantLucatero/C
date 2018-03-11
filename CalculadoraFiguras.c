/**
 * Implentar un Tipo de Dato Abstracto para un paralelogramo el cual queda
 * definido como:
 * el numero de puntos y un arreglo de Puntos donde el orden define la
 * conectividad de los mismos.
 * Crear las funciones es_cuadrado, es_rectangulo, es_triangulo.
 * Hint: implemente el TDA para definir un Punto en 2D
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct
{
    /** X coordinate */
    float x;

    /** Y coordinate */
    float y;
}Point;

/**
 * Computes the euclidean distance between two points
 */
float distance(Point p, Point q);

/**
 * Moves a point the desired delta (dx,dy)
 */
void move(Point *p, float dx, float dy);

/**
 * Computes the dot product between two points
 */
float dot_product(Point *p, Point *q);

/**
 * Prints the point
 */
void print(Point *p);

// --------------------------------------------------------------------------
float distance(Point a, Point b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

// --------------------------------------------------------------------------

void move(Point *p, float dx, float dy)
{
    p->x += dx;
    p->y += dy;
}

// --------------------------------------------------------------------------
float dot_product(Point *p, Point *q)
{
    float x = p->x * q->x;
    float y = p->y * q->y;
    return x + y;
}

// --------------------------------------------------------------------------
void print(Point *p)
{
    printf("(%0.2f, %0.2f) \n", p->x, p->y);
}

// --------------------------------------------------------------------------
// --------------------------------------------------------------------------


typedef struct
{
  //numero de puntos
  int _num_points;

  //arreglo de puntos
  Point *_points;
}Paralelogram;

//Transforma los datos en tipo de dato Paralelogram
Paralelogram constructor(int num_points, Point *points);

//Checa si es un triángulo
void is_triangle(Paralelogram *p);

//Checa si es un cuadrado
void is_square(Paralelogram *p);

//Checa si es un rectangulo
void is_rectangle(Paralelogram *p);

//---------------------------------------------------------------------------
Paralelogram constructor(int num_points, Point *points)
{
  Paralelogram figure; //creamos variable local
  figure._num_points=num_points; //asignamos valores recibidos a la variable
  figure._points=points;
  return figure; //devuelve variable tipo Paralelogram con los datos recibidos
}

void is_triangle(Paralelogram *p)
{
  if(p->_num_points==3) //si tiene 3 lados es un triangulo
    printf("Es un triángulo\n");
}

void is_square(Paralelogram *p)
{
  if(p->_num_points==4) //si tiene 4 lados iguales es un cuadrado
  {
    float dist1=distance(p->_points[0],p->_points[1]);
    float dist2=distance(p->_points[1],p->_points[2]);
    float dist3=distance(p->_points[2],p->_points[3]);
    float dist4=distance(p->_points[3],p->_points[0]);
    if (dist1==dist2&&dist3==dist4&&dist1==dist3&&dist2==dist4)
    {
      if(dot_product(&p->_points[1],&p->_points[3])==0)
        printf("Es un cuadrado\n");
    }
  }
}

void is_rectangle(Paralelogram *p)
{
  if(p->_num_points==4)
  { //si tiene 4 lados con lados opuestos iguales es un rectangulo
    float dist1=distance(p->_points[0],p->_points[1]);
    float dist2=distance(p->_points[1],p->_points[2]);
    float dist3=distance(p->_points[2],p->_points[3]);
    float dist4=distance(p->_points[3],p->_points[0]);
    if (dist1==dist3&&dist2==dist4&&dist1!=dist2&&dist3!=dist4)
    {
      printf("Es un rectangulo\n");
    }
  }
}

// --------------------------------------------------------------------------
// --------------------------------  Main  ----------------------------------
// --------------------------------------------------------------------------
int main()
{
  /*
//---------------------------------------------------------------------------
//----------------------------------  Pruebas  ------------------------------
//---------------------------------------------------------------------------
//    the square
//    #       #

//    #       #

    Point s1; s1.x = 0; s1.y = 0;
    Point s2; s2.x = 5; s2.y = 0;
    Point s3; s3.x = 5; s3.y = 5;
    Point s4; s4.x = 0; s4.y = 5;

    Point S[] = {s1, s2, s3, s4};

    printf(" --- El cuadrado --- \n");
    for(int i = 0; i < 4; i++)
        print(&(S[i]));

    Paralelogram square=constructor(*(&S+1)-S,S);
    is_square(&square);
    is_triangle(&square);
    is_rectangle(&square);

//    the rectangle
//    #             #

//    #             #

    Point r1; r1.x = 0; r1.y = 0;
    Point r2; r2.x = 10; r2.y = 0;
    Point r3; r3.x = 10; r3.y = 5;
    Point r4; r4.x = 0; r4.y = 5;

    Point R[] = {r1, r2, r3, r4};

    printf(" --- El rectangulo --- \n");
    for(int i = 0; i < 4; i++)
        print(&(R[i]));

    Paralelogram rectangle=constructor(*(&R+1)-R,R);
    is_square(&rectangle);
    is_triangle(&rectangle);
    is_rectangle(&rectangle);

//    the diamond
//        #
//    #       #
//        #
    Point d1; d1.x = 0; d1.y = 0;
    Point d2; d2.x = 5; d2.y = 2.5;
    Point d3; d3.x = 0; d3.y = 5;
    Point d4; d4.x = -5; d4.y = 2.5;

    Point D[] = {d1, d2, d3, d4};

    printf(" --- El rombo --- \n");
    for(int i = 0; i < 4; i++)
        print(&(D[i]));

    Paralelogram diamond=constructor(*(&D+1)-D,D);
    is_square(&diamond);
    is_triangle(&diamond);
    is_rectangle(&diamond);

//   the triangle
//        #
//    #       #
    Point t1; t1.x = 0; t1.y = 0;
    Point t2; t2.x = 5; t2.y = 0;
    Point t3; t3.x = 2.5; t3.y = 5;

    Point T[] = {t1, t2, t3};

    printf(" --- El triángulo --- \n");
    for(int i = 0; i < 3; i++)
        print(&(T[i]));

    Paralelogram triangle=constructor(*(&T+1)-T,T);
    is_square(&triangle);
    is_triangle(&triangle);
    is_rectangle(&triangle);
*/
//--------------------------------------------------------------------------
//------------------------Programa de Usuario-------------------------------
//--------------------------------------------------------------------------

    int puntos; //variable que recibirá el número de puntos
    Point *q; //apuntador

    printf("##### Calculadora de figuras #####\n");
    printf("Ingresa algunos puntos y te diré que figura es\n"); //menu
    printf("Cuantos puntos tiene tu figura? ");
    scanf("%d",&puntos); //recibimos número de puntos

    //apartamos el tamaño del TDA Point para el número de puntos seleccionados
    q = (Point*) malloc (sizeof(Point) * puntos);

    for (int i = 0; i < puntos; i++) //iteramos sobre el espacio apartado
    {
      printf("Dame las coordenadas de x del punto %d: ",i+1);
      scanf("%f",&(q+i)->x); //vamos guardando datos como si fuera un arreglo
      printf("Dame las coordenadas de y del punto %d: ",i+1);
      scanf("%f",&(q+i)->y); //recorriendo el espacio apartado y dejando el dato
    }

    Paralelogram figura = constructor(puntos,q);
    //creamos un nuevo paralelogram con los datos recabados
    is_square(&figura);
    is_triangle(&figura); //checamos si es alguna de las figuras
    is_rectangle(&figura);

    free(q); //liberamos el espacio apartado

    getchar(); //cachamos el último enter
    getchar(); //detenemos la ejecución para poder leer el resultado

    return 0;
}
