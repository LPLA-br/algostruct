/*utilitarios.c*/
#include <iostream>
#include <cstdlib>
#include "utilitarios.hpp"


void Utilitarios::escreverMatriz( int* m, unsigned int tamanho )
{
	for( unsigned int p=0; p < tamanho; p++ )
	{
		std::cout << *(m+p) << ' ';
	}
	std::cout << '\n';
}

unsigned int Utilitarios::mediaEntreDoisNumeros( int a, int b )
{
	return ((a+b)/2);
}

void Utilitarios::swap( int* a, int* b  )
{
	int tmp;
	tmp = *(a);
	*(a) = *(b);
	*(b) = tmp;
}

void Utilitarios::escreverMatrizEntreValores( int* m, unsigned int comesso, unsigned int fim )
{
	std::cout << '\n';
	for( comesso; comesso <= fim; comesso ++ )
	{
		std::cout << *( m + comesso ) << ' ';
	}
	std::cout << '\n';
}

//problemas com ponteiros.
int* Utilitarios::gerarmatrizaleatoria( int tamanho, int maxnum )
{
	srand( (unsigned)time(NULL) );
	int pos = 0;
	int* geracao = new int[tamanho];

	for( pos = 0; pos < tamanho; pos++ )
	{
		//0-99
		*(geracao + pos) = rand() % maxnum;
	}
	return geracao;
}

int* Utilitarios::gerarmatrizordendadadecrescente( int tamanho, int maxnum )
{
	int* geracao = new int[tamanho];
	int pos;
	int inverso = tamanho;
	for( pos = 0; pos < tamanho; pos++ )
	{
		*( geracao + pos ) = inverso;
		inverso--;
	}
	return geracao;
}
