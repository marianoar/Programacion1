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
    int opcion, p;
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
        ordenarBooks(libros,CANT);
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
    int flagAlta=1;//por que setee socio
    int p;

    system("cls");
   do{
        printf("\n\n\t Menu Socios");
        opcion=getIn("\n\n 1.- Alta \n 2.- Modificar\n 3.- Baja\n 4.- Listar Socios\n 5.- Listar Libros\n 6.- Listar Autores\n 7.- Prestamos\n\n 0.- Volver\n\n Su opcion: ");
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
            if(auxBaja){
                printf("\n Baja exitosa");
            }else {
            printf("\nSe ha producido un error. ");
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
            ordenarBooks(libros,CANT);
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

void menuListarPrestamos(Prestamo prestamos[], int CANT){
int i;
printf("\n\n\tId Prestamo\tCodigo libro \t Codigo Socio\t Fecha Prestamo ");
for (i=0;i<CANT;i++){
    if(prestamos[i].estado){
        printf("\n\t%d\t\t%d\t\t%d\t\t%d-%d-%d",prestamos[i].idPrestamo,prestamos[i].idBook,prestamos[i].idSocio,prestamos[i].fechaPrestamo.dia,prestamos[i].fechaPrestamo.mes,prestamos[i].fechaPrestamo.anio);
    }
}

}

void menuPrestamos(Prestamo prestamos[], Book libros[], Author autores[], Socio socios[], int CANT, int prestamosId){
    int auxPrestamos;
    int opcion;
    system("cls");
    printf("\n\tMenu Prestamos\n");
    printf(" 1.- Alta de prestamo\n");
    printf(" 2.- Listar todos los prestamos\n");
    printf("  3.- \n");
    printf(" 4.- \n");
    printf(" 5.- \n");
    printf(" 6.- \n");
    printf(" 7.- \n");
    printf(" 8.- \n");
    printf(" 9.- \n");
    printf(" 10.- \n");
    printf(" 11.- \n\n");
    printf(" 0.- Volver");
    opcion=getIn("\n\nIngrese opcion: ");
    switch(opcion){
    case 1:
        auxPrestamos=addPrestamo(prestamos, socios, autores, libros, CANT, prestamosId);
        if (auxPrestamos){
            printf("\nSe ha registrado el Prestamo:\n");
            prestamosId++;
            }else {
            printf("\nNo se ha registrado el prestamo.");
        }
    break;
    case 2:
        menuListarPrestamos(prestamos, CANT);
    break;
    case 3:
    break;
    case 4:
    break;
    case 5:
    break;
    case 6:
    break;
    case 7:
    break;
    case 8:
    break;
    case 9:
    break;
    case 10:
    break;
    case 11:
    break;
    case 12:
    break;

    }
return;
}
