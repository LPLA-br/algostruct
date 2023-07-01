#include <iostream>
#include <cstdlib>
#include <string>
#include "est.hpp"

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada( void )
{
	num_elementos = 1;

	corrente = new No;
	corrente->id = 0;
	corrente->c = '0';
	corrente->anterior = nullptr;
	corrente->posterior = nullptr;
}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada( void )
{
	while( corrente->anterior != nullptr )
	{
		corrente = corrente->anterior;
	}
	while( corrente->posterior != nullptr )
	{
		corrente = corrente->posterior;
		delete corrente->anterior;
	}
	delete corrente;
}

void ListaDuplamenteEncadeada::correnteParaUltimo( void )
{
	while( corrente->posterior != nullptr )
	{
		corrente = corrente->posterior;
	}
}

void ListaDuplamenteEncadeada::adicionarUltimo( char c )
{
	correnteParaUltimo();

	No* novo = new No;		//cria nó

	corrente->posterior = novo;		//posterior de corrente é novo

	novo->anterior = corrente;		//corrente é anterior de novo
	novo->posterior = nullptr;

	corrente = novo;		//avancar corrente para novo

	novo->c = c;

	num_elementos++;
}

char ListaDuplamenteEncadeada::retirarUltimo( void )
{
	char retorno = ' ';
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
	return retorno;
}

//end
