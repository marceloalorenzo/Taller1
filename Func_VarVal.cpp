#include "Func_VarVal.h"

// Devolver el nombre de la variable guardada
void dar_var_asig5 (func_varval func, strings &str)
{
    strcop(str,func.variable);
}

// Devolver el tipo de funcion guardada (SUM, RES, MUL, DIV)
tipo_funcion dar_funcion_asig5 (func_varval func)
{
    return func.funcion;
}

// Devolver el valor del parametro 1
void dar_param1_asig5 (func_varval func, strings &str)
{
    strcop(str,func.param1);
}

// Devolver el valor del parametro 2
int dar_param2_asig5 (func_varval func)
{
    return func.param2;
}

// Cargar la Asignaciòn 5
void cargar_func_asig5 (func_varval &func, strings nom, tipo_funcion tp, strings p1, int p2)
{
    strcrear(func.variable);
    strcop(func.variable,nom);
    func.funcion = tp;
    strcrear(func.param1);
    strcop(func.param1,p1);
    func.param2 = p2;
}

