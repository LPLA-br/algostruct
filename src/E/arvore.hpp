#ifndef ARVORE_HPP_INCLUDED
#define ARVORE_HPP_INCLUDED

struct No
{
	std::string info;

	No* direita;
	No* esquerda;
};

class Arvore
{
	private:
		No* raiz;
		No* explorador;
		
	protected:

	public:
		Arvore( void );
		Arvore( std::string texto );
		~Arvore( void );


};

#endif // ARVORE_HPP_INCLUDED
