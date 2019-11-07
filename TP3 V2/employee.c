#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/** \brief
 *
 * \param void
 * \param
 * \return puntero a estructura Employee
 *
 */

Employee* employee_new(){

Employee* pEmpleado=(Employee*)malloc(sizeof(Employee));

pEmpleado->id=0;
strcpy(pEmpleado->nombre," ");
pEmpleado->horasTrabajadas=0;
pEmpleado->sueldo=0;

return pEmpleado;
}
/** \brief
 *
 * \param
 * \param
 * \return int 1
 *
 */

int employee_setId(Employee* thisIs,int id){
    thisIs->id=id;
    return 1;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int employee_getId(Employee* thisIs,int* id){
    //int auxId;
  //
  return 1;
}
/** \brief
 *
 * \param
 * \param
 * \return int 1
 *
 */

int employee_setNombre(Employee* thisIs,char* nombre){
    strcpy(thisIs->nombre,nombre);
    return 1;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int employee_getNombre(Employee* thisIs,char* nombre){
    return 1;
}
/** \brief
 *
 * \param
 * \param
 * \return int 1
 *
 */

int employee_setHorasTrabajadas(Employee* thisIs,int horasTrabajadas){
    thisIs->horasTrabajadas=horasTrabajadas;
    return 1;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int employee_getHorasTrabajadas(Employee* thisIs,int* horasTrabajadas){
    return 1;
}
/** \brief
 *
 * \param
 * \param
 * \return int 1
 *
 */

int employee_setSueldo(Employee* thisIs,int sueldo){
    thisIs->sueldo=sueldo;
    return 1;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int employee_getSueldo(Employee* thisIs,int* sueldo){
    return 1;
}

