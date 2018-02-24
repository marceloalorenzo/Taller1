

// Cargar la Instruccion
void Cargar_instruccion (instruccion &i tipo_instruccion disc);

{

    //evaluo
    switch(disc)

    case LEER:          {
                        strcop(i.variable1,str);
                        }
                        break;
    case MOSTRAR:       {
                        strcop(i.variable2,str);
                        }
                        break;
    case ASIG_VAL:      {
                        carga_var_asig1(i.asig1,str,val);
                        }
                        break;
    case ASIG_VAR:      {
                        carga_var1_asig2(i.asig2,str,val);
                        }
                        break;
    case FUNC_VALVAL:   {
                        cargar_func_asig3(i.asig3,str,tp,p1,p2);
                        }
                        break;
    case FUNC_VARVAR:   {
                        cargar_func_asig4(i.asig4,str,tp,p1,p2);
                        }
                        break;
    case FUNC_VARVAL:   {
                        cargar_func_asig5(i.asig5,str,tp,p1,p2);
                        }
                        break;
    case FUNC_VALVAR:   {
                        cargar_func_asig6(i.asig6,str,tp,p1,p2);
                        }
                        break;
}

//Devolver el tipo de instruccion (LEER, MOSTRAR, ASIG_VAL, ASIG_VAR, FUNC_VALVAL, FUNC_VARVAR, FUNC_VARVAL, FUNC_VALVAR)
tipo_instruccion dar_tipo_inst (instruccion i);

{
    return i.discriminante;
}
