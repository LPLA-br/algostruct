#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstdbool>
#include <stdint.h>
#include "est.hpp"

FilaPrioritaria::FilaPrioritaria( void )
{
	p = nullptr;
}

FilaPrioritaria::~FilaPrioritaria( void )
{
	if ( p == nullptr ) return;

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

void FilaPrioritaria::enfileirar( char prioridade, char operacao )
{
	Senha* novo = new Senha;

	if ( p == nullptr )
	{
		p = novo;
		novo->prioridade = prioridade;
		novo->operacao = operacao;
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
		novo->operacao = operacao;
		novo->numero = novo->anterior->numero + 1;
	}
}

void FilaPrioritaria::desenfileirar( void )
{

	if ( p == nullptr )
	{
		std::cout << "sem elementos\n";
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
		std::printf( "último atendido: p=%c op=%c num=%i\n", p->prioridade, p->operacao, p->numero );
		p = nullptr;
		delete morto;
	}
	else
	{
		Senha* morto = p;
		p = p->proximo;
		std::printf( "atendido: p=%c op=%c num=%i\n", p->anterior->prioridade, p->anterior->operacao, p->anterior->numero );
		p->anterior = nullptr;
		delete morto;
	}
	return;
}

void FilaPrioritaria::descreva( void )
{
	while( p->anterior != nullptr )
	{
		p = p->anterior;
	}
	while( p->proximo != nullptr && p != nullptr )
	{
		std::printf( "%c%c%n a=%x p=%x\n", p->prioridade, p->operacao, p->numero, p->anterior, p->proximo );
		p = p->proximo;
	}
}

//	FIM
