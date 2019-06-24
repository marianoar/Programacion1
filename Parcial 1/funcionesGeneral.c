#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "entidades.h"
#include "funcionesGeneral.h"

int menuInicio (void){
int opcion;
printf("\n\tMenu Inicio\n");
printf("\n 1.- Autores\n 2.- Libros\n 3.- Socios\n 0.- Salir");
opcion=getIn("\n\nIngrese opcion: ");
return opcion;
}

void menuAutor(Author autores[], int CANT){
    int opcion,p;
    system("cls");
do{
    printf("\n\n\tMenu Autores\n");
    printf("\n 1.- Alta\n 2.- Baja\n 3.- Modificar \n 4.- Listar\n 0.- Volver");
    opcion=getIn("\n\nIngrese opcion: ");
switch (opcion){
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        ordenarAuthor(autores,CANT);
        p=printAutor(autores,CANT);
        break;
    case 0:
        return;
    }
}while(opcion!=0);

return;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void menuLibros(Book libros[], Author autores[], int CANT){
    int aux,p;
    system("cls");

do{
            printf("\n\n\tMenu Libros");
printf("\n\n 1.- Alta\n 2.- Baja\n 3.- Modificar \n 4.- Listar\n 0.- Volver");
    aux=getIn("\n\nIngrese opcion: ");
switch (aux){
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        ordenarBooks(libros,CANT,1);
        p=printBooks(libros, autores, CANT);
        break;
    case 0:
        return;
    }
}while(aux!=0);
return;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void menuSocios(Socio socios[], Book libros[], Author autores[], Prestamo prestamos[],int CANT, int sociosId, int prestamosId){
    int opcion, auxAlta, auxModify, auxBaja, auxPrestamos;
    int flagAlta=1;//La dejo en uno por que ya setee socios
    int p;

    system("cls");
   do{
        printf("\n\n\t Menu Socios");
        opcion=getIn("\n\n 1.- Alta \n 2.- Modificar\n 3.- Baja\n 4.- Listar Socios (por burbujeo ascendente)\n 5.- Listar Libros (ascendente)\n 6.- Listar Autores\n 7.- Prestamos e Informes\n\n 0.- Volver\n\n Su opcion: ");
        switch(opcion){
        case 1:
            auxAlta=addSocio(socios, CANT, sociosId);
            if (!auxAlta){
                printf("\nHay un error. Realizar alta nuevamente.");
            }else{
                system("cls");
                printf("Ha realizado Alta de Asociado exitosa.\n\n");
                sociosId++;
                flagAlta=1;
            }
        break;
        case 2:
            if(!flagAlta){
                printf("\n No hay socios activos aun");
                break;
            }

            auxModify=modifySocio(socios, CANT);
            if(auxModify){
                printf("\n Modificacion exitosa");
            }else {
            printf("\nSe ha producido un error. ");
            }
        break;
        case 3:
            if(!flagAlta){
                printf("\n No hay socios activos aun");
                break;
            }
            auxBaja=killSocio(socios, CANT);
            if(auxBaja==1){
                printf("\n Baja exitosa");
            }else {
            printf("\nSe ha producido un error. Baja no realizada ");
            }
        break;
        case 4:

            p=ordenarSocios(socios,CANT);
            if(p!=1){
                printf("algo fallo");
            }
            p=printSocios(socios,CANT);
        break;
        case 5:
            ordenarBooks(libros,CANT,1);
            p=printBooks(libros, autores, CANT);
        break;
        case 6:
            ordenarAuthor(autores,CANT);
            p=printAutor(autores,CANT);
        break;
        case 7:
            menuPrestamos(prestamos, libros, autores, socios, CANT, prestamosId);

        break;

        }


   }while (opcion!=0);
    return;
}

void ingresoFecha( Socio asociados[], int aux )
{
    printf("Ingrese fecha de alta:\n");
    asociados[aux].fechaIngreso.dia = getIntLimitado( "\nIngrese el dia: " , "\nDia fuera de rango, ingrese nuevamente: " , 1 , 31 );
    asociados[aux].fechaIngreso.mes = getIntLimitado( "\nIngrese el mes: " , "\nMes fuera de rango, ingrese nuevamente:  " , 1 , 12 );
    asociados[aux].fechaIngreso.anio = getIntLimitado( "\nIngrese el anio (entre 1990 - 2020): " , "\nAnio fuera de rango, ingrese nuevamente: " , 1990 , 2020);
}
void fechaPrestamo( Prestamo prestamos[], int aux ){
printf("Ingrese fecha Prestamos:\n");
    prestamos[aux].fechaPrestamo.dia = getIntLimitado( "\nIngrese el dia: " , "\nDia fuera de rango, ingrese nuevamente: " , 1 , 31 );
    prestamos[aux].fechaPrestamo.mes = getIntLimitado( "\nIngrese el mes: " , "\nMes fuera de rango, ingrese nuevamente:  " , 1 , 12 );
    prestamos[aux].fechaPrestamo.anio = getIntLimitado( "\nIngrese el anio (entre 2000 - 2050): " , "\nAnio fuera de rango, ingrese nuevamente: " , 2000 , 2050);
}

int menuModificar(){
int a;
a=getIn("\n Que dato desea modificar?\n\t\tIngrese:\n\t1.- Apellido\n\t2.- Nombre\n\t3.- Sexo\n\t4.- Telefono\n\t5.- Correo\n\n\t0.- Volver\n Elija opcion a modificar: ");
return a;
}


int mostrarMenuPrestamos(){
    int opcion;
    system("cls");
    printf("\n\n\tMenu Prestamos\n");
    printf("\n  1.- Alta de prestamo\n");
    printf("  2.- Listar todos los prestamos\n");
    printf("  3.- informar el total general  y promedio diario de las solicitudes a prestamo de los libros. \n");
    printf("  4.- Informar la cantidad de dias cuya solicitud a prestamo no superan  el promedio del dia anterior.\n");
    printf("  5.- Listar todos los socios que solicitaron el prestamo de un libro determinado.\n");
    printf("  6.- Listar todos los libros que fueron solicitados a prestamo por un socio determinado.\n");
    printf("  7.- Listar el o los libros menos solicitados en prestamo.\n");
    printf("  8.- Listar el o los socios que realizo mas solicitudes a prestamo.\n");
    printf("  9.- Listar todos los libros solicitadosa prestamo en una fecha determinada\n");
    printf(" 10.- Listar todos los socios que realizaron al menos una solicitud a prestamo en una fecha determinada. \n");
    printf(" 11.- Listar todos los libros ordenados por titulo (descendente), utilizando el metodo de burbujeo mas eficiente.\n");
    printf(" 12.- Listar todos los socios ordenados por Apellido (ascendente ) utilizando el metodo de insercion.\n\n");
    printf(" 0.- Volver");
    opcion=getIn("\n\nIngrese opcion: ");
    return opcion;
}
