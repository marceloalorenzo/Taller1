#include "Asig_Val.h"

// Devolver el nombre de la variable guardada
void darVarAsig1 (asigVal var, strings &str)
{
    strcop(str, var.varAsig);
}

// Devolver el valor de la variable guardada
int darValAsig1 (asigVal var)
{
    return var.valAsig;
}

// Aargar la asignacion 1
void cargaVarAsig1 (asigVal &var, strings nom, int val)
{
    strcrear(var.varAsig);
    strcop(var.varAsig,nom);
    var.valAsig = val;
}
