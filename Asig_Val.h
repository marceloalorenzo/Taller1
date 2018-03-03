#ifndef ASIG_VAL_H_INCLUDED
#define ASIG_VAL_H_INCLUDED
#include "StringDinamico.h"

typedef struct {strings varAsig;
                int valAsig;
                } asigVal;

// Devolver el nombre de la variable guardada
void darVarAsig1 (asigVal var, strings &str);

// Devolver el valor de la variable guardada
int darValAsig1 (asigVal var);

// Aargar la asignacion 1
void cargaVarAsig1 (asigVal &var, strings nom, int val);


#endif // ASIG_VAL_H_INCLUDED
