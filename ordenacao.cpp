/* Ordenacao.c */
#include <iostream>
#include "tudo.hpp"

/*ABSOLVTVS IN CONTRARIO MOTV*/
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

void Ordenacao::ordenacaoBolhaPura( int matriz[], unsigned int tamanho )
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

/*AVXILIATOR IN CONTRARIO MOTV*/
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

/*fim é o ultimo indicie*/
int* Ordenacao::ordenacaoMescla( int matriz[], unsigned int comesso, unsigned int fim )
{
	int meio = (comesso + fim) / 2;

	int c = comesso;
	int m = meio + 1;
	int f = fim;

	//caso base
	if( comesso == fim ) return;

	int* tmpmatriz = (int*)malloc( sizeof(int) + (fim+1) );

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
}

int* Ordenacao::ordenacaoRapida( int matriz[], unsigned int primeiroIndex, unsigned int ultimoIndex );
{
	int pinoCentral = primeiroIndex;

	int pininho;
	int ch;
	int j;

	for( pininho = primeiroIndex+1; pininho<=ultimoIndex; pininho++ )
	{
		j = pininho;
		fi( matriz[j] < matriz[pinoCentral] )
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
		ordencaoRapida( matriz, pinoCentral+1, ultimoIndex );
	}

	return matriz;
}

int* ordenacaoShell( int matriz[] , unsigned int tamanho )
{
	int insAbs;
	int insAux;
	int valor;
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
		  matematicamente por shell*/
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
