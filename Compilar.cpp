#include "Compilar.h"



void Compilar (strings nombreArchivo)
{
// ARCHIVO PARA .CSIM
    strings aux = ".csim";
    strcon(nombreArchivo,aux);
    ListaStrings listaArchivo;
    CrearListaStrings(listaArchivo);

    GenerarListaString(listaArchivo,nombreArchivo);

    if (EsVaciaListaStrings(listaArchivo) == FALSE)
    {
        /* ***************** PRIMERA LINEA ***************** */
        ListaStrings Parseado;
        CrearListaStrings(Parseado);
        Parseo(listaArchivo->info,Parseado);

        /* ************************************************************** */

        if (LargoListaStrings(Parseado) == 2)
        {
            while (Parseado != NULL)
            {
                if (streq(Parseado->info,PROG) == TRUE)
                {
                    Parseado = Parseado->sig;
                    if (streq(Parseado->info,nombreArchivo) == TRUE)
                    {
                        delete (Parseado);
                        CrearListaStrings(Parseado);
                        /* ***************** SEGUNDA LINEA ***************** */
                        listaArchivo = listaArchivo->sig;
                        Parseo(listaArchivo->info,Parseado);
                        if (streq(Parseado->info,VAR) == TRUE)
                        {
                            variable vari;
                            ArbolVariables variables;
                            crearABBvariable(variables);
                            Parseado = Parseado->sig;
                            boolean errorEnVariables = FALSE;
                            while (Parseado != NULL && errorEnVariables != TRUE)
                            {
                                if (esStringDeCaracteres(Parseado->info) == TRUE)
                                {
                                    if (existeEnABB(variables,Parseado->info) == FALSE)
                                    {
                                        CargarVariable(vari,Parseado->info,0);
                                        cargarABBvariable(variables,vari);
                                    }
                                    else
                                    {
                                        errorEnVariables = TRUE;
                                        printf("\n\nError de compilacion: La variable esta duplicada.");
                                    }
                                    Parseado = Parseado->sig;
                                }
                                else
                                {
                                    errorEnVariables = TRUE;
                                    printf("\n\nError de compilacion: La variable no contiene solamente caracteres.");
                                }
                            }

                            delete (Parseado);

                            if (errorEnVariables == FALSE)
                            {
                                /* ***************** TERCERA LINEA ***************** */
                                CrearListaStrings(Parseado);
                                listaArchivo = listaArchivo->sig;
                                Parseo(listaArchivo->info,Parseado);
                                if (LargoListaStrings(Parseado) == 1)
                                {
                                    if (streq(Parseado->info,INS) == TRUE)
                                    {
                                        ListaInstrucciones instrucciones;
                                        CrearListaInst(instrucciones);
                                        instruccion inst;
                                        boolean errorEnInstruccion = FALSE;
                                        listaArchivo = listaArchivo->sig;
                                        while (listaArchivo != NULL && errorEnInstruccion != TRUE)
                                        {
                                            delete (Parseado);
                                            CrearListaStrings(Parseado);
                                            /* ***************** CUARTA LINEA ***************** */
                                            Parseo(listaArchivo->info,Parseado);

                                            while (Parseado != NULL && errorEnInstruccion != TRUE)   /* PROCESOS PARA CARGAR LA LISTA */
                                            {
                                                if (streq(Parseado->info,"LEER") == TRUE) /* LEER */
                                                {
                                                    if (LargoListaStrings(Parseado) == 2)
                                                    {
                                                        Parseado = Parseado->sig;
                                                        if (existeEnABB(variables,Parseado->info) == TRUE)
                                                        {
                                                            CargarInsLeerMostrar(inst,LEER,Parseado->info);
                                                            InsBackListaInst(inst,instrucciones);
                                                        }
                                                        else
                                                        {
                                                            printf("\n\nLa variable no fue declarada.");
                                                            errorEnInstruccion = FALSE;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        printf("\n\nError de compilacion: Instruccione LEER incorrecta.");
                                                    }
                                                }
                                                else
                                                {
                                                    if (streq(Parseado->info,"MOSTRAR") == TRUE)  /* MOSTRAR */
                                                    {
                                                        if (LargoListaStrings(Parseado) == 2)
                                                        {
                                                            Parseado = Parseado->sig;
                                                            if (existeEnABB(variables,Parseado->info) == TRUE)
                                                            {
                                                                CargarInsLeerMostrar(inst,MOSTRAR,Parseado->info);
                                                                InsBackListaInst(inst,instrucciones);
                                                            }
                                                            else
                                                            {
                                                                printf("\n\nLa variable no fue declarada.");
                                                                errorEnInstruccion = FALSE;
                                                            }
                                                        }
                                                        else
                                                        {
                                                            printf("\n\nError de compilacion: Instruccion MOSTRAR incorrecta.");
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (LargoListaStrings(Parseado) == 5)
                                                        {
                                                            if (existeEnABB(variables,Parseado->info) == TRUE) /* ASUMO ES UNA VARIABLE - Una de las asignaciones */
                                                            {
                                                                strings auxVar;
                                                                strcrear(auxVar);
                                                                strcop(auxVar,Parseado->info);
                                                                Parseado = Parseado->sig;
                                                                if (streq(Parseado->info,"=") == TRUE)
                                                                {
                                                                    Parseado = Parseado->sig;
                                                                    if (esStringNumerico(Parseado->info) == TRUE) //Es un valor numerico
                                                                    {
                                                                        int valor = ConvertirStringEntero(Parseado->info);
                                                                        CargarInsAsigVal(inst,auxVar,valor);
                                                                        InsBackListaInst(inst,instrucciones);
                                                                    }
                                                                    else
                                                                    {
                                                                        if (esStringDeCaracteres(Parseado->info) == TRUE)
                                                                        {
                                                                            CargarInsAsigVar(inst,auxVar,Parseado->info);
                                                                            InsBackListaInst(inst,instrucciones);
                                                                        }
                                                                        else
                                                                        {
                                                                            if (streq(Parseado->info,"SUM") == TRUE)
                                                                            {
                                                                                Parseado = Parseado->sig;
                                                                                if (esStringNumerico(Parseado->info) == TRUE)
                                                                                {
                                                                                    int param1 = ConvertirStringEntero(Parseado->info);
                                                                                    Parseado = Parseado->sig;
                                                                                    if (esStringNumerico(Parseado->info) == TRUE)
                                                                                    {
                                                                                        CargarInsFuncValVal(inst,auxVar,SUM,param1,ConvertirStringEntero(Parseado->info));
                                                                                        InsBackListaInst(inst,instrucciones);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                        {
                                                                                            CargarInsFuncValVar(inst,auxVar,SUM,param1,Parseado->info);
                                                                                            InsBackListaInst(inst,instrucciones);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                                                            errorEnInstruccion = TRUE;
                                                                                        }
                                                                                    }
                                                                                }
                                                                                else
                                                                                {
                                                                                    if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                    {
                                                                                        strings param1;
                                                                                        strcrear(param1);
                                                                                        strcop(param1,Parseado->info);
                                                                                        Parseado = Parseado->sig;
                                                                                        if (esStringNumerico(Parseado->info) == TRUE)
                                                                                        {
                                                                                            CargarInsFuncVarVal(inst,auxVar,SUM,param1,ConvertirStringEntero(Parseado->info));
                                                                                            InsBackListaInst(inst,instrucciones);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                            {
                                                                                                CargarInsFuncVarVar(inst,auxVar,SUM,param1,Parseado->info);
                                                                                                InsBackListaInst(inst,instrucciones);
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                                                                errorEnInstruccion = TRUE;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        printf("\n\nError de compilacion: La variable no fue declarada.");
                                                                                        errorEnInstruccion = TRUE;
                                                                                    }
                                                                                }
                                                                            }
                                                                            else
                                                                            {
                                                                                if (streq(Parseado->info,"RES") == TRUE)
                                                                                {
                                                                                    Parseado = Parseado->sig;
                                                                                    if (esStringNumerico(Parseado->info) == TRUE)
                                                                                    {
                                                                                        int param1 = ConvertirStringEntero(Parseado->info);
                                                                                        Parseado = Parseado->sig;
                                                                                        if (esStringNumerico(Parseado->info) == TRUE)
                                                                                        {
                                                                                            CargarInsFuncValVal(inst,auxVar,RES,param1,ConvertirStringEntero(Parseado->info));
                                                                                            InsBackListaInst(inst,instrucciones);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                            {
                                                                                                CargarInsFuncValVar(inst,auxVar,RES,param1,Parseado->info);
                                                                                                InsBackListaInst(inst,instrucciones);
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                                                                errorEnInstruccion = TRUE;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                        {
                                                                                            strings param1;
                                                                                            strcrear(param1);
                                                                                            strcop(param1,Parseado->info);
                                                                                            Parseado = Parseado->sig;
                                                                                            if (esStringNumerico(Parseado->info) == TRUE)
                                                                                            {
                                                                                                CargarInsFuncVarVal(inst,auxVar,RES,param1,ConvertirStringEntero(Parseado->info));
                                                                                                InsBackListaInst(inst,instrucciones);
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                                {
                                                                                                    CargarInsFuncVarVar(inst,auxVar,RES,param1,Parseado->info);
                                                                                                    InsBackListaInst(inst,instrucciones);
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                    printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                                                                    errorEnInstruccion = TRUE;
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            printf("\n\nError de compilacion: La variable no fue declarada.");
                                                                                            errorEnInstruccion = TRUE;
                                                                                        }
                                                                                    }
                                                                                }
                                                                                else
                                                                                {
                                                                                    if (streq(Parseado->info,"MUL") == TRUE)
                                                                                    {
                                                                                        Parseado = Parseado->sig;
                                                                                        if (esStringNumerico(Parseado->info) == TRUE)
                                                                                        {
                                                                                            int param1 = ConvertirStringEntero(Parseado->info);
                                                                                            Parseado = Parseado->sig;
                                                                                            if (esStringNumerico(Parseado->info) == TRUE)
                                                                                            {
                                                                                                CargarInsFuncValVal(inst,auxVar,MUL,param1,ConvertirStringEntero(Parseado->info));
                                                                                                InsBackListaInst(inst,instrucciones);
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                                {
                                                                                                    CargarInsFuncValVar(inst,auxVar,MUL,param1,Parseado->info);
                                                                                                    InsBackListaInst(inst,instrucciones);
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                    printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                                                                    errorEnInstruccion = TRUE;
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                            {
                                                                                                strings param1;
                                                                                                strcrear(param1);
                                                                                                strcop(param1,Parseado->info);
                                                                                                Parseado = Parseado->sig;
                                                                                                if (esStringNumerico(Parseado->info) == TRUE)
                                                                                                {
                                                                                                    CargarInsFuncVarVal(inst,auxVar,MUL,param1,ConvertirStringEntero(Parseado->info));
                                                                                                    InsBackListaInst(inst,instrucciones);
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                    if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                                    {
                                                                                                        CargarInsFuncVarVar(inst,auxVar,MUL,param1,Parseado->info);
                                                                                                        InsBackListaInst(inst,instrucciones);
                                                                                                    }
                                                                                                    else
                                                                                                    {
                                                                                                        printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                                                                        errorEnInstruccion = TRUE;
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                printf("\n\nError de compilacion: La variable no fue declarada.");
                                                                                                errorEnInstruccion = TRUE;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if (streq(Parseado->info,"DIV") == TRUE)
                                                                                        {
                                                                                            Parseado = Parseado->sig;
                                                                                            if (esStringNumerico(Parseado->info) == TRUE)
                                                                                            {
                                                                                                int param1 = ConvertirStringEntero(Parseado->info);
                                                                                                Parseado = Parseado->sig;
                                                                                                if (esStringNumerico(Parseado->info) == TRUE)
                                                                                                {
                                                                                                    if (Parseado->info != 0)
                                                                                                    {
                                                                                                        CargarInsFuncValVal(inst,auxVar,DIV,param1,ConvertirStringEntero(Parseado->info));
                                                                                                        InsBackListaInst(inst,instrucciones);
                                                                                                    }
                                                                                                    else
                                                                                                    {
                                                                                                        printf("\n\nError de compilacion: El segundo parametro no puede ser cero en la funcion DIV");
                                                                                                        errorEnInstruccion = TRUE;
                                                                                                    }
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                    if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                                    {
                                                                                                        CargarInsFuncValVar(inst,auxVar,DIV,param1,Parseado->info);
                                                                                                        InsBackListaInst(inst,instrucciones);
                                                                                                    }
                                                                                                    else
                                                                                                    {
                                                                                                        printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                                                                        errorEnInstruccion = TRUE;
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                                {
                                                                                                    strings param1;
                                                                                                    strcrear(param1);
                                                                                                    strcop(param1,Parseado->info);
                                                                                                    Parseado = Parseado->sig;
                                                                                                    if (esStringNumerico(Parseado->info) == TRUE)
                                                                                                    {
                                                                                                        if (Parseado->info != 0)
                                                                                                        {
                                                                                                            CargarInsFuncVarVal(inst,auxVar,DIV,param1,ConvertirStringEntero(Parseado->info));
                                                                                                            InsBackListaInst(inst,instrucciones);
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            printf("\n\nError de compilacion: El segundo parametro no puede ser cero en la funcion DIV");
                                                                                                            errorEnInstruccion = TRUE;
                                                                                                        }
                                                                                                    }
                                                                                                    else
                                                                                                    {
                                                                                                        if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                                        {
                                                                                                            CargarInsFuncVarVar(inst,auxVar,DIV,param1,Parseado->info);
                                                                                                            InsBackListaInst(inst,instrucciones);
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                                                                            errorEnInstruccion = TRUE;
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                    printf("\n\nError de compilacion: La variable no fue declarada.");
                                                                                                    errorEnInstruccion = TRUE;
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            printf("\n\nError de compilacion: La instruccion no es valida.");
                                                                                            errorEnInstruccion = TRUE;
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    printf("\n\nError de compilacion:Falta signo de '=' en la asignacion.");
                                                                }
                                                                strdestruir(auxVar);
                                                            }
                                                            else
                                                            {
                                                                printf("\n\nError de compilacion: La variable no fue declarada.");
                                                            }
                                                        }
                                                        else
                                                        {
                                                            printf("\n\nError de compilacion: La instruccion no es correcta.");
                                                            errorEnInstruccion = TRUE;
                                                        }
                                                    }
                                                }
                                                Parseado = Parseado->sig;
                                            }
                                            listaArchivo = listaArchivo->sig;
                                        }
                                    }
                                    else
                                    {
                                        printf("Error de compilacion: No existe la palabra INSTRUCCIONES.");
                                    }
                                }
                                else
                                {
                                    printf("Error de compilacion: No debe existir nada luego de INSTRUCCIONES.");
                                }
                            }
                        }
                        else
                            printf("\n\nError de compilacion: No existe la palabra VARIABLES.");
                    }
                    else
                        printf("\n\nEl nombre del archivo no coincide con el nombre en el PROGRAMA.");
                }
                printf("\n\nEl programa no inicia con la palabra: PROGRAMA.");
            }


        }
        else
            printf("\nEl nombre del programa en el archivo no es correcto.");
        /* ************************************************************** */

        MostrarListaStrings(Parseado);
        listaArchivo = listaArchivo->sig;
        delete (Parseado);
    }
    else
    {
        printf("\n\nEl archivo ");
        print(nombreArchivo);
        printf("\n esta vacio. ");
    }


}
