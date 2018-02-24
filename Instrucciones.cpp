

// Cargar la Instruccion
void Cargar_instruccion (instruccion &i);

{
    /*
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
*/

    //recibo el enumerado, que es el discriminante
    scan(tipo_instruccion);
    //evaluo
    switch(tipo_instruccion)

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
                        }
                        break;
    case FUNC_VARVAR:   {
                        }
                        break;
    case FUNC_VARVAL:   {
                        }
                        break;
    case FUNC_VALVAR:   {
                        }
                        break;
}

//Devolver el tipo de instruccion (LEER, MOSTRAR, ASIG_VAL, ASIG_VAR, FUNC_VALVAL, FUNC_VARVAR, FUNC_VARVAL, FUNC_VALVAR)
tipo_instruccion dar_tipo_inst (instruccion i);

{
//escaneo el tipo de intrucción
scan(tipo_instruccion);
//evaluo si es:
switch(tipo_instruccion)

case LEER:          {
                    printf("Leer")
                    }
                    break;
case MOSTRAR:       {
                    printf("Mostrar")
                    }
                    break;
case ASIG_VAL:      {
                    printf("Asignación valor")
                    }
                    break;
case ASIG_VAR:      {
                    printf("Asignación Variable:)
                    }
case FUNC_VALVAL:   {
                    printf("VALOR VALOR");
                    }
                    break;
case FUNC_VARVAR:   {
                    printf("VARIABLE VARIABLE");
                    }
                    break;
case FUNC_VARVAL:   {
                    printf ("VARIABLE VALOR");
                    }
                    break;
case FUNC_VALVAR:   {
                    printf ("VALOR VARIABLE");
                    }
                    break;
