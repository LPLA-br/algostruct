#ifndef ORDENACAO_H_INCLUDED
#define ORDENACAO_H_INCLUDED

/*structs, unions, enums
 *protótipos de funções e etc...*/

void result( int* matriz, unsigned int tamanho );
void ordenacaoInsercao( int matriz[], unsigned int tamanho );
void ordenacaoShellSort( int matriz[], unsigned int tamanho );
void ordenacaoBolha( int matriz[], unsigned int tamanho );
void ordenacaoMerge( int matriz[], unsigned int primeiroElemento, unsigned int ultimoElemento );
void ordenacaoSelecao( int matriz[], int tamanho );
void ordenacaoIndicie( int matriz[], unsigned int tamanho);

void extra(void);

#endif // ORDENACAO_H_INCLUDED
