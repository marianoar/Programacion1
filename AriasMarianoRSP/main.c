#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "entidades.h"

int main()
{
    int option;
    //int largo;
    int flag=0;
    //int aux;

    FILE *pArch;



    LinkedList* listaLlamadas=ll_newLinkedList();
    LinkedList* listaProblemas=ll_newLinkedList();

   // eLlamada* llamada;
   // eLlamada* auxLlamada;


    char nombre[20];
    //char auxString[8];
    do{

        option=getIn("\n\n 1. Leer y cargar los datos de archivo \n 2. Imprimir\n 3. Generar archivos de salida.\n 4. Salir\n\nSu opcion: ");

        switch(option)
        {
            case 1:

               // getString("\nIngrese el nombre y ruta del archivo que desea abrir: (DATA_final1.csv)",nombre);
                if((pArch=fopen( "DATA_final1.csv" ,"r"))==NULL){
                    printf("\nEl archivo %s no pudo ser abierto",nombre);
                }else{
                    system("cls");
                    if(parser_FromText(pArch, listaLlamadas)){
                       printf("Archivo abierto exitosamente");
                       flag=1;

                       }
                }
                fclose(pArch);




            break;
            case 2:
                 printerList(listaLlamadas);

            break;
            case 3:
                if(!flag){
                        printf("\n No se cargo el archivo aun");
                }else{
                    //aux=getIn("Ingrese problema por que desea filtrar");

                     listaProblemas=ll_filter(listaLlamadas,getProblem1);
                     printerList(listaProblemas);
                    parser_SaveToText(listaProblemas,"problema1.csv");

                }
            break;


        }
    }while(option != 4);

    return 0;
}
