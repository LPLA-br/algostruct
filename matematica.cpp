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
	//muito errado kkk
	if( (num % 6) != 0 )
	{
		std::cout << "não é primo:" << num << '\n';
	}
	else
	{
		std::cout << "é primo:" << num << '\n';
	}

}
