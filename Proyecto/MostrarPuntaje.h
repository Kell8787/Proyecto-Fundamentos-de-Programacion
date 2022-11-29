#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
//Funcion para que nos muestre el puntaje 
void mostrarPuntaje()
{
    FILE *archivo;
    archivo = fopen("Posicion.txt", "r");

    //Esto solo para evaluar si existe o no el archivo
    if (archivo == NULL)
    {
        printf("El archivo no se abrio correctamente");
        // return 1;
    }

    char linea[100];
    //Funcion while que leera el contenido del archivo hasta que sea nulo
    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        printf("%s", linea);
    }
}