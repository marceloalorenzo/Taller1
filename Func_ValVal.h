#ifndef FUNC_VALVAL_H_INCLUDED
#define FUNC_VALVAL_H_INCLUDED
#include "Tipo_Funciones.h"
#include "StringDinamico.h"

typedef struct {strings var_asig;
                tipo_funcion funcion;
                int param1;
                int param2;
                } func_valval;

// Devolver el nombre de la variable guardada
void dar_var_asig3 (func_valval func, strings &str);

// Devolver el tipo de funcion guardada (SUM, RES, MUL, DIV)
tipo_funcion dar_funcion_asig3 (func_valval func);

// Devolver el valor del parametro 1
int dar_param1_asig3 (func_valval func);

// Devolver el valor del parametro 2
int dar_param2_asig3 (func_valval func);

// Cargar la Asignaciòn 3
void cargar_func_asig3 (func_valval &func, strings nom, tipo_funcion tp, int p1, int p2);

#endif // FUNC_VALVAL_H_INCLUDED
