#ifndef INSTRUCCIONES_H_INCLUDED
#define INSTRUCCIONES_H_INCLUDED
#include "Tipo_Instrucciones.h"
#include "Asig_Val.h"
#include "Asig_Var.h"
#include "Func_ValVal.h"
#include "Func_ValVar.h"
#include "Func_VarVal.h"
#include "Func_VarVar.h"

typedef struct {tipoInstruccion discriminante;
                union  {strings variable1;
                        strings variable2;
                        asigVal asig1;
                        asigVar asig2;
                        funcValVal asig3;
                        funcVarVar asig4;
                        funcVarVal asig5;
                        funcValVar asig6;
                        }datoDisc;
                }instruccion;

// Cargar la Instruccion LEER o MOSTRAR
void CargarInsLeerMostrar (instruccion &i, tipoInstruccion disc, strings str);

// Cargar la Instruccion Asignar valor
void CargarInsAsigVal (instruccion &i, strings varAsig, int valAsig);

// Cargar la Instruccion Asignar variable
void CargarInsAsigVar (instruccion &i, strings varAsig1, strings varAsig2);

// Cargar la Instruccion Fución Valor-Valor
void CargarInsFuncValVal (instruccion &i, strings str, tipoFuncion func, int param1, int param2);

// Cargar la Instruccion Fución Valor-Variable
void CargarInsFuncValVar (instruccion &i, strings str, tipoFuncion func, int parm1, strings param2);

// Cargar la Instruccion Fución Variable-Valor
void CargarInsFuncVarVal (instruccion &i, strings str, tipoFuncion func, strings parm1, int param2);

// Cargar la Instruccion Fución Variable-Vaariable
void CargarInsFuncVarVar (instruccion &i, strings str, tipoFuncion func, strings parm1, strings param2);

//Devolver el tipo de instruccion (LEER, MOSTRAR, ASIG_VAL, ASIG_VAR, FUNC_VALVAL, FUNC_VARVAR, FUNC_VARVAL, FUNC_VALVAR)
tipoInstruccion dar_tipo_inst (instruccion i);

//Mostrar Instruccion por pantalla
void MostrarInstruccion (instruccion i);

#endif // INSTRUCCIONES_H_INCLUDED
