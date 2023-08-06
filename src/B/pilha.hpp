#ifndef PILHA_HPP_INCLUDED
#define PILHA_HPP_INCLUDED

#define LIMITE 10000

class Pilha
{
	protected:
		char* m;
		int tamanho;
		unsigned int ponteiroPilhae;

	public:
		Pilha();
		Pilha( int tam );
		~Pilha();

		int tam( void );

		void empilhar( char v );
		char desempilhar( void );

		char topo( void );

		bool vazia( void );
		bool cheia( void );
};

#endif //PILHA_HPP_INCLUDED
