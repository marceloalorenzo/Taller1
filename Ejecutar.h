#ifndef EJECUTAR_H_INCLUDED
#define EJECUTAR_H_INCLUDED
#include "Archivo.h"


const strings INST = ".inst";
const strings VARS = ".vars";



void Ejecutar (strings str);

// Ejecucion funcion Valor Valor
int EjecutarFuncValVal (instruccion ins);

// Ejecucion funcion Variable variable
void EjecutarFuncVarVar (instruccion ins, ArbolVariables variables, boolean &errorEjecucion, int &resultado);


// Ejecucion funcion Variable valor
int EjecutarFuncVarVal (instruccion ins, ArbolVariables variables);

// Ejecucion funcion Valor variable
void EjecutarFuncValVar (instruccion ins, ArbolVariables variables, boolean &errorEjecucion, int &resultado);

#endif // EJECUTAR_H_INCLUDED
