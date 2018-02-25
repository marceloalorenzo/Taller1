#include "Variables.h"

// Devolver el nombre de la variable guardada
void dar_variable (strings &str, variable var)
{
    strcop(str,var.var);
}

// Devolver el valor de la variable guardada
int dar_valor_var (variable var)
{
    return var.valor;
}

// Cargar la variable
void Cargar_variable (variable &var, strings nom, int val)
{
    strcop(var.var,nom);
    var.valor = val;
}

//Mostrar en pantalla
void Mostrar_variable (variable var)
{
    print(var.var);
    printf (" vale: %d\n",var.valor);
}
