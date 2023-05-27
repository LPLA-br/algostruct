#include <iostream>
#include "dado.hpp"

Tad::Tad(): tamanho( 10 )
{
	this->m = new int[ tamanho ];
	ponteiroPilhae = 0;
	*( m + ponteiroPilhae ) = 0;
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
	ponteiroPilhae = 0;

	*( m + ponteiroPilhae ) = 0;
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
	/*selection sort - zero até ponteiroPilhae*/
	int menor;
	for( int absoluto = 0; absoluto < ponteiroPilhae; absoluto++ )
	{
		menor = absoluto;
		for( int indicador = absoluto; indicador < ponteiroPilhae; indicador++ )
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

void Tad::inserirValor( int v )
{
	if( ponteiroPilhae > LIMITE )
	{
		std::cout << "NEGADO! pilha cheia";
	}
	else
	{
		*( m + ponteiroPilhae ) = v;
		ponteiroPilhae++;
	}
}

int Tad::removerValor( void )
{
	int ret;

	ponteiroPilhae--;

	if( ponteiroPilhae < 0 )
	{
		ponteiroPilhae = 0;
	}

	ret = *( m + ponteiroPilhae );
	*( m + ponteiroPilhae ) = 0;
	return ret;
}

int Tad::maiorValor( void )
{
	if ( ordenado == true )
	{
		return *( m + (ponteiroPilhae - 1) );
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
			std::cout << "    " << ponteiroPilhae << "\n";
			break;
		case 'p':
			//até ponteiroPilhae
			for( leitor = 0; leitor < ponteiroPilhae; leitor++ )
			{
				std::cout << " " << *(m+leitor);
			}
			break;
		default:
			std::cout << "modo de escrita não definido para escrever( char modo )\n";
			break;
	}
	std::cout << "\n";
}

