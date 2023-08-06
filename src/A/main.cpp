#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <chrono>
#include <unistd.h>

#include "utilitarios.hpp"
#include "matematica.hpp"
#include "ordenacao.hpp"
#include "busca.hpp"

/*###################################################
 *#
 *#	SETOR DE FUNÇÕES
 *#
 *###################################################*/

void delimiter(void)
{
	std::cout << '\n' << "___________________________________________________" << '\n';
}

void selecionarAlgoritmo( Ordenacao* s, int tamanho, int limiteNumerico, char algoritmo, bool modo=true )
{
	int* matrizLocal = new int[ tamanho ];

	std::srand( 10121815 );

	switch ( modo )
	{
		case true:
			for( int p = 0; p < tamanho; p++ )
			{
				*( matrizLocal + p ) = int( std::rand() % limiteNumerico );
			}
			break;
		case false:
			for( int p = tamanho-1; p > 0; p-- )
			{
				*( matrizLocal + p ) = p;
			}
			break;
	}

	std::chrono::_V2::system_clock::time_point	inicio = std::chrono::high_resolution_clock::now();
	switch ( algoritmo )
	{
		case 'b':
			s->ordenacaoBolha( matrizLocal , tamanho  );
			break;
		case 's':
			s->ordenacaoSelecao( matrizLocal, tamanho );
			break;
		case 'i':
			s->ordenacaoInsercao( matrizLocal, tamanho );
			break;
		case 'h':
			s->ordenacaoShell( matrizLocal, tamanho );
			break;
		case 'm':
			s->ordenacaoMescla( matrizLocal, 0, tamanho - 1 );
			break;
		case 'r':
			s->ordenacaoMescla( matrizLocal, 0, tamanho - 1 );
			break;
		default:
			std::cout << "não ordenação";
	}
	std::chrono::_V2::system_clock::time_point	fim = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast <std::chrono::milliseconds> ( fim - inicio ).count();
	if( modo = true )
		printf("ms tamanho da matriz:%i %c \n", tamanho, algoritmo );
	else
		printf("ms tamanho da matriz:%i %c \n", tamanho, algoritmo );

	delete matrizLocal;
}

/*###################################################
 *#
 *#	SETOR DE EXECUÇÃO binário A
 *#
 *###################################################*/

int main(int argc, char* argv[])
{
	Matematica matema;
	Busca search;
	Ordenacao sort;
	Utilitarios uti;

	int ch;

	// opções que antecedem as de ordenação
	// aleatório decrescente teste
	int aflag = 0;
	int dflag = 0;
	int tflag = 0;

	// bolha, selecao, insercao. shell, mescla, rápida
	int bflag = 0;
	int sflag = 0;
	int iflag = 0;
	int hflag = 0;
	int mflag = 0;
	int rflag = 0;

	// Dado
	int xflag = 0;

	while( (ch = getopt(argc, argv, "adtbsihmrx")) != -1 )
	{
		switch (ch)
		{
			case 'a':
				aflag = 1;
				break;
			case 'd':
				dflag = 1;
				break;
			case 't':
				tflag = 1;
				break;

			case 'b':
				bflag = 1;
				break;
			case 's':
				sflag = 1;
				break;
			case 'i':
				iflag = 1;
				break;
			case 'h':
				hflag = 1;
				break;
			case 'm':
				mflag = 1;
				break;
			case 'r':
				rflag = 1;
				break;

			case 'x':
				xflag = 1;
				break;

			default:
				std::cout << "./algostruct [ [-a|-d] [-b|-s|-i|-h|-m|-r] ] | [-t]\n";
				std::cout << "./algostruct -x\n";
				std::exit(1);
		}
	}

	if( tflag == 1 )
	{

		delimiter();

		const char alfabeto[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		search.buscaBinariaAlfabeto( 'j', 26, alfabeto );
		search.buscaBinariaAlfabeto( 'd', 26, alfabeto );
		search.buscaBinariaAlfabeto( 'k', 26, alfabeto );
		search.buscaBinariaAlfabeto( 's', 26, alfabeto );
		search.buscaBinariaAlfabeto( 'x', 26, alfabeto );

		delimiter();

		int valor = 32;

		while( true )
		{
			valor--;
			matema.eprimo( valor );
			std::cout << valor;
			if( valor == 2 )
				break;
		}
		std::cout << "saindo";

		delimiter();

		//TESTANDO A VERSÃO VERBOSA DOS ALGORITMOS
		int teste[17] = { 4,28,18,100,75,13,51,23,96,86,92,63,77,53,82,74,88 };

		//sort.particionamento( teste, 0, 16 );
		uti.escreverMatriz( sort.ordenacaoBolha( teste, 17 ), 17 );
		uti.escreverMatriz( sort.ordenacaoInsercao( teste, 17 ), 17 );
		uti.escreverMatriz( sort.ordenacaoSelecao( teste, 17 ), 17 );
		uti.escreverMatriz( sort.ordenacaoShell( teste, 17), 17 );
		uti.escreverMatriz( sort.ordenacaoRapida( teste, 0, 16 ) ,17 );
		uti.escreverMatriz( sort.ordenacaoMescla( teste, 0, 16 ) ,17 );

		delimiter();
	}
	else if ( aflag == 1 )
	{
		int tamanho = 32;

		std::cout << "pseudo aleatorio estático\n";

		while( tamanho <= 1048576 )
		{
			if ( bflag == 1 )
			{
				selecionarAlgoritmo( &sort, tamanho, 1000, 'b', true );
			}
			else if ( sflag == 1 )
			{
				selecionarAlgoritmo( &sort, tamanho, 1000, 's', true );
			}
			else if ( iflag == 1 )
			{
				selecionarAlgoritmo( &sort, tamanho, 1000, 'i', true );
			}
			else if ( hflag == 1 )
			{
				selecionarAlgoritmo( &sort, tamanho, 1000, 'h', true );
			}
			else if ( mflag == 1 )
			{
				selecionarAlgoritmo( &sort, tamanho, 1000, 'm', true );
			}
			else if ( rflag == 1 )
			{
				selecionarAlgoritmo( &sort, tamanho, 1000, 'r', true );
			}
			else
			{
				std::cout << "nenhum algoritmo executado\n";
			}
			tamanho += tamanho;
		}
	}
	else if( dflag == 1 )
	{
		int tamanho = 32;

		std::cout << "Decrescente para Crescente\n";

		while( tamanho <= 1048576 )
		{
			if ( bflag == 1 )
			{
				selecionarAlgoritmo( &sort, tamanho, 1000, 'b', false );
			}
			else if ( sflag == 1 )
			{
				selecionarAlgoritmo( &sort, tamanho, 1000, 's', false );
			}
			else if ( iflag == 1 )
			{
				selecionarAlgoritmo( &sort, tamanho, 1000, 'i', false );
			}
			else if ( hflag == 1 )
			{
				selecionarAlgoritmo( &sort, tamanho, 1000, 'h', false );
			}
			else if ( mflag == 1 )
			{
				selecionarAlgoritmo( &sort, tamanho, 1000, 'm', false );
			}
			else if ( rflag == 1 )
			{
				selecionarAlgoritmo( &sort, tamanho, 1000, 'r', false );
			}
			else
			{
				std::cout << "nenhum algoritmo executado\n";
			}
		}
	}

	if( xflag == 1 )
	{
	}

	std::exit(0);
}


