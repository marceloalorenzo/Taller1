#ifndef ASIG_VAR_H_INCLUDED
#define ASIG_VAR_H_INCLUDED
#include "StringDinamico.h"

typedef struct {strings var1;
                strings var2;
                } asigVar;

// Devolver el nombre de la variable 1 guardada
void darVar1Asig2 (asigVar var, strings &str);

// Devolver el nombre de la variable 2 guardada
void darVar2Asig2 (asigVar var, strings &str);

// Cargar la Asignacion 2
void cargaVarAsig2 (asigVar &var, strings nom1, strings nom2);

#endif // ASIG_VAR_H_INCLUDED
