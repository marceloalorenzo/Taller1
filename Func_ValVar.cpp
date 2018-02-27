#include "Func_ValVar.h"

// Devolver el nombre de la variable guardada
void dar_var_asig6 (func_valvar func, strings &str)
{
    strcop(str,func.variable);
}

// Devolver el tipo de funcion guardada (SUM, RES, MUL, DIV)
tipo_funcion dar_funcion_asig6 (func_valvar func)
{
    return func.funcion;
}

// Devolver el valor del parametro 1
int dar_param1_asig6 (func_valvar func)
{
    return func.param1;
}

// Devolver el valor del parametro 2
void dar_param2_asig6 (func_valvar func, strings &str)
{
    strcop(str,func.param2);
}

// Cargar la Asignaciòn 6
void cargar_func_asig6 (func_valvar &func, strings nom, tipo_funcion tp, int p1, strings p2)
{
    strcrear(func.variable);
    strcop(func.variable,nom);
    func.funcion = tp;
    func.param1 = p1;
    strcrear(func.param2);
    strcop(func.param2,p2);
}

