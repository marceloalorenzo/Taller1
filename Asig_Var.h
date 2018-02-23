#ifndef ASIG_VAR_H_INCLUDED
#define ASIG_VAR_H_INCLUDED
#include "StringDinamico.h"

typedef struct {strings var1;
                strings var2;
                } asig_var;

// Devolver el nombre de la variable 1 guardada
void dar_var1_asig2 (asig_var var, strings &str);

// Devolver el nombre de la variable 2 guardada
void dar_var2_asig2 (asig_var var, strings &str);

// Cargar la Asignacion 2
void carga_var1_asig2 (asig_var &var, strings nom1, strings nom2);

#endif // ASIG_VAR_H_INCLUDED
