#include "Compilar.h"


void Compilar (strings str)
{
// ARCHIVO PARA .CSIM
    Lista_strings lis_archivo;
    Crear_Lista_strings(lis_archivo);
    Generar_Lista_String(lis_archivo,strcon(str,".csim"));
    Mostrar_Lista2(lis_archivo);

    if (Esta_Vacia2(lis_archivo) == FALSE)
    {
        /* ***************** PRIMERA LINEA ***************** */
        Lista_strings pars;
        Crear_Lista_strings(pars);
        Parseo(lis_archivo->info,pars);

        /* ************************************************************** */

        if (Largo_Lista(pars) == 2)
        {
            while (pars != NULL)
            {
                if (streq(pars->info,PROG) == TRUE)
                {
                    pars = pars->sig;
                    if (streq(pars->info,str) == TRUE);
                    {
                        /* ***************** SEGUNDA LINEA ***************** */
                        lis_archivo = lis_archivo->sig;
                        Parseo(lis_archivo->info,pars);
                        if (streq(pars->info,VAR) == TRUE)
                        {
                            Arbol ar;
                            variable vari;
                            crear(ar);
                            pars = pars->sig;
                            boolean duplicada = FALSE;
                            while (pars != NULL && duplicada != TRUE)
                            {
                                strings aux;
                                strcrear(aux);
                                strcop(aux,pars->info);
                                if (existe_ABB(ar,aux) == FALSE)
                                {
                                    Cargar_variable(vari,nom,0);
                                    cargar_ABBvariable(ar,vari);
                                }
                                else
                                {
                                    duplicada = TRUE;
                                    printf("\n\nLa variable esta duplicada.");
                                }
                                strdestruir(aux);
                                pars = pars->sig;
                            }

                            if (duplicada == FALSE)
                            {
                                /* ***************** TERCERA LINEA ***************** */
                                lis_archivo = lis_archivo->sig;
                                Parseo(lis_archivo->info,pars);
                                if (Largo_Lista(pars) == 1)
                                {
                                    if (streq(pars->info,INS) == TRUE)
                                    {
                                        Lista inst;
                                        Crear_Lista(inst);
                                        instruccion i;
                                        /* ***************** CUARTA LINEA ***************** */
                                        lis_archivo = lis_archivo->sig;
                                        Parseo(lis_archivo->info,pars);
                                        boolean declarada = TRUE;
                                        while (pars != NULL && declarada != TRUE)   /* PROCESOS PARA CARGAR LA LISTA */
                                        {
                                            if (streq(pars->info,LEER) == TRUE) /* LEER */
                                            {
                                                if (Largo_Lista(pars) == 2)
                                                {
                                                    pars = pars->sig;
                                                    if (existe_ABB(ar,pars->info) == TRUE)
                                                    {
                                                        i.discriminante = LEER;
                                                        strcrear(i.dato_disc.variable1);
                                                        strcop(i.dato_disc.variable1,pars->info);
                                                        InsBack(i,inst);
                                                    }
                                                    else
                                                    {
                                                        printf("\n\nLa variable no fue declarada.");
                                                        declarada = FALSE;
                                                    }
                                                }
                                                else
                                                {
                                                    printf("\n\nError de compilacion: Instruccione LEER incorrecta.");
                                                }
                                            }
                                            else
                                            {
                                                if (streq(pars->info,MOSTRAR) == TRUE)  /* MOSTRAR */
                                                {
                                                    if (Largo_Lista(pars) == 2)
                                                    {
                                                        pars = pars->sig;
                                                        if (existe_ABB(ar,pars->info) == TRUE)
                                                        {
                                                            i.discriminante = MOSTRAR;
                                                            strcrear(i.dato_disc.variable2);
                                                            strcop(i.dato_disc.variable2,pars->info);
                                                            InsBack(i,inst);
                                                        }
                                                        else
                                                        {
                                                            printf("\n\nLa variable no fue declarada.");
                                                            declarada = FALSE;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        printf("\n\nError de compilacion: Instruccion MOSTRAR incorrecta.");
                                                    }
                                                }
                                                else
                                                {
                                                    if (existe_ABB(ar,pars->info) == TRUE) /* ASUMO ES UNA VARIABLE - Una de las asignaciones */
                                                    {
                                                        pars = pars->sig;
                                                        if (streq(pars->info,'=') == TRUE)
                                                        {
                                                            pars = pars->sig;
                                                            if ( /* COMO COMPARO SI ES UNA VALOR NUMERICO UN STRING???? */)
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
                                            }
                                            pars = pars->sig;
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

        Mostrar_Lista2(pars);
        lis_archivo = lis_archivo->sig;
        delete (pars);
    }
    else
    {
        printf("\n\nEl archivo ");
        print(str);
        printf("\n esta vacio. ");
    }


}
