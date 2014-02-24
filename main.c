#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vectordinamico.h" 

#define tamano_combinacion_ganadora 8
#define tamano_apuesta 7

int main(int argc, char** argv) {
    vectorP v1,v2; /* declaramos el vector*/
    short tam1, i,j; /*variables para almacenar su tamaño y una variable para recorrerlo*/
    TELEMENTO valor; /*El valor a introducir en el vector*/
    char opcion; /*La variable del menú*/
    int numero;
    int bandera = 1;
    int comprobar = 1;
    short var,var2;
    int verdad = 1;

    while(bandera == 1){
    
    do {
        printf("\ṇ-----------------------------------------------------------\n");
        printf("\nBienvenidos a la aplicación de apuestas de quiniela\n");
        printf("\na) Sorteo");
        printf("\nb) Introducción de apuestas");
        printf("\nc) Comprobación de apuestas");
        printf("\nd) Salir");
        printf("\n-----------------------------------------------------------\n");

        printf("\nOpcion: ");
        scanf(" %c", &opcion);

       switch (opcion) {
            case 'a':
                comprobar = 1;
                while(comprobar == 1){
                        srand(time(NULL));
                        /*Creo vector v1 que va a ser el de la combinación ganadora con tamaño 8*/
                        crear(&v1, tamano_combinacion_ganadora);
                        /*Asigno valores de los primeros 6 numeros*/
                        for (i = 0; i <= tamano_combinacion_ganadora - 3; i++) {
                            valor = aleatorioUnoCuarentaNueve();
                            asignar(&v1, i, valor);
                        }

                        /*Asigno valores al complementario*/
                        for (i = 6; i <= tamano_combinacion_ganadora - 2; i++) {
                            valor = aleatorioUnoCuarentaNueve();
                            asignar(&v1, i, valor);
                        }
                        /*Asigno valores al reintegro*/
                        for (i = 7; i <= tamano_combinacion_ganadora - 1; i++) {
                            valor = aleatorioUnoNueve();
                            asignar(&v1, i, valor);
                        }
                        if (numerosRepetidos(v1) == -1) {
                            liberar(&v1);
                        } else {
                            imprimir(v1);
                            comprobar = 0;
                        }
                }
                break;
            case 'b':
                comprobar = 1;
                    while (comprobar == 1) {
                        printf("Seleccione su tipo de apuesta\n");
                        printf("1.Apuesta Manual - 2.Apuesta Automatica\n");
                        scanf("%d", &numero);
                        if (numero == 1) {
                            srand(time(NULL));
                            crear(&v2, tamano_apuesta);
                            printf("Introduzca los 6 numeros de su apuesta\n");
                            for (j = 0; j <= tamano_apuesta - 2; j++) {
                                printf("Numero [%d] ", j);
                                scanf("%hd", &valor);
                                asignar(&v2, j, valor);
                            }
                            for (j = 6; j <= tamano_apuesta; j++) {
                                valor = aleatorioUnoNueve();
                                asignar(&v2, j, valor);
                            }
                            if (numerosRepetidos(v2) == -1) {
                                liberar(&v2);
                                printf("No puede apostar numeros repetidos\n");
                            } else {
                                imprimirApuesta(v2);
                                comprobar = 0;
                            }
                        }
                        else if(numero == 2){
                            srand(time(NULL));
                            crear(&v2, tamano_apuesta);
                            printf("Introduzca los 6 numeros de su apuesta\n");
                            for (j = 0; j <= tamano_apuesta - 2; j++) {
                                valor = aleatorioUnoCuarentaNueve();
                                asignar(&v2, j, valor);
                            }
                            for (j = 6; j <= tamano_apuesta; j++) {
                                valor = aleatorioUnoNueve();
                                asignar(&v2, j, valor);
                            }
                            if (numerosRepetidos(v2) == -1) {
                                liberar(&v2);
                                printf("No puede apostar numeros repetidos");
                            } else {
                                imprimirApuesta(v2);
                                comprobar = 0;
                            }
                        }
                }
               break;
            
            case 'c':
                var = tamano(v1);
                var2 = tamano(v2);
        
                if(var != 8 && var2 != 7){
                     printf("Tiene que crear el vector v1 y v2, antes de usar esta opcion\n");
                     verdad = 0;
                }
                else{
                    verdad = 1;
                }
                if(verdad == 1){
                    numero = comprobacionApuesta(v1,v2);
                }
                
                switch (numero) {
                    case 6:
                        printf("Ha acertado 6 numeros, enhorabuena ha ganado un premio de primera categoria\n");
                        break;
                    case 11:
                        printf("Ha acertado 5 numeros mas el complementario, enhorabuena ha ganado un premio de segunda categoria\n");
                        break;
                    case 5:
                        printf("Ha acertado 5 numeros, enhorabuena ha ganado un premio de tercera categoria\n");
                        break;
                    case 4:
                        printf("Ha acertado 4 numeros, enhorabuena ha ganado un premio de cuarta categoria\n");
                        break;
                    case 3:
                        printf("Ha acertado 3 numeros, enhorabuena ha ganado un premio de quinta categoria\n");
                        break;
                    case 10:
                        printf("Enhorabuena, ha ganado el reintegro\n");
                        break;
                    case 2:
                        printf("No esta premiado\n");
                        break;
                    case 1:
                        printf("No esta premiado\n");
                        break;
                    case 0:
                        printf("No esta premiado\n");
                        break;
                }
               numero = 0;
               break;

            case 'd':
                printf("Seguro que desea salir?\n");
                printf("1.Si - 0.No\n");
                scanf("%d", &numero);
                if (numero == 1) {
                    bandera = 0;
                    liberar(&v1);
                    exit(0);
                } else{
                    bandera = 1;
                    break;
                }
            default: printf("Opcion incorrecta\n");
        }
    } 
    
    while (opcion != 'd');
    }
    return (EXIT_SUCCESS);
}

