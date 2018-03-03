#ifndef FUNC_VARVAR_H_INCLUDED
#define FUNC_VARVAR_H_INCLUDED
#include "Tipo_Funciones.h"
#include "StringDinamico.h"

typedef struct {strings variable;
                tipoFuncion funcion;
                strings param1;
                strings param2;
                } funcVarVar;

// Devolver el nombre de la variable guardada
void darVarAsig4 (funcVarVar func, strings &str);

// Devolver el tipo de funcion guardada (SUM, RES, MUL, DIV)
tipoFuncion darFuncionAsig4 (funcVarVar func);

// Devolver el valor del parametro 1
void darParam1Asig4 (funcVarVar func, strings &str);

// Devolver el valor del parametro 2
void darParam2Asig4 (funcVarVar func, strings &str);

// Cargar la Asignaciòn 4
void cargarFuncAsig4 (funcVarVar &func, strings nom, tipoFuncion tp, strings p1, strings p2);

#endif // FUNC_VARVAR_H_INCLUDED
