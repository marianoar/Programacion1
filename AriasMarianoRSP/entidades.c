#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "LinkedList.h"
#include "entidades.h"


int parser_FromText(FILE* pFile , LinkedList* listaLlamadas){
    char aux_id[5];
    char aux_fecha[10];
    char aux_cliente[10];
    char aux_problema[2];
    char aux_solucion[3];
    int charge;
    int retorno = 0;

    charge=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", aux_id, aux_fecha,aux_cliente,aux_problema,aux_solucion);

    do{
        charge=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", aux_id, aux_fecha,aux_cliente,aux_problema,aux_solucion);
        if(charge!=5){
            printf("Error");

            return retorno;
        }else{
            eLlamada* pLlamada=llamada_new();

            strcpy(pLlamada->id_llamada,aux_id);
            strcpy(pLlamada->fecha,aux_fecha);
            pLlamada->numeroCliente=atoi(aux_cliente);
            pLlamada->idProblema=atoi(aux_problema);
            strcpy(pLlamada->solucionado,aux_solucion);

            ll_add(listaLlamadas, pLlamada);
            retorno=1;
        }
    }while(!feof(pFile));
    fclose(pFile);

    return retorno;
}


eLlamada* llamada_new(){

eLlamada* pLlamada=(eLlamada*)malloc(sizeof(eLlamada));

     strcpy(pLlamada->id_llamada,"algo");
     strcpy(pLlamada->fecha," ");
     pLlamada->numeroCliente=0;
     pLlamada->idProblema=0;
     strcpy(pLlamada->solucionado," ");

return pLlamada;
}

void printerList(LinkedList* listaLlamadas ){
eLlamada* llamada;
int largo, i;
char problema_1[20] = "No enciende PC";
//char problema_2[20] = "No funciona mouse";
//char problema_3[20] = "No funciona teclado";
//char problema_4[20] = "No hay internet";
//char problema_5[20] = "No funciona telefono";

    if(listaLlamadas==NULL){
                    printf("\nError");
                    return ;
                }else{
                    largo=ll_len(listaLlamadas);
                   // printf("\n El largo es: %d",largo);
                    printf("\n %5s %15s %5s %5s %5s","ID_Llamada","Fecha","Numero_Cliente","ID_Problema","Solucionado");
                for (i=0;i<largo;i++){
                    llamada=ll_get(listaLlamadas, i);
                    printf("\n %5s %15s %5d",llamada->id_llamada, llamada->fecha,llamada->numeroCliente);
                if(llamada->idProblema==1){
                        printf(" %5s",problema_1);
                }
                    printf("%5s", llamada->solucionado);
                }

                }
}


/** \brief Graba los datos en el archivo un archivo .csv (modo texto).
 *
 * \param path char*
 * \param pLinkedListVend LinkedList*
 * \return int
 *
 */
/*
int saveAsText(char* path, LinkedList* listaLlamadas)
{
    FILE* pArchivo = fopen(path,"w");
    int retorno = -1;

    if(pArchivo != NULL && !parser_SaveToText(pArchivo,listaLlamadas))
    {
        printf("\n Grabado de datos en formato texto.\n");
        retorno = 0;
    }
    fclose(pArchivo);
    system("pause");
    return retorno;
}
*/
int parser_SaveToText(LinkedList* lista, char* archivo)
{
    int retorno = 0;
    eLlamada* aux;
    int largo=ll_len(lista);
    int i;
    int qw;
    FILE* pFile;

    pFile=fopen(archivo,"w");
    if(pFile != NULL && lista != NULL)
    {
        fprintf(pFile,"ID_Llamada,Fecha,Numero_Cliente,ID_Problema,Solucionado\n");

        for(i=0;i<largo;i++)
        {
            aux = ll_get(lista,i);

            qw=fprintf(pFile,"%s, %s, %i, %i, %s\n",aux->id_llamada, aux->fecha, aux->numeroCliente, aux->idProblema, aux->solucionado);

        }
        retorno= 1;
    }
    fclose(pFile);
    return retorno;
}

int getProblem1 (void* pElement){

    int retorno = 0;


    if (((eLlamada*)pElement)->idProblema==1){
        retorno = 1;
    }
    return retorno;
}
