#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "ABB_Variables.h"
#include "Lista_Instrucciones.h"
#include "Lista_string.h"

/* ********************************************** GENERALES ************************************************ */

// Determina si existe o no un archivo con el nombre recibido por par�metro
boolean Existe(strings nomArch);

// Determina si el archivo est� vac�o o no.
// Precondici�n: El archivo existe
boolean Vacio (strings nomArch);

// Devuelve la cantidad de enteros almacenados en el archivo.
// Precondici�n: El archivo existe
int Largo (strings nomArch);

//STRINGS
// Escribe en el archivo los caracteres del string s (incluido '\0')
// Precondici�n: El archivo viene abierto para escritura.
void Bajar_strings (strings s, FILE * f);

// Lee desde el archivo los caracteres del string s.
// Precondici�n: El archivo viene abierto para lectura.
void Levantar_strings (strings &s, FILE * f);

/* ********************************************** END GENERALES ************************************************ */

/* ********************************************** .VARS ************************************************ */
//VARIABLE
// Escribe en el archivo los datos de la variable.
// Precondici�n: El archivo viene abierto para escritura.
void Bajar_variable (variable v, FILE * f);

// Lee desde el archivo los datos de la variable.
// Precondici�n: El archivo viene abierto para lectura.
void Levantar_variable (variable &v, FILE * f);

//ABB Variables
// Escribe en el archivo los datos de todas las variables del �rbol en forma recursiva.
// PRECONDICION: El archivo viene abierto para escritura.
void Bajar_ABB_Aux (Arbol a, FILE * f);

// Abre el archivo para escritura y escribe los datos de todas las variables del �rbol (llamando al procedimiento anterior)
//Bajar Arbol de busqueda binario
void Bajar_ABB (Arbol a, strings NomArch);

// Abre el archivo para lectura e inserta en el �rbol todas las variables que est�n en el archivo (llamando al procedimiento ArbolABB).
// PRECONDICION: El archivo existe.
//Levantar Arbol de busqueda binario
void Levantar_ABB (Arbol &a, strings NomArch);

/* ********************************************** END .VARS ************************************************ */

/* ********************************************** .INST ************************************************ */

//INSTRUCCION
//Escribe en el archivo los datos de habilidad h
//Precondici�n: El archivo viene abierto para escritura
void Bajar_instruccion (instruccion i, FILE * f);

// Lee desde el archivo los datos de la habilitad h.
// Precondici�n: El archivo viene abierto para lectura.
void Levantar_instruccion (instruccion &i, FILE * f);

//LISTA
// Abre el archivo para escritura y escribe los datos de todas las instrucciones
// que est�n almacenadas en la lista
//Bajar lista
void Bajar_Lista (Lista L , strings NomArch);

//Levantar lista
void Levantar_Lista (Lista &L, strings NomArch);

/* ********************************************** END .INST ************************************************ */

/* ********************************************** .CSIM ************************************************ */

//Levanta el archivo linea por linea
void Levantar_strings_archivo (strings &s, FILE * f);

//Genera la lista con las lineas del archivo
void Generar_Lista_String (Lista_strings &L, strings NomArch);

/* ********************************************** END .CSIM ************************************************ */

#endif // ARCHIVO_H_INCLUDED
