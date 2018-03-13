#include "Ejecutar.h"


void Ejecutar (strings str)
{
    ListaStrings listaEjecucion;

    strings auxVars;
    strcrear(auxVars);
    strcop(auxVars,str);
    strcon(auxVars,VARS);

    strings auxInst;
    strcrear (auxInst);
    strcop (auxInst,str);
    strcon (auxInst,INST);


    if (ExisteArchivo(auxVars) && ExisteArchivo(auxInst)) //veo si existen los dos archivos con las extensiones solicitadas
    {
     ArbolVariables variables;
     ListaInstrucciones instrucciones;
     crearABBvariable(variables);
     CrearListaInst(instrucciones);

     LevantarAbb(variables,auxVars);
     LevantarLista(instrucciones,auxInst);

     boolean errorEjecucion = FALSE;

        while ( instrucciones != NULL && errorEjecucion != TRUE) //mientras la liesta no sea nula ingreso al nodo
        {
            tipoInstruccion tipoFunc = darTipoInst(instrucciones->info);
            switch (tipoFunc)
            {
            case LEER:
                            {
                                strings ingreso;
                                strcrear(ingreso);

                                printf("\nIngrese valor para ");
                                print(instrucciones->info.datoDisc.variable1);
                                printf(": ");
                                fflush(stdin);
                                scan(ingreso);
                                boolean entero = esStringNumerico(ingreso);

                                while (entero != TRUE)
                                {
                                    printf("\n\nEl valor ingresado no es un entero.\n***Favor ingresar un valor entero para ");
                                    print(instrucciones->info.datoDisc.variable1);
                                    printf(": ");
                                    fflush(stdin);
                                    scan(ingreso);
                                    entero = esStringNumerico(ingreso);
                                }

                                int lectura = ConvertirStringEntero(ingreso);
                                CargarValorVariable(variables,instrucciones->info.datoDisc.variable1,lectura);//
                            }
                break;
            case MOSTRAR:
                            {
                                MostrarValorVariable(variables,instrucciones->info.datoDisc.variable2);
                            }
                break;
            case ASIGVAL:
                            {
                                CargarValorVariable(variables,instrucciones->info.datoDisc.asig1.varAsig,instrucciones->info.datoDisc.asig1.valAsig);
                            }
                break;
            case ASIGVAR:
                            {
                                int valor = darValorVariable(variables,instrucciones->info.datoDisc.asig2.var2);
                                CargarValorVariable(variables, instrucciones->info.datoDisc.asig2.var1,valor);
                            }
                break;
            case FUNCVALVAL:
                            {
                                int resultado = EjecutarFuncValVal(instrucciones->info);
                                CargarValorVariable(variables,instrucciones->info.datoDisc.asig3.varAsig,resultado);
                            }
                break;
            case FUNCVARVAR:
                            {
                                int resultado;
                                EjecutarFuncVarVar(instrucciones->info,variables,errorEjecucion,resultado);
                                if (errorEjecucion != TRUE)
                                {
                                    CargarValorVariable(variables,instrucciones->info.datoDisc.asig4.variable,resultado);
                                }
                            }
                break;
            case FUNCVARVAL:
                            {
                                int resultado = EjecutarFuncVarVal(instrucciones->info,variables);
                                CargarValorVariable(variables,instrucciones->info.datoDisc.asig5.variable,resultado);
                            }
                break;
            case FUNCVALVAR:
                            {
                                int resultado;
                                EjecutarFuncValVar(instrucciones->info,variables,errorEjecucion,resultado);
                                if (errorEjecucion != TRUE)
                                {
                                    CargarValorVariable(variables,instrucciones->info.datoDisc.asig6.variable,resultado);
                                }
                            }
                break;
            }
            instrucciones = instrucciones->sig;
        }
        if (errorEjecucion == FALSE)
            system("pause");
    }
    else
    {
        printf("\n\nError de ejecucion: El programa no fue compilado correctamente.\nNo existen alguno o ambos de los archivos .inst o .vars)\n\n");
        system("pause");
    }
}


/* ********************** Auxiliares para ejecutar las funciones ********************************** */

int EjecutarFuncValVal (instruccion ins)
{
    switch (ins.datoDisc.asig3.funcion)
    {
        case SUM:
                    {
                        int param1 = darParam1Asig3(ins.datoDisc.asig3);
                        int param2 = darParam2Asig3(ins.datoDisc.asig3);
                        return (param1 + param2);
                    }
            break;
        case RES:
                    {
                        int param1 = darParam1Asig3(ins.datoDisc.asig3);
                        int param2 = darParam2Asig3(ins.datoDisc.asig3);
                        return (param1 - param2);
                    }
            break;
        case MUL:
                    {
                        int param1 = darParam1Asig3(ins.datoDisc.asig3);
                        int param2 = darParam2Asig3(ins.datoDisc.asig3);
                        return (param1 * param2);
                    }
            break;
        case DIV:
                    {
                        int param1 = darParam1Asig3(ins.datoDisc.asig3);
                        int param2 = darParam2Asig3(ins.datoDisc.asig3);
                        return (param1 / param2);
                    }
            break;
    }
}

