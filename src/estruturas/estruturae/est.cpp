#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstdbool>
#include <stdint.h>
#include "est.hpp"

FilaPrioritaria::FilaPrioritaria( void )
{
	operacao = 'd';
	p = nullptr;
}

FilaPrioritaria::FilaPrioritaria( char op )
{
	operacao = op;
	p = nullptr;
}

FilaPrioritaria::~FilaPrioritaria( void )
{
	if ( p == nullptr )
	{
		std::cout << "destruição de fila prioritaria vazia";
		return;
	}

	while( p->anterior != nullptr )
	{
		p = p->anterior;
	}
	while( p->proximo != nullptr )
	{
		p = p->proximo;
		Senha* morto = p->anterior;
		p->anterior = nullptr;
		delete morto;
	}
	delete p;
}

/* Retorna o endereço do anterior do novo nó.
 * ou nullptr para indicar inserção normal no
 * fim da fila.
 * */
Senha* FilaPrioritaria::localizarPontoDeInsercaoParaPrioritarios( void )
{
	Senha* bola = p;

	//inserção normal até três elementos na estrutura.
	if ( p == nullptr )
	{
		return nullptr;
	}
	else if ( numeroNos == 1 )
	{
		return nullptr;
	}
	else if ( numeroNos == 2 )
	{
		return nullptr;
	}

	//EM TRÊS ELEMENTOS O COCO SECA !

	//posicionamento da bola.
	while ( bola->anterior != nullptr )
	{
		bola = bola->anterior;
	}
	while ( bola->proximo != nullptr )
	{
		bola = bola->proximo;
	}

	if ( bola->prioridade == 'p' )
	{
		/*se último elemento é prioritário então
		insere normalmente. retorna o anterior do novo*/
		return bola;
	}

	// seguir até um Prioritário e parar ante ele.
	while ( true )
	{
		if ( bola->anterior == nullptr )
		{
			//atingiu o comesso da estrutura.
			break;
		}
		else if ( bola->anterior->prioridade == 'p' )
		{
			/*atingiu o último elemento N antes de um P */
			break;
		}
		else
		{
			bola = bola->anterior;
		}
	}
	// ricocheteio para posição final no novo elemento
	while( true )
	{
		//retorna o anterior do novo nó
		if ( bola->proximo != nullptr )
		{
			bola = bola->proximo;
			return bola;
		}
		else 
		{
			return bola;
		}
	}
}

void FilaPrioritaria::enfileirar( char prioridade )
{
	Senha* novo = new Senha;

	if ( p == nullptr )
	{
		novo->prioridade = prioridade;
		novo->numero = 0;
		novo->proximo = nullptr;
		novo->anterior = nullptr;

		p = novo;

		numeroNos = 1;
		return;
	}
	else
	{
		while ( p->proximo != nullptr )
		{
			p = p->proximo;
		}

		if ( prioridade == 'p' )
		{
			Senha* res = localizarPontoDeInsercaoParaPrioritarios();
			if ( res == nullptr )
			{
				//inserção natural no fim da fila.
				while ( p->proximo != nullptr )
				{
					p = p->proximo;
				}
				novo->anterior = p;
				novo->proximo = nullptr;
				novo->prioridade = prioridade;
				novo->numero = novo->anterior->numero + 1;

				p->proximo = novo;
				p = p->proximo;

			}
			else
			{
				//definindo para novo.
				novo->anterior = res;
				novo->proximo = res->proximo;

				novo->anterior->proximo = novo;
				if ( novo->proximo != nullptr )
				{
					novo->proximo->anterior = novo;
				}
			}

			numeroNos++;
			return;
		}

		//anexando ao fim.
		novo->anterior = p;
		novo->proximo = nullptr;
		novo->prioridade = prioridade;
		novo->numero = novo->anterior->numero + 1;

		p->proximo = novo;
		p = p->proximo;

		numeroNos++;
	}
}

void FilaPrioritaria::desenfileirar( void )
{

	if ( p == nullptr )
	{
		std::cout << "V A Z I O\n";
		return;
	}
	else
	{
		while( p->anterior != nullptr )
		{
			p = p->anterior;
		}
	}


	if ( p->proximo == nullptr && p->anterior == nullptr )
	{
		Senha* morto = p;
		std::printf( "último atendido: p=%c op=%c num=%i\n", p->prioridade, this->operacao, p->numero );
		p = nullptr;
		delete morto;
		morto = NULL;
	
		numeroNos = 0;
	}
	else
	{
		Senha* morto = p;
		std::printf( "atendido: p=%c op=%c num=%i\n", p->prioridade, this->operacao, p->numero );
		p = p->proximo;
		p->anterior = nullptr;
		delete morto;
		morto = NULL;

		numeroNos--;
	}
	return;
}

void FilaPrioritaria::descreva( void )
{
	if ( p == nullptr )
	{
		std::cout << "V A Z I O\n";
		return;
	}

	while( p->anterior != nullptr )
	{
		p = p->anterior;
	}
	while( p->proximo != nullptr )
	{
		//chega-se ao último elemento.
		//Entretando não há execução deste corpo para o último.
		std::printf( "p=%c n=%i a=%x ( %x ) p=%x\n", p->prioridade, p->numero, p->anterior, p, p->proximo );
		p = p->proximo;
	}
	std::printf( "p=%c n=%i a=%x ( %x ) p=%x\n", p->prioridade, p->numero, p->anterior, p, p->proximo );
	std::printf( "numeroNos: %i\n", this->numeroNos );

}

