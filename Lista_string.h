#ifndef LISTA_STRING_H_INCLUDED
#define LISTA_STRING_H_INCLUDED
#include "StringDinamico.h"

typedef struct tnodoL   {strings info;
                        tnodoL *sig;
                       }nodoLis;
typedef nodoLis *Lista_strings;

//Crear lista vacìa
void Crear_Lista_strings (Lista_strings &L);

//Agregar elemento al inicio
void InsFront2 (strings str, Lista_strings &L);

//Insertar nodo al final de la lista
void InsBack2 (strings str, Lista_strings &L);

//Saber si una Lista_strings està vacìa
boolean Esta_Vacia2 (Lista_strings L);

//obtener el primer elemento de una lista
void Primero2 (Lista_strings L, strings &str);

// Mostrar lista por pantalla
void Mostrar_Lista2 (Lista_strings L);

//Parseo
void Parseo (strings str,Lista_strings &parseo);

#endif // LISTA_STRING_H_INCLUDED
