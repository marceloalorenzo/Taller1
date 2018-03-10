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
void compilarInstrucciones (ArbolVariables variables, ListaStrings &Parseado, ListaInstrucciones &instrucciones, boolean &errorEnInstruccion, int linea);

//Carga asignaciòn 1 y 2
void asignar (ListaInstrucciones &instrucciones, ArbolVariables variables, ListaStrings &Parseado, instruccion inst, boolean &errorEnInstruccion, int linea);

//Cargar funciones
void asignarFunciones (ArbolVariables variables, ListaInstrucciones &instrucciones, ListaStrings &Parseado, instruccion inst, boolean &errorEnInstruccion, int linea);

// Verifica que tipo de funcion es y carga la instruccion
void asignarFuncionesAux (ArbolVariables variables, ListaInstrucciones &instrucciones,ListaStrings &Parseado, instruccion inst, boolean &errorEnInstruccion, tipoFuncion tipo, strings auxVar, int linea);


#endif // COMPILAR_H_INCLUDED
