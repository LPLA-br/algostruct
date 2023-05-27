#ifndef PILHA_HPP_INCLUDED
#define PILHA_HPP_INCLUDED

#define PILHAMAX 10000

class Pilha
{
	protected:
		int* m;
		int tamanho;
		int ponteiroPilhae;
		bool ordenado;
	public:
		Pilha();
		Pilha( int tam );
		~Pilha();

		int tam( void );
		void ordenar( void );

		void inserirValor( int v );
		int removerValor( void );

		int maiorValor( void );
		int menorValor( void );

		void printPilha( void );
};

#endif //PILHA_HPP_INCLUDED
