#include "Archivo.h"


// Agrega el nuevo entero al final del archivo
void Agregar (strings nomArch, int entero)
{
    FILE *f;
    f=fopen(nomArch,"ab");
    fwrite(&entero,sizeof(int),1,f);
    fclose(f);
}
// Determina si existe o no un archivo con el nombre recibido por parámetro
boolean Existe(strings nomArch)
{
    boolean es=TRUE;
    FILE *f;
    f=fopen(nomArch,"rb");
    if(f==NULL)
        es=FALSE;
    else
        fclose(f);

    return es;
}

// Determina si el archivo está vacío o no.
// Precondición: El archivo existe
boolean Vacio (strings nomArch)
{
    boolean res=FALSE;
    FILE *f=fopen(nomArch,"rb");
    fseek(f,0,SEEK_END);
    if(ftell(f)==0)
        res=TRUE;
    fclose(f);
    return res;
}
// Determina si el entero recibido está en el archivo.
// Precondición: El archivo existe
boolean Pertenece (strings nomArch, int entero)
{
    boolean encontre=FALSE;
    int num;
    FILE *f=fopen(nomArch,"rb");
    fread(&num,sizeof(int),1,f);

    while(encontre!=TRUE && !feof(f))
    {
        if(num==entero)
            encontre=TRUE;
        else
            fread(&num,sizeof(int),1,f);
    }
    fclose(f);
    return encontre;
}
// Devuelve la cantidad de enteros almacenados en el archivo.
// Precondición: El archivo existe
int Largo (strings nomArch)
{
    int largoArch;
    FILE *f=fopen(nomArch,"rb");
    fseek(f,0,SEEK_END);
    largoArch=ftell(f)/sizeof(int);
    fclose(f);
    return largoArch;
}
// Devuelve el k-ésimo entero almacenado en el archivo.
// Precondición: El archivo existe y su largo es ≥ k.
int K_esimo (strings nomArch, int k)
{
    int buffer;
    FILE *f=fopen(nomArch,"rb");
    fseek(f,(k-1)*sizeof(int),SEEK_SET);
    fread(&buffer,sizeof(int),1,f);
    fclose(f);
    return buffer;
}

//STRINGS
// Escribe en el archivo los caracteres del string s (incluido '\0')
// Precondición: El archivo viene abierto para escritura.
void Bajar_strings (strings s, FILE * f) /* Módulo String */
{
     int i=0;
     while (s[i] != '\0')
     {
         fwrite (&s[i], sizeof(char), 1, f);
         i++;
     }
     // escribo el '\0'
     fwrite (&s[i], sizeof(char), 1, f);
}
// Lee desde el archivo los caracteres del string s.
// Precondición: El archivo viene abierto para lectura.
void Levantar_strings (strings &s, FILE * f) /* Módulo String */
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
     strcop (s, aux);
     delete [] aux;
}
//SOCIO
// Escribe en el archivo los datos del socio s.
// Precondición: El archivo viene abierto para escritura.
void Bajar_socio (socio s, FILE * f) /* Módulo Socio */
{
     fwrite (&s.ced_magic, sizeof(long int), 1, f);
     Bajar_strings (s.nombre, f);
     Bajar_strings (s.origen, f);
     fwrite (&s.cat_magica, sizeof(catmagica), 1, f);
     fwrite (&s.fecha_nac, sizeof(fecha), 1, f);
}

// Lee desde el archivo los datos de la socio s.
// Precondición: El archivo viene abierto para lectura.
void Levantar_socio (socio &s, FILE * f) /* Módulo Socio */
{
     strcrear(s.nombre);
     strcrear(s.origen);
     fread (&s.ced_magic, sizeof(long int), 1, f);
     Levantar_strings (s.nombre, f);
     Levantar_strings (s.origen, f);
     fread (&s.cat_magica, sizeof(catmagica), 1, f);
     fread(&s.fecha_nac,sizeof(fecha),1,f);
}

//HABILIDAD
//Escribe en el archivo los datos de habilidad h
//Precondición: El archivo viene abierto para escritura
void Bajar_habilidad (habilidades h, FILE * f) /* Módulo habilidad */
{
    Bajar_strings(h.habilidad, f);
    fwrite (&h.fecha_manif, sizeof(fecha), 1, f);
    fwrite (&h.Ced_magica, sizeof(long int), 1, f);
    fwrite (&h.tipo, sizeof(tipo_habilidad), 1, f);
}
// Lee desde el archivo los datos de la habilitad h.
// Precondición: El archivo viene abierto para lectura.
void Levantar_habilidad (habilidades &h, FILE * f) /* Módulo habilidad */
{
    strcrear(h.habilidad);
    Levantar_strings(h.habilidad, f);
    fread (&h.fecha_manif, sizeof(fecha), 1, f);
    fread (&h.Ced_magica, sizeof(long int), 1, f);
    fread (&h.tipo, sizeof(tipo_habilidad), 1, f);
}
//ABB Socios
// Escribe en el archivo los datos de todas los socios del árbol
// en forma recursiva.
// PRECONDICION: El archivo viene abierto para escritura.
void Bajar_ABB_Aux (Arbol a, FILE * f)
{
     if (a != NULL)
     {
         //fwrite (&(a -> info), sizeof (int), 1, f);
         //Se llama a la función que guarda un socio a archivo y usar como parametro
        //a a->info
         Bajar_socio(a->info,f);
         Bajar_ABB_Aux (a -> hizq, f);
         Bajar_ABB_Aux (a -> hder, f);
     }
}
// Abre el archivo para escritura y escribe los datos de todas los socios
// del árbol (llamando al procedimiento anterior)
//Bajar Arbol de busqueda binario
void Bajar_ABB (Arbol a, strings NomArch)
{
 FILE * f = fopen (NomArch, "wb");
 Bajar_ABB_Aux (a, f);
 fclose (f);
}
// Abre el archivo para lectura e inserta en el árbol todos los socios que están en el archivo (llamando al procedimiento ArbolABB).
// PRECONDICION: El archivo existe.
//Levantar Arbol de busqueda binario
void Levantar_ABB (Arbol &a, strings NomArch)
{
     FILE * f = fopen (NomArch, "rb");
     socio buffer;
     Levantar_socio(buffer, f);
     while (!feof(f))
     {
         cargar_socios (a, buffer);
         Levantar_socio(buffer, f);
     }
     fclose (f);
}
//LISTA
// Abre el archivo para escritura y escribe los datos de todos los socios
// que están almacenadas en la lista
//Bajar lista
void Bajar_Lista (Lista L , strings NomArch) // Módulo Lista
{
     FILE * f = fopen (NomArch, "wb");
     while (L != NULL)
     {
         Bajar_habilidad(L->info, f);
         L = L->sig;
     }
     fclose (f);
}

//Levantar lista
void Levantar_Lista (Lista &L, strings NomArch) // Módulo Lista
{
     FILE * f = fopen (NomArch, "rb");
     habilidades buffer ;
     Levantar_habilidad(buffer, f);
     while (!feof(f))
     {
         InsBack (buffer, L);
         Levantar_habilidad (buffer, f);
     }
     fclose (f);
}






