#include <iostream>
#include <cstdlib>

#include "tad.hpp"
#include "pilha.hpp"
#include "fila.hpp"

void separadorVisual( void )
{
	std::cout << '\n' << "#################################################" << '\n' ;
}

int main( int argc, char* argv[] )
{
	//tadMaior

	Tad teste( 10 );

	std::cout << teste.maiorValor() << ":maiorValor\n";
	std::cout << teste.menorValor() << ":menorValor\n";

	teste.escrever( 't' );
	teste.inserir( 2 );
	teste.escrever( 't' );
	teste.inserir( 5 );
	teste.escrever( 't' );
	teste.inserir( 1 );
	teste.escrever( 't' );
	teste.inserir( 8 );
	teste.escrever( 't' );

	std::cout << teste.tamanhom() << "←Tamanho\n";

	teste.ordenar();
	std::cout << teste.maiorValor() << ":maiorValor\n";
	std::cout << teste.menorValor() << ":menorValor\n";

	separadorVisual();

	// PILHA ##############################################################

	Pilha p( 12 );

	int repete = 20;
	while( repete > 0 )
	{

		if( p.vazia() )
			std::cout << "pilha vazia\n";
		else
			std::cout << "pilha não vazia\n";

		std::cout << p.topo() << '\n';
		p.empilhar( 'k' );
		std::cout << p.topo() << '\n';
		p.empilhar( 'r' );
		std::cout << p.topo() << '\n';
		p.empilhar( 'o' );
		std::cout << p.topo() << '\n';
		p.empilhar( 'w' );
		std::cout << p.topo() << '\n';

		if( p.vazia() )
			std::cout << "pilha vazia\n";
		else
			std::cout << "pilha não vazia\n";

		std::cout << p.tam() << ":tamanho\n";

		std::cout << p.desempilhar() << ":desempilhado\n";
		std::cout << p.desempilhar() << ":desempilhado\n";
		std::cout << p.desempilhar() << ":desempilhado\n";
		std::cout << p.desempilhar() << ":desempilhado\n";
		std::cout << p.desempilhar() << ":desempilhado\n";
		std::cout << p.desempilhar() << ":desempilhado\n";
		std::cout << p.desempilhar() << ":desempilhado\n";
		std::cout << p.desempilhar() << ":desempilhado\n";
		std::cout << p.desempilhar() << ":desempilhado\n";

		if( p.vazia() )
			std::cout << "pilha vazia\n";
		else
			std::cout << "pilha não vazia\n";
	
		repete--;
	}

	// FILA #############################################################

	separadorVisual();
	
	Fila f;

	if( f.vazia() )
		std::cout << "vazia\n";
	else
		std::cout << "não vazia\n";

	f.status();
	f.enfileirar( 'p' );
	f.status();
	f.enfileirar( 'c' );
	f.status();
	f.enfileirar( 'c' );
	f.status();

	if( f.vazia() )
		std::cout << "vazia\n";
	else
		std::cout << "não vazia\n";

	std::cout << f.proximo() << '\n';
	std::cout << f.desenfileirar() << "←desenfileirado!\n";
	f.status();
	std::cout << f.proximo() << '\n';
	std::cout << f.desenfileirar() << "←desenfileirado!\n";
	f.status();
	std::cout << f.proximo() << '\n';
	std::cout << f.desenfileirar() << "←desenfileirado!\n";
	f.status();
	std::cout << f.proximo() << '\n';
	std::cout << f.desenfileirar() << "←desenfileirado!\n";
	f.status();
	std::cout << f.proximo() << '\n';
	std::cout << f.desenfileirar() << "←desenfileirado!\n";
	f.status();

	if( f.vazia() )
		std::cout << "vazia\n";
	else
		std::cout << "não vazia\n";

	f.limparFila();
	f.status();
	std::exit(0);

}
