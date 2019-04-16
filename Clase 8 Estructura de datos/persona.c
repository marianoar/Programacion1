#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

persona alta (persona per){
    printf("Ingresar apellido: ");
    scanf("%s",per.apellido);
    printf("\nIngrese nombre: ");
    scanf("%s",per.nombre);
    printf("\nIngrese edad: ");
    scanf("%d",&per.edad);
    per.isEmpty=0;
    return per;
}
