#include <stdio.h>
#include "Comando.h"


int main()
{
    strings comandoEntero;
    strcrear(comandoEntero);
    boolean salir = FALSE;
    do  {
            system("cls");
            printf("\n*******************\n");
            printf("\nIngrese un comando: ");
            fflush(stdin);
            scan(comandoEntero);
            Comando(comandoEntero,salir);
        }while (salir != TRUE);
}
