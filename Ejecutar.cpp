#include "Ejecutar.h"


void Ejecutar (strings str)


{
    ListaStrings listaEjecucion;
    strings auxVARS;
    strcrear(auxVARS);
    strcop(auxVARS,str);
    strcon(auxVARS,VARS);
    strings auxINST;
    strcrear (auxINST);
    strcop (auxINST,str);
    strcon (auxINST, INST);



    if ExisteArchivo(auxVARS)&&(auxINST) //veo si existen los dos archivos con las extensiones solicitadas
        {
         ArbolVariables variables;
         ListaInstrucciones instrucciones;
         crearABBvariable(variables);
         CrearListaInst(instrucciones);
         LevantarAbb(auxVARS);
         LevantarLista(instrucciones);

            while ( variables != NULL) //mientras la liesta no sea nula ingreso al nodo
            {

                switch (dar_tipo_inst(variables->info))
              //obtengo el dato cargado en el discriminante
                case LEER:  //Obtengo el nombre de la variable guardada en la compilación
                                {//agregar control con while
                                    int lectura;
                                    printf("\nIngrese un numero entero: ");
                                    scanf("%d", &lectura);
                                    CargarValorVariable(variables,instrucciones->info.datoDisc.variable1,lectura);//
                                }
                                break;
                case MOSTRAR:
                                {
                                    MostrarValorVariable(variables,instrucciones->info.datoDisc.variable2);

                                }
                                break;
                case ASIGVAL:
                                {
                                    CargarValorVariable(variables,instrucciones->info.datoDisc.asig1.varAsig,instrucciones->info.datoDisc.asig1.valAsig);


                                }
                                break;
                case ASIGVAR:
                                {
                                CargarValorVariable(variables,instrucciones->info.datoDisc.asig2.var1,instrucciones->info.datoDisc.asig2.var2);
                                }
                                break;
                case FUNCVALVAL:
                                {
                                //segun tipo de funcion
                                //
                                switch(tipoFuncion)
                                case SUM:
                                            {
                                                Obtengo datos guardados en param1 y param2
                                                Realizo la suma de param1 + param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior

                                                int auxParam;
                                                auxParam = param1 + param2;
                                                darVarAsig3()

                                            }
                                            break;
                                case RES:
                                            {
                                                Obtengo datos guardados en param1 y param2
                                                Realizo la resta de param1 - param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case MUL:
                                            {
                                                Obtengo datos guardados en param1 y param2
                                                Realizo la multiplicación de param1 * param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case DIV:
                                            {
                                                Obtengo el dato guardado en param2

                                                SI	param2 es igual a cero	ENTONCES
                                                    Error de ejecución (El segundo término no puede ser cero)
                                                    Finalizo ejecución
                                                SINO
                                                    Obtengo el dato guardado en param1
                                                    Realizo la división de param1 / param2
                                                    Guardo el valor en un auxiliar
                                                    Obtengo el nombre de la variable del campo variable
                                                    Busco en el ABB la variable
                                                    Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                                FIN SI
                                            }
                                            break;


                                }
                                break;
                case FUNCVARVAR:
                                {
                                     switch(tipoFuncion)
                                case SUM:
                                            {
                                                Obtengo los nombres de las variables guardados en param1 y param2
                                                Busco en el ABB el valor guardado para la variable del param1
                                                Busco en el ABB el valor guardado para la variable del param2
                                                Realizo la suma de param1 + param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case RES:
                                            {
                                                Obtengo los nombres de las variables guardados en param1 y param2
                                                Busco en el ABB el valor guardado para la variable del param1
                                                Busco en el ABB el valor guardado para la variable del param2
                                                Realizo la resta de param1 - param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case MUL:
                                            {
                                                Obtengo los nombres de las variables guardados en param1 y param2
                                                Busco en el ABB el valor guardado para la variable del param1
                                                Busco en el ABB el valor guardado para la variable del param2
                                                Realizo la multiplicación de param1 * param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case DIV:
                                            {
                                                Obtengo el nombre de la variable guardada en param2
                                                Busco en el ABB el valor guardado para la variable del param2

                                                SI	param2 es igual a cero	ENTONCES
                                                    Error de ejecución (El segundo término no puede ser cero)
                                                    Finalizo ejecución
                                                SINO
                                                    Obtengo el nombre de la variable guardada en param1
                                                    Busco en el ABB el valor guardado para la variable del param1
                                                    Realizo la división de param1 / param2
                                                    Guardo el valor en un auxiliar
                                                    Obtengo el nombre de la variable del campo variable
                                                    Busco en el ABB la variable
                                                    Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                                FIN SI

                                            }
                                            break;
                                }
                                break;
                case FUNCVARVAL:
                                {
                                     switch(tipoFuncion)
                                case SUM:
                                            {
                                                Obtengo el nombre de la variable guardada en param1
                                                Busco en el ABB el valor guardado para la variable del param1
                                                Realizo la suma de param1 + param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case RES:
                                            {
                                                Obtengo el nombre de la variable guardada en param1
                                                Busco en el ABB el valor guardado para la variable del param1
                                                Realizo la resta de param1 - param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case MUL:
                                            {
                                                Obtengo el nombre de la variable guardada en param1
                                                Busco en el ABB el valor guardado para la variable del param1
                                                Realizo la multiplicación de param1 * param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case DIV:
                                            {
                                            SI	param2 es igual a cero	ENTONCES
                                                Error de ejecución (El segundo término no puede ser cero)
                                                Finalizo ejecución
                                            SINO
                                                Obtengo el nombre de la variable guardada en param1
                                                Busco en el ABB el valor guardado para la variable del param1
                                                Realizo la división de param1 / param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            FIN SI
                                            }
                                            break;
                                }
                                break;
                case FUNCVALVAR:
                                {
                                     switch(tipoFuncion)
                                case SUM:
                                            {
                                                Obtengo el nombre de la variable guardada en param2
                                                Busco en el ABB el valor guardado para la variable del param2
                                                Realizo la suma de param1 + param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case RES:
                                            {
                                                Obtengo el nombre de la variable guardada en param
                                                Busco en el ABB el valor guardado para la variable del param2
                                                Realizo la resta de param1 - param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case MUL:
                                            {
                                                Obtengo el nombre de la variable guardada en param2
                                                Busco en el ABB el valor guardado para la variable del param2
                                                Realizo la multiplicación de param1 * param2
                                                Guardo el valor en un auxiliar
                                                Obtengo el nombre de la variable del campo variable
                                                Busco en el ABB la variable
                                                Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                            }
                                            break;
                                case DIV:
                                            {
                                                Obtengo el nombre de la variable guardada en param2
                                                Busco en el ABB el valor guardado para la variable del param2

                                                SI	param2 es igual a cero	ENTONCES
                                                    Error de ejecución (El segundo término no puede ser cero)
                                                    Finalizo ejecución
                                                SINO
                                                    Realizo la división de param1 / param2
                                                    Guardo el valor en un auxiliar
                                                    Obtengo el nombre de la variable del campo variable
                                                    Busco en el ABB la variable
                                                    Guardo en el campo valor de la variable en el ABB el resultado de la suma anterior
                                                FIN SI
                                            }
                                            break;
                                }
                                break;

            }
    else
        {
        printf("ERROR, no existen uno de los archivos .csim o .vars");
        }









}

