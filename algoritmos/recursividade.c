#include <stdio.h>
#include <stdlib.h>

int metadesInteiras( int numero );

int main(void)
{
    metadesInteiras(1024);
    exit(0);
}

int metadesInteiras( int numero )
{
    numero = numero / 2;
    printf( "\n%i", numero );

    if( numero <= 0 )
    {
        return numero;
    }
    else metadesInteiras( numero );
    return 0;
}
