#include "Lista_Instrucciones.h"
#include "Lista_string.h"
#include "StringDinamico.h"
#include <stdio.h>
#include <stdlib.h>
#include "Archivo.h"


int main ()
{
    ListaInstrucciones L; //L Se llama Lista
    CrearListaInst(L);//Creo nodo
    strings prueba; //le doy nombre al string
    strcrear(prueba); //creo string llamado prueba
    instruccion ins;
    int opc;
    char c;


    LevantarLista(L,"prueba.inst");
    MostrarListaInstrucciones(L);


    while (c != 'N')
    {
        printf("+++++++++++ MENU DE PRUEBA ++++++++++");
        printf ("\n1. Leer");
        printf ("\n2. Mostrar");
        printf ("\n3. Asignación variable");
        printf ("\n4. Asignación valor");
        printf ("\n5. Asignación Funcion variable - variable");
        printf ("\n6. Asignación Funcion variable - valor");
        printf ("\n7. Asignación Funcion valor - valor");
        printf ("\n8. Asignación Funcion valor - variable");
        printf ("\n9. Salir del programa.");
        printf ("\n\nIngrese una opcion: ");
        scanf ("%d",&opc );

        switch(opc)
            {
                case 1: {
                        printf("\n\nLEER \n");
                        tipoInstruccion tp = LEER;
                        strings var;
                        strcrear(var);
                        fflush(stdin);
                        printf("\n\nIngrese nombre de variable: ");
                        scan(var);
                        CargarInsLeerMostrar(ins,tp,var);
                        }
                        break;
                case 2: {
                        printf("\n\nMOSTRAR\n");
                        tipoInstruccion tp = MOSTRAR;
                        strings var;
                        strcrear(var);
                        fflush(stdin);
                        printf("\n\nIngrese nombre de variable: ");
                        scan(var);
                        CargarInsLeerMostrar(ins,tp,var);
                        }
                        break;
                case 3: {
                        printf("\n\nAsignación variable\n");
                        strings variable1;
                        strcrear(variable1);
                        fflush(stdin);
                        printf("\n\nIngrese variable 1: ");
                        scan(variable1);
                        strings variable2;
                        strcrear(variable2);
                        fflush(stdin);
                        printf("\n\nIngrese variable 2: ");
                        scan(variable2);
                        CargarInsAsigVar(ins,variable1,variable2);
                        strdestruir(variable1);
                        strdestruir(variable2);
                        }
                        break;
                case 4: {
                        printf("\n\nAsignación valor \n");
                        strings var;
                        strcrear(var);
                        fflush(stdin);
                        printf("\n\nIngrese variable: ");
                        scan(var);
                        int val;
                        fflush(stdin);
                        printf("\n\nIngrese valor: ");
                        scanf("%d",&val);
                        CargarInsAsigVal(ins,var,val);
                        strdestruir(var);
                        }
                        break;
                case 5: {
                        printf("\n\nAsignación func variable - variable \n");
                        strings var;
                        strcrear(var);
                        fflush(stdin);
                        printf("\n\nIngrese variable: ");
                        scan(var);
                        strings p1;
                        strcrear(p1);
                        fflush(stdin);
                        printf("\n\nIngrese param1: ");
                        scan(p1);
                        strings p2;
                        strcrear(p2);
                        fflush(stdin);
                        printf("\n\nIngrese param2: ");
                        scan(p2);
                        int i;
                        tipoFuncion fun;
                        fflush(stdin);
                        printf("\n\nIngrese opcion:\n1-SUM\n2-RES\n3-MUL\n4-DIV\n\n OPCION: ");
                        scanf("%d",&i);
                        switch (i)
                        {
                            case 1: fun = SUM;
                            break;
                            case 2: fun = RES;
                            break;
                            case 3: fun = MUL;
                            break;
                            case 4: fun = DIV;
                            break;
                        }
                        CargarInsFuncVarVar(ins,var,fun,p1,p2);
                        strdestruir(var);
                        strdestruir(p1);
                        strdestruir(p2);
                        }
                        break;
                case 6: {
                        printf("\n\nAsignación func variable - valor \n");
                        strings var;
                        strcrear(var);
                        fflush(stdin);
                        printf("\n\nIngrese variable: ");
                        scan(var);
                        strings p1;
                        strcrear(p1);
                        fflush(stdin);
                        printf("\n\nIngrese param1: ");
                        scan(p1);
                        int p2;
                        fflush(stdin);
                        printf("\n\nIngrese param2: ");
                        scanf("%d",&p2);
                        int i;
                        tipoFuncion fun;
                        fflush(stdin);
                        printf("\n\nIngrese opcion:\n1-SUM\n2-RES\n3-MUL\n4-DIV\n\n OPCION: ");
                        scanf("%d",&i);
                        switch (i)
                        {
                            case 1: fun = SUM;
                            break;
                            case 2: fun = RES;
                            break;
                            case 3: fun = MUL;
                            break;
                            case 4: fun = DIV;
                            break;
                        }
                        CargarInsFuncVarVal(ins,var,fun,p1,p2);
                        strdestruir(var);
                        strdestruir(p1);
                        }
                        break;
                case 7: {
                        printf("\n\nAsignación func valor - valor \n");
                        strings var;
                        strcrear(var);
                        fflush(stdin);
                        printf("\n\nIngrese variable: ");
                        scan(var);
                        int p1;
                        fflush(stdin);
                        printf("\n\nIngrese param1: ");
                        scanf("%d",&p1);
                        int p2;
                        fflush(stdin);
                        printf("\n\nIngrese param2: ");
                        scanf("%d",&p2);
                        int i;
                        tipoFuncion fun;
                        fflush(stdin);
                        printf("\n\nIngrese opcion:\n1-SUM\n2-RES\n3-MUL\n4-DIV\n\n OPCION: ");
                        scanf("%d",&i);
                        switch (i)
                        {
                            case 1: fun = SUM;
                            break;
                            case 2: fun = RES;
                            break;
                            case 3: fun = MUL;
                            break;
                            case 4: fun = DIV;
                            break;
                        }
                        CargarInsFuncValVal(ins,var,fun,p1,p2);
                        }
                        break;
                case 8: {
                        printf("\n\nAsignación func valor - variable \n");
                        strings var;
                        strcrear(var);
                        fflush(stdin);
                        printf("\n\nIngrese variable: ");
                        scan(var);
                        int p1;
                        fflush(stdin);
                        printf("\n\nIngrese param1: ");
                        scanf("%d",&p1);
                        strings p2;
                        strcrear(p2);
                        fflush(stdin);
                        printf("\n\nIngrese param2: ");
                        scan(p2);
                        int i;
                        tipoFuncion fun;
                        fflush(stdin);
                        printf("\n\nIngrese opcion:\n1-SUM\n2-RES\n3-MUL\n4-DIV\n\n OPCION: ");
                        scanf("%d",&i);
                        switch (i)
                        {
                            case 1: fun = SUM;
                            break;
                            case 2: fun = RES;
                            break;
                            case 3: fun = MUL;
                            break;
                            case 4: fun = DIV;
                            break;
                        }
                        CargarInsFuncValVar(ins,var,fun,p1,p2);
                        }
                        break;
            }
            InsBackListaInst(ins,L);

            fflush(stdin);
            printf("\n\nCONTINUAR??: ");
            scanf("%c",&c);
    }

    MostrarListaInstrucciones(L);

    BajarLista(L,"prueba.inst");
}
