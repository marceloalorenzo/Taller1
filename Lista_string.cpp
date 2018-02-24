#include "Lista_string.h"

//Crear lista vacìa
void Crear_Lista_strings (Lista_strings &L)
{
    L = NULL;
}

//Agregar elemento al inicio
void InsFront2 (strings str, Lista_strings &L)
{
    Lista_strings aux = new nodoL;
    strcop(aux->info,str);
    aux->sig = L;
    L = aux;
}

//Insertar nodo al final de la lista
void InsBack2 (strings str, Lista_strings &L)
{
    if (L == NULL)
    InsFront2(str,L);
    else
    InsBack2(str, L->sig);
}

//Saber si una lista està vacìa
boolean Esta_Vacia2 (Lista_strings L)
{
    return boolean (L == NULL);
}

//obtener el primer elemento de una lista
void Primero2 (Lista_strings L, strings &str)
{
    strcop(str,L->info);
}

// Mostrar lista por pantalla
void Mostrar_Lista2 (Lista_strings L)
{
    if (L != NULL)
    {
        print(L->info);
        printf("\n");
        Mostrar_Lista(L->sig);
    }
}

//Parseo
void Parseo (strings str,Lista_strings &parseo)
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
            InsBack2(aux,parseo);
        }
    }
    strdestruir(aux);
}
