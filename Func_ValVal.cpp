#include "Func_ValVal.h"

// Devolver el nombre de la variable guardada
void dar_var_asig3 (func_valval func, strings &str)
{
    strcop(str,func.var_asig);
}

// Devolver el tipo de funcion guardada (SUM, RES, MUL, DIV)
tipo_funcion dar_funcion_asig3 (func_valval func)
{
    return func.funcion;
}

// Devolver el valor del parametro 1
int dar_param1_asig3 (func_valval func)
{
    return func.param1;
}

// Devolver el valor del parametro 2
int dar_param2_asig3 (func_valval func)
{
    return func.param2;
}

// Cargar la Asignaciòn 3
void cargar_func_asig3 (func_valval &func, strings nom, tipo_funcion tp, int p1, int p2)
{
    strcrear(func.var_asig);
    strcop(func.var_asig,nom);
    func.funcion = tp;
    func.param1 = p1;
    func.param2 = p2;
}
