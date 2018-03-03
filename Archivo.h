#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "ABB_Variables.h"
#include "Lista_Instrucciones.h"
#include "Lista_string.h"

/* ********************************************** GENERALES ************************************************ */

// Determina si existe o no un archivo con el nombre recibido por parámetro
boolean ExisteArchivo(strings nomArch);

// Determina si el archivo está vacío o no.
// Precondición: El archivo existe
boolean EsVacioArchivo (strings nomArch);

// Devuelve la cantidad de enteros almacenados en el archivo.
// Precondición: El archivo existe
int LargoArchivo (strings nomArch);

//STRINGS
// Escribe en el archivo los caracteres del string s (incluido '\0')
// Precondición: El archivo viene abierto para escritura.
void BajarStrings (strings s, FILE * f);

// Lee desde el archivo los caracteres del string s.
// Precondición: El archivo viene abierto para lectura.
void LevantarStrings (strings &s, FILE * f);

/* ********************************************** END GENERALES ************************************************ */

/* ********************************************** .VARS ************************************************ */
//VARIABLE
// Escribe en el archivo los datos de la variable.
// Precondición: El archivo viene abierto para escritura.
void BajarVariable (variable v, FILE * f);

// Lee desde el archivo los datos de la variable.
// Precondición: El archivo viene abierto para lectura.
void LevantarVariable (variable &v, FILE * f);

//ABB Variables
// Escribe en el archivo los datos de todas las variables del árbol en forma recursiva.
// PRECONDICION: El archivo viene abierto para escritura.
void BajarAbbAux (ArbolVariables a, FILE * f);

// Abre el archivo para escritura y escribe los datos de todas las variables del árbol (llamando al procedimiento anterior)
//Bajar Arbol de busqueda binario
void BajarAbb (ArbolVariables a, strings NomArch);

// Abre el archivo para lectura e inserta en el árbol todas las variables que están en el archivo (llamando al procedimiento ArbolABB).
// PRECONDICION: El archivo existe.
//Levantar Arbol de busqueda binario
void LevantarAbb (ArbolVariables &a, strings NomArch);

/* ********************************************** END .VARS ************************************************ */

/* ********************************************** .INST ************************************************ */

//INSTRUCCION
//Escribe en el archivo los datos de habilidad h
//Precondición: El archivo viene abierto para escritura
void BajarInstruccion (instruccion i, FILE * f);

// Lee desde el archivo los datos de la habilitad h.
// Precondición: El archivo viene abierto para lectura.
void LevantarInstruccion (instruccion &i, FILE * f);

//LISTA
// Abre el archivo para escritura y escribe los datos de todas las instrucciones
// que están almacenadas en la lista
//Bajar lista
void BajarLista (ListaInstrucciones L , strings NomArch);

//Levantar lista
void LevantarLista (ListaInstrucciones &L, strings NomArch);

/* ********************************************** END .INST ************************************************ */

/* ********************************************** .CSIM ************************************************ */

//Levanta el archivo linea por linea
void LevantarStringsArchivo (strings &s, FILE * f);

//Genera la lista con las lineas del archivo
void GenerarListaString (ListaStrings &L, strings NomArch);

/* ********************************************** END .CSIM ************************************************ */

#endif // ARCHIVO_H_INCLUDED
