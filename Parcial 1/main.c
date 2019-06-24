#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "entidades.h"
#include "funcionesGeneral.h"
#define CANT 100

int main(){

    int opcionInicio;
    Author autores[CANT];
    Book libros[CANT];
    Socio socios[CANT];
    Prestamo prestamos[CANT];
    int autoresId=0;
    int librosId=0;
    int sociosId=105;
    int prestamosId=1;

    inicializarAuthor(autores,CANT,0);
    inicializarBook(libros,CANT,0);
    inicializarSocio(socios,CANT,0);
    inicializarPrestamo(prestamos,CANT,0);

    setBook(libros, 0, 100, "Un mundo feliz", 200,1);
    setBook(libros,1,101,"1984",201,1);
    setBook(libros,2,102,"Los desposeidos",202,1);
    setBook(libros,3,103,"Fahrenheit 451",203,1);
    setBook(libros,4,104,"Homenaje a Catalunya",201,1);
    setBook(libros,5,105,"Lectures on physics",204,1);

    setAuthor(autores, 0, 200, "Huxley","Aldous",1);
    setAuthor(autores,1,201,"Orwell","George",1);
    setAuthor(autores,2,202,"Le Guin","Ursula",1);
    setAuthor(autores,3,203,"Bradbury","Ray",1);
    setAuthor(autores,4,204,"Feynman","Richard",1);

    setSocio(socios, 0, 100,"Arias","Mariano",'M',"1231231230","sarasa@sarasa",10,3,2019,1);
    setSocio(socios, 1, 101,"Lala","Laura",'F',"1234567890","sarasa@.com",11,12,2015,1);
    setSocio(socios, 2, 102,"Prado","Luis",'M',"1515252536","luis.sarasa@algo",01,01,2008,1);
    setSocio(socios, 3, 103,"Garcia","Mariano",'M',"1122334455","mariano@algo",24,02,2018,1);
    setSocio(socios, 4, 104,"Mosto","Emiliano",'M',"1155556699","ryu@utn.com",10,01,2015,1);

    setPrestamo(prestamos,0, 1, 101,101,28,04,2019,1);
    setPrestamo(prestamos,1,2,104,102,29,5,2019,1);
    setPrestamo(prestamos,2,3,100,103,12,4,2010,1);
    setPrestamo(prestamos,3,4,104,100,26,12,2013,1);
    setPrestamo(prestamos,4,5,103,103,1,5,2015,1);
    setPrestamo(prestamos,5,6,102,100,1,5,2015,1);
    setPrestamo(prestamos,6,7,100,104,28,4,2001,1);
    setPrestamo(prestamos,7,8,102,101,25,12,2012,1);
    setPrestamo(prestamos,8,9,102,104,25,12,2012,1);
    setPrestamo(prestamos,9,10,101,103,29,5,2019,1);

    menuSocios(socios, libros, autores, prestamos, CANT, sociosId, prestamosId);


    return 0;
}
