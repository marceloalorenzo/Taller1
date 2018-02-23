#ifndef INSTRUCCIONES_H_INCLUDED
#define INSTRUCCIONES_H_INCLUDED
#include "Tipo_Instrucciones.h"
#include "Asig_Val.h"
#include "Asig_Var.h"
#include "Func_ValVal.h"
#include "Func_ValVar.h"
#include "Func_VarVal.h"
#include "Func_VarVar.h"

typedef struct {tipo_instruccion discriminante;
                union  {strings variable1;
                        strings variable2;
                        asig_val asig1;
                        asig_var asig2;
                        func_valval asig3;
                        func_varvar asig4;
                        func_varval asig5;
                        func_valvar asig6;
                        }dato_disc;
                }instruccion;

// Cargar la Instruccion
void Cargar_instruccion (instruccion &i);

//Devolver el tipo de instruccion (LEER, MOSTRAR, ASIG_VAL, ASIG_VAR, FUNC_VALVAL, FUNC_VARVAR, FUNC_VARVAL, FUNC_VALVAR)
tipo_instruccion dar_tipo_inst (instruccion i);


#endif // INSTRUCCIONES_H_INCLUDED
