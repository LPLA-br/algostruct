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
		p = novo;
		novo->prioridade = prioridade;
		p->numero = 0;
		p->proximo = nullptr;
		p->anterior = nullptr;
		return;
	}
	else
	{
		while( p->proximo != nullptr )
		{
			p = p->proximo;
		}
		p->proximo = novo;
		novo->anterior = p;
		novo->proximo = nullptr;
		novo->prioridade = prioridade;
		novo->numero = novo->anterior->numero + 1;
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
		// para 1..N elementos
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
	}
	else
	{
		Senha* morto = p;
		std::printf( "atendido: p=%c op=%c num=%i\n", p->prioridade, this->operacao, p->numero );
		p = p->proximo;
		p->anterior = nullptr;
		delete morto;
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

