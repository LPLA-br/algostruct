#include <iostream>
#include <cstdlib>

#include "dado.hpp"

int main( int argc, char* argv[] )
{

	Tad a( 12 );

	std::cout << a.tamanhom() << ":tamanho\n";

	std::cout << a.maiorValor() << ":maiorValor\n";
	std::cout << a.menorValor() << ":menorValor\n";
	
	a.escrever( 't' );
	a.inserirValor( 9 );
	a.escrever( 't' );
	a.inserirValor( 7 );
	a.escrever( 't' );
	a.inserirValor( 5 );
	a.escrever( 't' );
	a.inserirValor( 2 );
	a.escrever( 't' );
	a.inserirValor( 1 );
	a.escrever( 't' );

	a.ordenar();
	std::cout << a.maiorValor() << ":maiorValor\n";
	std::cout << a.menorValor() << ":menorValor\n";

	a.escrever( 't' );
	std::cout << a.removerValor() << ":retirado\n";
	a.escrever( 't' );
	std::cout << a.removerValor() << ":retirado\n";
	a.escrever( 't' );
	std::cout << a.removerValor() << ":retirado\n";
	a.escrever( 't' );
	std::cout << a.removerValor() << ":retirado\n";
	a.escrever( 't' );
	std::cout << a.removerValor() << ":retirado\n";
	a.escrever( 't' );
	std::cout << a.removerValor() << ":retirado\n";
	a.escrever( 't' );
	std::cout << a.removerValor() << ":retirado\n";
	a.escrever( 't' );

	std::exit(0);
}
