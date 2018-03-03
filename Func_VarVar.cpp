#include "Func_VarVar.h"

// Devolver el nombre de la variable guardada
void darVarAsig4 (funcVarVar func, strings &str)
{
    strcop(str,func.variable);
}

// Devolver el tipo de funcion guardada (SUM, RES, MUL, DIV)
tipoFuncion darFuncionAsig4 (funcVarVar func)
{
    return func.funcion;
}

// Devolver el valor del parametro 1
void darParam1Asig4 (funcVarVar func, strings &str)
{
    strcop(str,func.param1);
}

// Devolver el valor del parametro 2
void darParam2Asig4 (funcVarVar func, strings &str)
{
    strcop(str,func.param2);
}

// Cargar la Asignaciòn 4
void cargarFuncAsig4 (funcVarVar &func, strings nom, tipoFuncion tp, strings p1, strings p2)
{
    strcrear(func.variable);
    strcop(func.variable,nom);
    func.funcion = tp;
    strcrear(func.param1);
    strcop(func.param1,p1);
    strcrear(func.param2);
    strcop(func.param2,p2);
}


