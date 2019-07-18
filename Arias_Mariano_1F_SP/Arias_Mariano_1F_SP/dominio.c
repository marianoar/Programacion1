#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "dominio.h"


int parser_FromText(FILE* pFile , LinkedList* listaDominios){
    char aux_id[4];
    char aux_dominio[10];
    char aux_anio[5];
    //char aux_tipo[2];
    int charge;
    charge=fscanf(pFile, "%[^,],%[^,],%[^\n]\n", aux_id, aux_dominio, aux_anio);
    do{
        charge=fscanf(pFile, "%[^,],%[^,],%[^\n]\n", aux_id, aux_dominio, aux_anio);
        if(charge!=3){
            printf("Error");
        }else{
            eDominio* pDominio=dominio_new();

            pDominio->id=atoi(aux_id);
            strcpy(pDominio->dominio,aux_dominio);
            pDominio->anio=atoi(aux_anio);

           ll_add(listaDominios, pDominio);
        }
    }while(!feof(pFile));
    fclose(pFile);

    return 1;
}


eDominio* dominio_new(){

eDominio* pDominio=(eDominio*)malloc(sizeof(eDominio));

    pDominio->id=0;
    strcpy(pDominio->dominio," ");
    pDominio->anio=0;
   pDominio->tipo=' ';

return pDominio;
}

void setearTipo(eDominio* dominio){

    char auxString[8];

strcpy(auxString,dominio->dominio);
                    if(auxString[0]>'9'){
                        dominio->tipo='A';
                    }else{
                        dominio->tipo='M';
                        }
}

/** \brief Graba los datos de los empleados en el archivo un archivo .csv (modo texto).
 *
 * \param path char*
 * \param pLinkedListVend LinkedList*
 * \return int
 *
 */
 /*
int saveAsText(FILE* path, LinkedList* pLinkedListVend)
{
    FILE* pArchivo = fopen(path,"w");
    int retorno = -1;

    if(pArchivo != NULL && !parser_SaveToText(pArchivo,pLinkedListVend))
    {
        printf("\n El grabado de datos en formato texto ha sido un exito.\n");
        retorno = 0;
    }
    fclose(pArchivo);
    system("pause");
    return retorno;
}
*/
int parser_SaveToText(LinkedList* listaDominio, char* archivo)
{
    FILE* pFile;
    int retorno = -1;
    eDominio* aux;
    int len= ll_len(listaDominio);
    int i;
    int cantidad;

    pFile=fopen(archivo, "w");
    if(pFile != NULL && listaDominio != NULL)
    {
        fprintf(pFile,"ID,dominio,anio,tipo\n");

        for(i=0;i<len;i++)
        {
            aux = ll_get(listaDominio,i);

            cantidad=fprintf(pFile,"%d,%s,%d,%c\n",aux->id,aux->dominio,aux->anio,aux->tipo);
            retorno = 0;
        }
    }
    return retorno;
}

void printerList (LinkedList* lista){
int i;
int largo=ll_len(lista);
eDominio* dominio;
//printf("\n El largo es: %d",largo);
printf("\n %5s %15s %5s %s ","Id","domino","anio", "tipo");
    for (i=0;i<largo;i++){
        dominio=ll_get(lista, i);
        printf("\n %5d %-15s %5d %c",dominio->id, dominio->dominio,dominio->anio, dominio->tipo);
        if(dominio->tipo=='M'){
            printf("- Es Moto");

        }else{
        printf(" - Es auto");
        }
       // system("pause");
    }
}

void setMoto(eDominio* dominio){

char auxString[8];

strcpy(auxString,dominio->dominio);

    if(auxString[0]<'9'){
        dominio->tipo='M';
                        }
}

int filtraMoto(void* pElement){

   int retorno = 0;


if (((eDominio*)pElement)->tipo=='M')
    {
        retorno = 1;
    }
    return retorno;
}


int filtraCarro(void* pElement){

   int retorno = 0;


if (((eDominio*)pElement)->tipo=='A')
    {
        retorno = 1;
    }
    return retorno;
}



