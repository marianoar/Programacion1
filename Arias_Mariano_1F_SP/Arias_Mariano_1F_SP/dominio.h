typedef struct
{
    int id;
    char dominio[10];
    int anio;
    char tipo;
}eDominio;

int parser_FromText(FILE* pFile , LinkedList* listaDominios);

eDominio* dominio_new();

void setearTipo(eDominio* dominio);
//int saveAsText(FILE* path, LinkedList* listaAuto);

int parser_SaveToText(LinkedList* listaDominio, char* archivo);

void printerList (LinkedList* lista);
int filtraMoto(void* pElement);
int filtraCarro(void* pElement);
void setMoto(eDominio* dominio);
/*
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


*/
