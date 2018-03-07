#include "ABB_Variables.h"

//crear un árbol
void crearABBvariable(ArbolVariables &a)
{
    a = NULL;
}

//Cargar ABB
void cargarABBvariable (ArbolVariables &a, variable v)
{
    if(a == NULL)
    {
        a = new nodo;
        a->info = v;
        a->hizq = NULL;
        a->hder = NULL;
    }
    else
    {
        strings aux1, aux2;
        strcrear(aux1);
        strcrear(aux2);
        darVariable(aux1,v);
        darVariable(aux2,a->info);
        if(strmen(aux1,aux2) == TRUE)
        {
            cargarABBvariable(a->hizq,v);
        }

        else
        {
            cargarABBvariable(a->hder,v);
        }
        strdestruir(aux1);
        strdestruir(aux2);
    }
}

//saber si esta vácio
boolean ABBvacio (ArbolVariables a)
{
    boolean es=FALSE;
    if(a == NULL)
        es = TRUE;
    return es;
}

//buscar si existe variable en el arbol
boolean existeEnABB (ArbolVariables a, strings var)
{
    boolean es = FALSE;
    if (a != NULL && es != TRUE)
    {
        strings aux;
        strcrear(aux);
        darVariable(aux,a->info);
        if(streq(aux,var) == TRUE)
        {
            es = TRUE;
        }
        else
        {
            if (strmen(var,aux))
            {
                es = existeEnABB(a->hizq, var);
            }
            else
            {
                es = existeEnABB(a->hder, var);
            }
        }
    }
    return es;
}

//Mostrar valor de una variable
void MostrarValorVariable (ArbolVariables a, strings var)
{
    if (a != NULL)
    {
        strings aux;
        strcrear(aux);
        darVariable(aux,a->info);
        if(streq(aux,var) == TRUE)
        {
            MostrarVariable(a->info);
        }
        else
        {
            if (strmen(var,aux))
            {
                MostrarValorVariable(a->hizq, var);
            }
            else
            {
                MostrarValorVariable(a->hder, var);
            }
        }
        strdestruir(aux);
    }
}

//Mostrar arbol por pantalla
void MostrarVariablesTodas(ArbolVariables a)
{
    if (a != NULL)
    {
        MostrarVariablesTodas(a->hizq);
        MostrarVariable(a->info);
        MostrarVariablesTodas(a->hder);
    }
}

void CargarValorVariable (ArbolVariables &a, strings var, int carga)
{
    if (a != NULL)
    {
        strings aux;
        strcrear(aux);
        darVariable(aux,a->info);
        if(streq(aux,var) == TRUE)
        {
            CargarVariable(a->info,var,carga);
        }
        else
        {
            if (strmen(var,aux))
            {
                CargarValorVariable(a->hizq,var,carga);
            }
            else
            {
                CargarValorVariable(a->hder,var,carga);
            }
        }
        strdestruir(aux);
    }
}

int darValorVariable (ArbolVariables variables, strings nombre)
{
    if (variables != NULL)
    {
        strings aux;
        strcrear(aux);
        darVariable(aux,variables->info);
        if(streq(aux,nombre) == TRUE)
        {
           return darValorVar(variables->info);
        }
        else
        {
            if (strmen(nombre,aux))
            {
                darValorVariable(variables->hizq,nombre);
            }
            else
            {
                darValorVariable(variables->hder,nombre);
            }
        }
        strdestruir(aux);
    }
}
