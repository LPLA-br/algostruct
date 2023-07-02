#ifndef MODELO_HPP_INCLUDED
#define MODELO_HPP_INCLUDED

struct No
{
	unsigned short id;
	char c;
	No* anterior;
	No* posterior;
};

class ListaDuplamenteEncadeada
{
	private:
		unsigned short int num_elementos;
		No* corrente;
	protected:
		void correnteParaUltimo( void );
		void correnteParaPrimeiro( void );
		void correnteParaAntesDe( unsigned short int posicao );
		void vazio( void );
	public:
		ListaDuplamenteEncadeada( void );
		ListaDuplamenteEncadeada( char c );
		~ListaDuplamenteEncadeada( void );

		void adicionarUltimo( char c );
		char retirarUltimo( void );

		void adicionarComesso( char c );
		char retirarComesso( void );

		void adicionarFrentePosicao( unsigned short int posicao, char c );
		char removerFrentePosicao(  unsigned short int posicao  );

		void descreva( void );
		
};

struct Atendido
{
	char prioridade;
	char operacao;
	unsigned short int numero;

	Atendido* posterior;
	Atendido* anterior;
};

class FilaPrioritaria
{
	private:
	protected:
	public:
		FilaPrioritaria( void );

		Atendido* novoNo( void );
		void deleteNo( Atendido* alvo );
};

#endif // MODELO_HPP_INCLUDED
