/********************************************************************************
 *                    ALGORÍTMOS DE ORDENAÇÃO
 * 
 * DESCRIÇÃO
 *  Um Algoritmo de ordenação e utilizado para
 *  para re-arranjar uma matriz de elementos
 *  de acordo com suas características.
 *  Tipo de dado: Cardinal (números) ou alfabético (Caracteres).
 *  Ordem: Crescente ou decrescente
 *
 * MAIS CONHECIDOS
 *  INSERÇÃO
 *   insertion sort
 *   shell sort
 *  TROCA
 *   bubble sort
 *   merge sort
 *   quicksort
 *  SELEÇÃO
 *   selection sort
 *  
 ********************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "ordenacao.h"

#define PRIMEIRO 0

int main(int argc, char *argv[])
{

    int ch;

    int matriza[10] = { 0,2,8,9,6,7,3,5,4,1 };
    int matrizb[7] = { 0,5,2,4,6,1,3 };

    while( (( ch = getopt(argc, argv, "abcdefghijklmnopqrstuvwxyz")) != -1 ) )
    {
        switch( ch )
        {
            case 'i':
                ordenacaoInsercao( matriza, 10 );
                ordenacaoInsercao( matrizb, 7 );
                break;
            case 's':
                ordenacaoShellSort( matriza, 10 );
                ordenacaoShellSort( matrizb, 7 );
                break;
            case 'b':
                ordenacaoBolha( matriza, 10 );
                ordenacaoBolha( matrizb, 7 );
                break;
            case 'm':
                ordenacaoMerge( matriza, 0, 9 );
                ordenacaoMerge( matrizb, 0, 6 );
                break;
            case 'q':
                break;
            case 'l':
                ordenacaoSelecao( matriza, 10 );
                ordenacaoSelecao( matrizb, 7 );
                break;
            case 'z':
                ordenacaoIndicie( matriza, 10 );
                ordenacaoIndicie( matrizb, 7 );
                break;
            default:
                break;
        }
    }

	exit( 0 );
}

void result( int* matriz, unsigned int tamanho )
{
   unsigned int i ;
   for( i = 0; i < tamanho; i++ )
   {
       printf(" %i", *(matriz + i) );
   }
   printf("\n");
}

/* ORDENAÇÃO POR INSERÇÃO - INSERÇÃO
 * Tudo a esquerda do segundo elemento absoluto deve está ordenado.
 * Sempre sigo em frente ordenado à esquerda antes de dar cada passo.
 * Um valor faz seus superiores fluirem para direita até que sua posição
 * natural seja desocupada.
 * Quando eu chegar no fim da matriz tudo estará ordenado.
 * */
void ordenacaoInsercao( int matriz[], unsigned int tamanho )
{
   int i=0, j=0, aux=0;

   for( i = 1; i < tamanho; i++ )
   {
                                                                    //incremente i
       aux = matriz[i];                                             //salve [i]
       j = i-1;                                                     //move j para perto de i

       while ( !(j < 0) && (aux < matriz[j]) )                      //CONDIÇÃO REPETE WHILE( jnãonegativo, aux<[j] )
       {
            matriz[j+1] = matriz[j];                                // valor de j para j+1 vulgo próximo.
            j--;                                                    //decremente j
       }

       matriz[j+1] = aux;                                           // aux para j+1 vulgo próximo. REPETE FOR ++
   }
   result( matriz, tamanho );
}

/* ORDENAÇÃO SHELL - INSERÇÃO
 * Extenção da ordenação por inserção.
 * Criei sub listas de intervalos de quatro a quatro.
 * Ordenei cada uma delas.
 * Juntei as sublistas denovo.
 * Criei duas sublistas me utilizando do intervalo sim,não,sim,não...
 * Ordenei a do não e a do sim.
 * Juntei as duas.
 * INSERTION SORT NELA! O insertion sort teve seu trabalho facilitado.
 * */
void ordenacaoShellSort( int matriz[], unsigned int tamanho )
{
    int i, j, h, aux;

    //calcular o h inicial.
    h = 1;
    while( h < tamanho / 3 )
    {
        h = 3 * h + 1;
    }

    while( h > 0 )
    {

        for( i = h; i < tamanho; i++ )
        {
            aux = matriz[i];
            j = i;

            //comparações entre elementos com distância h
            while( j >= h && aux < matriz[ j-h ] )
            {
                matriz[j] = matriz[ j-h ];
                j = j - h;
            }
            matriz[j] = aux;
        }

        h = (h-1) / 3;
    }

    result( matriz, tamanho );
}

