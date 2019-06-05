#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "People.h"

int size;
int index;
Persona** lista;

void persona_initLista(void){
size = 10;
index=0;
lista = (Persona**)malloc(sizeof(Persona*)*size);
}

void persona_addPersona(Persona* p){
lista[index]=p;
index++;
    if(index>=size){
        printf("no hay mas lugar, redefinimos el array\r\n");
        size=size+10;
        lista = (Persona**)realloc(lista,sizeof(Persona*)*size);
    }
}

Persona* persona_newPersona(void){
    Persona* persona = (Persona*)malloc(sizeof(Persona));
    return persona;
}

void preguntarNombre (char auxName[]){
    while(!getStringLetras("\nIngrese nombre: ",auxName)){
            printf("\n Error. Ingrese nuevamente.");
    }
    while(strlen(auxName)<3){
        printf("Error");
            while(!getStringLetras("\nIngrese nombre: ",auxName)){
            printf("\n Error. Ingrese nuevamente.");
    }
    }

}

int preguntarEdad(){
    char auxEdad[3];
    int auxEdadInt;
    while(!getStringNumeros("\nIngrese edad:", auxEdad)){
    printf("\n Error. De nuevo");
    }
    auxEdadInt=atoi(auxEdad);
    if (auxEdadInt<=0 || auxEdadInt > 120){
        printf("Error. De nuevo");
        while(!getStringNumeros("\nIngrese edad:", auxEdad)){
        printf("\n Error. De nuevo");
    }
    auxEdadInt=atoi(auxEdad);
    }
    return auxEdadInt;
}
int persona_setName(Persona* pPersona, char* pName){
    if(strlen(pName)>2){
        strcpy(pPersona->nombre,pName);
    return 1;
    }
return 0;
}

int persona_setEdad(Persona* pPersona, int edad){
    pPersona->edad = edad;
    return 1;
}

int persona_getEdad(Persona* pPersona){
return pPersona->edad;
}
char* persona_getNombre(Persona* pPersona){
return pPersona->nombre;
}

void persona_toString(Persona* pPersona){
    printf("\nNombre:%s y  Edad:%d",pPersona->nombre,pPersona->edad);
}



