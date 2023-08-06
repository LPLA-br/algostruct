#ifndef UTILITARIOS_HPP_INCLUDED
#define UTILITARIOS_HPP_INCLUDED

class Utilitarios
{
	private:
	protected:
	public:
		void escreverMatriz( int* m, unsigned int tamanho );
		unsigned int mediaEntreDoisNumeros( int a, int b );
		void swap( int* a, int* b );
		void escreverMatrizEntreValores( int* m, unsigned int comesso, unsigned int fim );
		int* gerarmatrizaleatoria( int tamanho, int maxnum );
		int* gerarmatrizordendadadecrescente( int tamanho, int maxnum );
};

#endif //UTILITARIOS_HPP_INCLUDED
