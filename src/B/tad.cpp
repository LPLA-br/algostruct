#include <iostream>
#include "tad.hpp"

Tad::Tad(): tamanho( 10 )
{
	this->m = new int[ tamanho ];
	ponteiroTade = 0;
	*( m + ponteiroTade ) = 0;
	ordenado = false;
}

Tad::Tad( int tam ): tamanho( tam )
{

	this->m = new int[ tamanho ];

	if( tamanho > LIMITE )
	{
		std::cout << "pilha excede limite de número de elementos. corrigindo para 10000";
		tam = LIMITE;
	}

	tamanho = tam;
	ponteiroTade = 0;

	*( m + ponteiroTade ) = 0;
	ordenado = false;
}

Tad::~Tad()
{
	delete m;
}

int Tad::tamanhom( void )
{
	return tamanho;
}

void Tad::ordenar( void )
{
	/*selection sort - zero até ponteiroTade*/
	int menor;
	for( int absoluto = 0; absoluto < ponteiroTade; absoluto++ )
	{
		menor = absoluto;
		for( int indicador = absoluto; indicador < ponteiroTade; indicador++ )
		{
			if( *(m+menor) > *(m+indicador) )
			{
				menor = indicador;
			}
		}
		//troca
		int tmp = *(m+menor);
		*(m+menor) = *(m+absoluto);
		*(m+absoluto) = tmp;
	}
	ordenado = true;
}

void Tad::inserir( int v )
{
	if( ponteiroTade >= LIMITE )
	{
		std::cout << "NEGADO! tad cheio";
	}
	else
	{
		*( m + ponteiroTade ) = v;
		ponteiroTade++;
	}
}

int Tad::maiorValor( void )
{
	if ( ordenado == true )
	{
		return *( m + (ponteiroTade - 1) );
	}
	else return -1;
}

int Tad::menorValor( void )
{
	if ( ordenado == true )
	{
		return *(m+0);
	}
	else return -1;
}

void Tad::escrever( char modo )
{
	int leitor;
	switch( modo)
	{
		case 't':
			//tudo
			for( leitor = 0; leitor < tamanho-1; leitor++ )
			{
				std::cout << " " << *(m+leitor);
			}
			std::cout << "    " << ponteiroTade << "\n";
			break;
		case 'p':
			//até ponteiroTade
			for( leitor = 0; leitor < ponteiroTade; leitor++ )
			{
				std::cout << " " << *(m+leitor);
			}
			break;
		default:
			std::cout << "modo de escrita não definido para: escrever( char modo )\n";
			break;
	}
	std::cout << "\n";
}

