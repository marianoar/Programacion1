#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "entidades.h"

/** \brief parsea el archivo pFile que recibe
 *
 * \param pFile
 * \param linkedlist
 * \return
 *
 */

int parser_FromText(FILE* pFile , LinkedList* lista){
    char campo_1[10];
    char campo_2[20];
    char campo_3[10];
    char campo_4[10];
    //char aux_costo[5];
    int charge;
    charge=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", campo_1, campo_2, campo_3, campo_4);
    do{
        charge=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", campo_1, campo_2, campo_3, campo_4);
        if(charge!=4){
            printf("\nError");
        }else{
            eEnvio* pEnvio=envio_new();
            if (pEnvio!=NULL){

                    entidad_setCampo1(pEnvio, campo_1);
                    entidad_setCampo2(pEnvio, campo_2);
                    entidad_setCampo3(pEnvio, campo_3);
                    entidad_setCampo4(pEnvio, campo_4);
            }
            //pEnvio->costo=a
           ll_add(lista, pEnvio);
        }
    }while(!feof(pFile));
    fclose(pFile);

    return 1;
}

int entidad_setCampo1(eEnvio* pEnvio, char *aux){
    int retorno=0;
    if(pEnvio!=NULL && aux!=NULL){
        pEnvio->id_envio=atoi(aux);
        retorno=1;
    }
    return retorno;
}
int entidad_setCampo2(eEnvio* pEnvio, char *aux){
    int retorno=0;
    if(pEnvio!=NULL && aux!=NULL){
        strcpy(pEnvio->producto,aux);
        retorno=1;
    }
    return retorno;
}
int entidad_setCampo3(eEnvio* pEnvio, char *aux){
    int retorno=0;
    if(pEnvio!=NULL && aux!=NULL){
        pEnvio->km=atoi(aux);
        retorno=1;
    }
    return retorno;
}
int entidad_setCampo4(eEnvio* pEnvio, char *aux){
    int retorno=0;
    if(pEnvio!=NULL && aux!=NULL){
        pEnvio->tipo=atoi(aux);
        retorno=1;
    }
   return retorno;
}
int entidad_setCampo5(eEnvio* pEnvio, char *aux){
    int retorno=0;
    if(pEnvio!=NULL && aux!=NULL){
        pEnvio->tipo=atoi(aux);
        retorno=1;
    }
    return retorno;
}


/** \brief Reservo memoria mediante funcion malloc y casteo a estructura
 *          y seteo todos los campos en Cero o vacios usando get und set
 * \param
 * \param
 * \return devuelvo puntero a estructura
 *
 */

eEnvio* envio_new(){

eEnvio* pEnvio=(eEnvio*)malloc(sizeof(eEnvio));

    char* aux=0;

    entidad_setCampo1(pEnvio,aux);
    strcpy(eEntidad_getCampo2(pEnvio)," ");
    entidad_setCampo3(pEnvio,aux);
    entidad_setCampo4(pEnvio,aux);
    entidad_setCampo5(pEnvio,aux);

return pEnvio;
}

/** \brief tomo el valor del campo solicitado y lo asigno a la variable valor la cual retorno
 *
 * \param eEnvio entidad estructura
 * \param
 * \return retorna valor -1 si no asigno, o el valor asignado del campo correspondiente
 *
 */

int eEntidad_getCampo1(eEnvio* thisIs){
    int valor=-1;
    if (thisIs!=NULL){
        valor=thisIs->id_envio;
    }
    return valor;
}

char* eEntidad_getCampo2(eEnvio* thisIs){
    char* valor;
    if(thisIs!=NULL)
    {
       valor=thisIs->producto;
    }
    return valor;
}

int eEntidad_getCampo3(eEnvio* thisIs){
    int valor=-1;
    if (thisIs!=NULL){
        valor=thisIs->km;

    }
    return valor;
}

int eEntidad_getCampo4(eEnvio* thisIs){
    int valor=-1;
    if (thisIs!=NULL){
        valor=thisIs->tipo;

    }
    return valor;
}

