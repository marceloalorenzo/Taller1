#ifndef COMPILAR_H_INCLUDED
#define COMPILAR_H_INCLUDED
#include "Archivo.h"
#include "Lista_string.h"

const strings PROG = "PROGRAMA";
const strings VAR = "VARIABLES";
const strings INS = "INSTRUCCIONES";
const strings EXTCSIM = ".csim";
const strings EXTVARS = ".vars";
const strings EXTINST = ".inst";

// Programa principal de compilar
void Compilar (strings nombreArchivo);

//Genera el arbol de variables
void compilarVariables (ListaStrings str, ArbolVariables &variables, boolean &errorEnVariables);

//Genera la lista de instrucciones
void compilarInstrucciones (ArbolVariables variables, ListaStrings str, ListaInstrucciones &instrucciones, boolean &errorEnInstruccion);


#endif // COMPILAR_H_INCLUDED