/* ORDENAÇÃO BOLHA - TROCA
 * OS VALORES FLUEM PARA A ESQUEDA ATÉ SUAS RESPECTIVAS POSIÇÕES.
 * Comecei pelo primeiro elemeto. Comparei-o com o seguinte.
 * Se o seguinte fosse menor, trocaria-o de posição com o atual.
 * Caso contrário, nada faria. Apenas avancaria para a proximo elemento.
 * Se chego no fim da matriz e vejo que ela não está ordenada então
 * volto para o comesso e repito, repito, repito... ate a ordenação completa
 * de toda a matriz.
 * */
void ordenacaoBolha( int matriz[], unsigned int tamanho )
{
    int i, j;
    for( j = 1; j < tamanho; j++ )
    {
        for( i = 0; i < tamanho - 1; i++ )
        {
            if( matriz[i] > matriz[i+1] )
            {
                int temp = matriz[i];
                matriz[i] = matriz[i+1];
                matriz[i+1] = temp;
            }
        }
    }
    result( matriz, tamanho );
}

/* ORDENAÇÃO MERGE - TROCA
 * RECURSIVO - DIVISÃO PARA CONQUISTA
 * Quebrei a matriz principal em duas metades.
 * Quebrei as duas metades em duas para cada até
 * atingir matrizes de um elemento (recursão divisiva).
 * Ordenei os pares.
 * Os pares se uniram ordenadamente.
 * Blocos ordenados cada vez maiores se formaram
 * até criar a versão em ordem da antiga matriz
 * desordenada.
 *  */
void ordenacaoMerge( int matriz[], unsigned int primeiroElemento, unsigned int ultimoElemento )
{
    int i, j, k, meio, *tmpMatriz;
    
    if( ultimoElemento == primeiroElemento ) return;

    meio = ((primeiroElemento + ultimoElemento) / 2 );

    /*recursividade*/
    ordenacaoMerge( matriz, primeiroElemento, meio );
    ordenacaoMerge( matriz, meio + 1, ultimoElemento);

    i = primeiroElemento;
    j = meio + 1;
    k = 0;

    tmpMatriz = (int*) malloc( (sizeof(int)*((ultimoElemento-primeiroElemento)+1)) );

    while( i < meio + 1 || j < ultimoElemento + 1 )
    {
        if( i == meio + 1 )
        {
            *(tmpMatriz + k) = matriz[j];
            j++;
            k++;
        }
        else
        {
            if( j == ultimoElemento + 1)
            {
                *(tmpMatriz + k) = matriz[i];
                i++;
                k++;
            }
            else
            {
                if( matriz[i] < matriz[j] )
                {
                    *(tmpMatriz + k) = matriz[i];
                    i++;
                    k++;
                }
                else
                {
                    *(tmpMatriz + k) = matriz[j];
                    j++;
                    k++;
                }
            }
        }
    }
    for( i = primeiroElemento; i <= ultimoElemento; i++ )
    {
        matriz[i] = *(tmpMatriz + (i - primeiroElemento));
    }
    free( tmpMatriz );
    result( matriz, ultimoElemento+1 );
}

/* ORDENAÇÃO POR SELEÇÃO - SELEÇÃO */
void ordenacaoSelecao( int matriz[], int tamanho )
{
    int i, j, menor;
    for( i = 0; i < tamanho - 1; i++ )
    {
        menor = i;
        for( j = i+1; j < tamanho; j++ )
        {
            if( matriz[j] < matriz[menor] )
            {
                menor = j;
            }
        }
        if ( menor != i )
        {
            // xp = matriz[menor], yp = matriz[i]
            int tmp = matriz[menor];
            matriz[menor] = matriz[i];
            matriz[i] = tmp;
        }
    }
    result( matriz, tamanho );
}

/* ORDENAÇÃO QUICK SORT - TROCA
 * RECURSIVO - DIVISÃO PARA CONQUISTA
 * O pivó(ultímo elemento).
 * Tudo a sua esquerda deverá menor e tudo a sua direita deverá ser maior.
 * decantei os menores no inicio e coloquei o pivó entre os menores e maiores.
 * chamada recursiva para esquerda e direita.
 * Por fim, temos uma bela matriz ordenada.
 * */
void ordenacaoQuick( int matriz[], int tamanho )
{
    if( tamanho > 0 )
    {
    }
}

/* ORDENAÇÃO POR INDICIE PARA NÚMEROS
 * Os números indicam suas proprias posições na futura matriz.
 * */
void ordenacaoIndicie( int matriz[], unsigned int tamanho)
{
    unsigned int posicao = 0;
    int* retorno = (int*) malloc( sizeof(int) * tamanho );

    for( ; posicao < tamanho; posicao++ )
    {
        *(retorno + (matriz[posicao])) = matriz[posicao];
    }
    
    result( retorno, tamanho );
    free( retorno );
}

