#ifndef FUNC_VARVAL_H_INCLUDED
#define FUNC_VARVAL_H_INCLUDED
#include "Tipo_Funciones.h"
#include "StringDinamico.h"

typedef struct {strings variable;
                tipo_funcion funcion;
                strings param1;
                int param2;
                } func_varval;

// Devolver el nombre de la variable guardada
void dar_var_asig5 (func_varval func, strings &str);

// Devolver el tipo de funcion guardada (SUM, RES, MUL, DIV)
tipo_funcion dar_funcion_asig5 (func_varval func);

// Devolver el valor del parametro 1
void dar_param1_asig5 (func_varval func, strings &str);

// Devolver el valor del parametro 2
int dar_param2_asig5 (func_varval func);

// Cargar la Asignaciòn 5
void cargar_func_asig5 (func_varval &func, strings nom, tipo_funcion tp, strings p1, int p2);

#endif // FUNC_VARVAL_H_INCLUDED
