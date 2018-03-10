#include "Compilar.h"

void Compilar (strings nombreArchivo)
{
    strings auxArch;
    strcrear(auxArch);
    strcop(auxArch,nombreArchivo);
    strcon(auxArch,EXTCSIM); // ARCHIVO PARA .CSIM

    if (ExisteArchivo(auxArch) == TRUE)
    {

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
                                        int linea = 4;
                                        listaArchivo = listaArchivo->sig;
                                        while (listaArchivo != NULL && errorEnInstruccion != TRUE)
                                        {
                                            DestruirListaStrings(Parseado);
                                            CrearListaStrings(Parseado);

                                            Parseo(listaArchivo->info,Parseado); // *** CUARTA LINEA EN DELANTE***
                                            compilarInstrucciones(variables,Parseado,instrucciones,errorEnVariables,linea);
                                            linea++;
                                            listaArchivo = listaArchivo->sig;
                                        }
                                    }
                                    else
                                    {
                                        errorCompilacion = TRUE;
                                        printf("\n\nError en la linea 3.\nError de compilacion: No existe la palabra INSTRUCCIONES.\n\n");
                                        system ("pause");
                                    }
                                }
                                else
                                {
                                    errorCompilacion = TRUE;
                                    printf("\n\nError en la linea 3.\nError de compilacion: Debe existir solamente la palabra INSTRUCCIONES en esta linea.\n\n");
                                    system ("pause");
                                }
                            }
                        }
                        else
                        {
                            errorCompilacion = TRUE;
                            printf("\n\nError en la linea 1.\nEl nombre del archivo no coincide con el nombre en el programa.\n\n");
                            system ("pause");
                        }
                    }
                    else
                    {
                        errorCompilacion = TRUE;
                        printf("\n\nError en la linea 1.\nEl programa no inicia con la palabra: PROGRAMA.\n\n");
                        system ("pause");
                    }
                }
            }
            else
            {
                errorCompilacion = TRUE;
                printf("\nError en la linea 1.\nCantidad de palabras incorrectas (PROGRAMA Nombre)\n\n");
                system ("pause");
            }
        }
        else
        {
            errorCompilacion = TRUE;
            printf("\n\nEl archivo ''");
            print(nombreArchivo);
            printf("'' esta vacio. \n\n");
            system ("pause");
        }

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

            printf("\n\nEl archivo ''");
            print(nombreArchivo);
            printf("'' compilo correctamente. \n\n");
            system ("pause");

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
    else
    {
        printf("\n\nEl archivo ''");
        print(nombreArchivo);
        printf(".csim'' no existe. \n\n");
        system ("pause");
    }
}

/* ***************** COMPILAR VARIABLES ***************** */

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
                    printf("\n\nError en la linea 2.\nError de compilacion: La variable esta duplicada.\n\n");
                    system ("pause");
                }
            }
            else
            {
                errorEnVariables = TRUE;
                printf("\n\nError en la linea 2.\nError de compilacion: La variable no contiene solamente caracteres.\n\n");
                system ("pause");
            }
        }
    }
    else
    {
        errorEnVariables = TRUE;
        printf("\n\nError en la linea 2.\nError de compilacion: No existe la palabra VARIABLES.\n\n");
        system ("pause");
    }
}

/* ***************** COMPILAR INSTRUCCIONES ***************** */

void compilarInstrucciones (ArbolVariables variables, ListaStrings &Parseado, ListaInstrucciones &instrucciones, boolean &errorEnInstruccion, int linea)
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
                    printf("\n\nError en la linea %d.\nError de compilacion: La variable no fue declarada.\n\n",linea);
                    errorEnInstruccion = TRUE;
                    system ("pause");
                }
            }
            else
            {
                printf("\n\nError en la linea %d.\nError de compilacion: Instruccion LEER incorrecta.\n\n",linea);
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
                        printf("\n\nError en la linea %d.\nLa variable no fue declarada.\n\n",linea);
                        system ("pause");
                    }
                }
                else
                {
                    errorEnInstruccion = TRUE;
                    printf("\n\nError en la linea %d.\nError de compilacion: Instruccion MOSTRAR incorrecta.\n\n",linea);
                    system ("pause");
                }
            }
            else
            {
                if (LargoListaStrings(Parseado) == 3)/* ASUMO ES UNA VARIABLE - Una de las asignaciones 1 o 2*/
                {
                    asignar(instrucciones,variables,Parseado,inst,errorEnInstruccion,linea);
                }
                else
                {
                    if (LargoListaStrings(Parseado) == 5)/* ASUMO ES UNA VARIABLE - Una de las funciones */
                    {
                        asignarFunciones(variables,instrucciones,Parseado,inst,errorEnInstruccion,linea);
                    }
                    else
                    {
                        errorEnInstruccion = TRUE;
                        printf("\n\nError en la linea %d.\nError de compilacion: La instruccion no es correcta.\n\n",linea);
                        system ("pause");
                    }
                }
            }
        }
        Parseado = Parseado->sig;
    }
}

