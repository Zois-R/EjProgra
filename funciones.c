/// ACA PONGO LAS FUNCIONES CON SU CUERPO

#include "funciones.h"   /// tengo que incluir el header

int factorial(int num)
{
    int fact = 1;
    int n = num;
    /*
    Acá guardo el numero ingresado para poder ir decrementadolo
    y hacer los calculos para que me de factorial. Si no hago esto
    y voy decrementando num a medida que aumento el i del for
    va a terminar el proceso cuando num == i y no va a calcular bien
    el factorial. !!!!
    */
    if(n == 0)
    {
        return fact;
    }
    for(int i = 1; i<num; i++) // no es necesario que i = 0; ya que fact * 1 no
        // tiene sentido.
    {
        fact = fact * n;
        n--; // decremento n hasta que llegue a 1.
    }
    return fact;
}


int combinatorio(int n, int m)
{
    //m>=n y n>=0
    int combinatorio;
    if(m>=n && n>=0)
    {
        combinatorio = (factorial(m)/(factorial(n)*factorial(m-n)));
        return combinatorio;
    }
    else
    {
        printf("\nIngrese numeros validos \n");
        return 0;
    }

}

float exponencial(int base,int expo)
{
    float ex = base;
    while(expo>1)
        {
            ex = ex * base;
            expo--;

        }


    return ex;
}


float serieExponencial(int x,float tol)
{
    int i;
    float sumador;
    sumador = 0;

    /*
    Hago el calculo de la serie pero me falta poner el paso en el que
    siga calculando hasta llegar a un margen  de error ( TOL ) lo suficiente
    */

    for(i = 1; i<=x;i++)
        {

            sumador += (exponencial(x,i)/factorial(i));


        }
    printf("sumador %.0f",sumador);
    return sumador;

}


/*-------------------------------  EJ 7  ------------------------------------*/
void esPerfDefiAbund(int num)
{
    /// si la suma de sus divisores es igual al numero es PERFECTO
    /// si la suma de sus divisores es menor al numero es DEFICIENTE
    /// si la suma de sus divisores es mayor al numero es ABUNDANTE
    int i;
    int sum_div;
    sum_div = 0;
    for(i = 1;i<=num/2;i++)
        {
            if(num%i==0)
                {
                    sum_div +=i;
                }
        }
    printf(sum_div == num ? "PERFECTO" : sum_div < num ? "DEFICIENTE" : "ABUNDANTE");

}


/*-------------------------------  EJ 8  ------------------------------------*/
int sumas_sucesivas(int num1,int num2)
{
    int g = num2;
    int i;

    if(num1 == 0 || num2 == 0)
        {
            return 0;
        }
    for(i = 1;i<num1;i++)
        {
            g += num2;
        }
    return g;
}


/*-------------------------------  EJ 9  ------------------------------------*/


void cocienteYresto()
{
    int a,b;
    do{
            printf("INGRESE A \n");
            scanf("%d",&a);
            printf("INGRESE B [DISTINTO DE CERO] \n");
            scanf("%d",&b);


    }while(b==0);

    printf("A / B ES IGUAL A : %d",a/b);
    printf("\nA %c B ES IGUAL A : %d",37,a%b);
    // con %c y buscando el numero decimal en tabla ASCII puedo imprimir
    // caracteres especiales.
}

/*-------------------------------  EJ 10  ------------------------------------*/

int calculoDeNnumeros(int n)
{
    ///suponiendo que tambíen se suma el numero n
    ///sino seria i<n en el for
    int i;
    int sum;
    sum = 0;
    for(i = 0;i<=n;i++)
        {
            sum+=i;
        }
        return sum;

}

/*-------------------------------  EJ 11  ------------------------------------*/

int sumaNpares(int n)
{
    /// que diferencia hay entre el ejercicio 11 y 12?
    /// Este lo hago sin incluir el numero n. sino seria con i<=n
    int i;
    int sum_pares;
    sum_pares = 0;
    for(i = 0;i<n;i++)
        {
            if(i%2==0)
                {
                    sum_pares+=i;
                }
        }
        return sum_pares;
}


/*-------------------------------  EJ 13  ------------------------------------*/


