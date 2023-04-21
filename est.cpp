/*##############################################
 * B U S C A    E    O R D E N A Ç Ã O         #
 *##############################################*/
#include <iostream>
#include <cstdlib>
#include <string>

/*##############################################
 *#
 *#  SETOR DE DEFINIÇÃO DE:
 *#   CLASSES
 *#   FUNÇÕES MEMBROS
 *#
 *##############################################*/

class Utilitarios
{
	private:
	protected:
	public:
		void printMatriz( int* m, unsigned int tamanho );
		unsigned int mediaEntreDoisNumeros( int a, int b );
		void swap( int* a, int* b );
};

void Utilitarios::printMatriz( int* m, unsigned int tamanho )
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

class Matematica
{
	private:
	protected:
	public:
		void fibonatiA(void);
		void eprimo( int num );
};

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

class Ordenacao
{
	private:
	protected:
	public:
		int* ordenacaoBolha( int* matriz, unsigned int tamanho );
};

int* Ordenacao::ordenacaoBolha( int matriz[], unsigned int tamanho )
{
	Utilitarios operation;
	int i, abspnt;
	for( abspnt = tamanho-1; abspnt < tamanho; abspnt-- )
	{
		for( i = 0; i < tamanho-1; i++ )
		{
			if( matriz[i] > matriz[i+1] )
			{
				operation.swap( &matriz[i], &matriz[i+1]  );
			}
		}
	}
	return matriz;
}

class Busca
{
	private:
	protected:
	public:
		unsigned int buscaLinear( int alvo, int matriz[] );
		void buscaBinariaAlfabeto( char caractereAlvo, unsigned int tamanhoAbs, const char* alfabeto );
		void buscaBinariaNumerica( int numalvo, unsigned int tamanhoAbs, const int* matriz);
};

/* PRE-REQUISITO: dados ordenados numéricamente ou alfabeticamente */
void Busca::buscaBinariaAlfabeto( char caractereAlvo, unsigned int tamanhoAbs, const char alfabeto[] )
{
	Utilitarios operation;

	unsigned int posComeco = 0, posMeio = 0, posFim = tamanhoAbs-1;
	posMeio = (unsigned int)(tamanhoAbs / 2);

	while( true )
	{
		if( caractereAlvo > alfabeto[posMeio] )
		{
			// quebra a direita->
			posComeco = posMeio;
			posMeio = operation.mediaEntreDoisNumeros( posComeco, posFim );
		}
		else if( caractereAlvo < alfabeto[posMeio] )
		{
			//<-quebra a esquerda
			posFim = posMeio;
			posMeio = operation.mediaEntreDoisNumeros( posComeco, posFim );
		}

		// Apenas a saida da busca.
		if( alfabeto[posMeio] == caractereAlvo )
		{
			std::cout << alfabeto[posMeio] << ' ';
			std::cout << posMeio << '\n';
			break;
		}
	}
}

void Busca::buscaBinariaNumerica( int numalvo, unsigned int tamanhoAbs, const int matriz[] )
{
	Utilitarios operation;

	unsigned int posComeco = 0, posMeio = 0, posFim = tamanhoAbs-1;
	posMeio = (unsigned int)(tamanhoAbs / 2);

	while( true )
	{
		if( numalvo > matriz[posMeio] )
		{
			// quebra a direita->
			posComeco = posMeio;
			posMeio = operation.mediaEntreDoisNumeros( posComeco, posFim );
		}
		else if( numalvo < matriz[posMeio] )
		{
			//<-quebra a esquerda
			posFim = posMeio;
			posMeio = operation.mediaEntreDoisNumeros( posComeco, posFim );
		}

		// Apenas a saida da busca.
		if( matriz[posMeio] == numalvo )
		{
			std::cout << matriz[posMeio] << ' ';
			std::cout << posMeio << '\n';
			break;
		}
	}
}

/*###################################################
 *#
 *#	SETOR DE EXECUÇÃO
 *#
 *###################################################*/

int main(int argc, char* argv[])
{
	std::string textoA = "Busca Binaria";

	Ordenacao sort;
	Busca search;
	Utilitarios uti;

	const char alfabeto[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	search.buscaBinariaAlfabeto( 'j', 26, alfabeto );
	search.buscaBinariaAlfabeto( 'd', 26, alfabeto );
	search.buscaBinariaAlfabeto( 'k', 26, alfabeto );
	search.buscaBinariaAlfabeto( 's', 26, alfabeto );
	search.buscaBinariaAlfabeto( 'x', 26, alfabeto );

	int numeros[20] = { 34,61,44,826,14,5612,45,72,5,872,34,7827,66,675,456,45,882,45,122,412 };
	
	uti.printMatriz( sort.ordenacaoBolha( numeros, 20 ), 20 );
	search.buscaBinariaNumerica( 882, 20, numeros );

	Matematica f;
	f.fibonatiA();

	for( unsigned int vit=0; vit<=100; vit++)
	{
		f.eprimo(vit);
	}

	std::exit(0);
}
