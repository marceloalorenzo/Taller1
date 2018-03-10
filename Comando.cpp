#include "Comando.h"

void Comando (strings str, boolean &salir)
{
    ListaStrings comando;
    CrearListaStrings(comando);

    Parseo(str,comando);

    boolean errorComando = FALSE;
    while (comando != NULL && errorComando != TRUE && salir != TRUE)
    {
        if ( streq(comando->info,"COMPILAR")== TRUE)
        {
            {
                comando = comando->sig;
                if (LargoListaStrings(comando) == 1)
                {
                    if ( esStringDeCaracteres(comando->info) == TRUE )
                    {
                        Compilar(comando->info);
                        comando = comando->sig;
                    }
                    else
                    {
                        errorComando = TRUE;
                        printf("\n\nError en comando: El nombre del archivo ''");
                        print(comando->info);
                        printf("'' no contiene solo caracteres\n\n");
                        system("pause");
                    }
                }
                else
                {
                    errorComando = TRUE;
                    printf("\n\nError en comando: El nombre del archivo para compilar no se ingreso o posee mas de una palabra\n\n");
                    system("pause");
                }
            }
        }
        else
        {
            if ( streq(comando->info,"EJECUTAR")== TRUE)
            {
                comando = comando->sig;
                if (LargoListaStrings(comando) == 1)
                {
                    if ( esStringDeCaracteres(comando->info) == TRUE )
                    {
                        Ejecutar(comando->info);
                        comando = comando->sig;
                    }
                    else
                    {
                        errorComando = TRUE;
                        printf("\n\nError en comando: El nombre del archivo ''");
                        print(comando->info);
                        printf("'' no contiene solo caracteres\n\n");
                        system("pause");
                    }
                }
                else
                {
                    errorComando = TRUE;
                    printf("\n\nError en comando: El nombre del archivo para ejecutar no se ingreso o posee mas de una palabra\n\n");
                    system("pause");
                }
            }
            else
            {
                if ( streq(comando->info,"SALIR")== TRUE)
                {
                    if (LargoListaStrings(comando) == 1)
                    {
                        salir = TRUE;
                        Salir();
                    }
                    else
                    {
                        errorComando = TRUE;
                        printf("\n\nError en comando: El Comando indicado no es correcto\n\n");
                        system("pause");
                    }
                }
                else
                {
                    errorComando = TRUE;
                    printf("\n\nComando incorrecto\n\n");
                    system("pause");
                }
            }
        }
    }
}
