#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "ABB_Variables.h"
#include "Lista_Instrucciones.h"

//void Agregar (strings nomArch, int entero);
boolean Existe(strings nomArch);
boolean Vacio (strings nomArch);
//boolean Pertenece (strings nomArch, int entero);
int Largo (strings nomArch);
//int K_esimo (strings nomArch, int k);
void Bajar_strings (strings s, FILE * f);
void Levantar_strings (strings &s, FILE * f);
void Bajar_variable (variable v, FILE * f) ;
void Levantar_variable (variable &v, FILE * f);
void Bajar_instruccion (instruccion i, FILE * f);
void Levantar_instruccion (instruccion &i, FILE * f);
void Bajar_ABB_Aux (Arbol a, FILE * f);
void Bajar_ABB (Arbol a, strings NomArch);
void Levantar_ABB (Arbol &a, strings NomArch);
void Bajar_Lista (Lista L , strings NomArch);
void Levantar_Lista (Lista &L, strings NomArch);

#endif // ARCHIVO_H_INCLUDED
