#include "Archivo.h"

/* ********************************************** GENERALES ************************************************ */

// Determina si existe o no un archivo con el nombre recibido por parámetro
boolean Existe(strings nomArch)
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
boolean Vacio (strings nomArch) /* Precondición: El archivo existe */
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
int Largo (strings nomArch) /* Precondición: El archivo existe */
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
void Bajar_strings (strings s, FILE * f) /* Precondición: El archivo viene abierto para escritura*/
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
void Levantar_strings (strings &s, FILE * f) /* Precondición: El archivo viene abierto para lectura.*/
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
void Bajar_variable (variable v, FILE * f) /* Precondición: El archivo viene abierto para escritura. */
{
    Bajar_strings (v.var, f);
    fwrite (&v.valor, sizeof(int), 1, f);
}

// Lee desde el archivo los datos de la variable.
void Levantar_variable (variable &v, FILE * f) /* Precondición: El archivo viene abierto para lectura. */
{
    strcrear(v.var);
    Levantar_strings(v.var,f);
    fread(&v.valor, sizeof(int),1,f);
}

// Auxiliar ABB Variables
// Escribe en el archivo los datos de todas las variables del árbol en forma recursiva.
void Bajar_ABB_Aux (Arbol a, FILE * f) /* PRECONDICION: El archivo viene abierto para escritura. */
{
     if (a != NULL)
     {
         Bajar_variable(a->info,f);
         Bajar_ABB_Aux (a->hizq, f);
         Bajar_ABB_Aux (a->hder, f);
     }
}

// Abre el archivo para escritura y escribe los datos de todas las variables del árbol (llamando al procedimiento anterior)
// ABB Variables
void Bajar_ABB (Arbol a, strings NomArch)
{
 FILE * f = fopen (NomArch, "wb");
 Bajar_ABB_Aux (a, f);
 fclose (f);
}

// Abre el archivo para lectura e inserta en el árbol todas las variables que están en el archivo (llamando al procedimiento ArbolABB).
//Levantar Arbol de busqueda binario
void Levantar_ABB (Arbol &a, strings NomArch) /* PRECONDICION: El archivo existe. */
{
     FILE * f = fopen (NomArch, "rb");
     variable buffer;
     Levantar_variable(buffer, f);
     while (!feof(f))
     {
         cargar_ABBvariable(a, buffer);
         Levantar_variable(buffer, f);
     }
     fclose (f);
}

/* ********************************************** END .VARS ************************************************ */

/* ********************************************** .INST ************************************************ */

