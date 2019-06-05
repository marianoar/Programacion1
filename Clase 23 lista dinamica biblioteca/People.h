typedef struct{
char nombre[20];
int edad;
}Persona;

void persona_initLista(void);
void persona_addPersona(Persona* p);
Persona* persona_newPersona(void);

void preguntarNombre (char auxName[]);
int preguntarEdad();

int persona_setName(Persona* pPersona, char* pName);
int persona_setEdad(Persona* pPersona, int edad);


int persona_getEdad(Persona* pPersona);
char* persona_getNombre(Persona* pPersona);

void persona_toString(Persona* pPersona);
