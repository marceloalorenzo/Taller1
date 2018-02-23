#ifndef ASIG_VAL_H_INCLUDED
#define ASIG_VAL_H_INCLUDED
#include "StringDinamico.h"

typedef struct {strings var_asig;
                int val_asig;
                } asig_val;

// Devolver el nombre de la variable guardada
void dar_var_asig1 (asig_val var, strings &str);

// Devolver el valor de la variable guardada
int dar_val_asig1 (asig_val var);

// Aargar la asignacion 1
void carga_var_asig1 (asig_val &var, strings nom, int val);


#endif // ASIG_VAL_H_INCLUDED
