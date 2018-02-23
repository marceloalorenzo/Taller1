#ifndef LISTA_HABILIDADES_H_INCLUDED
#define LISTA_HABILIDADES_H_INCLUDED
#include "Instrucciones.h"

typedef struct tnodo   {instruccion info;
                        tnodo *sig;
                       }nodoL;
typedef nodoL *Lista;

//Crear lista vacìa
void Crear_Lista (Lista &L);

//Agregar elemento al inicio
void InsFront (instruccion i, Lista &L);

//Insertar nodo al final de la lista
void InsBack (instruccion i, Lista &L);

//Saber si una lista està vacìa
boolean Esta_Vecia (Lista L);

//obtener el primer elemento de una lista
instruccion Primero (Lista L);

#endif // LISTA_HABILIDADES_H_INCLUDED
