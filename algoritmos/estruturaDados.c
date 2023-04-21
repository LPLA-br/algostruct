#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "estruturaDados.h"

int main(void)
{
    char* dinamico = (char*) malloc( sizeof(char)*10 );
    strcpy( dinamico, "solibus\0" );
    dinamico = crescerString( dinamico, 10, 10 );
    printf( "\n%s", dinamico );
    strcpy( dinamico, "pugnaverunt\0" );
    printf( "\n%s", dinamico );


    struct Dados c = {3, 'k', NULL};
    struct Dados b = {2, 'w', &c};
    struct Dados a = {1, 'y', &b};

    struct Dados* listaLinkada[3] = {&a, &b, &c};

    uint8_t posicao;
    for( posicao = 0; posicao < 3; posicao++ )
    {
        printf("\n%c", listaLinkada[posicao]->caractereDado );
        if( listaLinkada[posicao]->proximo == NULL ) break;
    }

    exit(0);
}

/*função implementada por motivo de testes. Ignore*/
char* crescerString( char* alvo, uint16_t tamanho, uint16_t expancao )
{
    char* retorno = (char*) malloc( sizeof(char)*(tamanho + expancao) );
    uint16_t tam = 0;

    for( ; tam < (tamanho + expancao); tam++ )
    {
        if( tam < tamanho )
        {
            //transcrição
            *(retorno + tam) = *(alvo + tam);
        }
    }
    free( alvo );
    return retorno;
}

