#include "Func_VarVal.h"

// Devolver el nombre de la variable guardada
void darVarAsig5 (funcVarVal func, strings &str)
{
    strcop(str,func.variable);
}

// Devolver el tipo de funcion guardada (SUM, RES, MUL, DIV)
tipoFuncion darFuncionAsig5 (funcVarVal func)
{
    return func.funcion;
}

// Devolver el valor del parametro 1
void darParam1Asig5 (funcVarVal func, strings &str)
{
    strcop(str,func.param1);
}

// Devolver el valor del parametro 2
int darParam2Asig5 (funcVarVal func)
{
    return func.param2;
}

// Cargar la Asignaciòn 5
void cargarFuncAsig5 (funcVarVal &func, strings nom, tipoFuncion tp, strings p1, int p2)
{
    strcrear(func.variable);
    strcop(func.variable,nom);
    func.funcion = tp;
    strcrear(func.param1);
    strcop(func.param1,p1);
    func.param2 = p2;
}

