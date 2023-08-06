#include <iostream>
#include "pilha.hpp"

Pilha::Pilha(): tamanho( 10 )
{
	this->m = new char[ tamanho ];

	ponteiroPilhae = 0;
	*( m + ponteiroPilhae ) = '-';
}

Pilha::Pilha( int tam ): tamanho( tam )
{

	this->m = new char[ tamanho ];

	if( tamanho > LIMITE )
	{
		std::cout << "pilha excede limite de número de elementos. corrigido para: " << LIMITE << '\n';
		tam = LIMITE;
	}

	tamanho = tam;
	ponteiroPilhae = 0;
	*( m + ponteiroPilhae ) = '-';
}

Pilha::~Pilha()
{
	delete m;
}

int Pilha::tam( void )
{
	return tamanho;
}

void Pilha::empilhar( char v )
{
	if( ponteiroPilhae >= LIMITE )
	{
		std::cout << "NEGADO! pilha cheia";
	}
	else
	{
		*( m + ponteiroPilhae ) = v;
		ponteiroPilhae++;
	}
}

char Pilha::desempilhar( void )
{
	int ret;

	if( ponteiroPilhae == 0 )
	{
		ret = '0';
	}
	else if( ponteiroPilhae  )
	{
		ponteiroPilhae--;
		ret = *( m + ponteiroPilhae );
		*( m + ponteiroPilhae ) = '-';
	}

	return ret;
}

char Pilha::topo( void )
{
	if( ponteiroPilhae == 0 )
	{
		return '0';
	}
	else if( ponteiroPilhae >= 1 )
		return *( m + ponteiroPilhae );

	return '-';
}

bool Pilha::vazia( void )
{
	if( ponteiroPilhae == 0 )
		return true;
	else
		return false;
}

bool Pilha::cheia( void )
{
	if( ponteiroPilhae == ( LIMITE - 1 ) )
		return true;
	else
		return false;
}
