#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "est.hpp"

struct Dados
{
	unsigned int id;
	std::string rotulo;
	float preco;

	Dados* proximo;
	Dados* anterior;
};

void separador( void )
{
	std::cout << "---------------------------------------------------------------\n";
}

void ponteirosSaoFaceis( void )
{
	//vale a pena ver denovo

	char a = 'c';	//variável
	char *p = &a;	//ponteiro para char

	printf( "variável------------------------\n" );
	printf( "valor=%c       a\n", a );
	printf( "endereco=%x   &a\n", &a );

	printf( "ponteiro------------------------\n" );
	printf( "valorArmazPelPnt=%x         p\n", p );
	printf( "endereçoDoPnt=%x           &p\n", &p );
	printf( "valorDaVarApontPelPnt=%c   *p\n", *p );

	separador();

	printf( "\nextra:  %c\n", **&p );

	separador();
	printf( "estruturas e ponteiros------------------------\n" );

	struct Teste
	{
		char a;
		char b;
	};
	
	Teste sa;
	Teste* sp;

	sa.a = 'c';
	sa.b = 'p';

	sp = &sa;

	printf("&sa	%x\n", &sa);
	printf("sa.a	%c\n", sa.a);
	printf("sa.b	%c\n", sa.b);
	printf("&sa.a	%x\n", &sa.a);
	printf("&sa.b	%x\n", &sa.b);

	printf("&sp	%x\n", &sp);
	printf("sp->a	%c\n", sp->a);
	printf("sp->b	%c\n", sp->b);
	printf("&sp->a	%x\n", &sp->a);
	printf("&sp->b	%x\n", &sp->b);


}

void blocoIsoladoA( void )
{
	//simplemente um apontador móvel
	Dados* p = nullptr;

	//estruturas alocadas
	Dados* a;
	Dados* b;
	Dados* c;

	a = new Dados;
	b = new Dados;
	c = new Dados;

	a->id = 1;
	a->rotulo = "produto A";
	a->preco = 1.00;
	a->proximo = b;
	a->anterior = nullptr;

	b->id = 2;
	b->rotulo = "produto B";
	b->preco = 5.00;
	b->proximo = c;
	b->anterior = a;

	c->id = 3;
	c->rotulo = "produto C";
	c->preco = 15.00;
	c->proximo = nullptr;
	c->anterior = b;

	p = a;

	while( 1 )
	{
		std::cout << "id: " << p->id << " rotulo: " << p->rotulo << " preco: " << p->preco << '\n';
		if( p->proximo == nullptr ) break;
		p = p->proximo;
	}

	while( 1 )
	{
		std::cout << "id: " << p->id << " rotulo: " << p->rotulo << " preco: " << p->preco << '\n';
		if( p->anterior == nullptr ) break;
		p = p->anterior;
	}

	delete a;
	delete b;
	delete c;
}

void blocoIsoladoB( void )
{
}

int main( int argc, char** argv )
{
	int ch;
	int aflag = 0;
	int bflag = 0;
	int cflag = 0;
	int dflag = 0;
	int eflag = 0;
	int fflag = 0;

	while( (ch = getopt(argc, argv, "abcdef")) != -1 )
	{
		switch( ch )
		{
			case 'a':
				aflag = 1;
				break;
			case 'b':
				bflag = 1;
				break;
			case 'c':
				cflag = 1;
				break;
			case 'd':
				dflag = 1;
				break;
			case 'e':
				eflag = 1;
				break;
			case 'f':
				fflag = 1;
				break;
			default:
				std::cout << "sem opção.\n";
				std::exit(0);
				break;
		}
	}

	if( aflag == 1 )
	{
		blocoIsoladoA();
	}
	else if( bflag == 1 )
	{
		ponteirosSaoFaceis();
	}

	//-------------------------

	FilaPrioritaria a;

	uint8_t u;

	for( u = 0; u < 10; u++ )
		a.enfileirar('n');

	a.descreva();

	for( u = 30; u > 0; u-- )
		a.desenfileirar();

	std::cout << "inferno na terra\n";
	std::exit(0);

	//---------------------------

	FilaPrioritaria saque('s');
	FilaPrioritaria deposito('s');
	FilaPrioritaria emprestimo('s');
	FilaPrioritaria financiamento('s');

	std::string controle = "nada";
	while( true )
	{
		std::cout << ">";
		std::cin >> controle;

		if ( controle == "sair" )
		{
			std::cout << "chau, leve este fumo maratá contigo!\n";
			break;
		}
		else if ( controle == "ajuda" )
		{
			std::cout << "LISTA DE COMANDOS DO TERMINAL:\n";
			std::cout << "enfileirar\n";
				std::cout << "\tprioridade: (p|n)\n";
				std::cout << "\toperacao (s|d|f|e)\n";
				std::cout << "\tSAÍDA DE STATUS\n";
			std::cout << "desenfileirar\n";
				std::cout << "\toperacao: (s|d|f|e)\n";
				std::cout << "\tSAÍDA ATENDIMENTO\n";
			std::cout << "painel\n";
			std::cout << "ajuda\n";
			std::cout << "sair\n";
		}
		else if ( controle == "enfileirar" )
		{
			char prioridade;
			char operacao;

			std::cout << "Prioridade>";
			std::cin >> prioridade;

			switch ( prioridade )
			{
				case 'n':
					std::cout << "Operacao>";
					std::cin >> operacao;

					switch ( operacao )
					{
						case 's':
							saque.enfileirar( 'n' );
							break;
						case 'd':
							deposito.enfileirar( 'n' );
							break;
						case 'f':
							financiamento.enfileirar( 'n' );
							break;
						case 'e':
							emprestimo.enfileirar( 'n' );
							break;
						default:
							std::cout << "operação inválida!";
							continue;
					}

					break;
				case 'p':
					std::cout << "Operacao>";
					std::cin >> operacao;

					switch ( operacao )
					{
						case 's':
							saque.enfileirar( 'p' );
							break;
						case 'd':
							deposito.enfileirar( 'p' );
							break;
						case 'f':
							financiamento.enfileirar( 'p' );
							break;
						case 'e':
							emprestimo.enfileirar( 'p' );
							break;
						default:
							std::cout << "operação inválida!";
							continue;
					}

					break;
				default:
					std::cout << "prioridade inválida!\n";
					continue;

			}
		}
		else if ( controle == "desenfileirar" )
		{
			char operacao;

			std::cout << "Operacao>";
			std::cin >> operacao;

			switch ( operacao )
			{
				case 's':
					std::cout << "s info\n";
					break;
				case 'd':
					std::cout << "d info\n";
					break;
				case 'f':
					std::cout << "f info\n";
					break;
				case 'e':
					std::cout << "e info\n";
					break;
				default:
					std::cout << "operação inválida!\n";
					continue;
			}

		}
		else if ( controle == "painel" )
		{
			std::cout << "SAQUE:\n";
			saque.descreva();

			std::cout << "DEPOSITO:\n";
			deposito.descreva();

			std::cout << "FINANCIAMENTO:\n";
			financiamento.descreva();

			std::cout << "EMPRESTIMO:\n";
			emprestimo.descreva();

		}
		else
		{
			std::cout << "não operação\n";
			continue;
		}
	}

	std::exit(0);
}
