#ifndef ABBSOCIOS_H_INCLUDED
#define ABBSOCIOS_H_INCLUDED
#include "Variables.h"

typedef struct nodo_a   {variable info;
                        nodo_a *hizq;//puntero
                        nodo_a *hder;//puntero
                        } nodo;
typedef nodo *ArbolVariables;

//crear un árbol
void crearABBvariable(ArbolVariables &a);

//Cargar ABB
void cargarABBvariable (ArbolVariables &a, variable v);

//saber si esta vácio
boolean ABBvacio (ArbolVariables a);

//buscar si existe variable en el Arbol
boolean existeEnABB (ArbolVariables a, strings var);

//Mostrar valor de una variable
void MostrarValorVariable (ArbolVariables a, strings var);

//Mostrar arbol por pantalla
void MostrarVariablesTodas(ArbolVariables a);

void CargarValorVariable (ArbolVariables &a, strings var, int carga);

int darValorVariable (ArbolVariables variables, strings nombre);

#endif // ABBSOCIOS_H_INCLUDED
