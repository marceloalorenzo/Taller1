

// Cargar la Instruccion
void Cargar_instruccion (instruccion &i);

{
    fflush (stdin);
    strcrear(i.instruccion);
    scan(i.instruccion)
    LLEGA EL ENUM QUE ES EL DISCRIMINANTE, LEER MOSTRAR SALIR
    SI ES LEER CARGO EL STRING, SI ES MOSTRAR TAMBIEN(VAR2)
    Y LLEGA LA FUNCION, VARIABLE, ASIGNACIÓN ETC...
    APLICO LA FUNCION VARIABLE Y VOY A ASIG_VAR

    SI ES LEER
    SI ES MOSTRAR
    SI ES ALGUN TIPO DE ASIGNACION

    caso LEER: strcop(i.variable1,str);
    caso MOSTRAR: strcop(i.variable2,str);
    caso ASIG_VAL: carga_val_asig1(i.asig1,nom,val);
    caso ASIG_VAR: carga_var_asig1(i.asig1,nom,val);


}
//Devolver el tipo de instruccion (LEER, MOSTRAR, ASIG_VAL, ASIG_VAR, FUNC_VALVAL, FUNC_VARVAR, FUNC_VARVAL, FUNC_VALVAR)
tipo_instruccion dar_tipo_inst (instruccion i);

{

}
