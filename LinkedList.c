#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

//NO VALIDAR pELEMENT
static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
        returnAux=this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;

    if(this!=NULL){
        if(nodeIndex>=0 && nodeIndex<ll_len(this)){
            pNode=this->pFirstNode;

            while(nodeIndex>0){
                pNode=pNode->pNextNode;
                nodeIndex--;
            }
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement) //no validar p Element
{
    int returnAux = -1;
    if(this!=NULL){

        Node* nodoNew=(Node*)malloc(sizeof(Node*));
        Node* nodoAnt=(Node*)malloc(sizeof(Node*));
        Node* nodoSig=(Node*)malloc(sizeof(Node*));

        if(nodeIndex==0){
            if(ll_len(this)==0){
                nodoNew->pElement=pElement;
                nodoNew->pNextNode=NULL;
                }else{
                nodoSig=this->pFirstNode;
                nodoNew->pElement=pElement;
                nodoNew->pNextNode=nodoSig;
                }
                this->pFirstNode=nodoNew;
            }else{
                nodoAnt=getNode(this,nodeIndex-1);

                if(nodeIndex == ll_len(this)){
                    nodoNew->pElement = pElement;
                    nodoNew->pNextNode = NULL;
                    nodoAnt->pNextNode = nodoNew;
                }else{
                    nodoSig= getNode(this, nodeIndex + 1);
                    nodoNew->pElement = pElement;
                    nodoNew->pNextNode = nodoSig;
                    nodoAnt->pNextNode = nodoNew;
                }
            }

        this->size++;

        returnAux=0;
       }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* thisIs, void* pElement)
{
    int returnAux = -1;
    if(thisIs!=NULL){
        addNode(thisIs,ll_len(thisIs),pElement);
        return 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* thisIs, int index)
{
    void* returnAux = NULL;
    Node* nodo=(Node*)malloc(sizeof(Node*));

    if(thisIs!=NULL){
        if(index>=0 && index<ll_len(thisIs)){
    nodo=getNode(thisIs,index);
    returnAux=nodo->pElement;
    }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* thisIs, int index,void* pElement)//no validar p Element
{
    int returnAux = -1;
Node* nodo=(Node*)malloc(sizeof(Node*));
    if(thisIs!=NULL){
        if(index>=0 && index<ll_len(thisIs)){
nodo=getNode(thisIs,index);
nodo->pElement=pElement;
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* thisIs,int index)
{
    int returnAux = -1;
/*
    Node* nodo=(Node*)malloc(sizeof(Node*));
    Node* aux=(Node*)malloc(sizeof(Node*));

    if(thisIs!=NULL){
        if(index>0 && index<=ll_len(thisIs)){


                thisIs->size--;



        }

            //nodo=getNode(thisIs,index);
      //  nodo->pElement==NULL;


            returnAux=0;
    }
*/
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* thisIs)
{
    int returnAux = -1;
 if(thisIs!=NULL){


// NECESITO LL_REMOVE  para pasarlo x un for
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* thisIs)
{
    int returnAux = -1;
 if(thisIs!=NULL){
    free(thisIs);
    returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* thisIs, void* pElement)
{
    int returnAux = -1;
    Node* nodo;
    int i;
    if(thisIs!=NULL){
    for(i=0;i<ll_len(thisIs);i++){
        nodo=getNode(thisIs,i);
        if(nodo->pElement==pElement){
            returnAux=i;
            return returnAux;
        }
    }

    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* thisIs)
{
    int returnAux = -1;
    if(thisIs==NULL){
        return returnAux;
    }

    if(ll_len(thisIs)==0){
        returnAux=1;
    }else{
    returnAux=0;
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* thisis, int index, void* pElement)
{
    int returnAux = -1;

if(thisis!=NULL){
    if(index>=0&& index<=ll_len(thisis)){
        addNode(thisis, index,pElement);
        returnAux=0;
}}
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* thisis,int index)
{
    void* returnAux = NULL;
    if(thisis!=NULL){
        if(index>0 && index<ll_len(thisis)){

        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* thisis, void* pElement)
{
    int returnAux = -1;
    int i;
Node* nodo=(Node*)malloc(sizeof(Node*));

if(thisis!=NULL){
    for(i=0;i<ll_len(thisis);i++){
        nodo=getNode(thisis, i);
        if(nodo->pElement=pElement){
            returnAux=1;
            return returnAux;
        }
    }
    returnAux=0;
}
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this1,LinkedList* this2)
{
    int returnAux = -1;
    if(this1!=NULL && this2!=NULL){


    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* thisis, int (*pFunc)(void* ,void*), int order){
    int returnAux =-1;
    int i, j;
    int r;

   Node* nodoA=(Node*)malloc(sizeof(Node*));
   Node* nodoB=(Node*)malloc(sizeof(Node*));
    Node* aux=(Node*)malloc(sizeof(Node*));

    if(thisis!=NULL){
        if(order==1 || order==0){
            for(i=0;i<ll_len(thisis)-1;i++){
                for(j=i+1;j<ll_len(thisis);j++){
                    nodoA=getNode(thisis,i);
                    nodoB=getNode(thisis,j);
                    if(pFunc(nodoA->pElement,nodoB->pElement)){



               }
            }

          }

        }
    }
return returnAux;
}

