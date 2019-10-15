#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "entidades.h"

int main()
{
    int option;
    int optionB;
    int opcionC;
    int flag=0;
    int aux;

    FILE *pArch;

    LinkedList* listaEnvios=ll_newLinkedList();
    LinkedList* listaSalida;
    LinkedList* auxiliarList;

    char nombre[20];
    //char auxString[8];
    do{
        option=menuInicio();

        switch(option)
        {
            case 1:

               // getString("\nIngrese el nombre y ruta del archivo que desea abrir: (DATA_final1.csv)",nombre);
                if((pArch=fopen( "DATA_final2.csv" ,"r"))==NULL){
                    printf("\nEl archivo %s no pudo ser abierto",nombre);
                }else{
                    system("cls");
                    if(parser_FromText(pArch, listaEnvios)){
                       printf("Archivo abierto exitosamente");
                       flag=1;
                       }
                }
                fclose(pArch);
            break;
            case 2:
                if(flag){
                    printerList(listaEnvios);
                }else{
                    printf("No se cargo el archivo aun");
                }
            break;
            case 3:
                  if(!flag){
                        printf("\n No se cargo el archivo aun");
                }else{
                   listaSalida=ll_map(listaEnvios,setCosto);
                   printerList(listaSalida);
                    system("pause");
                  aux= parser_SaveToText(listaSalida,"salidaCostos.csv");
                  if (aux){
                    system("cls");
                    printf("Archivo ha sido creado");
                  }else{
                    printf("Error");
                  }
                }
            break;
            case 4:
                if(flag){
                    optionB=menuSecond();
                    if (optionB==1){
                        auxiliarList=ll_filter(listaEnvios,getEnvio1);
                        printerList(auxiliarList);
                    }else if (optionB==2){
                        auxiliarList=ll_filter(listaEnvios,getEnvio2);
                        printerList(auxiliarList);
                        }else if(optionB==3){
                            auxiliarList=ll_filter(listaEnvios,getEnvio3);
                            printerList(auxiliarList);
                        }
                }else{
                    printf("\n No se cargo el archivo aun");
                }
            break;
            case 5:
                if(flag){
                    ll_sort(listaEnvios, ordenar, 1);
                    printerList(listaEnvios);

                }else{
                    printf("\n No se cargo el archivo aun");
                }
                break;
            case 6:
                if(flag){
                    opcionC=menuArchivos();
                    if (opcionC==1){
                          auxiliarList=ll_filter(listaEnvios, getEnvio1);
                          if(parser_SaveToText(auxiliarList, "archivo1.txt")){
                            system("cls");
                            printf("\nArchivo creado!");
                          }else{
                            printf("Error. El archivo no ha sido creado.");
                          }

                    }else if(opcionC==2){
                        auxiliarList=ll_filter(listaEnvios, getEnvio2);
                          if(parser_SaveToText(auxiliarList, "archivo2.txt")){
                            system("cls");
                            printf("\nArchivo creado!");
                          }else{
                            printf("Error. El archivo no ha sido creado.");
                          }

                    }else if(opcionC==3){
                        auxiliarList=ll_filter(listaEnvios, getEnvio3);
                          if(parser_SaveToText(auxiliarList, "archivo3.txt")){
                            system("cls");
                            printf("\nArchivo creado!");
                          }else{
                            printf("Error. El archivo no ha sido creado.");
                          }
                    }
                }else{
                    printf("\n No se cargo el archivo aun");
                }
                break;
        }
    }while(option != 0);

    return 0;
}
