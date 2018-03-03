#include "Lista_string.h"

//Crear lista vacìa
void CrearListaStrings (ListaStrings &L)
{
    L = NULL;
}

//Agregar elemento al inicio
void InsFrontListaStrings (strings str, ListaStrings &L)
{
    ListaStrings aux = new nodoLis;
    strcop(aux->info,str);
    aux->sig = L;
    L = aux;
}

//Insertar nodo al final de la lista
void InsBackListaStrings (strings str, ListaStrings &L)
{
    if (L == NULL)
        InsFrontListaStrings(str,L);
    else
        InsBackListaStrings(str, L->sig);
}

//Saber si una lista està vacìa
boolean EsVaciaListaStrings (ListaStrings L)
{
    return boolean (L == NULL);
}

//obtener el primer elemento de una lista
void PrimeroListaStrings (ListaStrings L, strings &str)
{
    strcop(str,L->info);
}

// Mostrar lista por pantalla
void MostrarListaStrings (ListaStrings L)
{
    if (L != NULL)
    {
        print(L->info);
        printf("\n");
        MostrarListaStrings(L->sig);
    }
}

//Parseo
void Parseo (strings str,ListaStrings &parseo)
{
    strings aux;
    strcrear(aux);
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            i++;
        }
        else
        {
            fflush(stdin);
            scan_palabra(str,aux,i);
            InsBackListaStrings(aux,parseo);
        }
    }
    strdestruir(aux);
}

int LargoListaStrings (ListaStrings lis)
{
    if (lis == NULL)
        return 0;
    else
        return 1 + LargoListaStrings(lis->sig);
}
