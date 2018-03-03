#ifndef LISTA_HABILIDADES_H_INCLUDED
#define LISTA_HABILIDADES_H_INCLUDED
#include "Instrucciones.h"

typedef struct tnodo   {instruccion info;
                        tnodo *sig;
                       }nodoL;
typedef nodoL *ListaInstrucciones;

//Crear lista vacìa
void CrearListaInst (ListaInstrucciones &L);

//Agregar elemento al inicio
void InsFrontListaInst (instruccion i, ListaInstrucciones &L);

//Insertar nodo al final de la lista
void InsBackListaInst (instruccion i, ListaInstrucciones &L);

//Saber si una lista està vacìa
boolean EsVaciaListaInst (ListaInstrucciones L);

//obtener el primer elemento de una lista
instruccion PrimeroListaInst (ListaInstrucciones L);

// Mostrar lista por pantalla
void MostrarListaInstrucciones (ListaInstrucciones L);

#endif // LISTA_HABILIDADES_H_INCLUDED