//INSTRUCCION
//Escribe en el archivo los datos de instruccion
void Bajar_instruccion (instruccion i, FILE * f) /* Precondición: El archivo viene abierto para escritura */
{
    fwrite(&i.discriminante, sizeof(tipo_instruccion), 1, f);
    switch (i.discriminante)
    {
        case 'LEER':
            {
                Bajar_strings(i.dato_disc.variable1,f);
            }
            break;
        case 'MOSTRAR':
            {
                Bajar_strings(i.dato_disc.variable2,f);
            }
            break;
        case 'ASIG_VAL':
            {
                Bajar_strings(i.dato_disc.asig1.var_asig,f);
                fwrite(&i.dato_disc.asig1.val_asig, sizeof(int), 1, f);
            }
            break;
        case 'ASIG_VAR':
            {
                Bajar_strings(i.dato_disc.asig2.var1,f);
                Bajar_strings(i.dato_disc.asig2.var2,f);
            }
            break;
        case 'FUNC_VALVAL':
            {
                Bajar_strings(i.dato_disc.asig3.var_asig,f);
                fwrite(&i.dato_disc.asig3.funcion, sizeof(tipo_funcion), 1, f);
                fwrite(&i.dato_disc.asig3.param1, sizeof(int), 1, f);
                fwrite(&i.dato_disc.asig3.param2, sizeof(int), 1, f);
            }
            break;
        case 'FUNC_VARVAR':
            {
                Bajar_strings(i.dato_disc.asig4.variable,f);
                fwrite(&i.dato_disc.asig4.funcion, sizeof(tipo_funcion), 1, f);
                Bajar_strings(i.dato_disc.asig4.param1,f);
                Bajar_strings(i.dato_disc.asig4.param2,f);
            }
            break;
        case 'FUNC_VARVAL':
            {
                Bajar_strings(i.dato_disc.asig5.variable,f);
                fwrite(&i.dato_disc.asig5.funcion, sizeof(tipo_funcion), 1, f);
                Bajar_strings(i.dato_disc.asig5.param1,f);
                fwrite(&i.dato_disc.asig5.param2, sizeof(int), 1, f);
            }
            break;
        case 'FUNC_VALVAR':
            {
                Bajar_strings(i.dato_disc.asig6.variable,f);
                fwrite(&i.dato_disc.asig6.funcion, sizeof(tipo_funcion), 1, f);
                fwrite(&i.dato_disc.asig6.param1, sizeof(int), 1, f);
                Bajar_strings(i.dato_disc.asig6.param2,f);
            }
            break;
    }
}
// Lee desde el archivo los datos de la habilitad h.
void Levantar_instruccion (instruccion &i, FILE * f) /* Precondición: El archivo viene abierto para lectura. */
{
    fread(&i.discriminante, sizeof(tipo_instruccion), 1, f);
    switch (i.discriminante)
    {
        case 'LEER':
            {
                strcrear(i.dato_disc.variable1);
                Levantar_strings(i.dato_disc.variable1,f);
            }
            break;
        case 'MOSTRAR':
            {
                strcrear(i.dato_disc.variable2);
                Levantar_strings(i.dato_disc.variable2,f);
            }
            break;
        case 'ASIG_VAL':
            {
                strcrear(i.dato_disc.asig1.var_asig);
                Levantar_strings(i.dato_disc.asig1.var_asig,f);
                fread(&i.dato_disc.asig1.val_asig, sizeof(int), 1, f);
            }
            break;
        case 'ASIG_VAR':
            {
                strcrear(i.dato_disc.asig2.var1);
                Levantar_strings(i.dato_disc.asig2.var1,f);
                strcrear(i.dato_disc.asig2.var2);
                Levantar_strings(i.dato_disc.asig2.var2,f);
            }
            break;
        case 'FUNC_VALVAL':
            {
                strcrear(i.dato_disc.asig3.var_asig);
                Levantar_strings(i.dato_disc.asig3.var_asig,f);
                fread(&i.dato_disc.asig3.funcion, sizeof(tipo_funcion), 1, f);
                fread(&i.dato_disc.asig3.param1, sizeof(int), 1, f);
                fread(&i.dato_disc.asig3.param2, sizeof(int), 1, f);
            }
            break;
        case 'FUNC_VARVAR':
            {
                strcrear(i.dato_disc.asig4.variable);
                Levantar_strings(i.dato_disc.asig4.variable,f);
                fread(&i.dato_disc.asig4.funcion, sizeof(tipo_funcion), 1, f);
                strcrear(i.dato_disc.asig4.param1);
                Levantar_strings(i.dato_disc.asig4.param1,f);
                strcrear(i.dato_disc.asig4.param2);
                Levantar_strings(i.dato_disc.asig4.param2,f);
            }
            break;
        case 'FUNC_VARVAL':
            {
                strcrear(i.dato_disc.asig5.variable);
                Levantar_strings(i.dato_disc.asig5.variable,f);
                fread(&i.dato_disc.asig5.funcion, sizeof(tipo_funcion), 1, f);
                strcrear(i.dato_disc.asig5.param1);
                Levantar_strings(i.dato_disc.asig5.param1,f);
                fread(&i.dato_disc.asig5.param2, sizeof(int), 1, f);
            }
            break;
        case 'FUNC_VALVAR':
            {
                strcrear(i.dato_disc.asig6.variable);
                Levantar_strings(i.dato_disc.asig6.variable,f);
                fread(&i.dato_disc.asig6.funcion, sizeof(tipo_funcion), 1, f);
                fread(&i.dato_disc.asig6.param1, sizeof(int), 1, f);
                strcrear(i.dato_disc.asig6.param2);
                Levantar_strings(i.dato_disc.asig6.param2,f);
            }
            break;
    }
}

//LISTA
// Abre el archivo para escritura y escribe los datos de todas las instrucciones que están almacenadas en la lista
// Bajar lista
void Bajar_Lista (Lista L , strings NomArch)
{
     FILE * f = fopen (NomArch, "wb");
     while (L != NULL)
     {
         Bajar_instruccion(L->info, f);
         L = L->sig;
     }
     fclose (f);
}

// Levantar lista
void Levantar_Lista (Lista &L, strings NomArch) /* Precondición: El archivo existe */
{
     FILE * f = fopen (NomArch, "rb");
     instruccion buffer;
     Levantar_instruccion(buffer, f);
     while (!feof(f))
     {
         InsBack(buffer, L);
         Levantar_instruccion(buffer, f);
     }
     fclose (f);
}

/* ********************************************** END .INST ************************************************ */


/* ********************************************** .CSIM ************************************************ */

//Levanta el archivo linea por linea
void Levantar_strings_archivo (strings &s, FILE * f) /* Precondición: El archivo existe */
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
void Generar_Lista_String (Lista_strings &L, strings NomArch)
{
    FILE *f = fopen(NomArch,"rb");
    strings buffer ;
    //Levantar_strings_archivo(buffer,f);

    do
    {
        Levantar_strings_archivo(buffer, f);
        InsBack2(buffer, L);

    } while (!feof(f));
    fclose (f);
}

/* ********************************************** END .CSIM ************************************************ */
