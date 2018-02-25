#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED
#include "StringDinamico.h"

typedef struct {strings var;
                int valor;
                } variable;

// Devolver el nombre de la variable guardada
void dar_variable (strings &str, variable var);

// Devolver el valor de la variable guardada
int dar_valor_var (variable var);

// cargar la variable
void Cargar_variable (variable &var, strings nom, int val);

//Mostrar en pantalla
void Mostrar_variable (variable var);

#endif // VARIABLES_H_INCLUDED
