
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//Funciones

int jugar(const char *palabraSeleccionada, int dificultad);
const char *seleccionarPalabra(int dificultad);
void agregarPalabra();
void mostrarPuntaje();
void agregarPuntaje(const char *posicion);

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
}

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

            if (letraRepetida == 0)
            {
                posicionDeLaLetra[contador] = letraIngresada;
                contador++;

                for (int i = 0; i < strlen(palabraAdivinar); i++)
                {
                    if (palabraAdivinar[i] == letraIngresada) 
                    {
                        letras[i] = letraIngresada;
                        letrasAcertadas++;
                        condicion = 1;  
                    }
                }
            }

            if (letraRepetida == 0)
            {
                if (condicion == 0)
                {
                    oportunidades = oportunidades - 1;
                }

                system("cls");
                

                for (int i = 0; i < strlen(letras); i++)
                {
                    printf(" %c ", letras[i]);
                }

                printf("\n");

                if (strcmp(palabraAdivinar, letras) == 0)   //strcmp para  
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
        linea[strcspn(linea, "\n")] = 0;
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
    // toupper(palabraSeleccionada);
    return palabraSeleccionada;
}

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

    nuevaPalabra=tolower(nuevaPalabra);
    fprintf(archivo, "%s", nuevaPalabra);
    fprintf(archivo, "\n");
    fclose(archivo);
}

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

    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        printf("%s", linea);
    }
}