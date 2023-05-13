#include <vector>
#include <iostream>

void OrdenacaoVector::mescla( std::vector<int> matriz, int primeiroIndex, int ultimoIndex, int meio )
{
	int c[50];

	int i = primeiroIndex;
	int k = primeiroIndex;
	int j = meio + 1;

	while ( i <= meio && j <= ultimoIndex )
	{
		if( matriz[i] < matriz[j] )
		{
			c[k] = matriz[i];
			k++;
			i++;
		}
		else
		{
			c[k] = matriz[j];
			k++;
			i++;
		}
	}

	while ( i <= meio )
	{
		c[k] = matriz[i];
		k++;
		i++;
	}

	while ( j <= ultimoIndex )
	{
		c[k] = matriz[j];
		k++;
		j++;
	}

	for ( i = primeiroIndex; i < k; i++ )
	{
		matriz[i] = c[i];
	}
}
std::vector<int> OrdenacaoVector::ordenacaoMescla( std::vector<int> &matriz, int primeiroIndex, int ultimoIndex )
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

int OrdenacaoVector::particaoQS( std::vector<int> m, int pi, int ui )
{
	int pivo = m[ui];
	int i = ( pi - 1 );
	int j = pi;
	for( ; j <= ui - 1; j++ )
	{
		if( m[j] < pivo )
		{
			i++;
			int tmp = m[i];
			m[i] = m[j];
			m[j] = tmp;
		}
	}
	int tmp = m[i+1];
	m[i+1] = m[ui];
	m[ui] = tmp;
	return (i+1);
}
int* OrdenacaoVector::ordenacaoRapida( std::vector<int> matriz, unsigned int primeiroIndex, unsigned int ultimoIndex )
{
	if( primeiroIndex < ultimoIndex )
	{
		int part = particaoQS( matriz, primeiroIndex, ultimoIndex );
		ordenacaoRapida( matriz, primeiroIndex, part - 1 );
		ordenacaoRapida( matriz, part + 1, ultimoIndex);
	}
	return matriz;
}

