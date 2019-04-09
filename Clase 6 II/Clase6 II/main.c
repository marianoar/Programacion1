#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char apellido [15];
    char nombre [15];
    char apellidoNombre[50];

    printf (" Ingrese Apellido : ");
    scanf ("%s",apellido);
    printf (" Ingrese Nombre: ");
    scanf ("%s", nombre);

    strlwr (apellido); // string to lower
    strlwr (nombre);

    apellido[0] = toupper(apellido[0]);
    nombre[0]=toupper(nombre[0]);

    printf("\n");
   // printf(strtoupper(apellido[0]);
    apellidoNombre[0]='\0';
    strcat (apellidoNombre, apellido);
    strcat (apellidoNombre," ");
    strcat (apellidoNombre, nombre);
    printf (apellidoNombre);




return 0;
}
