#include <stdio.h>
#include <stdlib.h>
#define CANT 3
#include "persona.h"


int main()
{
    persona per;

    per= alta(per);

    printf("\nLos datos ingresados fueron:");
    printf("\n");
    printf("\n");
    printf("\n %s, \t  %s \t %d \t %d",per.apellido, per.nombre, per.edad, per.isEmpty);
    printf("\n");
    printf("\n");

    return 0;
}
