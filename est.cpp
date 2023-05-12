/*##############################################
 * B U S C A    E    O R D E N A Ç Ã O         #
 *##############################################*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
//#include <bits/stdc++.h>
#include <chrono>

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
	Busca search;
	Ordenacao sort;
	Utilitarios uti;


/*
	delimiter();

	const char alfabeto[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	search.buscaBinariaAlfabeto( 'j', 26, alfabeto );
	search.buscaBinariaAlfabeto( 'd', 26, alfabeto );
	search.buscaBinariaAlfabeto( 'k', 26, alfabeto );
	search.buscaBinariaAlfabeto( 's', 26, alfabeto );
	search.buscaBinariaAlfabeto( 'x', 26, alfabeto );

	delimiter();
*/

	delimiter();

	//TESTANDO A VERSÃO VERBOSA DOS ALGORITMOS
/*
	int teste[17] = { 4,28,18,100,75,13,51,23,96,86,92,63,77,53,82,74,88 };
	sort.particionamento( teste, 0, 16 );
	uti.escreverMatriz( sort.ordenacaoBolha( teste, 17 ), 17 );
	uti.escreverMatriz( sort.ordenacaoInsercao( teste, 17 ), 17 );
	uti.escreverMatriz( sort.ordenacaoSelecao( teste, 17 ), 17 );
	uti.escreverMatriz( sort.ordenacaoShell( teste, 17), 17 );
	uti.escreverMatriz( sort.ordenacaoMescla( teste, 0, 16 ), 17 );
	//uti.escreverMatriz( sort.ordenacaoRapida( teste, 0, 16 ), 17 );
	*/

	delimiter();

	OrdenacaoPura puresort;

	int tamanho = 32;
	int dezeroate = 1000;
	while( tamanho <= 1048576 )
	{
		int* a = new int[tamanho];

		//populando matriz ...
		srand( (unsigned)time(NULL) );
		int pos;
		for( pos=0; pos<= tamanho; pos++ )
		{
			*( a + pos ) = ( rand() % dezeroate );
		}

		std::chrono::_V2::system_clock::time_point inicio = std::chrono::high_resolution_clock::now();
			puresort.ordenacaoBolhaPura( a , tamanho  );
		std::chrono::_V2::system_clock::time_point fim = std::chrono::high_resolution_clock::now();

		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>( fim - inicio ).count();
		printf(" ←Tempo de Execução em Milisegundos; Tamanho do array: %i elementos de 1 até: %i \n", tamanho, dezeroate );

		delete a;
		tamanho += tamanho;
	}

	std::exit(0);
}
