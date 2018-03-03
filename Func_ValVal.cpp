#include "Func_ValVal.h"

// Devolver el nombre de la variable guardada
void darVarAsig3 (funcValVal func, strings &str)
{
    strcop(str,func.varAsig);
}

// Devolver el tipo de funcion guardada (SUM, RES, MUL, DIV)
tipoFuncion darFuncionAsig3 (funcValVal func)
{
    return func.funcion;
}

// Devolver el valor del parametro 1
int darParam1Asig3 (funcValVal func)
{
    return func.param1;
}

// Devolver el valor del parametro 2
int darParam2Asig3 (funcValVal func)
{
    return func.param2;
}

// Cargar la Asignaciòn 3
void cargarFuncAsig3 (funcValVal &func, strings nom, tipoFuncion tp, int p1, int p2)
{
    strcrear(func.varAsig);
    strcop(func.varAsig,nom);
    func.funcion = tp;
    func.param1 = p1;
    func.param2 = p2;
}
