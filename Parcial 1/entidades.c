#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "entidades.h"
#include "funcionesGeneral.h"

/** \brief inicializa estructura a estado 0
 *
 * \param
 * \param
 * \return void
 *
 */

void inicializarAuthor(Author autores[],int largo, int valor){
    int i;
    for (i=0;i<largo;i++){
                autores[i].estado=valor;
    }
}
/** \brief inicializa la estructura a estado 0
 *
 * \param
 * \param
 * \return
 *
 */

void inicializarBook (Book libros[],int largo, int valor){
    int i;
    for (i=0;i<largo;i++){
                libros[i].estado=valor;
    }
}
/** \brief inicializa la estructura a estado 0
 *
 * \param
 * \param
 * \return
 *
 */

void inicializarSocio (Socio socios[],int largo, int valor){
    int i;
    for (i=0;i<largo;i++){
                socios[i].estado=valor;
    }
}
/** \brief inicializa la estructura a estado 0
 *
 * \param
 * \param
 * \return
 *
 */

void inicializarPrestamo (Prestamo prestamos[],int largo, int valor){
    int i;
    for (i=0;i<largo;i++){
                prestamos[i].estado=valor;
    }
}
/** \brief setea valores en estructura
 *
 * \param recibe la estructura y los valores a setear en los campos
 * \param
 * \return
 *
 */

void setBook(Book libros[], int i,int id, char titulo[], int authorId, int estado){
    libros[i].idBook=id;
    strcpy(libros[i].title,titulo);
    libros[i].authorId=authorId;
    libros[i].estado=estado;
}
/** \brief recibe la estructura y los valores a setear en los campos
 *
 * \param
 * \param
 * \return
 *
 */

void setAuthor (Author autores[],int i, int id, char lastName[], char name[],int estado){
    autores[i].idAuthor=id;
    strcpy(autores[i].authorLastName, lastName);
    strcpy(autores[i].authorName, name);
    autores[i].estado=estado;
}
/** \brief recibe la estructura y los valores a setear en los campos
 *
 * \param
 * \param
 * \return
 *
 */

void setSocio(Socio socio[], int i, int id, char lastName[],char name[], char sexo, char telefono [], char correo[], int dia, int mes, int anio,  int estado){
    socio[i].id=id;
    strcpy(socio[i].apellido,lastName);
    strcpy(socio[i].nombre, name);
    socio[i].sexo=sexo;
    strcpy(socio[i].telefono, telefono);
    strcpy(socio[i].email, correo);
    socio[i].fechaIngreso.dia=dia;
    socio[i].fechaIngreso.mes=mes;
    socio[i].fechaIngreso.anio=anio;
    socio[i].estado=estado;
}
/** \brief recibe la estructura y los valores a setear en los campos
 *
 * \param
 * \param
 * \return
 *
 */

void setPrestamo (Prestamo prestamos[], int i,int idP, int  idB, int idS, int dia, int mes, int anio, int estado){
    prestamos[i].idPrestamo=idP;
    prestamos[i].idBook=idB;
    prestamos[i].idSocio=idS;
    prestamos[i].fechaPrestamo.dia=dia;
    prestamos[i].fechaPrestamo.mes=mes;
    prestamos[i].fechaPrestamo.anio=anio;
    prestamos[i].estado=estado;
}
/** \brief Agrega un socio nuevo
 *
 * \param Estructura
 * \param CANT es largo
 * \param recibe el id a asignar q es autoincremental
 * \return 1 para exito
 *
 */

int addSocio (Socio socio[], int CANT, int socioId){
char aux[31];
int i;
    for(i=0;i<CANT;i++){
            if(socio[i].estado==0){

                while(!getStringLetras("\nIngrese Apellido: ",aux)){
                    printf("\nError. Ingrese solo letras");
                }
                if(!checkLenght(aux,31)){
                    printf("\nExcedio el numero de caracteres");
                    break;
                }
                aux[0]=toupper(aux[0]);
                strcpy(socio[i].apellido,aux);

                while(!getStringLetras("\nIngrese Nombre: ",aux)){
                    printf("\nError. Ingrese solo letras");
                }
                 if(!checkLenght(aux,31)){
                    printf("Excedio el numero de caracteres");
                    break;
                }
                aux[0]=toupper(aux[0]);
                strcpy(socio[i].nombre, aux);

                socio[i].sexo=getCharSexo();

               if(!getStringNumeros("\nIngrese Telefono (solo numeros, minimo 6): ",aux)){
                    printf("\nError. Ingrese nuevamente");
                    break;
                }
                if(!checkLenghtTelefono(aux,6)){
                    printf("\nError. Ingrese nuevamente");
                    break;
                }
                strcpy(socio[i].telefono, aux);

                getString("\nIngrese Correo electronico (valido por arroba): ",aux);

                if(!checkLenght(aux,31)){
                    printf("Excedio el numero de caracteres");
                    break;
                }

                if(!checkMail(aux)){
                    printf("\nError. Ingrese nuevamente");
                    break;
                }
                strcpy(socio[i].email,aux);
                ingresoFecha(socio,i);
                socio[i].estado=1;
                socio[i].id=socioId;
                return 1;
            }
    }
    return 0;
}
/** \brief modifica campos estrucutura socios
 *
 * \param Socio
 * \param CANT largo definido
 * \return 1 si funciono o -1
 *
 */

