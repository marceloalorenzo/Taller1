#ifndef LISTA_STRING_H_INCLUDED
#define LISTA_STRING_H_INCLUDED
#include "StringDinamico.h"

typedef struct tnodoL   {strings info;
                        tnodoL *sig;
                       }nodoLis;
typedef nodoLis *ListaStrings;

//Crear lista vacìa
void CrearListaStrings (ListaStrings &L);

//Destruir lista
void DestruirListaStrings (ListaStrings &L);

//Agregar elemento al inicio
void InsFrontListaStrings (strings str, ListaStrings &L);

//Insertar nodo al final de la lista
void InsBackListaStrings (strings str, ListaStrings &L);

//Saber si una Lista_strings està vacìa
boolean EsVaciaListaStrings (ListaStrings L);

//obtener el primer elemento de una lista
void PrimeroListaStrings (ListaStrings L, strings &str);

// Mostrar lista por pantalla
void MostrarListaStrings (ListaStrings L);

//Parseo
void Parseo (strings str,ListaStrings &parseo);

int LargoListaStrings (ListaStrings lis);

#endif // LISTA_STRING_H_INCLUDED
