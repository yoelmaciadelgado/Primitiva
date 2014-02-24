#include <stdio.h>
#include <stdlib.h>

typedef short TELEMENTO;

typedef struct {
    TELEMENTO *datos; /*valores del vector*/
    short tam; /*tamaño del vector*/
} STVECTOR; /*definición de la estructura*/

typedef STVECTOR *vectorP; /*puntero a estructura*/

/*Función crear: asigna memoria y devuelve la asignación al vector*/

void crear(vectorP *v1, short tam1) {
    short i = 0;
    *v1 = (vectorP) malloc(sizeof (STVECTOR));
    if(v1==NULL){
        printf("No se ha reservado memoria\n");
    exit(-1);
    }
    (*v1)->datos = (TELEMENTO*)malloc(tam1*sizeof(TELEMENTO));
    if(v1==NULL){
        printf("No se ha reservado memoria\n");
    exit(-1);
    }
    (*v1)->tam = tam1;
    for (i = 0; i < tam1; i++)
        *((*v1)->datos + i) = 0; /*Inicialización a 0 de las componentes del vector*/
}

/*Función asignar: Asigna un valor a una posición del vector */

void asignar(vectorP *v1, short posicion, TELEMENTO valor) {
    *((*v1)->datos + posicion) = valor; // inicializa a 0 las variables no el puntero, si le quitamos el primer puntero inicializará a 0 el puntero.
}

/*Funcion recuperar siempre void en esta primera practica*/

TELEMENTO recuperar(vectorP v1,short posicion){
    if(posicion < 0 || posicion>= v1->tam){
        printf("Erro: Posición do vector incorrecta, valores válidos de 0 a %d\n",(v1->tam)-1);
        return -1;
    }
    else{
        return v1->datos[posicion];
    }
    
}

/*Función tamaño no devuelve nada void, primera practica*/

short tamano(vectorP v1){
    return v1->tam;
}

/*Función liberar*/

void liberar(vectorP *v1){
    if((*v1)!=NULL){
        free((*v1)->datos);
        free(*v1);
        *v1=NULL;
    }
}


TELEMENTO aleatorioUnoCuarentaNueve(){
    TELEMENTO numero;
    numero = 1+rand()%(50-1);
    return numero;
}

TELEMENTO aleatorioUnoNueve(){
    TELEMENTO numero;
    numero = 1+rand()%(10-1);
    return numero;
}
