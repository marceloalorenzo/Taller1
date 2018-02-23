
//Crear lista vacìa
void Crear_Lista (Lista &L)
{
    L = NULL;
}

//Agregar elemento al inicio
void InsFront (instruccion i, Lista &L)
{
    Lista aux = new nodoL;
    aux->info = h;
    aux->sig = L;
    L = aux;
}

//Insertar nodo al final de la lista
void InsBack (instruccion i, Lista &L)
{
if (L == NULL)
    InsFront(h,L);
    else
    InsBack (h, L->sig);
}

//Saber si una lista està vacìa
boolean Esta_Vecia (Lista L)
{
    return boolean (L == NULL);
}



//obtener el primer elemento de una lista
instruccion Primero (Lista L)
{
    return (L->info);
}
