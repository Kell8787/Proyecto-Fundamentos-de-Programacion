#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//Funcion para poder jugar
int jugar(const char *palabraAdivinar, int dificultad)

{
    int largodePalabra = 0, contador = 0, paso = 1, letrasAcertadas = 0, condicion = 0, oportunidades = 0, letrastotal = 0, letraRepetida = 0, gano = 0, puntuacion = 0; //Inicializamos lo que utliizaremos para poder jugar
    char posicionDeLaLetra[100], letras[100];
    char letraIngresada = -1;                   // le asignamos el -1 para que no incremente las letras acertadas cuando se repite una letra

    //comparamos que numero se a ingresado para poder saber que dificultad se utilizara y la cantidad de oportunidades que tendra

    if (dificultad == 1)
    {
        oportunidades = 15;
    }

    if (dificultad == 2)
    {
        oportunidades = 10;
    }

    if (dificultad == 3)
    {
        oportunidades = 7;
    }

    do  //Hasta que oportunidades sean diferentes de 0
    {
        condicion = 0;      //

        if (paso == 1)      
        {
            for (int i = 0; i < strlen(palabraAdivinar); i++)   //Lee la cantidad de caracteres que tiene la palabraAdvinar
            {   
                //Funcion if-else que ira mostrando los espacios que reemplazara cada letra que vaya poniendo el usuario
                if (palabraAdivinar[i] == ' ')
                {
                    letras[i] = ' ';
                    largodePalabra++;
                }
                else
                {
                    letras[i] = '_';
                    largodePalabra++;
                }
            }

            paso = 2;       //Paso 2 para que ya no siga poniendo los guiones
            letras[largodePalabra] = '\0';  //esto para que me muestre las letras exactas
        }

        else
        {
            //Funcion for que hara loop segun el tamaño del areglo
            for (int i = 0; i < strlen(posicionDeLaLetra); i++) 
            {
                if (posicionDeLaLetra[i] == letraIngresada) //Saber si se repite la letra
                {
                    letraRepetida = 1;
                    break;
                }

                else
                {
                    letraRepetida = 0;  
                }
            }
            //Funcion if que si la letra no es repetida ira metiendo cada letra en su posicion debida
            if (letraRepetida == 0)
            {
                posicionDeLaLetra[contador] = letraIngresada;
                contador++;

                //Funcion for que hara loop segun el tamaño del arreglo
                for (int i = 0; i < strlen(palabraAdivinar); i++)
                {
                    //Funcion if que si la letra es correcta, ira aumentando la puntuacion de las letras acertadas
                    if (palabraAdivinar[i] == letraIngresada) 
                    {
                        letras[i] = letraIngresada;
                        letrasAcertadas++;
                        condicion = 1;  
                    }
                }
            }
            //Funcion if que permite conocer si una letra se encuentra repetida
            if (letraRepetida == 0)
            {
                //Funcion if que le quita al usuario una oportunidad si la letra esta repetida
                if (condicion == 0)
                {
                    oportunidades = oportunidades - 1;
                }

                system("cls");
                
                //Funcion for que muestra las letras que se vayan ingresando
                for (int i = 0; i < strlen(letras); i++)
                {
                    printf(" %c ", letras[i]);
                }

                printf("\n");

                //Funcion if que permite conocer si el jugador a ganado o ha perdido
                if (strcmp(palabraAdivinar, letras) == 0)   //strcmp compara si la palsbra a sido adivinada
                {
                    gano = 1;
                    break;
                }

                printf("\nLetras Acertadas: %d\n", letrasAcertadas);
                printf("Oportunidades Restantes: %d\n", oportunidades);
                printf("Letras ingresadas: %d\n", letrastotal);
            }

            else
            {
                printf("Ya se ha introducido la '%c' en esta partida.\n", letraIngresada);
            }

            //Funcion if que hace un loop mientras las oportunidades sean diferentes de 0 para que logre completar la palabra
            if (oportunidades != 0)
            {
                printf("Introduzca una letra:");
                scanf(" %c", &letraIngresada);
                letraIngresada=tolower(letraIngresada); //Si colocamos una letra en mayuscula , convetira todas las letras a minusculas y si seria alrevez se utiliza Toupper

                if (letraIngresada)     //Cantidad de letras ingresadas en total
                {
                    letrastotal++;
                }
            }
        }

    } while (oportunidades != 0);

    //Funcion if-else que dara el puntaje si el jugador a ganado, o mostrara si el jugador a perdido
    if (gano)
    {
        puntuacion = letrasAcertadas + (3 * oportunidades);     //Letras que acertamos + (3 por las oportunidades que me quedan)
        printf("\n\n");
        printf("Felicidades! Ganaste esta ronda!\n");
        printf("Tu puntuacion es: %d", puntuacion);
    }

    else
    {
        printf("\n\n");
        printf("Lo sentimos, perdiste regacho.");
    }

    printf("\n\n");
    system("PAUSE");
    return puntuacion;
}