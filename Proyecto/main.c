#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "Jugar.h"//Modulo de la funcion jugar
#include "SeleccionarPalabra.h"//Modulo de la funcion SeleccionarPalabra
#include "AgregarPalabra.h"//Modulo de la funcion AgregarPalabra
#include "AgregarPuntaje.h"//Modulo de la funcion AgregarPuntaje
#include "MostrarPuntaje.h"//Modulo de la funcion MostrarPuntaje

int main()
{
    char palabraAdivinar[60];
    char nombre[20];
    const char *palabraSeleccionada;
    int opcion, puntaje = 0, dificultad = 0; 

    printf("\tJuego del Ahorcado\n");
    system("PAUSE");

    do // Leer la opt hasta que sea 4

    {
        system("cls");
        printf("\n1. Jugar\n2. Posiciones\n3. Agregar Palabras\n4. Salir\n");
        printf("Escoja una opcion en pantalla: ");
        scanf("%d", &opcion);

        //Funcion if que segun los valores que introduzca el usuario entrara en un switch que mandara a llamar a las dichas funciones/modulos
        if (opcion > 0 && opcion <= 4)
        {
            switch (opcion)
            {

                case 1:
                printf("Introduzca su nombre: ");
                scanf("%s", &nombre);

                printf("\nIngrese la dificultad\n1. Facil\n2. Medio\n3. Dificil: ");
                scanf("%d", &dificultad);

                puntaje = jugar(seleccionarPalabra(dificultad), dificultad);

                if (puntaje > 0)
                {
                    char posicion[] = "";
                    char pt[5];
                    itoa(puntaje, pt, 10);      //esta funcion nos convierte un dato int a un arreglo, pt significa puntuacion
                    strcat(posicion, nombre);   //Juntara mi nombre con la posicion, pero toma un espacio
                    strcat(posicion, " - ");    // espacio entre el nombre y la posicion
                    strcat(posicion, pt);       // ingresara el puntaje
                    agregarPuntaje(posicion);
                }

                break;

                case 2:
                mostrarPuntaje();   //Llama a la funcion de puntaje, para ver la tabla
                system("PAUSE"); //esta funcion sirve para detener el codigo 
                //y mostrar la funcion que esta siendo llamada anterior a ella

                break;

                case 3:
                agregarPalabra();
                system("PAUSE");//esta funcion sirve para detener el codigo 
                //y mostrar la funcion que esta siendo llamada anterior a ella

                break;

            }
        }

        else
        {
            printf("Su opcion no fue valida! \n");
            system("PAUSE");
        }

    } while (opcion != 4);  //Si la opcion es 4 se cerrara el juego

    return 0;
}