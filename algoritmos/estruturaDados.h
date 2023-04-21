#ifndef ESTRUTURADADOS_H_INCLUDED
#define ESTRUTURADADOS_H_INCLUDED

char* crescerString( char* alvo, uint16_t tamanho, uint16_t expancao );

struct Dados
{
    uint8_t index;
    char caractereDado;
    struct Dados* proximo;
};

#endif // ESTRUTURADADOS_H_INCLUDED