int eEntidad_getCampo5(eEnvio* thisIs){
    int valor=-1;
    if (thisIs!=NULL){
        valor=thisIs->costo;
    }
    return valor;
}

int getEnvio1 (void* pElement){
    int retorno=0;

    if(((eEnvio*)pElement)->tipo==1){
        retorno=1;
    }
return retorno;
}
int getEnvio2 (void* pElement){
    int retorno=0;

    if(((eEnvio*)pElement)->tipo==2){
        retorno=1;
    }
return retorno;
}
int getEnvio3 (void* pElement){
    int retorno=0;

    if(((eEnvio*)pElement)->tipo==3){
        retorno=1;
    }
return retorno;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int parser_SaveToText(LinkedList* lista, char* archivo)
{
    FILE* pFile;
    int retorno = 0;
    eEnvio* aux;
    int len= ll_len(lista);
    int i;
    //int qw;

    pFile=fopen(archivo, "w");
    if(pFile != NULL && lista!= NULL)
    {
        fprintf(pFile,"ID ,Producto,Km, Tipo, Costo\n");

        for(i=0;i<len;i++)
        {
            aux = ll_get(lista,i);

            fprintf(pFile,"%d,%s,%d,%d,%d\n",eEntidad_getCampo1(aux), eEntidad_getCampo2(aux), eEntidad_getCampo3(aux), eEntidad_getCampo4(aux), eEntidad_getCampo5(aux));

        }
        retorno = 1;
    }
    return retorno;
}
/** \brief Imprimo lista por pantalla
 *
 * \param LinkedList recibe lista ll
 * \param
 * \return
 *
 */

void printerList (LinkedList* lista){
int i;
int largo=ll_len(lista);
eEnvio* envio;
//printf("\n El largo es: %d",largo);
printf("\n %5s %10s %20s %10s","Id","Producto","Km", "Entrega");
    for (i=0;i<largo;i++){
        envio=ll_get(lista, i);
        printf("\n %5d %-25s %5d",eEntidad_getCampo1(envio),eEntidad_getCampo2(envio),eEntidad_getCampo3(envio));
        if(envio->tipo==1){
            printf(" - Normal");
        }else if(envio->tipo==2){
        printf(" - Express");
        }else if(envio->tipo==3){
            printf(" - Segun Disponibilidad");
        }
        printf(" - Costo: %-25d", eEntidad_getCampo5(envio));
    }
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
 void printerListSeteada (LinkedList* lista){
    int i;
    int largo=ll_len(lista);
    eEnvio* envio;

    printf("\n %10s %20s %5s %s","Id","Producto","Km", "Entrega");
    for (i=0;i<largo;i++){
        envio=ll_get(lista, i);
         printf("\n %5d %-25s %5d %5d",eEntidad_getCampo1(envio),eEntidad_getCampo2(envio),eEntidad_getCampo3(envio),eEntidad_getCampo4(envio));
        if(envio->tipo==1){
            printf(" - Normal");
        }else if(envio->tipo==2){
        printf(" - Express");
        }else if(envio->tipo==3){
            printf(" - Segun Disponibilidad");
        }
        printf(" - Costo: %d", eEntidad_getCampo5(envio));
    }
}
/** \brief Seteo el costo valor en funcion del campo tipo
 *
 * \param casteo el puntero a element a mi entidad Struct
 * \param
 * \return void
 *
 */

void setCosto(void* element){

    int aux=((eEnvio*)element)->km;
    int costoFijo=((eEnvio*)element)->tipo;
    if(aux<=50){
        ((eEnvio*)element)->costo=aux*67;
    }else{
        ((eEnvio*)element)->costo=aux*80;
    }
    if(costoFijo==1){
        ((eEnvio*)element)->costo=((eEnvio*)element)->costo+330;
    }else if(costoFijo==2){
        ((eEnvio*)element)->costo=((eEnvio*)element)->costo+560;
    }else if(costoFijo==3){
        ((eEnvio*)element)->costo=((eEnvio*)element)->costo+80;
    }
}
/*
int ordenar (void* element, void* elementB){

int aux=((eEnvio*)element;
int aux2=((eEnvio*)elementB;


    return 1;

}*/
