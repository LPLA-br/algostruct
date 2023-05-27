#ifndef TAD_HPP_INCLUDED
#define TAD_HPP_INCLUDED

#define LIMITE 10000

class Tad
{
	protected:
		int* m;
		int tamanho;
		int ponteiroPilhae;
		bool ultimaremocao;
		bool ordenado;
	public:
		Tad();
		Tad( int tam );
		~Tad();

		int tamanhom( void );

		void ordenar( void );

		void inserirValor( int v );
		int removerValor( void );

		int maiorValor( void );
		int menorValor( void );

		void escrever( char modo );
};

#endif //TAD_HPP_INCLUDED
