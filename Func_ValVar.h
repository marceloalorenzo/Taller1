#ifndef FUNC_VALVAR_H_INCLUDED
#define FUNC_VALVAR_H_INCLUDED
#include "Tipo_Funciones.h"
#include "StringDinamico.h"

typedef struct {strings variable;
                tipoFuncion funcion;
                int param1;
                strings param2;
                } funcValVar;

// Devolver el nombre de la variable guardada
void darVarAsig6 (funcValVar func, strings &str);

// Devolver el tipo de funcion guardada (SUM, RES, MUL, DIV)
tipoFuncion darFuncionAsig6 (funcValVar func);

// Devolver el valor del parametro 1
int darParam1Asig6 (funcValVar func);

// Devolver el valor del parametro 2
void darParam2Asig6 (funcValVar func, strings &str);

// Cargar la Asignaciòn 6
void cargarFuncAsig6 (funcValVar &func, strings nom, tipoFuncion tp, int p1, strings p2);

#endif // FUNC_VALVAR_H_INCLUDED
