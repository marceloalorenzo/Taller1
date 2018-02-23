
// Devolver el nombre de la variable guardada
void dar_variable (variable var, strings &str)
{
    strcop(str,var.valor);
}

// Devolver el valor de la variable guardada
int dar_valor_var (variable var)
{
    return var.val_asig;
}

// Cargar la variable
void Cargar_variable (variable &var, strings nom, int val)
{
    strcop(var.valor,nom);
    var.valor=val;
}

//Mostrar en pantalla
void Mostrar_variable (variable var)
{
    print(var.var);
    printf (" vale: %d\n",var.valor);
}
