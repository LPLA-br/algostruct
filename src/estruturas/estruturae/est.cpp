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

/* Aponta o elemento para qual novo
 * prioritário deve ficar a frente.
 *
 * retorno
 * nullptr|
 * nullptr|inserção normal
 * nullptr| nullptr para endereço
 * endereço 0..2 posições após prioritário.
 * */
Senha* FilaPrioritaria::localizarPontoDeInsercao( void )
{
	Senha* bola = p;
	retornoLocalidade* retorno = new retornoLocalidade;

	//inserção normal até três elementos na estrutura.
	if ( p == nullptr )
	{
		retorno->afrente = nullptr;
		retorno->status = 0;
		return retorno;
	}
	else if ( numeroNos == 1 )
	{
		retorno->afrente = nullptr;
		retorno->status = 1;
		return retorno;
	}
	else if ( numeroNos == 2 )
	{
		retorno->afrente = nullptr;
		retorno->status = 2;
		return retorno;
	}

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
		//se último elemento é prioritário então
		//insere normalmente.
		return bola;
	}

	// disparo !
	while ( true )
	{
		if ( bola->anterior == nullptr )
		{
			break;
		}
		else if ( bola->anterior->prioridade == 'p' )
		{
			//ricocheteia
			break;
		}
		else
		{
			bola = bola->anterior;
		}
	}
	// ricocheteio para posição final no novo elemento

	retorno->status = 3;
	// 3..N
	
	
	
	return p;
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
			//Anexado ao fim. por enquanto
			novo->anterior = p;
			novo->proximo = nullptr;
			novo->prioridade = prioridade;
			novo->numero = novo->anterior->numero + 1;

			p->proximo = novo;
			p = p->proximo;

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