void imprimir(vectorP v1) {
    short i = 0;
    printf("\n\t------ NUMEROS DEL SORTEO ------\n");
    for (i = 0; i < tamano(v1)-2; i++) {
        printf("\t|%hd|",recuperar(v1, i));
    }
    printf("\n");
    for (i = 6; i < tamano(v1)-1; i++) {
        printf("\tComplementario : |%hd|\n",recuperar(v1, i));
    }
    for (i = 7; i < tamano(v1); i++) {
        printf("\tReintegro : |%hd|\n",recuperar(v1, i));
    }
    printf("\t--------------------------------\n");
}

void imprimirApuesta(vectorP v1) {
    short i = 0;
    printf("\n\t------ NUMEROS DE TU APUESTA ------\n");
    for (i = 0; i < tamano(v1)-1; i++) {
        printf("\t|%hd|",recuperar(v1, i));
    }
    printf("\n");
    for (i = 6; i < tamano(v1); i++) {
        printf("\tReintegro : |%hd|\n",recuperar(v1, i));
    }
    printf("\t--------------------------------\n");
}

int numerosRepetidos(vectorP v1) {
    short i, k;
    short numero;
    for (i = 0; i < tamano(v1); i++) {
        numero = recuperar(v1, i);
        for (k = i + 1; k < tamano(v1); k++) {
            if (numero == recuperar(v1, k)) {
                return -1;
            }
        }
    }
}

int comprobacionApuesta(vectorP v1,vectorP v2){
    int i, j;
    int numeroAciertos = 0;
    for (i = 0; i < tamano(v1) - 2; i++) {
        for (j = 0; j < tamano(v2) - 1; j++) {
            if (recuperar(v1, i) == recuperar(v2, j)) {
                numeroAciertos++;
            }
        }
    }
    // Comprobación complementario :
    for (i = 6; i < tamano(v1) - 1; i++) {
        for (j = 6; j < tamano(v2) - 1; j++) {
            if (recuperar(v1, i) == recuperar(v2, j)) {
                numeroAciertos = 11;
            }
        }
    }
    // Comprobación reintegro : 
    for (i = 7; i < tamano(v1); i++) {
        for (j = 6; j < tamano(v2); j++) {
            if (recuperar(v1, i) == recuperar(v2, j)) {
                numeroAciertos = 10;
            }
        }
    }
    
    return numeroAciertos;
}

