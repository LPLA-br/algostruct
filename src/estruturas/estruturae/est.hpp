#ifndef MODELO_HPP_INCLUDED
#define MODELO_HPP_INCLUDED

struct Senha
{
	char prioridade;
	char operacao;
	uint8_t numero;

	Senha* anterior;
	Senha* proximo;
};

class FilaPrioritaria
{
	private:
		Senha* p;

	protected:
		void irUltimo( void );
		void irPrimeiro( void );
		bool verifPrioridadeEtOperacao( char prioridade, char operacao );

	public:
		FilaPrioritaria( void );
		FilaPrioritaria( char prioridade, char operacao, uint8_t numero );
		~FilaPrioritaria( void );

		void enfileirar( char prioridade, char operacao );
		void desenfileirar( void );

		void descreva( void );
};

#endif // MODELO_HPP_INCLUDED
