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

        while ( variables != NULL && errorEjecucion != TRUE) //mientras la liesta no sea nula ingreso al nodo
        {
            tipoInstruccion tipoFunc = darTipoInst(instrucciones->info);
            switch (tipoFunc)
            {
          //obtengo el dato cargado en el discriminante
            case LEER:  //Obtengo el nombre de la variable guardada en la compilación
                            {//agregar control con while
                                int lectura;
                                printf("\nIngrese un numero entero: ");
                                scanf("%d", &lectura);
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
                                EjecutarFuncVarVar(instrucciones->info,variables,errorEjecucion,resultado);
                                if (errorEjecucion != TRUE)
                                {
                                    CargarValorVariable(variables,instrucciones->info.datoDisc.asig6.variable,resultado);
                                }
                            }
                break;
            }
        }
    }
    else
    {
        printf("\n\nERROR, no existen uno de los archivos .csim o .vars\n\n");
        system("pause");
    }
}
                                /*
                case FUNCVARVAR:
                                {
                                     switch(tipoFuncion)
                                case SUM:
                                            {
                                                Obtengo los nombres de las variables guardados en param1 y param2
                                                Busco en el ABB el valor guardado para la variable del param1
                                                Busco en el ABB el valor guardado para la variable del param2
                                                Realizo la suma de param1 + param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case RES:
                                            {
                                                Obtengo los nombres de las variables guardados en param1 y param2
                                                Busco en el ABB el valor guardado para la variable del param1
                                                Busco en el ABB el valor guardado para la variable del param2
                                                Realizo la resta de param1 - param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case MUL:
                                            {
                                                Obtengo los nombres de las variables guardados en param1 y param2
                                                Busco en el ABB el valor guardado para la variable del param1
                                                Busco en el ABB el valor guardado para la variable del param2
                                                Realizo la multiplicación de param1 * param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case DIV:
                                            {
                                                Obtengo el nombre de la variable guardada en param2
                                                Busco en el ABB el valor guardado para la variable del param2

                                                SI	param2 es igual a cero	ENTONCES
                                                    Error de ejecución (El segundo término no puede ser cero)
                                                    Finalizo ejecución
                                                SINO
                                                    Obtengo el nombre de la variable guardada en param1
                                                    Busco en el ABB el valor guardado para la variable del param1
                                                    Realizo la división de param1 / param2
                                                    Guardo el valor en un auxiliar
                                                    Obtengo el nombre de la variable del campo variable
                                                    Busco en el ABB la variable
                                                    Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                                FIN SI

                                            }
                                            break;
                                }
                                break;
                case FUNCVARVAL:
                                {
                                     switch(tipoFuncion)
                                case SUM:
                                            {
                                                Obtengo el nombre de la variable guardada en param1
                                                Busco en el ABB el valor guardado para la variable del param1
                                                Realizo la suma de param1 + param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case RES:
                                            {
                                                Obtengo el nombre de la variable guardada en param1
                                                Busco en el ABB el valor guardado para la variable del param1
                                                Realizo la resta de param1 - param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case MUL:
                                            {
                                                Obtengo el nombre de la variable guardada en param1
                                                Busco en el ABB el valor guardado para la variable del param1
                                                Realizo la multiplicación de param1 * param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case DIV:
                                            {
                                            SI	param2 es igual a cero	ENTONCES
                                                Error de ejecución (El segundo término no puede ser cero)
                                                Finalizo ejecución
                                            SINO
                                                Obtengo el nombre de la variable guardada en param1
                                                Busco en el ABB el valor guardado para la variable del param1
                                                Realizo la división de param1 / param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            FIN SI
                                            }
                                            break;
                                }
                                break;
                case FUNCVALVAR:
                                {
                                     switch(tipoFuncion)
                                case SUM:
                                            {
                                                Obtengo el nombre de la variable guardada en param2
                                                Busco en el ABB el valor guardado para la variable del param2
                                                Realizo la suma de param1 + param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case RES:
                                            {
                                                Obtengo el nombre de la variable guardada en param
                                                Busco en el ABB el valor guardado para la variable del param2
                                                Realizo la resta de param1 - param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case MUL:
                                            {
                                                Obtengo el nombre de la variable guardada en param2
                                                Busco en el ABB el valor guardado para la variable del param2
                                                Realizo la multiplicación de param1 * param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case DIV:
                                            {
                                                Obtengo el nombre de la variable guardada en param2
                                                Busco en el ABB el valor guardado para la variable del param2

                                                SI	param2 es igual a cero	ENTONCES
                                                    Error de ejecución (El segundo término no puede ser cero)
                                                    Finalizo ejecución
                                                SINO
                                                    Realizo la división de param1 / param2
                                                    Guardo el valor en un auxiliar
                                                    Obtengo el nombre de la variable del campo variable
                                                    Busco en el ABB la variable
                                                    Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                                FIN SI
                                            }
                                            break;*/




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
                            printf("\n\nError de ejecucion: El parametro 2 en funcion DIV no puede ser cero.\n\n");
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
    switch (ins.datoDisc.asig4.funcion)
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
                            printf("\n\nError de ejecucion: El parametro 2 en funcion DIV no puede ser cero.\n\n");
                            system ("pause");
                        }
                    }
            break;
    }
}

