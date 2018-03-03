#include "Variables.h"

// Devolver el nombre de la variable guardada
void darVariable (strings &str, variable var)
{
    strcop(str,var.var);
}

// Devolver el valor de la variable guardada
int darValorVar (variable var)
{
    return var.valor;
}

// Cargar la variable
void CargarVariable (variable &var, strings nom, int val)
{
    strcrear(var.var);
    strcop(var.var,nom);
    var.valor = val;
}

//Mostrar en pantalla
void MostrarVariable (variable var)
{
    print(var.var);
    printf (" vale: %d\n",var.valor);
}
