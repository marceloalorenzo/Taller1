#include "Asig_Val.h"

// Devolver el nombre de la variable guardada
void dar_var_asig1 (asig_val var, strings &str)
{
    strcop(str, var.var_asig);
}

// Devolver el valor de la variable guardada
int dar_val_asig1 (asig_val var)
{
    return var.val_asig;
}

// Aargar la asignacion 1
void carga_var_asig1 (asig_val &var, strings nom, int val)
{
    strcrear(var.var_asig);
    strcop(var.var_asig,nom);
    var.val_asig = val;
}
