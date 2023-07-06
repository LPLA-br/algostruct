#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstdbool>
#include <stdint.h>
#include "est.hpp"

FilaPrioritaria::FilaPrioritaria( void )
{
	operacao = 'd';
	p = nullptr;
}

FilaPrioritaria::FilaPrioritaria( char op )
{
	operacao = op;
	p = nullptr;
}

FilaPrioritaria::~FilaPrioritaria( void )
{
	if ( p == nullptr )
	{
		std::cout << "destruição de fila prioritaria vazia";
		return;
	}

	while( p->anterior != nullptr )
	{
		p = p->anterior;
	}
	while( p->proximo != nullptr )
	{
		p = p->proximo;
		Senha* morto = p->anterior;
		p->anterior = nullptr;
		delete morto;
	}
	delete p;
}

void FilaPrioritaria::enfileirar( char prioridade )
{
	Senha* novo = new Senha;

	if ( p == nullptr )
	{
		novo->prioridade = prioridade;
		novo->numero = 0;
		novo->proximo = nullptr;
		novo->anterior = nullptr;

		p = novo;
		return;
	}
	else
	{
		if ( prioridade == 'p' )
		{
			novo->anterior = p;
			novo->proximo = nullptr;
			novo->prioridade = prioridade;
			novo->numero = novo->anterior->numero + 1;

			p->proximo = novo;
			p = p->proximo;

			//descida por "gravidade"
			//intercalação 0..2 descartada! Adotando 0..1
			
			while ( true )
			{
				Senha* a = p->proximo;
				Senha* aa = p->proximo->proximo;

				if ( aa == nullptr )
				{
					break;
				}

				if ( a->prioridade == 'n' && aa->prioridade == 'n' )
				{
					if ( p->anterior == nullptr )
					{
						// enfiar p no meio de aa e a
						// a->anterior = null

						a->anterior = nullptr;
						a->proximo = p;

						p->anterior = a;
						p->proximo = aa;

						aa->anterior = p;
					}
					else
					{
						//a será o anterior de p e o proximo doutro.
						p->anterior = ;
						p->proximo = ;

					}

				}
			}

			return;
		}

		while ( p->proximo != nullptr )
		{
			p = p->proximo;
		}

		novo->anterior = p;
		novo->proximo = nullptr;
		novo->prioridade = prioridade;
		novo->numero = novo->anterior->numero + 1;

		p->proximo = novo;
		p = p->proximo;
	}
}

void FilaPrioritaria::desenfileirar( void )
{

	if ( p == nullptr )
	{
		std::cout << "V A Z I O\n";
		return;
	}
	else
	{
		while( p->anterior != nullptr )
		{
			p = p->anterior;
		}
	}


	if ( p->proximo == nullptr && p->anterior == nullptr )
	{
		Senha* morto = p;
		std::printf( "último atendido: p=%c op=%c num=%i\n", p->prioridade, this->operacao, p->numero );
		p = nullptr;
		delete morto;
		morto = NULL;
	}
	else
	{
		Senha* morto = p;
		std::printf( "atendido: p=%c op=%c num=%i\n", p->prioridade, this->operacao, p->numero );
		p = p->proximo;
		p->anterior = nullptr;
		delete morto;
		morto = NULL;
	}
	return;
}

void FilaPrioritaria::descreva( void )
{
	if ( p == nullptr )
	{
		std::cout << "V A Z I O\n";
		return;
	}

	while( p->anterior != nullptr )
	{
		p = p->anterior;
	}
	while( p->proximo != nullptr )
	{
		std::printf( "p=%c n=%i a=%x ( %x ) p=%x\n", p->prioridade, p->numero, p->anterior, p, p->proximo );
		p = p->proximo;
	}

}