int modifySocio (Socio socios[], int CANT){
char aux[31];
char auxId[5];
int i,idModify;
int opcion;
    if(!getStringNumeros("\n Ingrese Id del Socio a modificar: ",auxId)){
                    printf("Error. Ingrese solo numeros");
                    return -1;
                }
    idModify=atoi(auxId);

    for (i=0;i<CANT;i++){
        if(socios[i].id==idModify){
        printf("\n Se ha encontrado la siguiente persona:\n");
        printf("\n\t%d\t%10s\t%10s\t%c\t%5s\t%5s",socios[i].id,socios[i].apellido,socios[i].nombre,socios[i].sexo, socios[i].telefono,socios[i].email);
        }
         opcion=menuModificar();
         switch(opcion){
             case 1:

                while(!getStringLetras("\nIngrese Apellido: ",aux)){
                    printf("\nError. Ingrese solo letras");
                }
                if(!checkLenght(aux,31)){
                    printf("\nExcedio el numero de caracteres");
                    break;
                }
                aux[0]=toupper(aux[0]);
                strcpy(socios[i].apellido,aux);
            break;
            case 2:
                while(!getStringLetras("\nIngrese Nombre: ",aux)){
                    printf("\nError. Ingrese solo letras");
                }
                 if(!checkLenght(aux,31)){
                    printf("Excedio el numero de caracteres");
                    break;
                }
                aux[0]=toupper(aux[0]);
                strcpy(socios[i].nombre, aux);
            break;
            case 3:
                socios[i].sexo=getCharSexo();
            break;
            case 4:
               if(!getStringNumeros("\nIngrese Telefono (solo numeros, minimo 6): ",aux)){
                    printf("\nError. Ingrese nuevamente");
                    break;
                }
                if(!checkLenghtTelefono(aux,6)){
                    printf("\nError. Ingrese nuevamente");
                    break;
                }
                strcpy(socios[i].telefono, aux);
            break;
            case 5:
                getString("\nIngrese Correo electronico: ",aux);

                if(!checkLenght(aux,31)){
                    printf("Excedio el numero de caracteres");
                    break;
                }

                if(!checkMail(aux)){
                    printf("\nError. Ingrese nuevamente");
                    break;
                }
                strcpy(socios[i].email,aux);
            break;
         }
            return 1;
    }


return 0;
}

/** \brief ordena socios por burbujeo
 *
 * \param socios estrucutra
 * \param CANT define largo
 * \return
 *
 */

int ordenarSocios(Socio socios[],int CANT){
    Socio Aux;
    int i,j;

    for(i=0; i < CANT - 1; i++)
    {
        if(socios[i].estado== 0)
        {
            continue;
        }
        for(j=i+1; j < CANT; j++)
        {
            if(socios[j].estado== 0)
            {
                continue;
            }
            if(strcmp(socios[j].apellido,socios[i].apellido)<0)
            {
                Aux = socios[j];
                socios[j] = socios[i];
                socios[i] = Aux;
            }
            else if(strcmp(socios[j].apellido,socios[i].apellido) == 0)
            {
                if(socios[i].nombre > socios[j].nombre)
                {
                    Aux = socios[j];
                    socios[j] = socios[i];
                    socios[i] = Aux;
                }
            }
        }
    }
return 1;
}
/** \brief ordena por metodo de insercion
 *
 * \param
 * \param
 * \return void
 *
 */

