/* Ordenacao.cpp */
#include <iostream>
#include <cstdlib>
#include "ordenacao.hpp"
#include "utilitarios.hpp"

int* Ordenacao::ordenacaoBolha( int matriz[], unsigned int tamanho )
{
	int i, absoluto;
	for( absoluto = tamanho-1; absoluto >= 0; absoluto-- )
	{
		for( i = 0; i < tamanho-1; i++ )
		{
			if( matriz[i] > matriz[i+1] )
			{
				//troca
				int tmp = matriz[i];
				matriz[i] = matriz[i+1];
				matriz[i+1] = tmp;
			}
		}
	}
	return matriz;
}

int* Ordenacao::ordenacaoInsercao( int matriz[], unsigned int tamanho )
{
	for ( int a = 0; a < tamanho-1; a++ )
	{
		for ( int b = a-1; b > -1; b-- )
		{
			if ( matriz[b] > matriz[b+1] )
			{
				//troca
				int tmp = matriz[b];
				matriz[b] = matriz[b+1];
				matriz[b+1] = tmp;
			}
			else
				break;
		}
	}
	return matriz;
}

int* Ordenacao::ordenacaoSelecao( int matriz[], unsigned int tamanho )
{
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
		//troca
		int tmp = matriz[menor];
		matriz[menor] = matriz[absoluto];
		matriz[absoluto] = tmp;
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
					//troca
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

/* tentativa de correção de problemas por ponteiro [não] */

void Ordenacao::mescla( int* matriz, int primeiroIndex, int ultimoIndex, int meio )
{
	int c[50];

	int i = primeiroIndex;
	int k = primeiroIndex;
	int j = meio + 1;

	while ( i <= meio && j <= ultimoIndex )
	{
		if( *(matriz+i) < *(matriz+j) )
		{
			c[k] = *(matriz+i);
			k++;
			i++;
		}
		else
		{
			c[k] = *(matriz+j);
			k++;
			i++;
		}
	}

	while ( i <= meio )
	{
		c[k] = *(matriz+i);
		k++;
		i++;
	}

	while ( j <= ultimoIndex )
	{
		c[k] = *(matriz+j);
		k++;
		j++;
	}

	for ( i = primeiroIndex; i < k; i++ )
	{
		*(matriz+i) = c[i];
	}
}
int* Ordenacao::ordenacaoMescla( int* matriz, int primeiroIndex, int ultimoIndex )
{
	if ( primeiroIndex < ultimoIndex )
	{
		int meio = ( primeiroIndex + ultimoIndex ) / 2;
		ordenacaoMescla( matriz, primeiroIndex, meio );
		ordenacaoMescla( matriz, meio + 1, ultimoIndex );
		mescla( matriz, primeiroIndex, ultimoIndex, meio );
	}
	return matriz;
}

int Ordenacao::particaoQS( int* m, int pi, int ui )
{
	int pivo = *(m+ui);
	int i = ( pi - 1 );
	int j = pi;
	for( ; j <= ui - 1; j++ )
	{
		if( *(m+j) < pivo )
		{
			i++;
			int tmp = *(m+i);
			*(m+i) = *(m+j);
			*(m+j) = tmp;
		}
	}
	int tmp = m[i+1];
	m[i+1] = m[ui];
	m[ui] = tmp;
	return (i+1);
}

int* Ordenacao::ordenacaoRapida( int* matriz, unsigned int primeiroIndex, unsigned int ultimoIndex )
{
	if( primeiroIndex < ultimoIndex )
	{
		int part = particaoQS( matriz, primeiroIndex, ultimoIndex );
		ordenacaoRapida( matriz, primeiroIndex, part - 1 );
		ordenacaoRapida( matriz, part + 1, ultimoIndex);
	}
	return matriz;
}

/*teste de particionamento recursivo*/
int* Ordenacao::particionamento( int matriz[], unsigned int comesso, unsigned int fim )
{
	Utilitarios local; //temporário
	int* a = new int[10];

	if( comesso >= fim )
	{
		local.escreverMatrizEntreValores( matriz, comesso, fim );
		return a;
	}
	else
	{
		int meio = ( comesso + fim ) / 2;

		local.escreverMatrizEntreValores( matriz, comesso, fim );

		particionamento( matriz, comesso, meio );
		particionamento( matriz, meio + 1, fim );
		
		return a;
	}
}
