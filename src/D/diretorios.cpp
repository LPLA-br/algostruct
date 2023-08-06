#include <iostream>
#include <string>
#include <cstdbool>
#include "diretorios.hpp"

Diretorio::Diretorio()
{
	/*radix nodus aedificatur*/
	radix = new No;
	radix->rota = "/e";
	radix->pai = nullptr;
	radix->esquerda = nullptr;
	radix->direita = nullptr;
	numeroDeNos = 1;


	currens = radix;
}

Diretorio::~Diretorio(void)
{}

No* Diretorio::novoNo( bool aDireita )
{
	No* novus = new No;

	novus->pai = currens;
	novus->esquerda = nullptr;
	novus->direita = nullptr;

	if ( aDireita )
	{
		novus->rota = novus->pai->rota + "/d";
	}
	else
	{
		novus->rota = novus->pai->rota + "/e";
	}
	
	return novus;
}

void Diretorio::ls( void )
{
	if ( currens->esquerda == nullptr && currens->direita == nullptr )
	{
		std::cout << "VAZIO\n";
	}
	else if ( currens->esquerda == nullptr && currens->direita != nullptr )
	{
		std::cout << currens->direita->rota << '\n';
	}
	else if ( currens->direita == nullptr && currens->esquerda != nullptr )
	{
		std::cout << currens->esquerda->rota << '\n';
	}
	else if ( currens->direita != nullptr && currens->esquerda != nullptr )
	{
		std::cout << currens->esquerda->rota << ' ' << currens->direita->rota << '\n';
	}
	else
	{
		std::cout << "ls: wtf man\n";
	}
}

void Diretorio::mknode( char esqDir )
{
	switch ( esqDir )
	{
		case 'e':
			if ( currens->esquerda == nullptr )
				currens->esquerda = novoNo( false );
			else
				std::cout << "mknode: esquerda ocupado! ABORTADO\n";
			break;
		case 'd':
			if ( currens->direita == nullptr )
				currens->direita = novoNo( true );
			else
				std::cout << "mknode: direita ocupado! ABORTADO\n";
			break;
		default:
			std::cout << "mknode: argumento inválido para função. ABORTADO\n";
	}
}

void Diretorio::cnode( char esqDirPai )
{
	switch( esqDirPai )
	{
		case 'p':
			//voltar um nó
			if ( currens->pai != nullptr )
				currens = currens->pai;
			else
				std::cout << "cnode: não é possível retornar para antes da raiz!\n";
			break;
		case 'e':
			if ( currens->esquerda != nullptr )
				currens = currens->esquerda;
			else
				std::cout << "cnode: não é possível avancar para esquerda vazio\n";
			break;
		case 'd':
			if ( currens->direita != nullptr )
				currens = currens->direita;
			else
				std::cout << "cnode: não é possível avancar para direita vazio\n";
			break;
		default:
			std::cout << "cnode: argumento inválido passado!\n";
	}
}

void Diretorio::pwd( void )
{
	std::cout << currens->rota << '\n';
}

void Diretorio::rm( char esqDir )
{
	switch ( esqDir )
	{
		case 'e':
			if ( currens->esquerda != nullptr )
			{
				if ( currens->esquerda->direita == nullptr || currens->esquerda->esquerda == nullptr )
				{
					No* tmp = currens->esquerda;
					currens->esquerda = nullptr;

					tmp->pai = nullptr;
					tmp->esquerda = nullptr;
					tmp->direita = nullptr;

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
			if ( currens->direita != nullptr )
			{
				if ( currens->direita->esquerda == nullptr && currens->direita->direita == nullptr )
				{
					No* tmp = currens->direita;
					currens->direita = nullptr;

					tmp->pai = nullptr;
					tmp->esquerda = nullptr;
					tmp->direita = nullptr;

					delete tmp;
				}
				else
				{
					std::cout << "Apenas nós sem filhos podem ser removidos por rm (folhas)\n";
				}
			}
			else
				std::cout << "rm: direita já está vazio\n";
			break;
		default:
			std::cout << "rm: argumento inválido passado!\n";
	}
}

void Diretorio::shell( void )
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
			std::cout << "ls       listar conteudo do nó\n";
			std::cout << "mknode   criar nó no lado direita ou esquerda\n";
			std::cout << "cnode    ir para node direita ou esquerda\n";
			std::cout << "pwd      mostrar posição atual no grafo de nós\n";
			std::cout << "rm       remover nó esquerda ou direita do corrente\n";
			std::cout << "depth    obter profundidade da árvore\n";
			std::cout << "inorder  varredura infixa\n";
			std::cout << "preorder varredura pre-ordem\n";
			std::cout << "posorder varredura pós-ordem\n";
		}
		else if ( comando == "ls" )
		{
			ls();
		}
		else if ( comando == "mknode" )
		{
			char lado = 'd';

			std::cout << "\n(d|e)> ";
			std::cin >> lado;

			switch ( lado )
			{
				case 'e':
					mknode( 'e' );
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

			std::cout << "\n(p|d|e)> ";
			std::cin >> i;

			switch ( i )
			{
				case 'p':
					cnode( 'p' );
					break;
				case 'e':
					cnode( 'e' );
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

			std::cout << "\n(d|e)> ";
			std::cin >> alvo;

			switch ( alvo )
			{
				case 'e':
					rm( 'e' );
					break;
				case 'd':
					rm( 'd' );
					break;
				default:
					std::cout << "rm: argumento inválido\n";
			}
		}
		else if ( comando == "pwd" )
		{
			pwd();
		}
		else if ( comando == "depth" )
		{
			std::cout << mostrarProfundidadeDoGrafoDeDiretorios( radix );
		}
		else if ( comando == "inorder" )
		{
			inOrderCorrer( radix );
		}
		else if ( comando == "preorder" )
		{
			preOrderCorrer( radix );
		}
		else if ( comando == "posorder" )
		{
			posOrderCorrer( radix );
		}
		else
		{
			std::cout << "# \"help\" para obter ajuda ";
		}
	}
}

unsigned int Diretorio::mostrarProfundidadeDoGrafoDeDiretorios( No* leitor )
{
	if ( leitor == nullptr )
	{
		return 0;
	}
	else
	{
		int esquerdaProfunditas = mostrarProfundidadeDoGrafoDeDiretorios( leitor->esquerda );
		int direitaProfunditas = mostrarProfundidadeDoGrafoDeDiretorios( leitor->direita );

		if ( esquerdaProfunditas > direitaProfunditas )
		{
			return ( esquerdaProfunditas + 1 );
		}
		else
		{
			return ( direitaProfunditas + 1 );
		}
	}
}

void Diretorio::inOrderCorrer( No* leitor )
{
	if ( leitor == nullptr )
		return;

	inOrderCorrer( leitor->esquerda );
	std::cout << ' ' << leitor->rota << '\n';
	inOrderCorrer( leitor->direita );
}

void Diretorio::preOrderCorrer( No* leitor )
{
	if ( leitor == nullptr )
		return;

	std::cout << ' ' << leitor->rota << '\n';
	preOrderCorrer( leitor->esquerda );
	preOrderCorrer( leitor->direita );
}

void Diretorio::posOrderCorrer( No* leitor )
{
	if ( leitor == nullptr )
		return;
	
	preOrderCorrer( leitor->esquerda );
	preOrderCorrer( leitor->direita );
	std::cout << ' ' << leitor->rota << '\n';
}

/* FIM */
