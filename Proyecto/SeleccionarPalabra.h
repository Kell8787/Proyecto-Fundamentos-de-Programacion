#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
//#include "Jugar.h"
//Funcion para que seleccione una palabra
const char *seleccionarPalabra(int dificultad)

{

    int cantidadDePalabrasEncontradasPorDificultad = 0;
    char palabras[100][100];

    // Leer del archivo
    FILE *textfile;
    char linea[100];
    textfile = fopen("Palabras.txt", "r");

    while (fgets(linea, sizeof(linea), textfile) != NULL)       //Leera todas las lineas del archivo que sean diferente de NULL
    {
        linea[strcspn(linea, "\n")] = 0;//strcspn lee desde el primer caracter de la palabra hasta que haya un salto de linea
        int tamanioPalabra = strlen(linea); // Verificando el tamanioPalabra

        if (dificultad == 1)
        {
            if (tamanioPalabra >= 6 && tamanioPalabra <= 11)
            {
                strcpy(palabras[cantidadDePalabrasEncontradasPorDificultad], linea);    //Copia lo que esta en Linea en Palabras y subira la cantidad de palabras que esta en dificultad
                cantidadDePalabrasEncontradasPorDificultad++;
            }
        }

        if (dificultad == 2)
        {
            if (tamanioPalabra >= 12 && tamanioPalabra <= 19)
            {
                strcpy(palabras[cantidadDePalabrasEncontradasPorDificultad], linea);    //Copia lo que esta en Linea en Palabras y subira la cantidad de palabras que esta en dificultad
                cantidadDePalabrasEncontradasPorDificultad++;
            }
        }

        if (dificultad == 3)
        {
            if (tamanioPalabra >= 20)
            {
                strcpy(palabras[cantidadDePalabrasEncontradasPorDificultad], linea);    //Copia lo que esta en Linea en Palabras y subira la cantidad de palabras que esta en dificultad
                cantidadDePalabrasEncontradasPorDificultad++;
            }
        }
    }

    fclose(textfile);
    srand(time(NULL)); // Generar num aleatorio
    int posicionPalabraAJugar = rand() % cantidadDePalabrasEncontradasPorDificultad + 0;
    const char *palabraSeleccionada = palabras[posicionPalabraAJugar];
    
    return palabraSeleccionada;
}