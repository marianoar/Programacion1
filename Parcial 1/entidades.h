typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int idAuthor;
    char authorLastName[31];
    char authorName[31];
    int estado; /**< Active (1) or Inactive (0)  */
}Author;

typedef struct{
    int idBook;
    char title[51];
    int authorId;
    int estado;
}Book;

typedef struct{
    int id;
    char apellido[50];
    char nombre[50];
    char sexo;
    char telefono[16];
    char email[31];
    eFecha fechaIngreso;
    int estado;
}Socio;

typedef struct{
    int idPrestamo;
    int idBook;
    int idSocio;
    eFecha fechaPrestamo;
    int estado;
}Prestamo;

void inicializarAuthor(Author autores[],int largo, int valor);
void inicializarBook (Book libros[],int largo, int valor);
void inicializarSocio (Socio socios[],int largo, int valor);
void inicializarPrestamo (Prestamo prestamos[],int largo, int valor);

void setBook(Book libros[], int i,int id, char titulo[], int authorId, int estado);
void setAuthor (Author autores[],int i, int id, char lastName[], char name[],int estado);
void setSocio(Socio socio[], int i, int id, char lastName[],char name[], char sexo, char telefono [], char correo[], int dia, int mes, int anio,  int estado);
void setPrestamo (Prestamo prestamos[], int i,int idP, int  idB, int idS, int dia, int mes, int anio, int estado);

int addSocio (Socio socios[], int CANT,int socioId);
int modifySocio (Socio socios[], int CANT);
int ordenarSocios(Socio socios[],int CANT);
int printSocios (Socio socios[], int CANT);
void ordenarAuthor(Author autores[],int CANT);
void ordenarSociosPorInsercion(Socio socios[], int CANT);
int printAutor (Author autores[], int CANT);
int printBooks (Book libros[], Author autores[], int CANT);
void printPrestamos(Prestamo prestamos[], Book libros[], Author autores[], Socio socios[],  int CANT);
void ordenarBooks (Book libros[],int CANT, int order);
int addPrestamo(Prestamo prestamos[],Socio socios[],Author autores[],Book libros[],int CANT, int idPrestamo);

int killSocio (Socio socios[], int CANT);
void menuPrestamos(Prestamo prestamos[], Book libros[], Author autores [], Socio socios[],int CANT, int prestamosId);