void ordenarSociosPorInsercion(Socio socios[], int CANT){
    int i,j;
    Socio eAux;
    for(i=1;i<CANT;i++){
        eAux= socios[i];
        j=i-1;
        while((strcmp(eAux.apellido,socios[j].apellido)<0) && j>=0){
            socios[j+1] = socios[j];
            j--;
            }
            socios[j+1]=eAux; // insercion    }
}
return;
}
/** \brief recibe variable estrucura y largo e imprime
 *
 * \param
 * \param
 * \return
 *
 */

int printSocios (Socio socios[], int CANT){
    int i;
    system("cls");
        printf("\n\t\t-------  Listado de Socios  -------\n");
        printf("  %-10s %-15s %-15s %s %-10s %-20s %s","Nro Id","Apellido","Nombre","Sexo","Telefono","Correo","Fecha Ingreso");
        printf("\n");
        for (i=0;i<CANT;i++){
            if(socios[i].estado){
                printf("\n  %-10d %-15s %-15s %-5c %-10s %-20s %d-%d-%d",socios[i].id,socios[i].apellido,socios[i].nombre,socios[i].sexo,socios[i].telefono,socios[i].email,socios[i].fechaIngreso.dia,socios[i].fechaIngreso.mes,socios[i].fechaIngreso.anio);
            }
        }
return 1;
}
/** \brief ordeno por burbujeo
 *
 * \param
 * \param
 * \return
 *
 */

void ordenarAuthor(Author autores[],int CANT){
    Author Aux;
    int i,j;
    for(i=0; i < CANT - 1; i++)
    {
        if(autores[i].estado== 0)
        {
            continue;
        }
        for(j=i+1; j < CANT; j++)
        {
            if(autores[j].estado== 0)
            {
                continue;
            }
            if(strcmp(autores[j].authorLastName,autores[i].authorLastName)<0)
            {
                Aux = autores[j];
                autores[j] = autores[i];
                autores[i] = Aux;
            }
            else if(strcmp(autores[j].authorLastName,autores[i].authorLastName) == 0)
            {
                if(autores[i].authorName > autores[j].authorName)
                {
                    Aux = autores[j];
                    autores[j] = autores[i];
                    autores[i] = Aux;
                }
            }
        }
    }
}
/** \brief recibe variable y largo e imprime
 *
 * \param
 * \param
 * \return
 *
 */

int printAutor (Author autores[], int CANT){
    int i;
    system("cls");
        printf("\n\t\t-------  Listado de Autores  -------\n");
        printf("\n\tNro. Id\t\t Apellido\t\tNombre");
        printf("\n");
        for (i=0;i<CANT;i++){
            if(autores[i].estado){
                printf("\n\t%d\t\t%-10s\t\t%s",autores[i].idAuthor,autores[i].authorLastName,autores[i].authorName);
            }
        }
return 1;
}
/** \brief recibe variable y largo e imprime
 *
 * \param
 * \param
 * \return
 *
 */

int printBooks (Book libros[], Author autores[], int CANT){
    int i,j;
    system("cls");
        printf("\n\t\t-------  Listado de Libros  -------\n");
        printf("\n%-10s %-30s %-15s %s\n","Nro. Id","Titulo", "Id Autor","Name Autor");
        for (i=0;i<CANT;i++){
            if(libros[i].estado){
                printf("\n%-10d %-30s %-10d",libros[i].idBook,libros[i].title,libros[i].authorId);
                    for (j=0; j<CANT; j++){
                        if(libros[i].authorId == autores[j].idAuthor){
                            printf("\t%s",autores[j].authorLastName);
                        }
                    }
            }
        }
return 1;
}
/** \brief  REcibe todas las estructuras por que busco por id en las otras estructuras ,a partir de los prestamos, para mostrar
 *
 * \param
 * \param
 * \return
 *
 */

void printPrestamos(Prestamo prestamos[], Book libros[], Author autores[],  Socio socios[], int CANT){
    int i, j, h;
    char auxBook[30];
    char auxSocio[30];
    printf("\n\n\tId Prestamo\tIdBook - Titulo \t\t Socio: Id - Apellido\t Fecha Prestamo ");
    for (i=0;i<CANT;i++){
        if(prestamos[i].estado){
            for(j=0;j<CANT;j++){
                if(prestamos[i].idBook==libros[j].idBook){
                    strcpy(auxBook,libros[j].title);
                }
                if(prestamos[i].idSocio==socios[j].id){
                    strcpy(auxSocio,socios[j].apellido);
                }
            }
        printf("\n\t%-10d\t%d\t%-25s\t%d\t%-15s\t%d-%d-%d",prestamos[i].idPrestamo,prestamos[i].idBook,auxBook,prestamos[i].idSocio,auxSocio,prestamos[i].fechaPrestamo.dia,prestamos[i].fechaPrestamo.mes,prestamos[i].fechaPrestamo.anio);
        }
    }
}
/** \brief Ordeno estructura libros
 *
 * \param
 * \param order 0 para descendente y 1 para ascendente
 * \return void
 *
 */

