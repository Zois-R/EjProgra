#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
// ACA SE METEN TODOS LOS PROTOTIPOS DE FUNCIONES

typedef struct
{
    int dia,
        mes,
        anio;
}tFecha;


int factorial(int);
int combinatorio(int,int);
float exponencial(int,int);
float serieExponencial(int,float);
void esPerfDefiAbund(int);
int sumas_sucesivas(int,int);
void cocienteYresto();
int calculoDeNnumeros(int);
int sumaNpares(int);
void esPrimo(int);
int esBisiesto(int);
int cantDiasMes(int,int);
int esFechaValida(const tFecha *pf);
void sumoUnDiaFecha(tFecha *pf);
void sumarNdiasFecha(tFecha *pf,int);
#endif // FUNCIONES_H_INCLUDED
