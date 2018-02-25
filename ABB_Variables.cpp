#include "ABB_Variables.h"

//crear un árbol
void crear(Arbol &a)
{
    a = NULL;
}

//Cargar ABB
void cargar_ABBvariable (Arbol &a, variable v)
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
        dar_variable(aux1,v);
        dar_variable(aux2,a->info);
        if(strmen(aux1,aux2) == TRUE)
        {
            cargar_ABBvariable(a->hizq,v);
        }

        else
        {
            cargar_ABBvariable(a->hder,v);
        }
        strdestruir(aux1);
        strdestruir(aux2);
    }
}

//saber si esta vácio
boolean ABB_vacio (Arbol a)
{
    boolean es=FALSE;
    if(a == NULL)
        es = TRUE;
    return es;
}

//buscar si existe variable en el arbol
boolean existe_ABB (Arbol a, strings var)
{
    boolean es = FALSE;
    if (a != NULL && es != TRUE)
    {
        strings aux;
        strcrear(aux);
        dar_variable(aux,a->info);
        if(streq(aux,var) == TRUE)
        {
            es = TRUE;
        }
        else
        {
            if (strmen(var,aux))
            {
                es = existe_ABB(a->hizq, var);
            }
            else
            {
                es = existe_ABB(a->hder, var);
            }
        }
    }
    return es;
}

//Mostrar valor de una variable
int Mostrar_valor (Arbol a, strings var)
{
    if (a != NULL)
    {
        strings aux;
        strcrear(aux);
        dar_variable(aux,a->info);
        if(streq(aux,var) == TRUE)
        {
            Mostrar_variable(a->info);
        }
        else
        {
            if (strmen(var,aux))
            {
                Mostrar_valor(a->hizq, var);
            }
            else
            {
                Mostrar_valor(a->hder, var);
            }
        }
        strdestruir(aux);
    }
}

//Mostrar arbol por pantalla
void Mostrar_arbol(Arbol a)
{
    if (a != NULL)
    {
        Mostrar_arbol(a->hizq);
        Mostrar_variable(a->info);
        Mostrar_arbol(a->hder);
    }
}
