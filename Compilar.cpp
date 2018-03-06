#include "Compilar.h"

void Compilar (strings nombreArchivo)
{
// ARCHIVO PARA .CSIM
    strings auxArch;
    strcrear(auxArch);
    strcop(auxArch,nombreArchivo);
    strcon(auxArch,EXTCSIM);

    ListaStrings listaArchivo;
    CrearListaStrings(listaArchivo);

    ListaInstrucciones instrucciones;
    CrearListaInst(instrucciones);
    ArbolVariables variables;
    crearABBvariable(variables);

    boolean errorEnInstruccion = FALSE;
    boolean errorEnVariables = FALSE;
    boolean errorCompilacion = FALSE;

    GenerarListaString(listaArchivo,auxArch);

    /* ***********DEBUG**************** */
    printf("\nLISTA STRINGS listaArchivo\n");
    MostrarListaStrings(listaArchivo);
    system ("pause");
    /* ***********END DEBUG**************** */

    strdestruir(auxArch);

    if (EsVaciaListaStrings(listaArchivo) == FALSE)
    {
        /* ***************** PRIMERA LINEA ***************** */
        ListaStrings Parseado;
        CrearListaStrings(Parseado);
        Parseo(listaArchivo->info,Parseado);

        /* ***********DEBUG**************** */
        printf("\nLISTA STRINGS parseado\n");
        MostrarListaStrings(Parseado);
        system ("pause");
        /* ***********END DEBUG**************** */

        if (LargoListaStrings(Parseado) == 2)
        {
            while (listaArchivo != NULL, errorEnInstruccion != TRUE && errorEnVariables != TRUE && errorCompilacion != TRUE)
            {
                if (streq(Parseado->info,PROG) == TRUE)
                {
                    Parseado = Parseado->sig;

                    /* ***********DEBUG**************** */
                    printf("\nNOMBRE PARS???\n");
                    print(Parseado->info);
                    printf("\n");
                    system ("pause");

                    printf("\nnombreArchivo\n");
                    print(nombreArchivo);
                    printf("\n");
                    system ("pause");
                    /* ***********END DEBUG**************** */

                    if (streq(Parseado->info,nombreArchivo) == TRUE)
                    {
                        /* ***************** SEGUNDA LINEA ***************** */
                        listaArchivo = listaArchivo->sig;

                        DestruirListaStrings(Parseado);
                        CrearListaStrings(Parseado);
                        Parseo(listaArchivo->info,Parseado);

                        /* ***********DEBUG**************** */
                        printf("\nlistaArchivo - PARSEADO\n");
                        MostrarListaStrings(Parseado);
                        printf("\n");
                        system ("pause");
                        /* ***********END DEBUG**************** */

                        /* ***********DEBUG**************** */
                        printf("\nPARSEADO INFO\n");
                        print(Parseado->info);
                        printf("\n");
                        system ("pause");

                        printf("\nVAR\n");
                        print(VAR);
                        printf("\n");
                        system ("pause");
                        /* ***********END DEBUG**************** */

                        if (streq(Parseado->info,VAR) == TRUE)
                        {
                            variable vari;
                            Parseado = Parseado->sig;
                            while (Parseado != NULL && errorEnVariables != TRUE)
                            {
                                if (esStringDeCaracteres(Parseado->info) == TRUE)
                                {
                                    if (existeEnABB(variables,Parseado->info) == FALSE)
                                    {
                                        CargarVariable(vari,Parseado->info,0);
                                        cargarABBvariable(variables,vari);
                                        Parseado = Parseado->sig;
                                    }
                                    else
                                    {
                                        errorEnVariables = TRUE;
                                        printf("\n\nError de compilacion: La variable esta duplicada.");
                                    }
                                }
                                else
                                {
                                    errorEnVariables = TRUE;
                                    printf("\n\nError de compilacion: La variable no contiene solamente caracteres.");
                                }
                            }


                            if (errorEnVariables == FALSE)
                            {
                                /* ***************** TERCERA LINEA ***************** */
                                listaArchivo = listaArchivo->sig;

                                DestruirListaStrings(Parseado);
                                CrearListaStrings(Parseado);

                                Parseo(listaArchivo->info,Parseado);

                                if (LargoListaStrings(Parseado) == 1)
                                {
                                    if (streq(Parseado->info,INS) == TRUE)
                                    {
                                        instruccion inst;
                                        listaArchivo = listaArchivo->sig;
                                        while (listaArchivo != NULL && errorEnInstruccion != TRUE)
                                        {
                                            /* ***************** CUARTA LINEA ***************** */
                                            DestruirListaStrings(Parseado);
                                            CrearListaStrings(Parseado);

                                            Parseo(listaArchivo->info,Parseado);

                                            /* ***********************DEBUG ****************** */
                                            printf("\nlista info????\n");
                                            MostrarListaStrings(listaArchivo);
                                            printf("\n");
                                            system ("pause");

                                            printf("\nparseado????\n");
                                            MostrarListaStrings(Parseado);
                                            printf("\n");
                                            system ("pause");
                                            /* ***********************DEBUG ****************** */

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
                                                            errorEnInstruccion = TRUE;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        printf("\n\nError de compilacion: Instruccione LEER incorrecta.");
                                                        errorEnInstruccion = TRUE;
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
                                                                errorEnInstruccion = TRUE;
                                                            }
                                                        }
                                                        else
                                                        {
                                                            printf("\n\nError de compilacion: Instruccion MOSTRAR incorrecta.");
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (LargoListaStrings(Parseado) == 3)/* ASUMO ES UNA VARIABLE - Una de las asignaciones 1 o 2*/
                                                        {
                                                            if (existeEnABB(variables,Parseado->info) == TRUE)
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
                                                                        strdestruir(auxVar);
                                                                    }
                                                                    else
                                                                    {
                                                                        if (esStringDeCaracteres(Parseado->info) == TRUE)
                                                                        {
                                                                            if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                            {
                                                                                CargarInsAsigVar(inst,auxVar,Parseado->info);
                                                                                InsBackListaInst(inst,instrucciones);
                                                                                strdestruir(auxVar);
                                                                            }
                                                                            else
                                                                            {
                                                                                printf("\n\nError de compilacion: La variable no fue declarada.");
                                                                            }
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("\n\nError de compilacion:El campo declarado no es correcto.");
                                                                        }
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    printf("\n\nError de compilacion:Falta signo de '=' en la asignacion.");
                                                                }
                                                            }
                                                            else
                                                            {
                                                                printf("\n\nError de compilacion: La variable no fue declarada.");
                                                            }
                                                        }
                                                        else
                                                        {
                                                            if (LargoListaStrings(Parseado) == 5)/* ASUMO ES UNA VARIABLE - Una de las funciones */
                                                            {
                                                                if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                {
                                                                    strings auxVar;
                                                                    strcrear(auxVar);
                                                                    strcop(auxVar,Parseado->info);
                                                                    Parseado = Parseado->sig;
                                                                    if (streq(Parseado->info,"=") == TRUE)
                                                                    {
                                                                        Parseado = Parseado->sig;
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
                                                                                    strdestruir(auxVar);
                                                                                }
                                                                                else
                                                                                {
                                                                                    if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                    {
                                                                                        CargarInsFuncValVar(inst,auxVar,SUM,param1,Parseado->info);
                                                                                        InsBackListaInst(inst,instrucciones);
                                                                                        strdestruir(auxVar);
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
                                                                                        strdestruir(auxVar);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                        {
                                                                                            CargarInsFuncVarVar(inst,auxVar,SUM,param1,Parseado->info);
                                                                                            InsBackListaInst(inst,instrucciones);
                                                                                            strdestruir(auxVar);
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
                                                                                        strdestruir(auxVar);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                        {
                                                                                            CargarInsFuncValVar(inst,auxVar,RES,param1,Parseado->info);
                                                                                            InsBackListaInst(inst,instrucciones);
                                                                                            strdestruir(auxVar);
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
                                                                                            strdestruir(auxVar);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                            {
                                                                                                CargarInsFuncVarVar(inst,auxVar,RES,param1,Parseado->info);
                                                                                                InsBackListaInst(inst,instrucciones);
                                                                                                strdestruir(auxVar);
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
                                                                                            strdestruir(auxVar);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                            {
                                                                                                CargarInsFuncValVar(inst,auxVar,MUL,param1,Parseado->info);
                                                                                                InsBackListaInst(inst,instrucciones);
                                                                                                strdestruir(auxVar);
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
                                                                                                strdestruir(auxVar);
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                                {
                                                                                                    CargarInsFuncVarVar(inst,auxVar,MUL,param1,Parseado->info);
                                                                                                    InsBackListaInst(inst,instrucciones);
                                                                                                    strdestruir(auxVar);
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
                                                                                                    strdestruir(auxVar);
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                    printf("\n\nError de compilacion: El segundo parametro no puede ser cero en la funcion DIV");
                                                                                                    errorEnInstruccion = TRUE;
                                                                                                }
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                /* ***********************DEBUG ****************** */
                                                                                                printf("\nOCTA????\n");
                                                                                                print(Parseado->info);
                                                                                                printf("\n");
                                                                                                system ("pause");
                                                                                                /* ***********************DEBUG ****************** */
                                                                                                if (existeEnABB(variables,Parseado->info) == TRUE)
                                                                                                {
                                                                                                    CargarInsFuncValVar(inst,auxVar,DIV,param1,Parseado->info);
                                                                                                    InsBackListaInst(inst,instrucciones);
                                                                                                    strdestruir(auxVar);
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
                                                                                                        strdestruir(auxVar);
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
                                                                                                        strdestruir(auxVar);
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
                                                                    else
                                                                    {
                                                                        printf("\n\nError de compilacion:Falta signo de '=' en la asignacion.");
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                                    errorEnInstruccion = TRUE;
                                                                }
                                                            }
                                                            else
                                                            {
                                                                printf("\n\nError de compilacion: La instruccion no es correcta.");
                                                                errorEnInstruccion = TRUE;
                                                            }
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
                        {
                            printf("\n\nError de compilacion: No existe la palabra VARIABLES.");
                            errorCompilacion = TRUE;
                        }
                    }
                    else
                    {
                        printf("\n\nEl nombre del archivo no coincide con el nombre en el PROGRAMA.");
                        errorCompilacion = TRUE;
                    }
                }
                else
                {
                    printf("\n\nEl programa no inicia con la palabra: PROGRAMA.");
                    errorCompilacion = TRUE;
                }
            }
        }
        else
        {
            printf("\nEl nombre del programa en el archivo no es correcto: ");
            print(nombreArchivo);
            errorCompilacion = TRUE;
        }
    }
    else
    {
        printf("\n\nEl archivo ");
        print(nombreArchivo);
        printf("\n esta vacio. ");
    }

    printf("\n\n********************** Variables **********************\n");
    MostrarVariablesTodas(variables);
    printf("\n\n********************** End Variables **********************\n");

    printf("\n\n********************** Instrucciones **********************\n");
    MostrarListaInstrucciones(instrucciones);
    printf("\n\n********************** End Instrucciones **********************\n");

    if (errorEnVariables == FALSE && errorEnInstruccion == FALSE && errorCompilacion == FALSE)
    {
        strings auxVars;
        strcrear(auxVars);
        strcop(auxVars,nombreArchivo);
        strcon(auxVars,EXTVARS);

        strings auxInst;
        strcrear(auxInst);
        strcop(auxInst,nombreArchivo);
        strcon(auxInst,EXTINST);

        BajarAbb(variables,auxVars);
        BajarLista(instrucciones,auxInst);

        strdestruir(auxInst);
        strdestruir(auxVars);
        delete (variables);
        delete (instrucciones);
    }
    else
    {
        delete (variables);
        delete (instrucciones);
    }

}