void ordenarBooks (Book libros[],int CANT, int order){
    Book Aux;
    int i,j;
    int flag;
    if (order==1 && flag!=1){
    for(i=0; i < CANT - 1; i++){
        if(libros[i].estado== 0)
        {
            continue;
        }
        for(j=i+1; j < CANT; j++){
            if(libros[j].estado== 0)
            {
                continue;
            }
            if(strcmp(libros[j].title,libros[i].title)<0)
            {
                Aux = libros[j];
                libros[j] = libros[i];
                libros[i] = Aux;
            }
            else if(strcmp(libros[j].title,libros[i].title) == 0)
            {
                if(libros[i].idBook > libros[j].idBook)
                {
                    Aux = libros[j];
                    libros[j] = libros[i];
                    libros[i] = Aux;
                }
            }
        }
        }
        flag=1;
    }else if(order==0 && flag!=0){
        for(i=0; i < CANT - 1; i++){
        if(libros[i].estado== 0)
        {
            continue;
        }
        for(j=i+1; j < CANT; j++)
        {
            if(libros[j].estado== 0)
            {
                continue;
            }
            if(strcmp(libros[j].title,libros[i].title)>0)
            {
                Aux = libros[j];
                libros[j] = libros[i];
                libros[i] = Aux;
            }
            else if(strcmp(libros[j].title,libros[i].title) == 0)
            {
                if(libros[i].idBook > libros[j].idBook)
                {
                    Aux = libros[j];
                    libros[j] = libros[i];
                    libros[i] = Aux;
                }
            }
        }
        }
        flag=0;
    }
}
/** \brief Agrego la ocurrencia de prestamo
 *
 * \param
 * \param
 * \return 1 si lo hizo , 0 si no lo realizo.
 *
 */

int addPrestamo(Prestamo prestamos[],Socio socios[],Author autores[],Book libros[],int CANT, int idPrestamo){
int i,j, auxId, auxBook;
int flagSocio=0;
int flagBook=0;
char aux[5];
printf("\n\tMenu Alta de Prestamos\n");

 if(!getStringNumeros("\nIngrese Id de socio:",aux)){
            printf("\nError. Ingrese solo numeros");
        }
        auxId=atoi(aux);
        for(i=0;i<CANT;i++){
            if(auxId==socios[i].id && socios[i].estado==1){
            system("cls");
            printf("\n Se ha encontrado la siguiente persona:\n");
            printf("\n\tNro Id \t Apellido\tNombre\t\tSexo\tTelefono\t\tCorreo \t\tIngreso");
            printf("\n\t%d\t%10s\t%10s\t%c\t%5s\t%5s",socios[i].id,socios[i].apellido,socios[i].nombre,socios[i].sexo, socios[i].telefono,socios[i].email);
            printf("\n");
            flagSocio=1;
            }
        }
        if(!flagSocio){
            printf("\nNo se ha encontrado Socio con ese Id");
           return 0;
        }
     if(!getStringNumeros("\nIngrese Id de Libro:",aux)){
            printf("\nError. Ingrese solo numeros");
        }
        auxBook=atoi(aux);
        for(i=0;i<CANT;i++){
            if(auxBook==libros[i].idBook && libros[i].estado==1){


            printf("\nSe ha encontrado el siguiente Libro:\n");
            printf("\n\tNro. Id\t\t Titulo\t\tId Autor - Name Author");
            printf("\n\t%d\t\t%s\t\t%d",libros[i].idBook,libros[i].title,libros[i].authorId);
             for (j=0; j<CANT; j++){
                        if(libros[i].authorId == autores[j].idAuthor){
                            printf("\t%s",autores[j].authorLastName);
                        }}
            printf("\n");
            flagBook=1;
            }
        }
        if(!flagBook){
            printf("\nNo se ha encontrado Socio con ese Id\n");
            return 0;
        }
if (flagSocio && flagBook){
    for (i=0;i<CANT;i++){
        if(prestamos[i].estado==0){
            prestamos[i].idPrestamo=i+1;
            prestamos[i].estado=1;
            prestamos[i].idSocio=auxId;
            prestamos[i].idBook=auxBook;
            fechaPrestamo(prestamos,i);
            idPrestamo++;
            return 1;
        }
    }
}
return 0;
}
/** \brief Elimina socio por baja logica
 *
 * \param estructura socio
 * \param CANT largo define
 * \return return 1 si hizo baja sino -1
 *
 */


