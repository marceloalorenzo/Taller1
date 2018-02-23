#ifndef FUNC_VALVAR_H_INCLUDED
#define FUNC_VALVAR_H_INCLUDED
#include "Tipo_Funciones.h"
#include "StringDinamico.h"

typedef struct {strings variable;
                tipo_funcion funcion;
                int param1;
                strings param2;
                } func_valvar;

// Devolver el nombre de la variable guardada
void dar_var_asig6 (func_valvar func, strings &str);

// Devolver el tipo de funcion guardada (SUM, RES, MUL, DIV)
tipo_funcion dar_funcion_asig6 (func_valvar func);

// Devolver el valor del parametro 1
int dar_param1_asig6 (func_valvar func);

// Devolver el valor del parametro 2
void dar_param2_asig6 (func_valvar func, strings &str);

// Cargar la Asignaciòn 6
void cargar_func_asig6 (func_valvar &func, strings nom, tipo_funcion tp, int p1, strings p2);

#endif // FUNC_VALVAR_H_INCLUDED
