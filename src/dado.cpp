#include <iostream>
#include "pilha.hpp"

Pilha::Pilha(): tamanho( 10 )
{
	this->m = new int[ tamanho ];
	*(m+0) = 0; //primeira posição recebe 0
	ponteiroPilhae = 1;
	ordenado = false;
}

Pilha::Pilha( int tam ): tamanho( tam )
{

	if( tamanho > PILHAMAX )
	{
		std::cout << "pilha excede limite de número de elementos. corrigindo para 10000";
		tam = PILHAMAX;
	}

	tamanho = tam;
	this->m = new int[ tamanho ];
	*(m+0) = 0; //primeira posição recebe 0
	ponteiroPilhae = 1;
	ordenado = false;
}

Pilha::~Pilha()
{
	delete m;
}

int Pilha::tam( void )
{
	return tamanho;
}

void Pilha::ordenar( void )
{
	/*Insertion*/
	for( int abs = 2; abs < tamanho; abs++ )
	{
		for( int aux = abs-1; aux > -1; aux--)
		{
			if( *(m+(aux+1)) > *(m+aux) )
			{
				int tmp = *(m+aux);
				*(m+aux) = *(m+(aux+1));
				*(m+(aux+1)) = tmp;
			}
			else break;
		}
	}
	std::cout << "Pilha ordenada\n";
	ordenado = true;
}

void Pilha::inserirValor( int v )
{
	if( ponteiroPilhae >= tamanho )
	{
		std::cout << "pilha cheia";
	}
	else
	{
		ponteiroPilhae++;
		*(m+ponteiroPilhae) = v;
	}
}

int Pilha::removerValor( void )
{
	int ret;

	if( ponteiroPilhae == 1 )
	{
		std::cout << "pilha com um elemento";
	}
	else
	{
		ret = *(m+ponteiroPilhae);
		ponteiroPilhae--;
		*(m+(ponteiroPilhae+1)) = 0;
		return ret;
	}
}

int Pilha::maiorValor( void )
{
	if ( ordenado == true )
	{
		return *(m+(tamanho-1));
	}
	else return 0;
}

int Pilha::menorValor( void )
{
	if ( ordenado == true )
	{
		return *(m+0);
	}
	else return 0;
}

void Pilha::printPilha( void )
{
	int leitor;
	for( leitor = 0; leitor < tamanho; leitor++ )
	{
		std::cout << " " << *(m+leitor);
	}
	std::cout << "\n";
}

