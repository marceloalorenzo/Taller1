#include "Instrucciones.h"

// Cargar la Instruccion LEER o MOSTRAR
void CargarInsLeerMostrar (instruccion &i, tipoInstruccion disc, strings str)
{
    i.discriminante = disc;
    switch (disc)
    {
        case LEER:  {
                    strcrear(i.datoDisc.variable1);
                    strcop(i.datoDisc.variable1,str);
                    }
            break;
        case MOSTRAR:   {
                        strcrear(i.datoDisc.variable1);
                        strcop(i.datoDisc.variable1,str);
                        }
            break;
    }
}

// Cargar la Instruccion Asignar valor
void CargarInsAsigVal (instruccion &i, strings varAsig, int valAsig)
{
    i.discriminante = ASIGVAL;
    cargaVarAsig1(i.datoDisc.asig1,varAsig,valAsig);
}

// Cargar la Instruccion Asignar variable
void CargarInsAsigVar (instruccion &i, strings varAsig1, strings varAsig2)
{
    i.discriminante = ASIGVAR;
    cargaVarAsig2(i.datoDisc.asig2,varAsig1,varAsig2);
}

// Cargar la Instruccion Fución Valor-Valor
void CargarInsFuncValVal (instruccion &i, strings str, tipoFuncion func, int param1, int param2)
{
    i.discriminante = FUNCVALVAL;
    cargarFuncAsig3(i.datoDisc.asig3,str,func,param1,param2);
}

// Cargar la Instruccion Fución Valor-Variable
void CargarInsFuncValVar (instruccion &i, strings str, tipoFuncion func, int param1, strings param2)
{
    i.discriminante = FUNCVALVAR;
    cargarFuncAsig6(i.datoDisc.asig6,str,func,param1,param2);
}

// Cargar la Instruccion Fución Variable-Valor
void CargarInsFuncVarVal (instruccion &i, strings str, tipoFuncion func, strings param1, int param2)
{
    i.discriminante = FUNCVARVAL;
    cargarFuncAsig5(i.datoDisc.asig5,str,func,param1,param2);
}

// Cargar la Instruccion Fución Variable-Vaariable
void CargarInsFuncVarVar (instruccion &i, strings str, tipoFuncion func, strings param1, strings param2)
{
    i.discriminante = FUNCVARVAR;
    cargarFuncAsig4(i.datoDisc.asig4,str,func,param1,param2);
}

//Devolver el tipo de instruccion (LEER, MOSTRAR, ASIG_VAL, ASIG_VAR, FUNC_VALVAL, FUNC_VARVAR, FUNC_VARVAL, FUNC_VALVAR)
tipoInstruccion dar_tipo_inst (instruccion i)
{
    return i.discriminante;
}


//Mostrar Instruccion por pantalla
void MostrarInstruccion (instruccion i)
{
    switch (i.discriminante)
    {
        case LEER: {
                    printf("\n\nLEER.");
                    print(i.datoDisc.variable1);
                   }
           break;
        case MOSTRAR: {
                    printf("\n\nMOSTRAR.");
                    print(i.datoDisc.variable2);
                   }
           break;
        case ASIGVAL: {
                        printf("\n\nASIGVAL.");
                        printf("\nvariable = ");
                        print(i.datoDisc.asig1.varAsig);
                        printf("\nValor = %d",i.datoDisc.asig1.valAsig);
                       }
           break;
        case ASIGVAR: {
                        printf("\n\nASIGVAR.");
                        printf("\nvariable1 = ");
                        print(i.datoDisc.asig2.var1);
                        printf("\nvariable2 = ");
                        print(i.datoDisc.asig2.var2);
                       }
           break;
        case FUNCVALVAL: {
                        printf("\n\FUNCVALVAL.");
                        printf("\nvariable = ");
                        print(i.datoDisc.asig3.varAsig);
                        switch (i.datoDisc.asig3.funcion)
                        {
                            case SUM: printf("\nSUM");
                            break;
                            case RES: printf("\nRES");
                            break;
                            case MUL: printf("\nMUL");
                            break;
                            case DIV: printf("\nDIV");
                            break;
                        }
                        printf("\n\nParam 1 = %d",i.datoDisc.asig3.param1);
                        printf("\n\nParam 2 = %d",i.datoDisc.asig3.param2);
                       }
           break;
        case FUNCVARVAR: {
                        printf("\n\FUNCVARVAR.");
                        printf("\nvariable = ");
                        print(i.datoDisc.asig4.variable);
                        switch (i.datoDisc.asig4.funcion)
                        {
                            case SUM: printf("\nSUM");
                            break;
                            case RES: printf("\nRES");
                            break;
                            case MUL: printf("\nMUL");
                            break;
                            case DIV: printf("\nDIV");
                            break;
                        }
                        printf("\nParam 1 = ");
                        print(i.datoDisc.asig4.param1);
                        printf("\nParam 2 = ");
                        print(i.datoDisc.asig4.param2);
                       }
           break;
        case FUNCVARVAL: {
                        printf("\n\FUNCVARVAL.");
                        printf("\nvariable = ");
                        print(i.datoDisc.asig5.variable);
                        switch (i.datoDisc.asig5.funcion)
                        {
                            case SUM: printf("\nSUM");
                            break;
                            case RES: printf("\nRES");
                            break;
                            case MUL: printf("\nMUL");
                            break;
                            case DIV: printf("\nDIV");
                            break;
                        }
                        printf("\nParam 1 = ");
                        print(i.datoDisc.asig5.param1);
                        printf("\n\nParam 2 = %d",i.datoDisc.asig5.param2);
                       }
           break;
        case FUNCVALVAR: {
                        printf("\n\FUNCVALVAR.");
                        printf("\nvariable = ");
                        print(i.datoDisc.asig6.variable);
                        switch (i.datoDisc.asig6.funcion)
                        {
                            case SUM: printf("\nSUM");
                            break;
                            case RES: printf("\nRES");
                            break;
                            case MUL: printf("\nMUL");
                            break;
                            case DIV: printf("\nDIV");
                            break;
                        }
                        printf("\n\nParam 1 = %d",i.datoDisc.asig6.param1);
                        printf("\nParam 2 = ");
                        print(i.datoDisc.asig6.param2);
                       }
           break;
    }
}
