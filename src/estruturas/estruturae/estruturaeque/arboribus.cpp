#include <iostream>
#include <string>
#include <cstdbool>
#include "arboribus.hpp"

Arbor::Arbor()
{
	/*radix nodus aedificatur*/
	currens = new Nodum;
	currens->rota = "/s";
	currens->pater = nullptr;
	currens->sinister = nullptr;
	currens->dexter = nullptr;
	nodiNumeri = 1;
}

Arbor::~Arbor(void)
{}

Nodum* Arbor::novusNodum( bool estneDexter )
{
	Nodum* novus = new Nodum;

	novus->pater = currens;
	novus->sinister = nullptr;
	novus->dexter = nullptr;

	if ( estneDexter )
	{
		novus->rota = novus->pater->rota + "/d";
	}
	else
	{
		novus->rota = novus->pater->rota + "/s";
	}
	
	return novus;
}

void Arbor::ls( void )
{
	if ( currens->sinister == nullptr && currens->dexter == nullptr )
	{
		std::cout << "vacvvs\n";
	}
	else if ( currens->sinister == nullptr && currens->dexter != nullptr )
	{
		std::cout << currens->dexter->rota << '\n';
	}
	else if ( currens->dexter == nullptr && currens->sinister != nullptr )
	{
		std::cout << currens->sinister->rota << '\n';
	}
	else if ( currens->dexter != nullptr && currens->sinister != nullptr )
	{
		std::cout << currens->sinister->rota << ' ' << currens->dexter->rota << '\n';
	}
	else
	{
		std::cout << "ls: wtf man\n";
	}
}

void Arbor::mknode( char ds )
{
	switch ( ds )
	{
		case 's':
			if ( currens->sinister == nullptr )
				currens->sinister = novusNodum( false );
			else
				std::cout << "mknode: sinister ocupado! ABORTADO\n";
			break;
		case 'd':
			if ( currens->dexter == nullptr )
				currens->dexter = novusNodum( true );
			else
				std::cout << "mknode: dexter ocupado! ABORTADO\n";
			break;
		default:
			std::cout << "mknode: argumento inválido para função. ABORTADO\n";
	}
}

void Arbor::cnode( char dsp )
{
	switch( dsp )
	{
		case 'p':
			//voltar um nó
			if ( currens->pater != nullptr )
				currens = currens->pater;
			else
				std::cout << "cnode: não é possível retornar para antes da raiz!\n";
			break;
		case 's':
			if ( currens->sinister != nullptr )
				currens = currens->sinister;
			else
				std::cout << "cnode: não é possível avancar para sinister vazio\n";
			break;
		case 'd':
			if ( currens->dexter != nullptr )
				currens = currens->dexter;
			else
				std::cout << "cnode: não é possível avancar para dexter vazio\n";
			break;
		default:
			std::cout << "cnode: argumento inválido passado!\n";
	}
}

void Arbor::pwd( void )
{
	std::cout << currens->rota << '\n';
}

void Arbor::rm( char ds )
{
	switch ( ds )
	{
		case 's':
			if ( currens->sinister != nullptr )
			{
				if ( currens->sinister->dexter == nullptr || currens->sinister->sinister == nullptr )
				{
					Nodum* tmp = currens->sinister;
					currens->sinister = nullptr;

					tmp->pater = nullptr;
					tmp->sinister = nullptr;
					tmp->dexter = nullptr;

					delete tmp;
				}
				else
				{
					std::cout << "apenas nós sem filhos poder ser removidos por rm (folhas)\n";
				}
			}
			else
				std::cout << "rm: sexter já está vazio\n";
			break;
		case 'd':
			if ( currens->dexter != nullptr )
			{
				if ( currens->dexter->sinister == nullptr && currens->dexter->dexter == nullptr )
				{
					Nodum* tmp = currens->dexter;
					currens->dexter = nullptr;

					tmp->pater = nullptr;
					tmp->sinister = nullptr;
					tmp->dexter = nullptr;

					delete tmp;
				}
				else
				{
					std::cout << "Apenas nós sem filhos podem ser removidos por rm (folhas)\n";
				}
			}
			else
				std::cout << "rm: dexter já está vazio\n";
			break;
		default:
			std::cout << "rm: argumento inválido passado!\n";
	}
}

void Arbor::testa( void )
{
	std::string comando = "help";

	std::cout << "\nEste software tem absolutamente nenhuma\n";
	std::cout << "garantia na medida permitida pela lei aplicável.\n";
	std::cout << "Autor: Luiz Paulo de Lima Araújo Email: luiz.araujo1@escolar.ifrn.edu.br\n";
	std::cout << "\"help\" para obter ajuda\n\n";

	while( true )
	{
		std::cout << "\n[" << currens->rota << "]# ";
		std::cin >> comando;

		if ( comando == "help" )
		{
			std::cout << "U N I X    V I B E S  1969\n\n";
			std::cout << "ls       listar conteudo do nó\n";
			std::cout << "mknode   criar nó no lado dexter ou sinister\n";
			std::cout << "cnode    ir para node dexter ou sinister\n";
			std::cout << "pwd      mostrar posição atual na árvore de nós\n";
			std::cout << "rm       remover nó sinister ou dexter do corrente\n";
		}
		else if ( comando == "ls" )
		{
			ls();
		}
		else if ( comando == "mknode" )
		{
			char lado = 'd';

			std::cout << "\n(s|d)> ";
			std::cin >> lado;

			switch ( lado )
			{
				case 's':
					mknode( 's' );
					break;
				case 'd':
					mknode( 'd' );
					break;
				default:
					std::cout << "mknode: argumento inválido " << lado << "\n";
			}

			
		}
		else if ( comando == "cnode" )
		{
			char i = 'p';

			std::cout << "\n(p|s|d)> ";
			std::cin >> i;

			switch ( i )
			{
				case 'p':
					cnode( 'p' );
					break;
				case 's':
					cnode( 's' );
					break;
				case 'd':
					cnode( 'd' );
					break;
				default:
					std::cout << "cnode: argumento inválido!\n";
			}
		}
		else if ( comando == "rm" )
		{
			char alvo = 'x';

			std::cout << "\n(s|d)> ";
			std::cin >> alvo;

			switch ( alvo )
			{
				case 'd':
					break;
				case 's':
					break;
				default:
					std::cout << "rm: argumento inválido\n";
			}
		}
		else if ( comando == "pwd" )
		{
			pwd();
		}
		else
		{
			std::cout << "# \"help\" para obter ajuda ";
		}
	}
}

unsigned int Arbor::profunditasArborisMonstra( void )
{
	return 1;
}

void Arbor::inOrdinemCurre( void )
{}

void Arbor::preOrdinemCurre( void )
{}

void Arbor::postOrdinemCurre( void )
{}

/* FIM */
