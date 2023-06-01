#ifndef FILA_HPP_INCLUDED
#define FILA_HPP_INCLUDED

#define MAXIMVS 100

class Fila
{
	protected:
		char* m;
		unsigned int caput;
		unsigned int pedes;
	public:

		Fila();
		~Fila();

		void enfileirar( char letra );
		char desenfileirar( void );

		char proximo( void );

		void limparFila( void );

		bool vazia( void );
		bool cheia( void );

		void status( void );
};


#endif //FILA_HPP_INCLUDED
