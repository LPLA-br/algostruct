#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstdbool>
#include "est.hpp"

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada( void )
{
	corrente = nullptr;
}

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada( char c )
{
	num_elementos = 1;
	corrente = new No;
	corrente->id = 0;
	corrente->c = c;
	corrente->anterior = nullptr;
	corrente->posterior = nullptr;
}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada( void )
{
	if ( vazio() ) return;

	correnteParaPrimeiro();
	while( corrente->posterior != nullptr )
	{
		corrente = corrente->posterior;
		delete corrente->anterior;
	}
	delete corrente;
}

void ListaDuplamenteEncadeada::correnteParaUltimo( void )
{
	if ( vazio() ) return;

	while( corrente->posterior != nullptr )
	{
		corrente = corrente->posterior;
	}
}

void ListaDuplamenteEncadeada::correnteParaPrimeiro( void )
{
	if ( vazio() ) return;

	while( corrente->anterior != nullptr )
	{
		corrente = corrente->anterior;
	}
}

void ListaDuplamenteEncadeada::correnteParaAntesDe( unsigned short int posicao )
{

}

bool ListaDuplamenteEncadeada::vazio( void )
{
	if( corrente == nullptr ) return true;
	else return false;
}

void ListaDuplamenteEncadeada::adicionarUltimo( char c )
{
	No* novo = new No;

	switch( vazio() )
	{
		case true:
			corrente = novo;
			novo->anterior = nullptr;
			novo->posterior = nullptr;
			break;
		case false:
			correnteParaUltimo();
			corrente->posterior = novo;
			novo->anterior = corrente;
			novo->posterior = nullptr;
			corrente = novo;
			novo->id = corrente->anterior->id + 1;
			novo->c = c;
			num_elementos++;
			break;
	}
}

char ListaDuplamenteEncadeada::retirarUltimo( void )
{
	char retorno = '\0';
	if( num_elementos > 1 )
	{
		correnteParaUltimo();
		retorno = corrente->c;
		corrente = corrente->anterior;
		delete corrente->posterior;
		corrente->posterior = nullptr;
		num_elementos--;
		return retorno;
	}
	else
	{
		return corrente->c;
	}
}

void ListaDuplamenteEncadeada::adicionarComesso( char c )
{
	correnteParaPrimeiro();
	No* novo = new No;
	corrente->anterior = novo;
	novo->posterior = corrente;
	novo->anterior = nullptr;
	novo->c = c;
	novo->id = corrente->id;
	while( corrente->posterior != nullptr )
	{
		corrente->id = corrente->anterior->id + 1;
		corrente = corrente->posterior;
	}
	num_elementos++;
}

char ListaDuplamenteEncadeada::retirarComesso( void )
{
	char retorno = '\0';
	correnteParaPrimeiro();
	if( num_elementos > 1 )
	{
		retorno = corrente->c;
		corrente = corrente->posterior;
		delete corrente->anterior;
		corrente->anterior = nullptr;
		while( corrente->posterior != nullptr )
		{
			corrente->id--;
			corrente = corrente->posterior;
		}
		return retorno;
	}
	else
	{
		return corrente->c;
	}
}

/*
void ListaDuplamenteEncadeada::adicionarFrentePosicao( unsigned short int posicao, char c )
{

}

char removerFretnePosicao( unsigned short int posicao, char c );
{
	return '';
}*/

void ListaDuplamenteEncadeada::descreva( void )
{
	correnteParaPrimeiro();
	while( 1 )
	{
		std::printf( "%c %i número de elementos: %i\n", corrente->c, corrente->id, num_elementos );
		if ( corrente->posterior != nullptr )
			corrente = corrente->posterior;
		else break;
	}
}

//end
