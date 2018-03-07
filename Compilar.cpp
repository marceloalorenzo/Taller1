#include "Compilar.h"

void Compilar (strings nombreArchivo)
{
    strings auxArch;
    strcrear(auxArch);
    strcop(auxArch,nombreArchivo);
    strcon(auxArch,EXTCSIM); // ARCHIVO PARA .CSIM

    ListaStrings listaArchivo;
    CrearListaStrings(listaArchivo); // LISTA DONSE LEVANTAR EL ARCHIVO :CSIM

    ListaInstrucciones instrucciones; // LISTA INSTRUCCIONES DONDE COMPILAR
    CrearListaInst(instrucciones);
    ArbolVariables variables; // ARBOL DE VARIABLES DONDE COMPILAR
    crearABBvariable(variables);

    boolean errorEnInstruccion = FALSE;
    boolean errorEnVariables = FALSE;
    boolean errorCompilacion = FALSE;

    GenerarListaString(listaArchivo,auxArch);

    strdestruir(auxArch);

    if (EsVaciaListaStrings(listaArchivo) == FALSE)
    {
        ListaStrings Parseado;
        CrearListaStrings(Parseado);
        Parseo(listaArchivo->info,Parseado); // *** PRIMERA LINEA ***

        if (LargoListaStrings(Parseado) == 2)
        {
            while (listaArchivo != NULL && errorEnInstruccion != TRUE && errorEnVariables != TRUE && errorCompilacion != TRUE)
            {
                if (streq(Parseado->info,PROG) == TRUE)
                {
                    Parseado = Parseado->sig;

                    if (streq(Parseado->info,nombreArchivo) == TRUE)
                    {
                        listaArchivo = listaArchivo->sig;

                        DestruirListaStrings(Parseado);
                        CrearListaStrings(Parseado);
                        Parseo(listaArchivo->info,Parseado); // *** SEGUNDA LINEA ***

                        compilarVariables(Parseado,variables,errorEnVariables);

                        if (errorEnVariables == FALSE)
                        {
                            listaArchivo = listaArchivo->sig;

                            DestruirListaStrings(Parseado);
                            CrearListaStrings(Parseado);

                            Parseo(listaArchivo->info,Parseado); // *** TERCERA LINEA ***

                            if (LargoListaStrings(Parseado) == 1)
                            {
                                if (streq(Parseado->info,INS) == TRUE)
                                {
                                    listaArchivo = listaArchivo->sig;
                                    while (listaArchivo != NULL && errorEnInstruccion != TRUE)
                                    {
                                        DestruirListaStrings(Parseado);
                                        CrearListaStrings(Parseado);

                                        Parseo(listaArchivo->info,Parseado); // *** CUARTA LINEA EN DELANTE***
                                        compilarInstrucciones(variables,Parseado,instrucciones,errorEnVariables);
                                        listaArchivo = listaArchivo->sig;
                                    }
                                }
                                else
                                {
                                    errorCompilacion = TRUE;
                                    printf("Error de compilacion: No existe la palabra INSTRUCCIONES.");
                                    system ("pause");
                                }
                            }
                            else
                            {
                                errorCompilacion = TRUE;
                                printf("Error de compilacion: Debe existir solamente la palabra INSTRUCCIONES en esta linea.");
                                system ("pause");
                            }
                        }
                    }
                    else
                    {
                        errorCompilacion = TRUE;
                        printf("\n\nEl nombre del archivo no coincide con el nombre en el PROGRAMA.");
                        system ("pause");
                    }
                }
                else
                {
                    errorCompilacion = TRUE;
                    printf("\n\nEl programa no inicia con la palabra: PROGRAMA.");
                    system ("pause");
                }
            }
        }
        else
        {
            printf("\nEl nombre del programa no contiene la cantidad de palabras correctas");
            print(listaArchivo->info);
            system ("pause");
        }
    }
    else
    {
        printf("\n\nEl archivo ");
        print(nombreArchivo);
        printf("\n esta vacio. ");
        system ("pause");
    }

    /* ************************ DEBUG **************************** */
    printf("\n\n********************** Variables **********************\n");
    MostrarVariablesTodas(variables);
    printf("\n\n********************** End Variables **********************\n");
    system ("pause");

    printf("\n\n********************** Instrucciones **********************\n");
    MostrarListaInstrucciones(instrucciones);
    printf("\n\n********************** End Instrucciones **********************\n");
    system ("pause");
    /* ************************ END DEBUG **************************** */

    if (errorEnVariables == FALSE && errorEnInstruccion == FALSE && errorCompilacion == FALSE)
    {
        strings auxVars;
        strcrear(auxVars);
        strcop(auxVars,nombreArchivo);
        strcon(auxVars,EXTVARS); // AUXILIAR PARA BAJAR EL ARBOL DE VARIABLES

        strings auxInst;
        strcrear(auxInst);
        strcop(auxInst,nombreArchivo);
        strcon(auxInst,EXTINST); // AUXILIAR PARA BAJAR LA LISTA DE INSTRUCCIONES

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

///////////////////////////////////////////////////////////////////////////////////////////

void compilarVariables (ListaStrings Parseado, ArbolVariables &variables, boolean &errorEnVariables)
{
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
                    system ("pause");
                }
            }
            else
            {
                errorEnVariables = TRUE;
                printf("\n\nError de compilacion: La variable no contiene solamente caracteres.");
                system ("pause");
            }
        }
    }
    else
    {
        errorEnVariables = TRUE;
        printf("\n\nError de compilacion: No existe la palabra VARIABLES.");
        system ("pause");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

void compilarInstrucciones (ArbolVariables variables, ListaStrings Parseado, ListaInstrucciones &instrucciones, boolean &errorEnInstruccion)
{
    instruccion inst;
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
                    system ("pause");
                }
            }
            else
            {
                printf("\n\nError de compilacion: Instruccion LEER incorrecta.");
                errorEnInstruccion = TRUE;
                system ("pause");
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
                        errorEnInstruccion = TRUE;
                        printf("\n\nLa variable no fue declarada.");
                        system ("pause");
                    }
                }
                else
                {
                    errorEnInstruccion = TRUE;
                    printf("\n\nError de compilacion: Instruccion MOSTRAR incorrecta.");
                    system ("pause");
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
                                if (esStringDeCaracteres(Parseado->info) == TRUE) // Es una variable
                                {
                                    if (existeEnABB(variables,Parseado->info) == TRUE)
                                    {
                                        CargarInsAsigVar(inst,auxVar,Parseado->info);
                                        InsBackListaInst(inst,instrucciones);
                                        strdestruir(auxVar);
                                    }
                                    else
                                    {
                                        errorEnInstruccion = TRUE;
                                        printf("\n\nError de compilacion: La variable no fue declarada.");
                                        system ("pause");
                                    }
                                }
                                else
                                {
                                    errorEnInstruccion = TRUE;
                                    printf("\n\nError de compilacion:El campo declarado no es correcto.");
                                    system ("pause");
                                }
                            }
                        }
                        else
                        {
                            errorEnInstruccion = TRUE;
                            printf("\n\nError de compilacion:Falta signo de '=' en la asignacion.");
                            system ("pause");
                        }
                    }
                    else
                    {
                        errorEnInstruccion = TRUE;
                        printf("\n\nError de compilacion: La variable no fue declarada.");
                        system ("pause");
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

                                /* *** EMPIEZA SUM *** */
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
                                                errorEnInstruccion = TRUE;
                                                printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                system ("pause");
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
                                                    errorEnInstruccion = TRUE;
                                                    printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                    system ("pause");
                                                }
                                            }
                                        }
                                        else
                                        {
                                            errorEnInstruccion = TRUE;
                                            printf("\n\nError de compilacion: La variable no fue declarada.");
                                            system ("pause");
                                        }
                                    }
                                }/* *** FIN SUM *** */
                                else
                                {
                                    /* *** EMPIEZA RES *** */
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
                                                    errorEnInstruccion = TRUE;
                                                    printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                    system ("pause");
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
                                                        errorEnInstruccion = TRUE;
                                                        printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                        system ("pause");
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                errorEnInstruccion = TRUE;
                                                printf("\n\nError de compilacion: La variable no fue declarada.");
                                                system ("pause");
                                            }
                                        }
                                    } /* *** FIN RES *** */
                                    else
                                    {
                                        /* *** EMPIEZA MUL *** */
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
                                                        errorEnInstruccion = TRUE;
                                                        printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                        system ("pause");
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
                                                            errorEnInstruccion = TRUE;
                                                            printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                            system ("pause");
                                                        }
                                                    }
                                                }
                                                else
                                                {
                                                    errorEnInstruccion = TRUE;
                                                    printf("\n\nError de compilacion: La variable no fue declarada.");
                                                    system ("pause");
                                                }
                                            }
                                        } /* *** FIN MUL *** */
                                        else
                                        {
                                            /* *** EMPIEZA DIV *** */
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
                                                            errorEnInstruccion = TRUE;
                                                            printf("\n\nError de compilacion: El segundo parametro no puede ser cero en la funcion DIV.");
                                                            system ("pause");
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (existeEnABB(variables,Parseado->info) == TRUE)
                                                        {
                                                            CargarInsFuncValVar(inst,auxVar,DIV,param1,Parseado->info);
                                                            InsBackListaInst(inst,instrucciones);
                                                            strdestruir(auxVar);
                                                        }
                                                        else
                                                        {
                                                            errorEnInstruccion = TRUE;
                                                            printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                            system ("pause");
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
                                                                errorEnInstruccion = TRUE;
                                                                printf("\n\nError de compilacion: El segundo parametro no puede ser cero en la funcion DIV.");
                                                                system ("pause");
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
                                                                errorEnInstruccion = TRUE;
                                                                printf("\n\nError de compilaciòn: La variable no fue declarada.");
                                                                system ("pause");
                                                            }
                                                        }
                                                    }
                                                    else
                                                    {
                                                        errorEnInstruccion = TRUE;
                                                        printf("\n\nError de compilacion: La variable no fue declarada.");
                                                        system ("pause");
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                errorEnInstruccion = TRUE;
                                                printf("\n\nError de compilacion: La instruccion no es valida.");
                                                system ("pause");
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                errorEnInstruccion = TRUE;
                                printf("\n\nError de compilacion:Falta signo de '=' en la asignacion.");
                                system ("pause");
                            }
                        }
                        else
                        {
                            errorEnInstruccion = TRUE;
                            printf("\n\nError de compilaciòn: La variable no fue declarada.");
                            system ("pause");
                        }
                    }
                    else
                    {
                        errorEnInstruccion = TRUE;
                        printf("\n\nError de compilacion: La instruccion no es correcta.");
                        system ("pause");
                    }
                }
            }
        }
        Parseado = Parseado->sig;
    }
}
