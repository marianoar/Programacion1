
int menuInicio (void);
void menuAutor(Author autores[], int CANT);
void menuLibros(Book libros[],Author autores[], int CANT);
void menuSocios(Socio socios[], Book libros[], Author autores[],Prestamo prestamos[], int CANT,int sociosId, int prestamosId);

void ingresoFecha( Socio asociados[], int aux );
void fechaPrestamo( Prestamo prestamos[], int aux );
int menuModificar();

void menuListarPrestamos(Prestamo prestamos[], int CANT);
void menuPrestamos(Prestamo prestamos[], Book libros[], Author autores [], Socio socios[], int CANT, int prestamosId);