/* ***************** RESUELVE Y CARGA ASIGNACIONES 1 Y 2 ***************** */
void asignar (ListaInstrucciones &instrucciones, ArbolVariables variables, ListaStrings &Parseado, instruccion inst, boolean &errorEnInstruccion, int linea)
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
                        printf("\n\nError en la linea %d.\nError de compilacion: La variable no fue declarada.\n\n",linea);
                        system ("pause");
                    }
                }
                else
                {
                    errorEnInstruccion = TRUE;
                    printf("\n\nError en la linea %d.\nError de compilacion:El campo indicado no es correcto en la asignacion.\n\n",linea);
                    system ("pause");
                }
            }
        }
        else
        {
            errorEnInstruccion = TRUE;
            printf("\n\nError en la linea %d.\nError de compilacion:Falta signo de '=' en la asignacion.\n\n",linea);
            system ("pause");
        }
    }
    else
    {
        errorEnInstruccion = TRUE;
        printf("\n\nError en la linea %d.\nError de compilacion: La variable no fue declarada.\n\n",linea);
        system ("pause");
    }
}

/* ***************** RESUELVE Y CARGA ASIGNACIONES POR FUNCIONES ***************** */
void asignarFunciones (ArbolVariables variables, ListaInstrucciones &instrucciones, ListaStrings &Parseado, instruccion inst, boolean &errorEnInstruccion, int linea)
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

            tipoFuncion tipo;
            if (streq(Parseado->info,"SUM") == TRUE)
            {
                tipo = SUM;
            }
            else
            {
                if (streq(Parseado->info,"RES") == TRUE)
                {
                    tipo = RES;
                }
                else
                {
                    if (streq(Parseado->info,"MUL") == TRUE)
                    {
                        tipo = MUL;
                    }
                    else
                    {
                        if (streq(Parseado->info,"DIV") == TRUE)
                        {
                            tipo = DIV;
                        }
                        else
                        {
                            errorEnInstruccion = TRUE;
                            printf("\n\nError en la linea %d.\nError de compilacion: La instruccion no es correcta.\n\n",linea);
                            system("pause");
                        }
                    }
                }
            }

            if (errorEnInstruccion != TRUE)
            {
                asignarFuncionesAux(variables,instrucciones,Parseado,inst,errorEnInstruccion,tipo,auxVar,linea);
            }
        }
        else
        {
            errorEnInstruccion = TRUE;
            printf("\n\nError en la linea %d.\nError de compilacion:Falta signo de '=' en la asignacion.\n\n",linea);
            system ("pause");
        }
    }
    else
    {
        errorEnInstruccion = TRUE;
        printf("\n\nError en la linea %d.\nError de compilacion: La variable no fue declarada.\n\n",linea);
        system ("pause");
    }
}


/* ***************** AUXILIAR PARA LA CARGA FINAL DE ASIGNACIONES POR FUNCIONES ***************** */
void asignarFuncionesAux (ArbolVariables variables, ListaInstrucciones &instrucciones,ListaStrings &Parseado, instruccion inst, boolean &errorEnInstruccion, tipoFuncion tipo, strings auxVar, int linea)
{

    Parseado = Parseado->sig;
    if (esStringNumerico(Parseado->info) == TRUE)
    {
        int param1 = ConvertirStringEntero(Parseado->info);
        Parseado = Parseado->sig;
        if (esStringNumerico(Parseado->info) == TRUE)
        {
            if (streq(Parseado->info,"0") == FALSE)
            {
                CargarInsFuncValVal(inst,auxVar,tipo,param1,ConvertirStringEntero(Parseado->info));
                InsBackListaInst(inst,instrucciones);
            }
            else
            {
                if (tipo != DIV)
                {
                    CargarInsFuncValVal(inst,auxVar,tipo,param1,ConvertirStringEntero(Parseado->info));
                    InsBackListaInst(inst,instrucciones);
                }
                else
                {
                    errorEnInstruccion = TRUE;
                    printf("\n\nError en la linea %d.\nError de compilacion: El segundo parametro en la funcion DIV no puede ser cero.\n\n",linea);
                    system("pause");
                }
            }
        }
        else
        {
            if (existeEnABB(variables,Parseado->info) == TRUE)
            {
                CargarInsFuncValVar(inst,auxVar,tipo,param1,Parseado->info);
                InsBackListaInst(inst,instrucciones);
            }
            else
            {
                errorEnInstruccion = TRUE;
                printf("\n\nError en la linea %d.\nError de compilacion: La variable no fue declarada.\n\n",linea);
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
                if (streq(Parseado->info,"0") == FALSE)
                {
                    CargarInsFuncVarVal(inst,auxVar,tipo,param1,ConvertirStringEntero(Parseado->info));
                    InsBackListaInst(inst,instrucciones);
                    strdestruir(auxVar);
                }
                else
                {
                    if (tipo != DIV)
                    {
                        CargarInsFuncVarVal(inst,auxVar,tipo,param1,ConvertirStringEntero(Parseado->info));
                        InsBackListaInst(inst,instrucciones);
                        strdestruir(auxVar);
                    }
                    else
                    {
                        errorEnInstruccion = TRUE;
                        printf("\n\nError en la linea %d.\nError de compilacion: El segundo parametro en la funcion DIV no puede ser cero.\n\n",linea);
                        system("pause");
                    }
                }
            }
            else
            {
                if (existeEnABB(variables,Parseado->info) == TRUE)
                {
                    CargarInsFuncVarVar(inst,auxVar,tipo,param1,Parseado->info);
                    InsBackListaInst(inst,instrucciones);
                    strdestruir(auxVar);
                }
                else
                {
                    errorEnInstruccion = TRUE;
                    printf("\n\nError en la linea %d.\nError de compilacion: La variable no fue declarada.\n\n",linea);
                    system ("pause");
                }
            }
        }
        else
        {
            errorEnInstruccion = TRUE;
            printf("\n\nError en la linea %d.\nError de compilacion: La variable no fue declarada.\n\n",linea);
            system ("pause");
        }
    }
}



