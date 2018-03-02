#include "Lista_Instrucciones.h"
#include "Lista_string.h"
#include "StringDinamico.h"
#include<stdio.h>
#include<stdlib.h>


int main ()
{
    Lista L; //L Se llama Lista
    Crear_Lista(L);//Creo nodo
    strings prueba; //le doy nombre al string
    strcrear(prueba); //creo string llamado prueba
    int opc;

printf("+++++++++++ MENU DE PRUEBA ++++++++++");
printf ("\n1. Leer");
printf ("\n2. Mostrar");
printf ("\n3. Asignación variable");
printf ("\n4. Asignación valor");
printf ("\n5. Asignación variable - variable");
printf ("\n6. Asignación variable - valor");
printf ("\n7. Asignación valor - valor");
printf ("\n8. Asignación valor - variable");
printf ("\n9. Salir del programa.");
printf ("\n\nIngrese una opcion: ");
scanf ("%d",&opc );

    do  {
    switch(opc)
            {
                case 1: printf("LEER: \n");
                        i.discriminante = LEER;
                        printf("Ingrese nombre de variable: ");
                        scan(str);
                        strcop(i.dato_disc.variable1,str);
                        break;
                case 2: printf("MOSTRAR: \n");
                        i.discriminante = MOSTRAR;
                        printf("Ingrese variable a mostrar: ");
                        scan(str);
                        strcop(i.dato_disc.variable2,str);
                        break;
                case 3: printf("Asignación variable: \n");
                        i.discriminante = ASIG_VAR;
                        printf("Ingrese variable a asignar: ");
                        scan(str);
                        printf("Ingrese valor a la variable: ");
                        scan(val);
                        carga_var1_asig2(i.dato_disc.asig2,str,val);
                        break;
                case 4: printf("Asignación valor \n");
                        i.discriminante = ASIG_VAL;
                        printf("Ingrese valor a asignar: ");
                        scan(val);
                        printf("Ingrese variable al valor: ");
                        scan(str);
                        carga_var_asig1(i.dato_disc.asig1,str,val);
                        break;
                case 5: printf("Asignación variable - variable \n");
                        i.discriminante = ASIG_VARVAR;
                        cargar_func_asig4(i.dato_disc.asig4,str,tp,p1,p2);
                        break;
                case 6: printf("Asignación variable - valor \n");
                        i.discriminante = ASIG_VARVAL;
                        cargar_func_asig5(i.dato_disc.asig5,str,tp,p1,p2);
                        break;
                case 7: printf("Asignación valor - valor \n");
                        i.discriminante = ASIG_VALVAL;
                        cargar_func_asig3(i.dato_disc.asig3,str,tp,p1,p2);
                        break;
                case 8: printf("Asignación valor - variable \n");
                        i.discriminante = ASIG_VALVAR;
                        cargar_func_asig6(i.dato_disc.asig6,str,tp,p1,p2);
                        break;
            }
        }while (opc1 != 9);


}
