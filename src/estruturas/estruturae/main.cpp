#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <unistd.h>

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
	printf( "valor:			%c\n    a", a );
	printf( "endereco:		%x\n   &a", &a );

	printf( "ponteiro------------------------\n" );
	printf( "valorArmazPelPnt:	%x\n    p", p );
	printf( "endereçoDoPnt:		%x\n   &p", &p );
	printf( "valorDaVarApontPelPnt:	%c\n   *p", *p );

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
	a->id = 1;
	a->rotulo = "produto A";
	a->preco = 1.00;
	a->proximo = b;
	a->anterior = nullptr;

	b = new Dados;
	b->id = 2;
	b->rotulo = "produto B";
	b->preco = 5.00;
	b->proximo = c;
	b->anterior = a;

	c = new Dados;
	c->id = 3;
	c->rotulo = "produto C";
	c->preco = 15.00;
	c->proximo = nullptr;
	c->anterior = b;


	while( p != nullptr )
	{
		std::cout << "id: " << p->id << " rotulo: " << p->rotulo << " preco: " << p->preco << '\n';
		p = p->proximo;
	}

	p = c;

	while( p != nullptr  )
	{
		std::cout << "id: " << p->id << " rotulo: " << p->rotulo << " preco: " << p->preco << '\n';
		p = p->anterior;
	}

	delete a;
	delete b;
	delete c;
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

	while( (ch = getopt(argc, argv, "ab")) != -1 )
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

	std::exit(0);
}
