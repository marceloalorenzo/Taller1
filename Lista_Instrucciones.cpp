#include "Lista_Instrucciones.h"

//Crear lista vacìa
void CrearListaInst (ListaInstrucciones &L)
{
    L = NULL;
}

//Agregar elemento al inicio
void InsFrontListaInst (instruccion i, ListaInstrucciones &L)
{
    ListaInstrucciones aux = new nodoL;
    aux->info = i;
    aux->sig = L;
    L = aux;
}

//Insertar nodo al final de la lista
void InsBackListaInst (instruccion i, ListaInstrucciones &L)
{
if (L == NULL)
    InsFrontListaInst(i,L);
    else
    InsBackListaInst (i, L->sig);
}

//Saber si una lista està vacìa
boolean EsVaciaListaInst (ListaInstrucciones L)
{
    return boolean (L == NULL);
}

//obtener el primer elemento de una lista
instruccion PrimeroListaInst (ListaInstrucciones L)
{
    return (L->info);
}

// Mostrar lista por pantalla
void MostrarListaInstrucciones (ListaInstrucciones L)
{
    if (L != NULL)
    {
        MostrarInstruccion(L->info);
        printf("\n");
        MostrarListaInstrucciones(L->sig);
    }
}
