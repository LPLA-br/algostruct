#include <iostream>
#include <cstdbool>
#include <cstdlib>
#include <cstdint>
#include "arvore.hpp"

Arvore::Arvore( void )
{
	raiz = new No;
	raiz->direita = nullptr;
	raiz->esquerda = nullptr;
	raiz->info = "raiz";
}

Arvore::Arvore( std::string texto )
{
	raiz = new No;
	raiz->direita = nullptr;
	raiz->esquerda = nullptr;
	raiz->info = "raiz";
}


