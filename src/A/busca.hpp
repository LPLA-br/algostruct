#ifndef BUSCA_HPP_INCLUDED
#define BUSCA_HPP_INCLUDED

class Busca
{
	private:
	protected:
	public:
		unsigned int buscaLinear( int alvo, int matriz[] );
		void buscaBinariaAlfabeto( char caractereAlvo, unsigned int tamanhoAbs, const char* alfabeto );
		void buscaBinariaNumerica( int numalvo, unsigned int tamanhoAbs, const int* matriz);
};

#endif // BUSCA_HPP_INCLUDED
