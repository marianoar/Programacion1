#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "dominio.h"

int main()
{
    int option, opcion;
    int largo,i;
    int aux;
    FILE *parch;
    FILE* prueba;
    FILE *car;
    FILE *moto;
    LinkedList* listaDominios=ll_newLinkedList();
    LinkedList* listaNueva=ll_newLinkedList();
    LinkedList* listaMoto=ll_newLinkedList();
    LinkedList* listaAuto=ll_newLinkedList();
    eDominio* dominio;
    char motos='M';
    char carro='A';
    char nombre[20];
    int flag=0;
    //char auxString[8];
    do{

        option=getIn("\n\n 1. Leer y cargar los datos de archivo \n 2. Setear campo tipo\n 3. Realizar filter\n 4. Generar archivos de salida. \n5.-Listar \n 6.- Sacar archivo ordenado por año\n 0. Salir\nSu opcion: ");

        switch(option)
        {
            case 1:

               // getString("\nIngrese el nombre y ruta del archivo que desea abrir: (datos.csv)",nombre);
                if((parch=fopen( "datos.csv" ,"r"))==NULL){
                    printf("\nEl archivo %s no pudo ser abierto",nombre);
                }else{
                    system("cls");
                    printf("Archivo abierto exitosamente");
                    parser_FromText(parch, listaDominios);

                }
                fclose(parch);


            break;
            case 2:
                ll_map(listaDominios, setearTipo);

            break;
            case 3:
                opcion=getIn("ingrese 1 para Auto o 2para Moto para hacaer archivos de salida: ");
                //opcion=toupper(opcion);
                if(opcion==1){
                    listaAuto=ll_filter(listaDominios, filtraCarro);
                    aux = parser_SaveToText(listaAuto, "auto.csv");
                   }else if (opcion==2){

                     listaMoto= ll_filter(listaDominios, filtraMoto);
                     aux=parser_SaveToText(listaMoto, "moto.csv");
                   }

            break;
            case 4:
               /* prueba=fopen("datos.csv" ,"r");
                parser_DominioFromText(prueba, listaNueva);
                ll_map(listaNueva,setearTipo);

                aux=parser_SaveToText(listaNueva, "nuevanueva.txt");
*/

            break;
            case 5:
                if(listaDominios==NULL){
                    printf("\nError");
                }else{
                    printerList(listaDominios);
                }
                break;
            case 6:


                break;

        }
    }while(option != 0);

    return 0;
}
