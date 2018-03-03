#include "Archivo.h"

/* ********************************************** GENERALES ************************************************ */

// Determina si existe o no un archivo con el nombre recibido por parámetro
boolean ExisteArchivo(strings nomArch)
{
    boolean es = TRUE;
    FILE *f;
    f=fopen(nomArch,"rb");
    if(f==NULL)
        es = FALSE;
    else
        fclose(f);

    return es;
}

// Determina si el archivo está vacío o no.
boolean EsVacioArchivo (strings nomArch) /* Precondición: El archivo existe */
{
    boolean res = FALSE;
    FILE *f = fopen(nomArch,"rb");
    fseek(f,0,SEEK_END);
    if(ftell(f) == 0)
        res = TRUE;
    fclose(f);
    return res;
}

// Devuelve la cantidad de enteros almacenados en el archivo.
int LargoArchivo (strings nomArch) /* Precondición: El archivo existe */
{
    int largoArch;
    FILE *f = fopen(nomArch,"rb");
    fseek(f,0,SEEK_END);
    largoArch = ftell(f)/sizeof(int);
    fclose(f);
    return largoArch;
}

//STRINGS
// Escribe en el archivo los caracteres del string s (incluido '\0')
void BajarStrings (strings s, FILE * f) /* Precondición: El archivo viene abierto para escritura*/
{
     int i = 0;
     while (s[i] != '\0')
     {
         fwrite (&s[i], sizeof(char), 1, f);
         i++;
     }
     fwrite (&s[i], sizeof(char), 1, f);
}

// Lee desde el archivo los caracteres del string s.
void LevantarStrings (strings &s, FILE * f) /* Precondición: El archivo viene abierto para lectura.*/
{
     int i=0;
     strings aux;
     aux = new char[MAX];
     fread (&aux[i], sizeof(char), 1, f);
     while (!feof(f) && (aux[i] != '\0'))
     {
         i++;
         fread (&aux[i], sizeof(char), 1, f);
     }
     aux[i] = '\0';
     strcop (s, aux);
     delete [] aux;
}

/* ********************************************** END GENERALES ************************************************ */

/* ********************************************** .VARS ************************************************ */
//VARIABLE
// Escribe en el archivo los datos de la variable.
void BajarVariable (variable v, FILE * f) /* Precondición: El archivo viene abierto para escritura. */
{
    BajarStrings (v.var, f);
    fwrite (&v.valor, sizeof(int), 1, f);
}

// Lee desde el archivo los datos de la variable.
void LevantarVariable (variable &v, FILE * f) /* Precondición: El archivo viene abierto para lectura. */
{
    strcrear(v.var);
    LevantarStrings(v.var,f);
    fread(&v.valor, sizeof(int),1,f);
}

// Auxiliar ABB Variables
// Escribe en el archivo los datos de todas las variables del árbol en forma recursiva.
void BajarAbbAux (ArbolVariables a, FILE * f) /* PRECONDICION: El archivo viene abierto para escritura. */
{
     if (a != NULL)
     {
         BajarVariable(a->info,f);
         BajarAbbAux (a->hizq, f);
         BajarAbbAux (a->hder, f);
     }
}

// Abre el archivo para escritura y escribe los datos de todas las variables del árbol (llamando al procedimiento anterior)
// ABB Variables
void BajarAbb (ArbolVariables a, strings NomArch)
{
 FILE * f = fopen (NomArch, "wb");
 BajarAbbAux (a, f);
 fclose (f);
}

// Abre el archivo para lectura e inserta en el árbol todas las variables que están en el archivo (llamando al procedimiento ArbolABB).
//Levantar Arbol de busqueda binario
void LevantarAbb (ArbolVariables &a, strings NomArch) /* PRECONDICION: El archivo existe. */
{
     FILE * f = fopen (NomArch, "rb");
     variable buffer;
     LevantarVariable(buffer, f);
     while (!feof(f))
     {
         cargarABBvariable(a, buffer);
         LevantarVariable(buffer, f);
     }
     fclose (f);
}

