#ifndef MODELO_HPP_INCLUDED
#define MODELO_HPP_INCLUDED

struct Senha
{
	char prioridade;
	uint8_t numero;

	Senha* anterior;
	Senha* proximo;
};

class FilaPrioritaria
{
	private:
		Senha* p;
		char operacao;
		unsigned short int numeroNos;

	protected:
		retornoLocalidade* localizarPontoDeInsercao( void );

	public:
		FilaPrioritaria( void );
		FilaPrioritaria( char op );
		~FilaPrioritaria( void );


		void enfileirar( char prioridade );
		void desenfileirar( void );

		void descreva( void );
};

#endif // MODELO_HPP_INCLUDED