void esPrimo(int n)
{
    /*
    Un numero es primo si y solo si es divisible por el 1 y el mismo.
    Este problema lo puedo resolver con un contador de divisores que
    al superar el numero 2 ya no sería primo, es decir , si el numero
    ingresado en la función tiene mas de 2 divisores (el mismo y el uno y más)
    entonces no es primo
    */
    int cont_div,i;
    cont_div = 0;

    for(i=1;i<=n;i++)
        {
            if(n%i == 0)
                {
                    cont_div++;
                }
        }
    if(cont_div>2)
        {
            printf("NO ES PRIMO");
        }else
        {
            printf("ES PRIMO");
        }
}

/*-------------------------------  EJ 14 ------------------------------------*/
int esBisiesto(int anio)
{ //retorna 1 o 0
    return anio%400 == 0 || (anio%4==0 && anio%100 !=0);
}

int cantDiasMes(int mes,int anio)
{   ///                            E  F  M  A  MA J  JUL  A   S  O  N  D
    static const int diaMes[12]= {31,28,31,30,31,30, 31, 31, 30,31,30,31};
    return esBisiesto(anio) && mes == 2 ? 29 : diaMes[mes-1];
}

int esFechaValida(const tFecha *pf)
{
    if(pf->anio>1600)
        if(pf->mes>=1 && pf->mes<=12)
            if(pf->dia>=1 && pf->dia<= cantDiasMes(pf->mes,pf->anio))
                return 1;
    return 0;

}
/*
Porque recibo esta fecha como puntero?
Si no lo recibo como puntero el compilador copia toda
la estructura y la pone en otro lugar ocupando mucha memoria
Entonces cuando pasamos estructuras por parametro no vamos a pasar la estructura
por copia, sino se pasa el puntero a estructura, esto es una cuestion de
performance.

Se toman los anios validos de 1601 hacia aca debido a que
en ese anio se creo el calendario gregoriano.

Los dias en la validacion estan entre el dia 1 y los dias que devuelve la
funcion cantDiaMes que a su vez le paso a esa funcion el mes y el anio.
Si la fecha es valida retorna 1 sino returna 0.


int esFechaValida(const tFecha *f)
{
    if(f->a>1600)
        if(f->m>=1 && f->m<=12)
            if(f->d>=1 && f->d <= cantDiaMes(f->m,f->a))
                return 1;
    return 0;
}

Los dias en un mes se pone en un vector. Tambien se puede poner
con un if o un switch pero es larguisima.
Se le resta 1 al mes para poder ubicarme en la posicion del vector.
Y si es biciesto se le suma un dia a febrero.
Que significa que sea static ?
Que la memoria seas estatica quiere decir que queda estatico en la memoria
esa memoria no es liberada con la funcion sino que se mantiene hasta que se
termine el programa.
Que ventaja tiene esto ? El vector no se tiene que volver a declarar cada vez
que se llama a la funcion entonces el sistema operativo no tiene que perder tiempo
en declarar el vector y asignarlo a memoria cada vez que se llame a la funcion
entonces lo hace mucho mas rapido.

int cantDiasMes(int m,int a)
{
    static const int diaMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31}
    return esBisiesto(a) && m == 2 ? 29 : diasMes[m-1];
}


int esBisiesto(int a)
{
    return a%400 == 0 || (a % 4 == 0 && a % 100 != 0);
}

Si no es multiplo de 400 me fijo si es multiplo de 4 puede ser biciesto como no
tengo que fijarme que no sea multiplo de 100.

*/


/*
2 FORMAS DE DECLARAR ESTRUCTURAS

1)
struct sFecha
{
    int d,m,a;

};

El typedef es ponerle un alias a algo.
typedef unsigned long size_t;

size_t es un tipo de dato que indica tamanio.
typedef struct sFecha tFecha;

2)
typedef struct
{
int d,m,a;
}tFecha;

La segunda forma es mejor porque no tengo que poner struct cada vez que
pongo el nombre de la estructura.


ESTRUCTURA ANIDADA

typedef struct{
 int dni;
 char apyn[30];
 tFecha fNac;
}tPersona;

DECLARACION DE VARIABLES DE TIPO ESTRUCTURA EN MAIN
tFecha f1 = {8,9,2020};
tPersona p1 = {12345678,"Sa,Lia",{2,2,2020}};


INICIALICACION ELEMENTO POR ELEMENTO
f1.d = 8;
f1.m = 9;
f1.a = 2020;

VECTOR DE ESTRUCTURAS
vector de fechas

tFecha vf1[] = {{8,9,2020},{12,10.2020}};

PUNTEROS A ESTRUCTURAS!!!

tFecha * pf;


pf = &f1; // pf guarda la dirección de memoria de f1.

printf("\n%d\%d\%d--\n%d\%d\%d",f1.dia,f1.mes,f1.anio,pf->d,pf->m,pf->a);


OJO!
ESTO (*pf).d es lo mismo que pf->d
PERO SE UTILIZA LA SEGUNDA OPCION
DEBIDO A UNA MEJOR LEGIBILIDAD DEL CÓDIGO

UTILIZO EL "." CUANDO LO QUE TENGO A LA IZQUIERDA ES UNA VARIABLE
UTILIZO EL "->" CUANDO LO QUE TENGO A LA DERECHA ES UN PUNTERO



*/

