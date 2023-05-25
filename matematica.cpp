/*matematica.c*/
#include <iostream>
#include "tudo.hpp"

void Matematica::fibonatiA(void)
{
	unsigned int a = 1;
	unsigned int b = 1;
	unsigned int c = 0;

	for( int k = 0; k<=10; k++ )
	{
		c = a + b;
		std::cout << a << ' ' << b << ' ' << c << '\n';
		b = a;
		a = c;
	}
}

void Matematica::eprimo( int num )
{
	if( num < 0 ) return;
	unsigned int a = 2;
	while(true)
	{
		if( a == num )
		{
			std::cout << "não é primo\n";
			break;
		}
		else if( num % a == 0 )
		{
			std::cout << "é primo\n";
			break;
		}
		a++;
	}
}
