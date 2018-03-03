#ifndef FUNC_VALVAL_H_INCLUDED
#define FUNC_VALVAL_H_INCLUDED
#include "Tipo_Funciones.h"
#include "StringDinamico.h"

typedef struct {strings varAsig;
                tipoFuncion funcion;
                int param1;
                int param2;
                } funcValVal;

// Devolver el nombre de la variable guardada
void darVarAsig3 (funcValVal func, strings &str);

// Devolver el tipo de funcion guardada (SUM, RES, MUL, DIV)
tipoFuncion darFuncionAsig3 (funcValVal func);

// Devolver el valor del parametro 1
int darParam1Asig3 (funcValVal func);

// Devolver el valor del parametro 2
int darParam2Asig3 (funcValVal func);

// Cargar la Asignaciòn 3
void cargarFuncAsig3 (funcValVal &func, strings nom, tipoFuncion tp, int p1, int p2);

#endif // FUNC_VALVAL_H_INCLUDED
