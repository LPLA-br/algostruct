/* Ordenacao.c */
#include <iostream>
#include <cstdlib>
#include "tudo.hpp"

int* Ordenacao::ordenacaoBolha( int matriz[], unsigned int tamanho )
{
	Utilitarios operation;
	int i, absoluto;
	for( absoluto = tamanho-1; absoluto >= 0; absoluto-- )
	{
		for( i = 0; i < tamanho-1; i++ )
		{
			if( matriz[i] > matriz[i+1] )
			{
				operation.swap( &matriz[i], &matriz[i+1]  );
			}
		}
	}
	return matriz;
}

int* Ordenacao::ordenacaoInsercao( int matriz[], unsigned int tamanho )
{
	Utilitarios operation;
	for( int a = 0; a < tamanho-1; a++ )
	{
		for( int b = a-1; b > -1; b-- )
		{
			if( matriz[b] > matriz[b+1] )
				operation.swap( &matriz[b], &matriz[b+1] );
			else
				break;
		}
	}
	return matriz;
}

int* Ordenacao::ordenacaoSelecao( int matriz[], unsigned int tamanho )
{
	Utilitarios operation;
	int menor;
	for( int absoluto = 0; absoluto < tamanho-1; absoluto++ )
	{
		menor = absoluto+1;
		for( int indicador = absoluto; indicador < tamanho-1; indicador++ )
		{
			if( matriz[menor] > matriz[indicador] )
			{
				menor = indicador;
			}
		}
		operation.swap( &matriz[menor], &matriz[absoluto] );
	}
	return matriz;
}

int* Ordenacao::ordenacaoShell( int matriz[] , unsigned int tamanho )
{
	int insAbs;
	int insAux;
	int afastamento = 1;

	while( afastamento < tamanho )
	{
		afastamento = 3*afastamento+1;
	}

	while( afastamento > 1 )
	{
		afastamento = afastamento / 3;

		/*ordenação por inserção que
		  segue os limites impostos
		  matematicamente por shellsort*/
		for( insAbs = afastamento; insAbs<tamanho; insAbs++ )
		{
			for( insAux = insAbs-1; insAux > -1; insAux-- )
			{
				if( matriz[insAux] > matriz[insAux+1] )
				{
					int tmp = matriz[insAux];
					matriz[insAux] = matriz[insAux+1];
					matriz[insAux+1] = tmp;
				}
				else break;
			}
		}
	}
	return matriz;
}

/*RECURSIVO*/

int* Ordenacao::ordenacaoMescla( int matriz[], unsigned int comesso, unsigned int fim )
{
	int meio = (comesso + fim) / 2;


	//caso base
	if( comesso == fim ) return;

	ordenacaoMescla(matriz, comesso, meio);
	ordenacaoMescla(matriz, meio+1, fim);

	int* tmpmatriz = (int*)malloc( sizeof(int) + (fim+1) );

	int c = comesso;
	int m = meio + 1;
	int f = 0;

	while(c < meio + 1 || m  < fim + 1)
	{
		if (c == meio + 1 )
		{ 
			tmpmatriz[f] = matriz[m];
			m++;
			f++;
		}
		else
		{
			if (m == fim + 1)
			{
				tmpmatriz[f] = matriz[c];
				c++;
				f++;
			}
			else
			{
				if (matriz[c] < matriz[m])
				{
					tmpmatriz[f] = matriz[c];
					c++;
					f++;
				}
				else
				{
					tmpmatriz[f] = matriz[m];
					m++;
					f++;
				}
			}
		}

    }
    for(c = comesso; c <= fim; c++)
    {
        matriz[c] = tmpmatriz[c - comesso];
    }
    free( tmpmatriz );
    return matriz;
}

int* Ordenacao::ordenacaoRapida( int matriz[], unsigned int primeiroIndex, unsigned int ultimoIndex )
{
	int pinoCentral = primeiroIndex;

	int subpino;
	int ch;
	int j;

	for( subpino = primeiroIndex+1; subpino <= ultimoIndex; subpino++ )
	{
		j = subpino;
		if( matriz[j] < matriz[pinoCentral] )
		{
			ch = matriz[j];
			while( j > pinoCentral )
			{
				matriz[j] = matriz[j-1];
				j--;
			}
			matriz[j] = ch;
			pinoCentral++;
		}
	}

	if( pinoCentral-1 >= primeiroIndex )
	{
		ordenacaoRapida( matriz, primeiroIndex, pinoCentral-1 );	
	}
	if( pinoCentral+1 <= ultimoIndex )
	{
		ordenacaoRapida( matriz, pinoCentral+1, ultimoIndex );
	}

	return matriz;
}


/* ex: index(0,1,2,3,4,5,6) = nãozero(1,2,3,4,5,6,7) 7/2 = 3,5 = 3  */
int* Ordenacao::particionamento( int matriz[], unsigned int comesso, unsigned int fim )
{
	Utilitarios local; //temporário

	if( comesso >= fim )
	{
		local.escreverMatrizEntreValores( matriz, comesso, fim );
		return;
	}
	else
	{
		int meio = ( comesso + fim ) / 2;

		local.escreverMatrizEntreValores( matriz, comesso, fim );

		particionamento( matriz, comesso, meio );
		particionamento( matriz, meio + 1, fim );

		return;
	}

}
