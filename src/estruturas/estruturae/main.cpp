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
	ListaDuplamenteEncadeada a;
	uint8_t k = 0;
	for( k = 65; k < 91; k++ )
	{
		a.adicionarUltimo( char(k) );
	}
	a.descreva();
	for( k = 0; k < 30; k++ )
	{
		std::cout << a.retirarUltimo();
	}
	for( k = 97; k < 123; k++ )
	{
		a.adicionarComesso( char(k) );
	}
	a.descreva();
	for( k = 0; k < 30; k++ )
	{
		std::cout << a.retirarComesso();
	}
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
	else if( cflag == 1 )
	{
		blocoIsoladoB();
	}

	std::exit(0);
}
