#include "Asig_Var.h"

// Devolver el nombre de la variable 1 guardada
void darVar1Asig2 (asigVar var, strings &str)
{
    strcop(str,var.var1);
}

// Devolver el nombre de la variable 2 guardada
void darVar2Asig2 (asigVar var, strings &str)
{
    strcop(str,var.var2);
}

// Cargar la Asignacion 2
void cargaVarAsig2 (asigVar &var, strings nom1, strings nom2)
{
    strcrear(var.var1);
    strcop(var.var1,nom1);
    strcrear(var.var2);
    strcop(var.var2,nom2);
}