int killSocio (Socio socios[], int CANT){
int i, auxBajaInt;
    char auxBaja[5];
    if(!getStringNumeros("\n Ingrese Id del Socio a eliminar: ",auxBaja)){
                    printf("Error. Ingrese solo numeros");
                    return -1;
                }
    auxBajaInt=atoi(auxBaja);
    for (i=0;i<CANT;i++){
        if(socios[i].id==auxBajaInt){
            printf("\n Se ha encontrado la siguiente persona:\n");
            printf("\n\t%d\t%10s\t%10s\t%c\t%5s\t%5s",socios[i].id,socios[i].apellido,socios[i].nombre,socios[i].sexo, socios[i].telefono,socios[i].email);
            socios[i].estado=0;
            return 1;
        }
    }
    printf("\nNo se ha encontrado el socio ingresado.");
return -1;
}

/** \brief Entro a menu prestamo para hacer los informes a partir del swicht
 *
 * \param recibe todas las variables estructuras
 * \param
 * \return FALTa CONVERTIR CADA INFORME EN una funcion
 *
 */
void menuPrestamos(Prestamo prestamos[], Book libros[], Author autores[], Socio socios[], int CANT, int prestamosId){
    int auxPrestamos,i, j,dia, mes, anio, idAuxSearch, opcion;
    int fechas;
    char idSearch[4];
    Prestamo eAux;
    Socio aux;
    Book auxBook;
    int activeLenght=0;
    int contadorFechasRepet=0;

    float promedio;
    int auxCont, flag, mayor, menor;


    opcion=mostrarMenuPrestamos();
    switch(opcion){
    case 1:
        auxPrestamos=addPrestamo(prestamos, socios, autores, libros, CANT, prestamosId);
        if (auxPrestamos){
            printf("\nSe ha registrado el Prestamo.\n");
            prestamosId++;
            }else {
            printf("\nNo se ha registrado el prestamo.");
        }
    break;
    case 2:
        printPrestamos(prestamos, libros, autores, socios, CANT);
    break;
    case 3:
        for(i=0;i<CANT-1;i++){
            if(prestamos[i].estado==1){
                activeLenght++;
            for(j=i+1;j<CANT;j++){
                if(prestamos[i].fechaPrestamo.dia==prestamos[j].fechaPrestamo.dia && prestamos[i].fechaPrestamo.mes==prestamos[j].fechaPrestamo.mes && prestamos[i].fechaPrestamo.anio==prestamos[j].fechaPrestamo.anio){
                 contadorFechasRepet++;
                }
            }
            }
        }
        printf("\nLa cantidad total de prestamos es: %d",activeLenght);
//        printf("\nLa cantidad total de fechas es: %d",contadorFechas);
        fechas=activeLenght-contadorFechasRepet;
        promedio=dividir(activeLenght,fechas);
         printf("\nEl promedio de prestamos por fecha es: %.2f",promedio);
    break;
    case 4:
        printf("\n Informe no realizado.");


    break;
    case 5:// Listar todos los socios que solicitaron el préstamo de un libro determinado.

        getStringNumeros("Ingrese el Id del libro a buscar (rango de 100): ",idSearch);
        idAuxSearch=atoi(idSearch);
        printf("\nEl libro ha sido retirado por los siguientes socios:\n");

        for(i=0;i<CANT;i++){
            if(prestamos[i].idBook==idAuxSearch && prestamos[i].estado==1){
                for(j=0;j<CANT;j++){
                    if(prestamos[i].idSocio==socios[j].id){
                        printf("\n%d %s %s",socios[j].id, socios[j].apellido, socios[j].nombre);
                    }
                }
            }
        }


    break;
    case 6://Listar todos los libros que fueron solicitados a préstamo por un socio determinado.
        getStringNumeros("Ingrese el Id del socio a buscar (rango de 100): ",idSearch);
        idAuxSearch=atoi(idSearch);
        printf("\nEl Socio ha retirado los siguientes libros:\n");

        for(i=0;i<CANT;i++){
            if(prestamos[i].idSocio ==idAuxSearch && prestamos[i].estado==1){
                for(j=0;j<CANT;j++){
                    if(prestamos[i].idBook==libros[j].idBook){
                        printf("\n%d %s",libros[j].idBook , libros[j].title);
                    }
                }
            }
        }

    break;
    case 7: //Listar libro menos prestado
        flag=0;
        auxCont=0;
        menor=0;
        for(i=0;i<CANT;i++){
            auxCont=0;
            for(j=0;j<CANT;j++){
                    if(libros[i].idBook==prestamos[j].idBook){
                        auxCont++;
                    }
                }
                if(flag==0 || auxCont<menor){
                        menor=auxCont;
                        auxBook=libros[i];
                        flag=1;
                        }
                    }
        system("cls");
        printf("\n Libro con menos solicitud de prestamo:\n Id: %d - Titulo : %s - Cantidad de prestamos: %d",auxBook.idBook, auxBook.title,menor);



    break;
    case 8://Listar el o los socios que realizo mas solicitudes a préstamo.

        for(i=0;i<CANT;i++){
            if(prestamos[i].estado==1){
                activeLenght++;
            }
        }
        flag=0;

        system("cls");
        printf("Prestamos activos: %d",activeLenght);

        for(i=0;i<activeLenght;i++){
            auxCont=0;
            for(j=0;j<activeLenght;j++){
                if(socios[i].id==prestamos[j].idSocio){
                  //  printf("\n Socios que realizaron mas de un prestamo: %d ",prestamos[i].idSocio);
                    auxCont++;
                }
            }
            if(auxCont>0){
                if(flag==0 || auxCont>mayor){
                    mayor=auxCont;
                    aux=socios[i];
                    flag=1;
                }
            }
        }
        system("cls");
        printf("\n Socio que retiro mas libros: \n Id: %d - Apellido: %s - Cantidad de prestamos: %d",aux.id,aux.apellido,mayor);

    break;
    case 9: // Listar libros prestados en una fecha especifica
        printf("Ingrese fecha Prestamosa buscar:\n");
        dia = getIntLimitado( "\nIngrese el dia: " , "\nDia fuera de rango, ingrese nuevamente: " , 1 , 31 );
        mes = getIntLimitado( "\nIngrese el mes: " , "\nMes fuera de rango, ingrese nuevamente:  " , 1 , 12 );
        anio = getIntLimitado( "\nIngrese el anio (entre 2000 - 2050): " , "\nAnio fuera de rango, ingrese nuevamente: " , 2000 , 2050);
        printf("\nSe han encontrado los siguientes libros en la fecha solicitada: ");
        for(i=0;i<CANT;i++){
            if(prestamos[i].fechaPrestamo.dia==dia && prestamos[i].fechaPrestamo.mes==mes && prestamos[i].fechaPrestamo.anio==anio){
                printf("\nId Book: %d",prestamos[i].idBook);
                for(j=0;j<CANT;j++){
                    if(prestamos[i].idBook==libros[j].idBook){
                        printf(" Titulo: %s",libros[j].title);
                    }
                }
            }
        }
    break;
    case 10: //Listar todos los socios que realizaron al menos una solicitud a préstamo en una fecha determinada.
        printf("Ingrese fecha Prestamosa buscar:\n");
        dia = getIntLimitado( "\nIngrese el dia: " , "\nDia fuera de rango, ingrese nuevamente: " , 1 , 31 );
        mes = getIntLimitado( "\nIngrese el mes: " , "\nMes fuera de rango, ingrese nuevamente:  " , 1 , 12 );
        anio = getIntLimitado( "\nIngrese el anio (entre 2000 - 2050): " , "\nAnio fuera de rango, ingrese nuevamente: " , 2000 , 2050);
        printf("\nSe han encontrado los siguientes socios en la fecha solicitada: ");
         for(i=0;i<CANT;i++){
            if(prestamos[i].fechaPrestamo.dia==dia && prestamos[i].fechaPrestamo.mes==mes && prestamos[i].fechaPrestamo.anio==anio){
                 printf("\nId Socio: %d",prestamos[i].idSocio);
                for(j=0;j<CANT;j++){
                    if(prestamos[i].idSocio==socios[j].id){
                        printf(" Nombre: %s %s",socios[j].apellido, socios[j].nombre);
                    }
                }
            }
        }
    break;
    case 11:
        ordenarBooks(libros,CANT,0);
        printBooks(libros,autores,CANT);
    break;
    case 12:
        ordenarSociosPorInsercion(socios,CANT);
        printSocios(socios,CANT);
    break;
    }
return;
}
