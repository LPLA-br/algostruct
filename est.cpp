/*##############################################
 * B U S C A    E    O R D E N A Ç Ã O         #
 *##############################################*/

#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>

#include "tudo.hpp"

/*###################################################
 *#
 *#	SETOR DE FUNÇÕES
 *#
 *###################################################*/

void delimiter(void)
{
	std::cout << '\n' << "___________________________________________________" << '\n';
}

/*###################################################
 *#
 *#	SETOR DE EXECUÇÃO
 *#
 *###################################################*/

int main(int argc, char* argv[])
{


	Matematica matema;
	Ordenacao sort;
	Busca search;
	Utilitarios uti;



	delimiter();

	const char alfabeto[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	search.buscaBinariaAlfabeto( 'j', 26, alfabeto );
	search.buscaBinariaAlfabeto( 'd', 26, alfabeto );
	search.buscaBinariaAlfabeto( 'k', 26, alfabeto );
	search.buscaBinariaAlfabeto( 's', 26, alfabeto );
	search.buscaBinariaAlfabeto( 'x', 26, alfabeto );

	delimiter();

	//uti.escreverMatriz( sort.ordenacaoBolha( a, 10 ), 10 );

	delimiter();

	int relo[7] = { 1,2,3,4,5,6,7 }; 
	sort.particionamento( relo, 0, 6 );

	delimiter();

	int tamanhoCrescente;
	int dezeroate = 100;
	for( tamanhoCrescente = 10; tamanhoCrescente < 1000; tamanhoCrescente++ )
	{

		srand( (unsigned)time(NULL) );
		int pos = 0;
		int* geracao = new int[tamanhoCrescente];

		for( pos = 0; pos < tamanhoCrescente; pos++ )
		{
			//0-99
			*(geracao + pos) = rand() % maxnum;
		}

		time_t start, end;

		time( &start );
			std::ios_base::sync_with_stdio( false );
			sort.ordenacaoBolhaPura( a , 100  );
		time( &end );

		double tempo_tomado = double( end - start );
		std::cout << "\nTempo tomado-> " <<
		std::fixed << tempo_tomado << std::setprecision(10) << tamanhoCrescente
		<< "<-tamanho" << '\n';

		delete geracao;
	}


	std::exit(0);
}
