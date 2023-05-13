/*##############################################
 * B U S C A    E    O R D E N A Ç Ã O         #
 *##############################################*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <chrono>
#include <unistd.h>

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

	int ch;

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

	while( (ch = getopt(argc, argv, "adtbsihmr")) != -1 )
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

			default:
				std::cout << "./est.out [ [-a|-d] [-b|-s|-i|-h|-m|-r] ] | [-t]\n";
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

		//TESTANDO A VERSÃO VERBOSA DOS ALGORITMOS
		int teste[17] = { 4,28,18,100,75,13,51,23,96,86,92,63,77,53,82,74,88 };
		int* aloca = new int[17];

		int inverso = 16;
		int p = 0;
		for ( ; p < 17; p++ )
		{
			*( aloca + p ) = inverso;
			inverso--;
			std::cout << *(aloca+p) << ' ';
		}

		delimiter();

		//sort.particionamento( teste, 0, 16 );
		uti.escreverMatriz( sort.ordenacaoBolha( teste, 17 ), 17 );
		uti.escreverMatriz( sort.ordenacaoInsercao( teste, 17 ), 17 );
		uti.escreverMatriz( sort.ordenacaoSelecao( teste, 17 ), 17 );
		uti.escreverMatriz( sort.ordenacaoShell( teste, 17), 17 );
		uti.escreverMatriz( sort.ordenacaoRapida( teste, 0, 16 ) ,17 );
		uti.escreverMatriz( sort.ordenacaoMescla( teste, 0, 16 ) ,17 );

		uti.escreverMatriz( sort.ordenacaoRapida( aloca, 0, 16 ) ,17 );
		uti.escreverMatriz( sort.ordenacaoMescla( aloca, 0, 16 ) ,17 );

		delete aloca;
		delimiter();
	}
	else if ( aflag == 1 )
	{
		int tamanho = 32;
		int dezeroate = 1000;

		std::cout << "pseudo aleatorio estático\n";
		std::cout << "tempo_de_execução_milisegundos, tamanho_input, faixa_de_valores\n";

		while( tamanho <= 1048576 )
		{
			int* a = new int[tamanho];

			//populando matriz ...
			srand( 10121815 );
			int pos;
			for( pos=0; pos<= tamanho; pos++ )
			{
				*( a + pos ) = ( rand() % dezeroate );
			}

			if ( bflag == 1 )
			{
				std::chrono::_V2::system_clock::time_point inicio = std::chrono::high_resolution_clock::now();
					sort.ordenacaoBolha( a , tamanho  );
				std::chrono::_V2::system_clock::time_point fim = std::chrono::high_resolution_clock::now();

				std::cout << std::chrono::duration_cast<std::chrono::milliseconds>( fim - inicio ).count();
				printf(", %i, 1-%i Bolha \n", tamanho, dezeroate );
			}
			else if ( sflag == 1 )
			{
				std::chrono::_V2::system_clock::time_point inicio = std::chrono::high_resolution_clock::now();
					sort.ordenacaoSelecao( a , tamanho  );
				std::chrono::_V2::system_clock::time_point fim = std::chrono::high_resolution_clock::now();

				std::cout << std::chrono::duration_cast<std::chrono::milliseconds>( fim - inicio ).count();
				printf(", %i, 1-%i Seleção \n", tamanho, dezeroate );
			}
			else if ( iflag == 1 )
			{
				std::chrono::_V2::system_clock::time_point inicio = std::chrono::high_resolution_clock::now();
					sort.ordenacaoInsercao( a , tamanho  );
				std::chrono::_V2::system_clock::time_point fim = std::chrono::high_resolution_clock::now();

				std::cout << std::chrono::duration_cast<std::chrono::milliseconds>( fim - inicio ).count();
				printf(", %i, 1-%i Inserção \n", tamanho, dezeroate );
			}
			else if ( hflag == 1 )
			{
				std::chrono::_V2::system_clock::time_point inicio = std::chrono::high_resolution_clock::now();
					sort.ordenacaoShell( a , tamanho  );
				std::chrono::_V2::system_clock::time_point fim = std::chrono::high_resolution_clock::now();

				std::cout << std::chrono::duration_cast<std::chrono::milliseconds>( fim - inicio ).count();
				printf(", %i, 1-%i Shell \n", tamanho, dezeroate );
			}
			else if ( mflag == 1 )
			{
				std::chrono::_V2::system_clock::time_point inicio = std::chrono::high_resolution_clock::now();
					sort.ordenacaoMescla( a , 0, tamanho-1  );
				std::chrono::_V2::system_clock::time_point fim = std::chrono::high_resolution_clock::now();

				std::cout << std::chrono::duration_cast<std::chrono::milliseconds>( fim - inicio ).count();
				printf(", %i, 1-%i Mescla \n", tamanho, dezeroate );
			}
			else if ( rflag == 1 )
			{
				std::chrono::_V2::system_clock::time_point inicio = std::chrono::high_resolution_clock::now();
					sort.ordenacaoRapida( a ,0 , tamanho-1  );
				std::chrono::_V2::system_clock::time_point fim = std::chrono::high_resolution_clock::now();

				std::cout << std::chrono::duration_cast<std::chrono::milliseconds>( fim - inicio ).count();
				printf(", %i, 1-%i Rápida \n", tamanho, dezeroate );

			}
			else
			{
				std::cout << "nenhum algoritmo executado\n";
			}
			

			delete a;
			tamanho += tamanho;
		}

	}
	else if( dflag == 1 )
	{
		int tamanho = 32;
		int dezeroate = 1000;

		std::cout << "Decrescente para Crescente\n";
		std::cout << "tempo_de_execução_milisegundos, tamanho_input, decrecente_de_N_até_1\n";

		while( tamanho <= 1048576 )
		{
			int* a = new int[tamanho];

			//populando matriz ...
			int pos;
			int retrogrado = tamanho;
			for( pos=0; pos<= tamanho; pos++ )
			{
				*( a + pos ) = retrogrado;
				retrogrado--;
			}

			if ( bflag == 1 )
			{
				std::chrono::_V2::system_clock::time_point inicio = std::chrono::high_resolution_clock::now();
					sort.ordenacaoBolha( a , tamanho  );
				std::chrono::_V2::system_clock::time_point fim = std::chrono::high_resolution_clock::now();

				std::cout << std::chrono::duration_cast<std::chrono::milliseconds>( fim - inicio ).count();
				printf(", %i, %i-1 Bolha \n", tamanho, tamanho );
			}
			else if ( sflag == 1 )
			{
				std::chrono::_V2::system_clock::time_point inicio = std::chrono::high_resolution_clock::now();
					sort.ordenacaoSelecao( a , tamanho  );
				std::chrono::_V2::system_clock::time_point fim = std::chrono::high_resolution_clock::now();

				std::cout << std::chrono::duration_cast<std::chrono::milliseconds>( fim - inicio ).count();
				printf(", %i, %i-1 Seleção \n", tamanho, tamanho );
			}
			else if ( iflag == 1 )
			{
				std::chrono::_V2::system_clock::time_point inicio = std::chrono::high_resolution_clock::now();
					sort.ordenacaoInsercao( a , tamanho  );
				std::chrono::_V2::system_clock::time_point fim = std::chrono::high_resolution_clock::now();

				std::cout << std::chrono::duration_cast<std::chrono::milliseconds>( fim - inicio ).count();
				printf(", %i, %i-1 Inserção \n", tamanho, tamanho );
			}
			else if ( hflag == 1 )
			{
				std::chrono::_V2::system_clock::time_point inicio = std::chrono::high_resolution_clock::now();
					sort.ordenacaoShell( a , tamanho  );
				std::chrono::_V2::system_clock::time_point fim = std::chrono::high_resolution_clock::now();

				std::cout << std::chrono::duration_cast<std::chrono::milliseconds>( fim - inicio ).count();
				printf(", %i, %i-1 Shell \n", tamanho, tamanho );
			}
			else if ( mflag == 1 )
			{
				std::chrono::_V2::system_clock::time_point inicio = std::chrono::high_resolution_clock::now();
					sort.ordenacaoMescla( a , 0, tamanho-1  );
				std::chrono::_V2::system_clock::time_point fim = std::chrono::high_resolution_clock::now();

				std::cout << std::chrono::duration_cast<std::chrono::milliseconds>( fim - inicio ).count();
				printf(", %i, %i-1 Mescla \n", tamanho, tamanho );
			}
			else if ( rflag == 1 )
			{
				std::chrono::_V2::system_clock::time_point inicio = std::chrono::high_resolution_clock::now();
					sort.ordenacaoRapida( a ,0 , tamanho-1  );
				std::chrono::_V2::system_clock::time_point fim = std::chrono::high_resolution_clock::now();

				std::cout << std::chrono::duration_cast<std::chrono::milliseconds>( fim - inicio ).count();
				printf(", %i, %i-1 Rápida \n", tamanho, tamanho );

			}
			else
			{
				std::cout << "nenhum algoritmo executado\n";
			}

			delete a;
			tamanho += tamanho;
		}
	}

	std::exit(0);
}


