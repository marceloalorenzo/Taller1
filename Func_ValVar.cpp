#include "Func_ValVar.h"

// Devolver el nombre de la variable guardada
void darVarAsig6 (funcValVar func, strings &str)
{
    strcop(str,func.variable);
}

// Devolver el tipo de funcion guardada (SUM, RES, MUL, DIV)
tipoFuncion darFuncionAsig6 (funcValVar func)
{
    return func.funcion;
}

// Devolver el valor del parametro 1
int darParam1Asig6 (funcValVar func)
{
    return func.param1;
}

// Devolver el valor del parametro 2
void darParam2Asig6 (funcValVar func, strings &str)
{
    strcop(str,func.param2);
}

// Cargar la Asignaciòn 6
void cargarFuncAsig6 (funcValVar &func, strings nom, tipoFuncion tp, int p1, strings p2)
{
    strcrear(func.variable);
    strcop(func.variable,nom);
    func.funcion = tp;
    func.param1 = p1;
    strcrear(func.param2);
    strcop(func.param2,p2);
}

