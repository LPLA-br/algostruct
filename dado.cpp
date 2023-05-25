#include <iostream>
#include "tudo.hpp"

Dado::Dado(): tamanho( 10 )
{
	this->m = new int[ tamanho ];
}

Dado::Dado( int tam ): tamanho( tam )
{
	tamanho = tam;
	this->m = new int[ tamanho ];
}

Dado::~Dado()
{
	delete m;
}

int Dado::tam()
{
	return tamanho;
}
