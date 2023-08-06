/*busca.cpp*/
#include <iostream>
#include "busca.hpp"
#include "utilitarios.hpp"

/* PRE-REQUISITO: dados ordenados numéricamente ou alfabeticamente */
void Busca::buscaBinariaAlfabeto( char caractereAlvo, unsigned int tamanhoAbs, const char alfabeto[] )
{
	Utilitarios operation;

	unsigned int posComeco = 0, posMeio = 0, posFim = tamanhoAbs-1;
	posMeio = (unsigned int)(tamanhoAbs / 2);

	while( true )
	{
		if( caractereAlvo > alfabeto[posMeio] )
		{
			// quebra a direita->
			posComeco = posMeio;
			posMeio = operation.mediaEntreDoisNumeros( posComeco, posFim );
		}
		else if( caractereAlvo < alfabeto[posMeio] )
		{
			//<-quebra a esquerda
			posFim = posMeio;
			posMeio = operation.mediaEntreDoisNumeros( posComeco, posFim );
		}

		// Apenas a saida da busca.
		if( alfabeto[posMeio] == caractereAlvo )
		{
			std::cout << alfabeto[posMeio] << ' ';
			std::cout << posMeio << '\n';
			break;
		}
	}
}

void Busca::buscaBinariaNumerica( int numalvo, unsigned int tamanhoAbs, const int matriz[] )
{
	Utilitarios operation;

	unsigned int posComeco = 0, posMeio = 0, posFim = tamanhoAbs-1;
	posMeio = (unsigned int)(tamanhoAbs / 2);

	while( true )
	{
		if( numalvo > matriz[posMeio] )
		{
			// quebra a direita->
			posComeco = posMeio;
			posMeio = operation.mediaEntreDoisNumeros( posComeco, posFim );
		}
		else if( numalvo < matriz[posMeio] )
		{
			//<-quebra a esquerda
			posFim = posMeio;
			posMeio = operation.mediaEntreDoisNumeros( posComeco, posFim );
		}

		// Apenas a saida da busca.
		if( matriz[posMeio] == numalvo )
		{
			std::cout << matriz[posMeio] << ' ';
			std::cout << posMeio << '\n';
			break;
		}
	}
}

