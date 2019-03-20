#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int numero, maximo, minimo, flag=0;
    char respuesta;

    do{
        printf("Ingrese un numero: ");
        scanf("%d",&numero);
        if ((flag==0) || (numero>maximo)){
        maximo=numero;
        }
        if (flag==0 || numero<minimo){
            minimo=numero;
            flag=1;
        }
        do{
        printf("continua? [S/N]");
        fflush(stdin);              //limpio el buffer
        scanf("%c",&respuesta);
        respuesta=toupper(respuesta); //pasa a mayuscula , sino uso 'tolower' para pasar a minuscula
        }while (respuesta!='S' && respuesta!='N');
    }while (respuesta=='S');
    system("cls");                  // limpia la pantalla
    printf("El numero maximo es :%d\n El numero minimo es :%d",maximo,minimo);
    return 0;
    }