/* ********************************************** END .VARS ************************************************ */

/* ********************************************** .INST ************************************************ */

//INSTRUCCION
//Escribe en el archivo los datos de instruccion
void BajarInstruccion (instruccion i, FILE * f) /* Precondición: El archivo viene abierto para escritura */
{
    fwrite(&i.discriminante, sizeof(tipoInstruccion), 1, f);
    switch (i.discriminante)
    {
        case LEER:
            {
                BajarStrings(i.datoDisc.variable1,f);
            }
            break;
        case MOSTRAR:
            {
                BajarStrings(i.datoDisc.variable2,f);
            }
            break;
        case ASIGVAL:
            {
                BajarStrings(i.datoDisc.asig1.varAsig,f);
                fwrite(&i.datoDisc.asig1.valAsig, sizeof(int), 1, f);
            }
            break;
        case ASIGVAR:
            {
                BajarStrings(i.datoDisc.asig2.var1,f);
                BajarStrings(i.datoDisc.asig2.var2,f);
            }
            break;
        case FUNCVALVAL:
            {
                BajarStrings(i.datoDisc.asig3.varAsig,f);
                fwrite(&i.datoDisc.asig3.funcion, sizeof(tipoFuncion), 1, f);
                fwrite(&i.datoDisc.asig3.param1, sizeof(int), 1, f);
                fwrite(&i.datoDisc.asig3.param2, sizeof(int), 1, f);
            }
            break;
        case FUNCVARVAR:
            {
                BajarStrings(i.datoDisc.asig4.variable,f);
                fwrite(&i.datoDisc.asig4.funcion, sizeof(tipoFuncion), 1, f);
                BajarStrings(i.datoDisc.asig4.param1,f);
                BajarStrings(i.datoDisc.asig4.param2,f);
            }
            break;
        case FUNCVARVAL:
            {
                BajarStrings(i.datoDisc.asig5.variable,f);
                fwrite(&i.datoDisc.asig5.funcion, sizeof(tipoFuncion), 1, f);
                BajarStrings(i.datoDisc.asig5.param1,f);
                fwrite(&i.datoDisc.asig5.param2, sizeof(int), 1, f);
            }
            break;
        case FUNCVALVAR:
            {
                BajarStrings(i.datoDisc.asig6.variable,f);
                fwrite(&i.datoDisc.asig6.funcion, sizeof(tipoFuncion), 1, f);
                fwrite(&i.datoDisc.asig6.param1, sizeof(int), 1, f);
                BajarStrings(i.datoDisc.asig6.param2,f);
            }
            break;
    }
}
// Lee desde el archivo los datos de la habilitad h.
void LevantarInstruccion (instruccion &i, FILE * f) /* Precondición: El archivo viene abierto para lectura. */
{
    fread(&i.discriminante, sizeof(tipoInstruccion), 1, f);
    switch (i.discriminante)
    {
        case LEER:
            {
                strcrear(i.datoDisc.variable1);
                LevantarStrings(i.datoDisc.variable1,f);
            }
            break;
        case MOSTRAR:
            {
                strcrear(i.datoDisc.variable2);
                LevantarStrings(i.datoDisc.variable2,f);
            }
            break;
        case ASIGVAL:
            {
                strcrear(i.datoDisc.asig1.varAsig);
                LevantarStrings(i.datoDisc.asig1.varAsig,f);
                fread(&i.datoDisc.asig1.valAsig, sizeof(int), 1, f);
            }
            break;
        case ASIGVAR:
            {
                strcrear(i.datoDisc.asig2.var1);
                LevantarStrings(i.datoDisc.asig2.var1,f);
                strcrear(i.datoDisc.asig2.var2);
                LevantarStrings(i.datoDisc.asig2.var2,f);
            }
            break;
        case FUNCVALVAL:
            {
                strcrear(i.datoDisc.asig3.varAsig);
                LevantarStrings(i.datoDisc.asig3.varAsig,f);
                fread(&i.datoDisc.asig3.funcion, sizeof(tipoFuncion), 1, f);
                fread(&i.datoDisc.asig3.param1, sizeof(int), 1, f);
                fread(&i.datoDisc.asig3.param2, sizeof(int), 1, f);
            }
            break;
        case FUNCVARVAR:
            {
                strcrear(i.datoDisc.asig4.variable);
                LevantarStrings(i.datoDisc.asig4.variable,f);
                fread(&i.datoDisc.asig4.funcion, sizeof(tipoFuncion), 1, f);
                strcrear(i.datoDisc.asig4.param1);
                LevantarStrings(i.datoDisc.asig4.param1,f);
                strcrear(i.datoDisc.asig4.param2);
                LevantarStrings(i.datoDisc.asig4.param2,f);
            }
            break;
        case FUNCVARVAL:
            {
                strcrear(i.datoDisc.asig5.variable);
                LevantarStrings(i.datoDisc.asig5.variable,f);
                fread(&i.datoDisc.asig5.funcion, sizeof(tipoFuncion), 1, f);
                strcrear(i.datoDisc.asig5.param1);
                LevantarStrings(i.datoDisc.asig5.param1,f);
                fread(&i.datoDisc.asig5.param2, sizeof(int), 1, f);
            }
            break;
        case FUNCVALVAR:
            {
                strcrear(i.datoDisc.asig6.variable);
                LevantarStrings(i.datoDisc.asig6.variable,f);
                fread(&i.datoDisc.asig6.funcion, sizeof(tipoFuncion), 1, f);
                fread(&i.datoDisc.asig6.param1, sizeof(int), 1, f);
                strcrear(i.datoDisc.asig6.param2);
                LevantarStrings(i.datoDisc.asig6.param2,f);
            }
            break;
    }
}

