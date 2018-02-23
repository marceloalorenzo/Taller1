#ifndef LISTA_STRING_H_INCLUDED
#define LISTA_STRING_H_INCLUDED
#include "StringDinamico.h"

typedef struct tnodo   {strings info;
                        tnodo *sig;
                       }nodoL;
typedef nodoL *Lista;

//Crear lista vacìa
void Crear_Lista (Lista &L);

//Agregar elemento al inicio
void InsFront (strings str, Lista &L);

//Insertar nodo al final de la lista
void InsBack (strings str, Lista &L);

//Saber si una lista està vacìa
boolean Esta_Vecia (Lista L);

//obtener el primer elemento de una lista
void Primero (Lista L, strings &str);

#endif // LISTA_STRING_H_INCLUDED
