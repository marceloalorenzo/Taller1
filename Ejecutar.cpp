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
                case FUNCVALVAR:
                                {

                                }
                                break;
        }
    else
        {
        printf("ERROR, no existen uno de los archivos .csim o .vars");
        }









}