//LISTA
// Abre el archivo para escritura y escribe los datos de todas las instrucciones que están almacenadas en la lista
// Bajar lista
void BajarLista (ListaInstrucciones L , strings NomArch)
{
     FILE * f = fopen (NomArch, "wb");
     while (L != NULL)
     {
         BajarInstruccion(L->info, f);
         L = L->sig;
     }
     fclose (f);
}

// Levantar lista
void LevantarLista (ListaInstrucciones &L, strings NomArch) /* Precondición: El archivo existe */
{
     FILE * f = fopen (NomArch, "rb");
     instruccion buffer;
     LevantarInstruccion(buffer, f);
     while (!feof(f))
     {
         InsBackListaInst(buffer, L);
         LevantarInstruccion(buffer, f);
     }
     fclose (f);
}

/* ********************************************** END .INST ************************************************ */


/* ********************************************** .CSIM ************************************************ */

//Levanta el archivo linea por linea
void LevantarStringsArchivo (strings &s, FILE * f) /* Precondición: El archivo existe */
{
     int i=0;
     strings aux;
     aux = new char[MAX];
     fread (&aux[i], sizeof(char), 1, f);
     while (!feof(f) && aux[i] != '\n')
     {
         i++;
         fread (&aux[i], sizeof(char), 1, f);
     }
     aux[i] = '\0';
     strcop (s, aux);
     delete [] aux;
}

//Genera la lista con las lineas del archivo
void GenerarListaString (ListaStrings &L, strings NomArch)
{
    FILE *f = fopen(NomArch,"rb");
    strings buffer ;
    //Levantar_strings_archivo(buffer,f);

    do
    {
        LevantarStringsArchivo(buffer, f);
        InsBackListaStrings(buffer, L);

    } while (!feof(f));
    fclose (f);
}

/* ********************************************** END .CSIM ************************************************ */