void EjecutarFuncVarVar (instruccion ins, ArbolVariables variables, boolean &errorEjecucion, int &resultado)
{
    switch (ins.datoDisc.asig4.funcion)
    {
        case SUM:
                    {
                        int param1 = darValorVariable(variables,ins.datoDisc.asig4.param1);
                        int param2 = darValorVariable(variables,ins.datoDisc.asig4.param2);
                        resultado = (param1 + param2);
                    }
            break;
        case RES:
                    {
                        int param1 = darValorVariable(variables,ins.datoDisc.asig4.param1);
                        int param2 = darValorVariable(variables,ins.datoDisc.asig4.param2);
                        resultado = (param1 - param2);
                    }
            break;
        case MUL:
                    {
                        int param1 = darValorVariable(variables,ins.datoDisc.asig4.param1);
                        int param2 = darValorVariable(variables,ins.datoDisc.asig4.param2);
                        resultado = (param1 * param2);
                    }
            break;
        case DIV:
                    {
                        int param1 = darValorVariable(variables,ins.datoDisc.asig4.param1);
                        int param2 = darValorVariable(variables,ins.datoDisc.asig4.param2);
                        if (param2 != 0)
                        {
                            resultado = (param1 / param2);
                        }
                        else
                        {
                            resultado = 0;
                            errorEjecucion = TRUE;
                            printf("\n\nError de ejecucion: El parametro 2 en funcion DIV no puede ser cero.\n");
                            printf("\t\t    ");
                            MostrarValorVariable(variables,ins.datoDisc.asig4.param2);
                            printf("\n");
                            system ("pause");
                        }
                    }
            break;
    }
}

int EjecutarFuncVarVal (instruccion ins, ArbolVariables variables)
{
    switch (ins.datoDisc.asig5.funcion)
    {
        case SUM:
                    {
                        int param1 = darValorVariable(variables,ins.datoDisc.asig5.param1);
                        int param2 = darParam2Asig5(ins.datoDisc.asig5);
                        return (param1 + param2);
                    }
            break;
        case RES:
                    {
                        int param1 = darValorVariable(variables,ins.datoDisc.asig5.param1);
                        int param2 = darParam2Asig5(ins.datoDisc.asig5);
                        return (param1 - param2);
                    }
            break;
        case MUL:
                    {
                        int param1 = darValorVariable(variables,ins.datoDisc.asig5.param1);
                        int param2 = darParam2Asig5(ins.datoDisc.asig5);
                        return (param1 * param2);
                    }
            break;
        case DIV:
                    {
                        int param1 = darValorVariable(variables,ins.datoDisc.asig5.param1);
                        int param2 = darParam2Asig5(ins.datoDisc.asig5);
                        return (param1 / param2);
                    }
            break;
    }
}

void EjecutarFuncValVar (instruccion ins, ArbolVariables variables, boolean &errorEjecucion, int &resultado)
{
    switch (ins.datoDisc.asig6.funcion)
    {
        case SUM:
                    {
                        int param1 = darParam1Asig6(ins.datoDisc.asig6);
                        int param2 = darValorVariable(variables,ins.datoDisc.asig6.param2);
                        resultado = (param1 + param2);
                    }
            break;
        case RES:
                    {
                        int param1 = darParam1Asig6(ins.datoDisc.asig6);
                        int param2 = darValorVariable(variables,ins.datoDisc.asig6.param2);
                        resultado = (param1 - param2);
                    }
            break;
        case MUL:
                    {
                        int param1 = darParam1Asig6(ins.datoDisc.asig6);
                        int param2 = darValorVariable(variables,ins.datoDisc.asig6.param2);
                        resultado = (param1 * param2);
                    }
            break;
        case DIV:
                    {
                        int param1 = darParam1Asig6(ins.datoDisc.asig6);
                        int param2 = darValorVariable(variables,ins.datoDisc.asig6.param2);
                        if (param2 != 0)
                        {
                            resultado = (param1 / param2);
                        }
                        else
                        {
                            resultado = 0;
                            errorEjecucion = TRUE;
                            printf("\n\nError de ejecucion: El parametro 2 en funcion DIV no puede ser cero.\n");
                            printf("\t\t    ");
                            MostrarValorVariable(variables,ins.datoDisc.asig4.param2);
                            printf("\n");
                            system ("pause");
                        }
                    }
            break;
    }
}

