#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
void employee_delete();

int employee_setId(Employee* thisIs,int id);
int employee_getId(Employee* thisIs,int* id);

int employee_setNombre(Employee* thisIs,char* nombre);
int employee_getNombre(Employee* thisIs,char* nombre);

int employee_setHorasTrabajadas(Employee* thisIs,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* thisIs,int* horasTrabajadas);

int employee_setSueldo(Employee* thisIs,int sueldo);
int employee_getSueldo(Employee* thisIs,int* sueldo);

#endif // employee_H_INCLUDED