/*-------------------------------  EJ 15 ------------------------------------*/

void sumoUnDiaFecha(tFecha *pf)
{
    switch(pf->mes)
    {
    case 2:
        if( ((esBisiesto(pf->anio))==1) && pf->dia == 28)
            {
                pf->dia++;
            }else
            {
                if(((esBisiesto(pf->anio))==1) && pf->dia == 29)
                    {
                        pf->dia = 1;
                        pf->mes++;
                    }else
                    {
                        if(pf->dia == 28)
                            {
                                pf->dia = 1;
                        pf->mes++;

                            }else
                            {
                                pf->dia++;
                            }

                    }
            }
        break;

    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
        if(pf->dia==31)
            {
                pf->dia = 1;
                pf->mes ++;
            }
            else
                {
                    pf->dia++;
                }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if(pf->dia == 30)
            {
                pf->dia = 1;
                pf->mes++;
            }
        else
            {
                pf->dia ++;
            }
        break;
    case 12:
        if(pf->dia == 31 && pf->mes == 12)
            {
                pf->dia = 1;
                pf->mes = 1;
                pf->anio++;
            }else
            {
                if(pf->dia == 31)
                    {
                        pf->dia = 1;
                        pf->mes++;
                    }else
                    {
                        pf->dia++;
                    }
            }
            break;
    }
    printf("%d/%d/%d",pf->dia,pf->mes,pf->anio);
}

/*
recibe como argumento una fecha
sumarle un dia quiere decirle que primero tengo que sumarle 1 a los dias
pero a su vez los días dependen del mes en el que estemos porque si le sumo
1 al dia 30 de abril o al 31 de mayo voy a tener que pasar de mes entonces no
seria lo mismo.
Como soluciono esto? Con un switch poniendo las condiciones necesarias.
utilizando la notación de punteros con estructuras -> y manipulando los valores.

*/


/*-------------------------------  EJ 16 ------------------------------------*/

/*
Dada una fecha random 29/3/2022 le sumo N dias y devuelvo la fecha nueva.
Tengo que encarar el problema por los meses, tengo que saber en que mes estoy
ubicado. Porque no va a ser lo mismo el mes de enero que el de febrero ya que
uno puede llegar a 30 y otro a 28 y así. Lo primero que podriamos preguntar
es una vez ubicado en el mes es que si la suma de la cantidad de dias que tengo
en mi fecha actual + la cantidada de n dias que le sumo supera los dias del mes
en el que estoy y ahi efectuo los calculos. Sino lo supera simplemente sumo y
listo. Pero aca viene lo lindo si el numero es muy grande tengo que preguntarme
por cada mes si se pasa el limite hacer una operación algebraica y pasar al sig
guiente.
Entonces se podria empezar por algo asi:

if(pf->dia + n > cant_dias_en_el_mes_ubicado)
    {   n=177
        3/marzo
        n = n - ( cantDiaMes(pf->mes(marzo),2022)-pf->dia) //calculo cantidad de dias en los que estoy ubicado
        pf->mes++; abril
        pf->dia = 1;
        while(n>cantDiaMes(pf->mes,pf->anio))
        n = n - (cantDiaMes(pf->mes,2022);
        pf->mes++;
        n=119
        (mayo)
        n = 119 -31
        88
        junio
        58
        JULIO
        27

        if(pf->mes >12){
            pf->mes = 1;
            pf->anio++;
           }



    }else
    {
        quiere decir que no supera los dias del mes actual
        entonces hago solo la suma de dias + n y listo.

    }

*/
/*-------------------------------  EJ 16 ------------------------------------*/

