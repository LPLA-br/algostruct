#ifndef DIRETORIO_HPP_INCLUDED
#define DIRETORIO_HPP_INCLUDED

struct No
{
	std::string rota;

	No* pai;

	No* esquerda;
	No* direita;
};

class Diretorio
{
	private:
		No* radix;
		No* currens;
		unsigned short int numeroDeNos;

	protected:
		No* novoNo( bool aDireita );

		void ls( void );
		void mknode( char esqDir );
		void cnode( char esqDirPai );
		void pwd( void );
		void rm( char esqDir );


	public:
		Diretorio();

		~Diretorio( void );

		unsigned int mostrarProfundidadeDoGrafoDeDiretorios( No* leitor );

		void inOrderCorrer( No* leitor );
		void preOrderCorrer( No* leitor );
		void posOrderCorrer( No* leitor );

		void shell( void );
};

#endif // DIRETORIO_HPP_INCLUDED
