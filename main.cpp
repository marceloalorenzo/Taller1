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
printf ("\n3. Asignaci�n variable");
printf ("\n4. Asignaci�n valor");
printf ("\n5. Asignaci�n variable - variable");
printf ("\n6. Asignaci�n variable - valor");
printf ("\n7. Asignaci�n valor - valor");
printf ("\n8. Asignaci�n valor - variable");
printf ("\n9. Salir del programa.");
printf ("\n\nIngrese una opcion: ");
scanf ("%d",&opc );

    do  {
    switch(opc)
            {
                case 1: printf("LEER: \n");
                        strcop(i.dato_disc.variable1,str);
                        break;
                case 2: printf("MOSTRAR: \n");
                        strcop(i.dato_disc.variable2,str);
                        break;
                case 3: printf("Asignaci�n variable: \n");
                        carga_var1_asig2(i.dato_disc.asig2,str,val);
                        break;
                case 4: printf("Asignaci�n valor \n");
                        carga_var_asig1(i.dato_disc.asig1,str,val);
                        break;
                case 5: printf("Asignaci�n variable - variable \n");
                        cargar_func_asig4(i.dato_disc.asig4,str,tp,p1,p2);
                        break;
                case 6: printf("Asignaci�n variable - valor \n");
                        cargar_func_asig5(i.dato_disc.asig5,str,tp,p1,p2);
                        break;
                case 7: printf("Asignaci�n valor - valor \n");
                        cargar_func_asig3(i.dato_disc.asig3,str,tp,p1,p2);
                        break;
                case 8: printf("Asignaci�n valor - variable \n");
                        cargar_func_asig6(i.dato_disc.asig6,str,tp,p1,p2);
                        break;
            }
        }while (opc1 != 9);


}