/*
Bueno despues de horas de razonamiento vamos a documentar esto
En la condicion (1) planteo que si la cantidad de dias que tengo en la fecha
actual mas el numero n que es el que ingresa el usuario es mayor que la cantidad
de dias que tiene el mes de mi fecha actual entonces tengo que hacer operaciones
para poder "reducir" ese n de apoco.
Una vez que entro al if (1) a n le resto los dias que me faltan para completar
el mes de mi fecha actual. Por ejemplo si estoy en la fecha 3/5/2020 el mes de
mayo tiene 31 dias, si yo a 31 le resto 3 obtengo 28 que son los dias que me
faltan para "completar" el mes y pasar al siguiente. Ese 28 se lo resto a n
mes lo incremento en 1 y dia lo asigno a 1. Tambien pregunto que si el mes>12
sume un año y deje pf->mes en 1 para "resetearlo"
En el while planteo que si lo mismo que en el if(1) y si eso se cumple
le voy restando los dias del nuevo mes a n e incremento mes.
Cuando n ya no es mayor a la cantidad de dias que tiene el mes en que le toque
entonces los dias que quedan se lo asigno a pf->dia y listo tendria la fecha
nueva. Funciono con varios casos de prueba asi que supongo que esta bien.
En caso de que entre en el else grande (2) quiere decir que n es un numero
menor que la cantidad maxima que puede tener el mes de la fecha actual
entonces simplemente hago la suma.
*/
void sumarNdiasFecha(tFecha *pf,int n)
{
    if( (pf->dia + n) > cantDiasMes(pf->mes,pf->anio)) // (1)
        {
            n = n - (cantDiasMes(pf->mes,pf->anio)-pf->dia);


            pf->mes++;
            pf->dia = 1;
            if(pf->mes >12)
                        {
                            pf->mes = 1;
                            pf->anio++;
                        }
            while(n>cantDiasMes(pf->mes,pf->anio))
                  {
                     n = n - (cantDiasMes(pf->mes,pf->anio));
                     pf->mes++;
                     printf("valor de n %d \n",n);
                      if(pf->mes >12)
                        {
                            pf->mes = 1;
                            pf->anio++;
                        }
                  }
                  pf->dia =n;

        }
        else // (2)
            {
               pf->dia = pf->dia +n;
            }
    printf("\n%d/%d/%d",pf->dia,pf->mes,pf->anio);

}



/*-------------------------------  EJ 17 ------------------------------------*/


/*
Si la cantidad de dias de fecha actual - n >1


// caso de prueba 3/8/1999  n = 177
// 3 - 177 = -174
if(pf->dia -n <1)
    {
        n = pf->dia -n*(-1); // cambio el signo a positivo para seguir haciendo operaciones
        n = 174;
        pf->mes --; // decremento el mes para volver al pasado
        pf->dia = cantDiasMes(pf->mes,pf->anio);
        while(pf->dia -n < 1)
            {
              n = pf->dia -n *(-1);
              pf->mes --;
              pf->dia = cantDiasMes(pf->mes,pf->anio);
            }
    }else
    {
        pf->dia = pf->dia - n;
    }
    printf("%d/%d/%d",pf->dia,pf->mes,pf->anio);
*/


/*-------------------------------  EJ 18 ------------------------------------*/

/*
Desarrollar una función que a partir de dos fechas otbenga la cantidad de dias
que hay entre ellas.

int cantDiasEntreFechas(tFecha *pf, tFecha *pg)
{
    int cant_dias;
    int cant_anios;
    cant_dias = 0;

                    1997    -    2022 = -25
                    2022     -   1997 = 25

    if(pf->anio <  pg->anio)
        {
            cant_anios = (pf->anio - pg->anio)* (-1); // cambio signo
            cant_dias = cant_dias + ( cant_anios * 365);
        }else{
        if(pf->anio > pg->anio)
            {
                cant_anios = pf->anio - pg->anio;
                cant_dias = cant_dias + ( cant_anios * 365);
            }else
            {

                cant_dias = cant_dias + 0;
            }
        }

        // analisis de los meses
           ///                    E  F  M  A  MA J  JUL  A   S  O  N  D
    static const int diaMes[12]= {31,28,31,30,31,30, 31, 31, 30,31,30,31};

    2/4/1997   2/12/2022

    while(pf->mes <= diaMes[i])
        {
            cant_dias =
        }
}

*/
