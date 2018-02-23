#ifndef ABBSOCIOS_H_INCLUDED
#define ABBSOCIOS_H_INCLUDED
#include "Variables.h"

typedef struct nodo_a   {variable info;
                        nodo_a *hizq;//puntero
                        nodo_a *hder;//puntero
                        } nodo;
typedef nodo *Arbol;

//crear un árbol
void crear(Arbol &a);

//Cargar ABB
void cargar_variable (Arbol &a, variable v);

//saber si esta vácio
boolean esvacio (Arbol a);

//buscar si existe variable en el arbol
boolean buscar (Arbol a, strings var);

//Mostrar valor de una variable
int Mostrar_valor (Arbol a, strings var);

#endif // ABBSOCIOS_H_INCLUDED
