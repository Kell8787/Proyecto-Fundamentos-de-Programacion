#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
//Funcion para agregar el puntaje
void agregarPuntaje(const char *posicion)
{
    FILE *archivo;
    archivo = fopen("Posicion.txt", "a");

    //Esto solo para evaluar si existe o no el archivo
    if (archivo == NULL)
    {
        printf("El archivo no se abrio correctamente");
        // return 1;
    }

    fprintf(archivo, "%s", posicion);
    fprintf(archivo, "\n");
    fclose(archivo);
}