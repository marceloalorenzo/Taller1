#include "Lista_string.h"

//Crear lista vac�a
void Crear_Lista (Lista &L)
{
    L = NULL;
}

//Agregar elemento al inicio
void InsFront (strings str, Lista &L)
{
    Lista aux = new nodoL;
    strcop(aux->info,str);
    aux->sig = L;
    L = aux;
}

//Insertar nodo al final de la lista
void InsBack (strings str, Lista &L)
{
    if (L == NULL)
    InsFront(str,L);
    else
    InsBack (str, L->sig);
}

//Saber si una lista est� vac�a
boolean Esta_Vacia (Lista L)
{
    return boolean (L == NULL);
}

//obtener el primer elemento de una lista
void Primero (Lista L, strings &str)
{
    strcop(str,L->info);
}

// Mostrar lista por pantalla
void Mostrar_Lista (Lista L)
{
    if (L != NULL)
    {
        print(L->info);
        printf("\n");
        Mostrar_Lista(L->sig);
    }
}

//Parseo
void Parseo (strings str,Lista &parseo)
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
            InsBack(aux,parseo);
        }
    }
    strdestruir(aux);
}