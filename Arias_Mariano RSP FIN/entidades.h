typedef struct
{
    int id_envio;
    char producto[20];
    int km;
    int tipo;
    int costo;
}eEnvio;

int parser_FromText(FILE* pFile , LinkedList* lista);

eEnvio* envio_new();

int entidad_setCampo1(eEnvio* pEnvio, char *aux);
int entidad_setCampo2(eEnvio* pEnvio, char *aux);
int entidad_setCampo3(eEnvio* pEnvio, char *aux);
int entidad_setCampo4(eEnvio* pEnvio, char *aux);
int entidad_setCampo5(eEnvio* pEnvio, char *aux);

int eEntidad_getCampo1(eEnvio* thisIs);
char* eEntidad_getCampo2(eEnvio* thisIs);
int eEntidad_getCampo3(eEnvio* thisIs);
int eEntidad_getCampo4(eEnvio* thisIs);
int eEntidad_getCampo5(eEnvio* thisIs);

int getEnvio1 (void* pElement);
int getEnvio2 (void* pElement);
int getEnvio3 (void* pElement);

int parser_SaveToText(LinkedList* lista, char* archivo);
void printerList (LinkedList* lista);
void printerListSeteada (LinkedList* lista);
void setCosto(void* element);

int ordenar (void* element, void* elementB);


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

