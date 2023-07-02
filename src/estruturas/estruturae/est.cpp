#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstdbool>
#include "est.hpp"

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada( void )
{
	num_elementos = 0;
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

	if ( vazio() )
	{
			corrente = novo;
			novo->id = 0;
			novo->c = c;
			novo->anterior = nullptr;
			novo->posterior = nullptr;
			num_elementos = 1;
	}
	else
	{
			correnteParaUltimo();
			corrente->posterior = novo;
			novo->anterior = corrente;
			novo->posterior = nullptr;
			novo->id = novo->anterior->id + 1;
			novo->c = c;
			num_elementos++;
	}
}

char ListaDuplamenteEncadeada::retirarUltimo( void )
{
	char retorno = '\0';

	if (  vazio() )
	{
		return retorno;
	}
	else
	{
		correnteParaUltimo();
		if ( num_elementos == 1 )
		{
			retorno = corrente->c;
			delete corrente;
			corrente = nullptr;
			num_elementos = 0;
			return retorno;
		}
		else
		{
			retorno = corrente->c;
			corrente = corrente->anterior;
			delete corrente->posterior;
			corrente->posterior = nullptr;
			num_elementos--;
			return retorno;
		}
	}
}

void ListaDuplamenteEncadeada::adicionarComesso( char c )
{
	No* novo = new No;

	if ( vazio() )
	{
			corrente = novo;
			novo->id = 0;
			novo->c = c;
			novo->posterior = nullptr;
			novo->anterior = nullptr;
			num_elementos = 1;
	}
	else
	{
			correnteParaPrimeiro();
			corrente->anterior = novo;
			novo->posterior = corrente;
			novo->id = corrente->id;
			novo->c = c;
			while ( corrente->posterior != nullptr )
			{
				corrente->id = corrente->anterior->id + 1;
				corrente = corrente->posterior;
			}
			num_elementos++;
	}
}

char ListaDuplamenteEncadeada::retirarComesso( void )
{
	char retorno = '\0';

	if ( vazio() ) return retorno;

	correnteParaPrimeiro();

	if( num_elementos == 1 )
	{
		retorno = corrente->c;
		delete corrente;
		corrente = nullptr;
		num_elementos = 0;
		return retorno;
	}
	else
	{
		retorno = corrente->c;
		corrente = corrente->posterior;
		delete corrente->anterior;
		corrente->anterior = nullptr;
		return retorno;
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
	if ( vazio() ) return;

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
