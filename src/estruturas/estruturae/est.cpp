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

FilaPrioritaria::FilaPrioritaria( char prioridade, char operacao, uint8_t numero )
{
	Senha* p = new Senha;
	p->prioridade = prioridade;
	switch( operacao )
	{
		case 'e':
			p->operacao = operacao;
			break;
		case 's':
			p->operacao = operacao;
			break;
		case 'd':
			p->operacao = operacao;
			break;
		case 'f':
			p->operacao = operacao;
			break;
		default:
			std::cout << "operação bancária inválida detectada !\nabortar";
			delete p;
			std::exit(0);
	}
	p->numero = 0;

	p->anterior = nullptr;
	p->proximo = nullptr;

}

FilaPrioritaria::~FilaPrioritaria( void )
{
	irPrimeiro();
	while( p->proximo != nullptr )
	{
		p = p->proximo;
		delete p->anterior;
	}
	delete p;
}

void FilaPrioritaria::irUltimo( void )
{
	while( p->proximo != nullptr )
	{
		p = p->proximo;
	}
}

void FilaPrioritaria::irPrimeiro( void )
{
	while( p->anterior != nullptr )
	{
		p = p->anterior;
	}
}

bool FilaPrioritaria::verifPrioridadeEtOperacao( char prioridade, char operacao )
{
	bool p = false;
	bool o = false;

	switch( prioridade )
	{
		case 'n':
			p = true;
			break;
		case 'p':
			p = true;
		default:
			p = false;
	}
	switch( operacao )
	{
		case 'e':
			o = true;
			break;
		case 's':
			o = true;
			break;
		case 'd':
			o = true;
			break;
		case 'f':
			o = true;
			break;
		default:
			o = false;
	}

	if( p && o )
		return true;
	else
		return false;

}

void FilaPrioritaria::enfileirar( char prioridade, char operacao )
{
	Senha* novo = new Senha;

	if( verifPrioridadeEtOperacao( prioridade, operacao ) )
	{

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

		irUltimo();

		p->proximo = novo;

		novo->anterior = p;
		novo->proximo = nullptr;

		novo->prioridade = prioridade;
		novo->operacao = operacao;
		novo->numero = novo->anterior->numero + 1;
		
		p = novo;
	}
	else
	{
		std::cout << "Enfileiramento abortado: prioridade ou operação inválida(s)\n";
	}

	return;
}

void FilaPrioritaria::desenfileirar( void )
{
	irPrimeiro();

	if ( p == nullptr )
		std::cout << "sem elementos\n";
	else if ( p->proximo == nullptr && p->anterior == nullptr )
	{
		std::printf( "último atendido: p=%c op=%c num=%c\n", p->prioridade, p->operacao, p->numero );
		delete p;
		p = nullptr;
	}
	else
	{
		p = p->proximo;
		std::printf( "atendido: p=%c op=%c num=%c\n", p->anterior->prioridade, p->anterior->operacao, p->anterior->numero );
		delete p->anterior;
		p->anterior = nullptr;
	}
	return;
}

void FilaPrioritaria::descreva( void )
{
	irPrimeiro();
	while( p->proximo != nullptr )
	{
		std::printf( "%c%c%n\n", p->prioridade, p->operacao, p->numero );
		p = p->proximo;
	}
}

//	FIM
