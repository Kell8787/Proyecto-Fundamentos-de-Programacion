#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
//Funcion para agregar palabra
void agregarPalabra()
{
    
    FILE *archivo;
    archivo = fopen("Palabras.txt", "a");   //ocupamos el a, porque esto nos permite escribir sobre el archivo y no borrar los datos anteriores

    if (archivo == NULL)
    {
        printf("El archivo no se abrio correctamente");
        //return 1;
    }

    char nuevaPalabra[150];
    printf("Introduzca una palabra: ");
    scanf("%s", nuevaPalabra);

    fprintf(archivo, "%s", nuevaPalabra);
    fprintf(archivo, "\n");
    fclose(archivo);
}