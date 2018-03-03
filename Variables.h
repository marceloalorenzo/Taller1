#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED
#include "StringDinamico.h"

typedef struct {strings var;
                int valor;
                } variable;

// Devolver el nombre de la variable guardada
void darVariable (strings &str, variable var);

// Devolver el valor de la variable guardada
int darValorVar (variable var);

// cargar la variable
void CargarVariable (variable &var, strings nom, int val);

//Mostrar en pantalla
void MostrarVariable (variable var);

#endif // VARIABLES_H_INCLUDED
