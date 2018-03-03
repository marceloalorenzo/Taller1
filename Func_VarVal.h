#ifndef FUNC_VARVAL_H_INCLUDED
#define FUNC_VARVAL_H_INCLUDED
#include "Tipo_Funciones.h"
#include "StringDinamico.h"

typedef struct {strings variable;
                tipoFuncion funcion;
                strings param1;
                int param2;
                } funcVarVal;

// Devolver el nombre de la variable guardada
void darVarAsig5 (funcVarVal func, strings &str);

// Devolver el tipo de funcion guardada (SUM, RES, MUL, DIV)
tipoFuncion darFuncionAsig5 (funcVarVal func);

// Devolver el valor del parametro 1
void darParam1Asig5 (funcVarVal func, strings &str);

// Devolver el valor del parametro 2
int darParam2Asig5 (funcVarVal func);

// Cargar la Asignaciòn 5
void cargarFuncAsig5 (funcVarVal &func, strings nom, tipoFuncion tp, strings p1, int p2);

#endif // FUNC_VARVAL_H_INCLUDED
