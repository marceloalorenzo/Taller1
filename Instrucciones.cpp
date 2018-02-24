

// Cargar la Instruccion
void Cargar_instruccion (instruccion &i tipo_instruccion disc);

{
    /*
    LLEGA EL ENUM QUE ES EL DISCRIMINANTE, LEER MOSTRAR SALIR
    SI ES LEER CARGO EL STRING, SI ES MOSTRAR TAMBIEN(VAR2)
    Y LLEGA LA FUNCION, VARIABLE, ASIGNACIÓN ETC...
    APLICO LA FUNCION VARIABLE Y VOY A ASIG_VAR

    SI ES LEER
    SI ES MOSTRAR
    SI ES ALGUN TIPO DE ASIGNACION

*/
    //evaluo
    switch(disc)

    case LEER:          {
                        strcop(i.variable1,str);//str
                        }
                        break;
    case MOSTRAR:       {
                        strcop(i.variable2,str);//str
                        }
                        break;
    case ASIG_VAL:      {
                        carga_var_asig1(i.asig1,str,val)//
                        }
                        break;
    case ASIG_VAR:      {
                        carga_var1_asig2(i.asig2,str,val)//
                        }
                        break;
    case FUNC_VALVAL:   {
                        cargar_func_asig3(i.asig3,str,tp,p1,p2)
                        }
                        break;
    case FUNC_VARVAR:   {
                        cargar_func_asig4(i.asig4,str,tp,p1,p2)
                        }
                        break;
    case FUNC_VARVAL:   {
                        cargar_func_asig5(i.asig5,str,tp,p1,p2)
                        }
                        break;
    case FUNC_VALVAR:   {
                        cargar_func_asig6(i.asig6,str,tp,p1,p2)
                        }
                        break;
}

//Devolver el tipo de instruccion (LEER, MOSTRAR, ASIG_VAL, ASIG_VAR, FUNC_VALVAL, FUNC_VARVAR, FUNC_VARVAL, FUNC_VALVAR)
tipo_instruccion dar_tipo_inst (instruccion i);

{
    return i.discriminante;
}
