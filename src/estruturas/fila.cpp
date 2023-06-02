#include <iostream>
#include "fila.hpp"

Fila::Fila()
{
	this->m = new char[ MAXIMVS ];
	caput = 0;
	pedes = 0;
}

Fila::~Fila()
{
	delete m;
}

void Fila::enfileirar( char letra )
{
	if( !( cheia() ) )
	{
		*( m + caput ) = letra;
		caput++;
	}
	else
	{
		std::cout << "fila cheia\n";
	}
}

char Fila::desenfileirar( void )
{
	char ret = *( m + pedes );
	*( m + pedes ) = 0;
	if( pedes < caput )
	{
		pedes++;
	}
	return ret;
}

void Fila::limparFila( void )
{
	caput = 0;
	pedes = 0;
	int p;
	for( p = 0; p < MAXIMVS; p++ )
	{
		*( m + p ) = 0;
	}
	std::cout << "pilha limpa\n";
}

char Fila::proximo( void )
{
	return *( m + pedes );
}

bool Fila::vazia( void )
{
	if( caput == pedes )
		return true;
	else if( pedes < caput )
		return false;

	return true;
}

bool Fila::cheia( void )
{
	if( caput == ( MAXIMVS - 1 ) )
		return true;
	else
		return false;
}

void Fila::status( void )
{
	std::cout << pedes << "←pedes " << caput << "←caput" << '\n';
}
