#include "Func_VarVar.h"

// Devolver el nombre de la variable guardada
void dar_var_asig4 (func_varvar func, strings &str)
{
    strcop(str,func.variable);
}

// Devolver el tipo de funcion guardada (SUM, RES, MUL, DIV)
tipo_funcion dar_funcion_asig4 (func_varvar func)
{
    return func.funcion;
}

// Devolver el valor del parametro 1
void dar_param1_asig4 (func_varvar func, strings &str)
{
    strcop(str,func.param1);
}

// Devolver el valor del parametro 2
void dar_param2_asig4 (func_varvar func, strings &str)
{
    strcop(str,func.param2);
}

// Cargar la Asignaciòn 4
void cargar_func_asig4 (func_varvar &func, strings nom, tipo_funcion tp, strings p1, strings p2)
{
    strcop(func.variable,nom);
    func.funcion = tp;
    strcop(func.param1,p1);
    strcop(func.param2,p2);
}


