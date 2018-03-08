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
                    if (LargoListaStrings(comando) == 2)
                    {
                        comando = comando->sig;
                        if ( esStringDeCaracteres(comando->info) == TRUE )
                        {
                            Compilar(comando->info);
                        }
                        else
                        {
                            errorComando = TRUE;
                            printf("\nEl nombre del archivo no contiene solo caracteres\n");
                            system("pause");
                        }
                    }
                    else
                    {
                        printf("\nEl comando no contiene las 2 palabras solicitadas\n");
                        system ("pause");
                    }
                }
            }
            else if ( streq(comando->info,"EJECUTAR")== TRUE)
            {
                {
                    if (LargoListaStrings(comando) == 2)
                    {
                        comando = comando->sig;
                        if ( esStringDeCaracteres(comando->info) == TRUE )
                        {
                            Ejecutar(comando->info);
                        }
                        else
                        {
                            errorComando = TRUE;
                            printf("\nEl nombre del archivo no contiene solo caracteres\n");
                            system("pause");
                        }
                    }
                    else
                    {
                        errorComando = TRUE;
                        printf("\nEl comando no contiene las 2 palabras solicitadas\n");
                        system ("pause");

                    }
                }
             }
            else if ( streq(comando->info,"SALIR")== TRUE)
            {
                if (LargoListaStrings(comando) == 1)
                {
                    salir = TRUE;
                    Salir();
                }
                else
                {
                    errorComando = TRUE;
                    printf("\nComando incorrecto\n");
                    system("pause");
                }
            }
            else
            {
                errorComando = TRUE;
                printf("\nComando incorrecto\n");
                system("pause");
            }
        }
}
