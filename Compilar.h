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

void Compilar (strings nombreArchivo);

#endif // COMPILAR_H_INCLUDED
