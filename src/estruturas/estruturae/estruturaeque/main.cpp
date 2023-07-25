#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "arboribus.hpp"


void separador( void )
{
	std::cout << "---------------------------------------------------------------\n";
}

int main( int argc, char** argv )
{
	int ch;
	int aflag = 0;
	int bflag = 0;
	int cflag = 0;
	int dflag = 0;
	int eflag = 0;
	int fflag = 0;

	while( (ch = getopt(argc, argv, "abcdef")) != -1 )
	{
		switch( ch )
		{
			case 'a':
				aflag = 1;
				break;
			case 'b':
				bflag = 1;
				break;
			case 'c':
				cflag = 1;
				break;
			case 'd':
				dflag = 1;
				break;
			case 'e':
				eflag = 1;
				break;
			case 'f':
				fflag = 1;
				break;
			default:
				std::cout << "sem opção.\n";
				std::exit(0);
				break;
		}
	}

	if( aflag == 1 )
	{
		blocoIsoladoA();
	}
	else if( bflag == 1 )
	{
		ponteirosSaoFaceis();
	}

	std::exit(0);
}
