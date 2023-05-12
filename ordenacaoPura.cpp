#include "tudo.hpp"

void OrdenacaoPura::ordenacaoBolhaPura( int matriz[], unsigned int tamanho )
{
	int i, absoluto;
	for( absoluto = tamanho-1; absoluto >= 0; absoluto-- )
	{
		for( i = 0; i < tamanho-1; i++ )
		{
			if( matriz[i] > matriz[i+1] )
			{
				int tmp = matriz[i];
				matriz[i] = matriz[i+1];
				matriz[i+1] = tmp;
			}
		}
	}
}
