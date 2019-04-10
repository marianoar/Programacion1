#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

//BORRADOR de la Funcion ejemplo para la baja

void baja (int legajo[], int estado [], int cantidad){
    char rta;
    int legajoAux, i, flag=0;
    printf (" ingrese Legajo a buscar:");
    scanf ("%d",&legajoAux);
    for (i=0; i<cantidad;i++) {
        if (legajo[i]==legajoAux){
                printf ("%d",legajo[i]);
                do{
                printf ("dar de baja el registro s/N?")
                fflush(stdin);
                scanf("%c",&rta);
                rta=toupper(rta);
                } while (rta!='S'&&rta!='N');
                flag=1;
         if(rta=='S'){
            estado[i]=0;
            break;
         } else {
             printf("no se elimino el registro");
         }
        }
    }
    if (flag==0){
        printf("legajo inexistente");
    }
}
//BORRADOR PARA MODIFICACION
do {
    op=menu()// esta opcion debe ser distinta de la otra opncion, el nombre. Es el SUBMENU DE
    switch(op){
    case 1:
        //apellido
    case 2:
        //nombre
    case 3:
        //etc..
    }// WHILE por q debe mantenerse en el menu para modificar las distintas opciones variables
}
