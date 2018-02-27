#include <stdio.h>
#include "Archivo.h"
#include "ABB_Variables.h"
#include "Lista_Instrucciones.h"
#include "Lista_string.h"

int main ()
{
    variable vari;
    Arbol ar;
    crear(ar);
    strings nombre;
    int val;
    char c;

    if (Existe("arbol.vars") == TRUE)
    {
        Levantar_ABB(ar,"arbol.vars");
        Mostrar_arbol(ar);
    }
    else
    {
        while (c != 'N')
        {
            strcrear(nombre);
            fflush(stdin);
            printf("\nIngrese variable: ");
            scan(nombre);

            fflush(stdin);
            printf("\nIngrese valor: ");
            scanf("%d",&val);

            Cargar_variable(vari,nombre,val);
            cargar_ABBvariable(ar,vari);
            strdestruir(nombre);

            printf("\n");
            Mostrar_arbol(ar);
            printf("\n");

            printf("\nCONTINUAR: ");
            fflush(stdin);
            scanf("%c",&c);
        }
        printf("\n");
        Mostrar_arbol(ar);
    }

    Bajar_ABB(ar,"arbol.vars");

}
