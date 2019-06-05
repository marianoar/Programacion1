#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "People.h"

int main(){

persona_initLista();

do {
    Persona* persona=persona_newPersona();

    char auxNombre[25];
    preguntarNombre(auxNombre);
    if(!persona_setName(persona, auxNombre)){
        printf("\nError. Nombre no valido.");
    }

    int auxEdad=preguntarEdad();

    persona_setEdad(persona, auxEdad);

    persona_addPersona(persona);

    persona_toString(persona);

}while(preguntarSalir()!='N');



return 0;
}
