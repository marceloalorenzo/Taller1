#ifndef FUNC_VARVAR_H_INCLUDED
#define FUNC_VARVAR_H_INCLUDED
#include "Tipo_Funciones.h"
#include "StringDinamico.h"

typedef struct {strings variable;
                tipo_funcion funcion;
                strings param1;
                strings param2;
                } func_varvar;

// Devolver el nombre de la variable guardada
void dar_var_asig4 (func_varvar func, strings &str);

// Devolver el tipo de funcion guardada (SUM, RES, MUL, DIV)
tipo_funcion dar_funcion_asig4 (func_varvar func);

// Devolver el valor del parametro 1
void dar_param1_asig4 (func_varvar func, strings &str);

// Devolver el valor del parametro 2
void dar_param2_asig4 (func_varvar func, strings &str);

// Cargar la Asignaciòn 4
void cargar_func_asig4 (func_varvar &func, strings nom, tipo_funcion tp, strings p1, strings p2);

#endif // FUNC_VARVAR_H_INCLUDED
