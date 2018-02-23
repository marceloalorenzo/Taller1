
// Devolver el nombre de la variable 1 guardada
void dar_var1_asig2 (asig_var var, strings &str)
{
    strcop(str,var.var1);
}

// Devolver el nombre de la variable 2 guardada
void dar_var2_asig2 (asig_var var, strings &str)
{
    strcop(str,var.var2);
}

// Cargar la Asignacion 2
void carga_var1_asig2 (asig_var &var, strings nom1, strings nom2)
{
    strcop(var.var1,nom1);
    strcop(var.var2,nom2);
}
