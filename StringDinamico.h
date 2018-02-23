#ifndef STRINGDINAMICO_H_INCLUDED
#define STRINGDINAMICO_H_INCLUDED
#include "boolean.h"

const int MAX=80;
typedef char *strings;

// Crear string
void strcrear (strings & s);

//Destruir string
void strdestruir (strings & s);

//Largo del string
int strlar(strings s);

// Copiar el string 2 en el string 1
void strcop(strings &s1,strings s2);

//Leer un string
void scan(strings &s);

//Leer string hasta el espacio (solo una palabra)
void scan_palabra(strings &s);

// Concatenar 2 strings
void strcon(strings &s1,strings s2);

//Mostrar string por pantalla
void print(strings s);

//Ver si el primer string es menor al segundo
boolean strmen(strings s1,strings s2);

//Ver si 2 strings son iguales
boolean streq(strings s1,strings s2);

//Controlar si el string tiene solo caracteres
boolean solo_caracteres(strings s1);

#endif // STRINGDINAMICO_H_INCLUDED
