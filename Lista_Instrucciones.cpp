#include "Lista_Instrucciones.h"

//Crear lista vacìa
void Crear_Lista (Lista &L)
{
    L = NULL;
}

//Agregar elemento al inicio
void InsFront (instruccion i, Lista &L)
{
    Lista aux = new nodoL;
    aux->info = i;
    aux->sig = L;
    L = aux;
}

//Insertar nodo al final de la lista
void InsBack (instruccion i, Lista &L)
{
if (L == NULL)
    InsFront(i,L);
    else
    InsBack (i, L->sig);
}

//Saber si una lista està vacìa
boolean Esta_Vacia_Lista (Lista L)
{
    return boolean (L == NULL);
}



//obtener el primer elemento de una lista
instruccion Primero (Lista L)
{
    return (L->info);
}
