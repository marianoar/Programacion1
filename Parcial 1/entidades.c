#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "entidades.h"
#include "funcionesGeneral.h"

void inicializarAuthor(Author autores[],int largo, int valor){
    int i;
    for (i=0;i<largo;i++){
                autores[i].estado=valor;
    }
}
void inicializarBook (Book libros[],int largo, int valor){
    int i;
    for (i=0;i<largo;i++){
                libros[i].estado=valor;
    }
}
void inicializarSocio (Socio socios[],int largo, int valor){
    int i;
    for (i=0;i<largo;i++){
                socios[i].estado=valor;
    }
}
void inicializarPrestamo (Prestamo prestamos[],int largo, int valor){
    int i;
    for (i=0;i<largo;i++){
                prestamos[i].estado=valor;
    }
}

void setBook(Book libros[], int i,int id, char titulo[], int authorId, int estado){
    libros[i].idBook=id;
    strcpy(libros[i].title,titulo);
    libros[i].authorId=authorId;
    libros[i].estado=estado;
}

void setAuthor (Author autores[],int i, int id, char lastName[], char name[],int estado){
    autores[i].idAuthor=id;
    strcpy(autores[i].authorLastName, lastName);
    strcpy(autores[i].authorName, name);
    autores[i].estado=estado;
}
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

void setPrestamo (Prestamo prestamos[], int i,int idP, int  idB, int idS, int dia, int mes, int anio, int estado){
    prestamos[i].idPrestamo=idP;
    prestamos[i].idBook=idB;
    prestamos[i].idSocio=idS;
    prestamos[i].fechaPrestamo.dia=dia;
    prestamos[i].fechaPrestamo.mes=mes;
    prestamos[i].fechaPrestamo.anio=anio;
    prestamos[i].estado=estado;
}

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

                getString("\nIngrese Correo electronico: ",aux);

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

int printAutor (Author autores[], int CANT){
    int i;
    system("cls");
        printf("\n\t\t-------  Listado de Autores  -------\n");
        printf("\n\tNro. Id\t\t Apellido\t\tNombre");
        printf("\n");
        for (i=0;i<CANT;i++){
            if(autores[i].estado){
                printf("\n\t%d\t\t%s\t\t%s",autores[i].idAuthor,autores[i].authorLastName,autores[i].authorName);
            }
        }
return 1;
}
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
void ordenarBooks (Book libros[],int CANT){
    Book Aux;
    int i,j;
    for(i=0; i < CANT - 1; i++)
    {
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
}
int addPrestamo(Prestamo prestamos[],Socio socios[],Author autores[],Book libros[],int CANT, int idPrestamo){
int i, auxId, auxBook;
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
            printf("\n\tNro. Id\t\t Titulo\t\tId Autor");
            printf("\n\t%d\t\t%s\t\t%d",libros[i].idBook,libros[i].title,libros[i].authorId);
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
return -1;
}
