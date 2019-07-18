
typedef struct
{
    char id_llamada[5];
    char fecha[10];
    int numeroCliente;
    int idProblema;
    char solucionado[3];
}eLlamada;
/*
typedef struct
{
    char problema_1[20] = "No enciende PC";
    char problema_2[20] = "No funciona mouse";
    char problema_3[20] = "No funciona teclado";
    char problema_4[20] = "No hay internet";
    char problema_5[20] = "No funciona telefono";
}eProblem;*/
int parser_FromText(FILE* pFile , LinkedList* listaLlamadas);
void printerList(LinkedList*  listaLlamadas );
int parser_SaveToText(LinkedList* listaLlamadas, char* archivo);
int saveAsText(char* path, LinkedList* listaLlamadas);

eLlamada* llamada_new();

int getProblem1 (void* pElement);

